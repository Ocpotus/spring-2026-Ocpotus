#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "../../../lib/utf8.h/utf8.h"
#include "../../../lib/utf8file/utf8file.h"

#include "../../token/token.h"

#include "internal.h"


static Token lexer_lex_rule_name(Lexer *l);
static Token lexer_lex_operator(Lexer *l);
static Token lexer_lex_literal(Lexer *l, char end_char);

utf8_int32_t lexer_advance(Lexer *l) {
	utf8_int32_t result = '\0';

	if(!lexer_at_end(l)) {
		result = utf8file_get_codepoint(l->f);

		if(result == '\n') {
			l->pos.row += 1;
			l->pos.col = 1;
		}

		l->cc = result;
	}

	return result;
}

utf8_int32_t lexer_current_character(Lexer *l) {
	return l->cc;
}

utf8_int32_t lexer_peek_character(Lexer *l) {
	utf8_int32_t result = utf8file_get_codepoint(l->f);

	utf8file_unget_codepoint(l->f);

	return result;
}

void lexer_undo(Lexer *l) {
	utf8file_unget_codepoint(l->f);
}

bool lexer_at_end(Lexer *l) {
	return utf8file_at_end(l->f);
}

void lexer_report_error(Lexer *l, utf8_int32_t c) {
	fprintf(stderr, "%s: (%d:%d) unrecognized token '%lc'\n", utf8file_path(l->f), l->pos.row, l->pos.col, c);
}

Token lexer_lex(Lexer *l) {
	Token result = {
		.lexeme = "EOF",
		.type = TokenType_EOF,
		.pos = {
			.row = l->pos.row,
			.col = l->pos.col,
		},
	};
	utf8_int32_t c = lexer_advance(l);

	if(isascii(c) && isspace(c)) {
		result = (Token) {
			.lexeme = " ",
			.type = TokenType_Whitespace,
			.pos = {
				.row = l->pos.row,
				.col = l->pos.col,
			},
		};

		return result;
	}

	if(lexer_at_end(l)) {
		return (Token) {
			.lexeme = "EOF",
			.type = TokenType_EOF,
			.pos = {
				.row = l->pos.row,
				.col = l->pos.col,
			},
		};
	}

	if(utf8chr(OPERATOR_CHARS, c)) {
		return lexer_lex_operator(l);
	}

	if(utf8chr(LITERAL_CHARS, c)) {
		return lexer_lex_literal(l, c);
	}

	if(c == RULE_START_CHAR) {
		return lexer_lex_rule_name(l);
	}

	if(utf8chr(INVALID_CHARS, c)) {
		result.lexeme = "invalid";
		result.type = TokenType_Invalid;
	}

	lexer_advance(l);


	return result;
}

Token lexer_lex_rule_name(Lexer *l) {
	Token result = {
		.lexeme = NULL,
		.type = TokenType_RuleName,
		.pos = {
			.row = l->pos.row,
			.col = l->pos.col,
		},
	};
	size_t len = 1;

	lexer_advance(l);

	do {
		len += utf8codepointsize(lexer_current_character(l));
		lexer_advance(l);
	} while(utf8chr(INVALID_RULE_CHARS, lexer_current_character(l)) == NULL && lexer_current_character(l) != RULE_END_CHAR);

	result.lexeme = utf8file_copy_from(l->f, utf8file_tell(l->f) - len, len);
	lexer_advance(l);

	return result;
}

static Token lexer_lex_operator(Lexer *l) {
	Token result = {
		.lexeme = NULL,
		.type = TokenType_Invalid,
		.pos = {
			.row = l->pos.row,
			.col = l->pos.col,
		},
	};
        utf8_int32_t peeked = lexer_peek_character(l);

        switch(lexer_current_character(l)) {
	case '|':
		result.lexeme = "|";
		result.type = TokenType_Or;
		break;
        case ':':
		if(peeked == ':') {
			lexer_advance(l);
			peeked = lexer_peek_character(l);

			if(peeked == '=') {
				result.lexeme = "::=";
				result.type = TokenType_Evaluate;
				lexer_advance(l);
			} else {
				// Error
			}
		} else {
			// Error
		}
                break;
        }

        return result;
}

static Token lexer_lex_literal(Lexer *l, char end_char) {
	Token result = {
		.lexeme = NULL,
		.type = TokenType_Literal,
		.pos = {
			.row = l->pos.row,
			.col = l->pos.col,
		},
	};
	size_t len = 0;

	do {
		len += utf8codepointsize(lexer_advance(l));

		if(lexer_current_character(l) == '\\') {
			len += utf8codepointsize(lexer_advance(l));
		}
	} while(lexer_current_character(l) != end_char);

	result.lexeme = utf8file_copy_from(l->f, utf8file_tell(l->f) - len, len);

	return result;
}
