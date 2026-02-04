#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "../../../lib/utf8.h/utf8.h"
#include "../../../lib/utf8file/utf8file.h"

#include "../../token/token.h"

#include "internal.h"

/*
$COMMENT        = "(*" , { $CHARACTER } - ( { $CHARACTER } , "*)" , { $CHARACTER } ) , "*)" ;
$NONTERMINAL_IDENTIFIER     = $LETTER , { $LETTER | $DIGIT | "_" } ;
$TERMINAL_IDENTIFIER = "$" , ( $LETTER | "_" ) , { $LETTER | $DIGIT | "_" } ;
$LITERAL        = "'" , { $CHARACTER - "'" } , "'" 
               | '"' , { $CHARACTER - '"' } , '"' ;
$LETTER         = "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K" | "L" | "M"
	       | "N" | "O" | "P" | "Q" | "R" | "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z"
	       | "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m"
	       | "n" | "o" | "p" | "q" | "r" | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z" ;
$DIGIT          = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;
$SYMBOL	       = "`" | "~" | "!" | "@" | "#" | "$" | "%" | "^" | "&" | "*" | "(" | ")" | "_"
	       | "-" | "+" | "=" | "{" | "}" | "[" | "]" | ":" | ";" | "<" | ">" | "," | "."
	       | "?" | "/" | "|" | "\" | "'" | '"' ;
$CHARACTER      =  $LETTER | $DIGIT | $SYMBOL ;
*/

static Token lexer_lex_nonterminal_identifier(Lexer *l);
static Token lexer_lex_terminal_identifier(Lexer *l);
static Token lexer_lex_operator(Lexer *l);
static Token lexer_lex_literal(Lexer *l);
//static Token lexer_lex_comment(Lexer *l);

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

	if(utf8chr("$", c)) {
		return lexer_lex_terminal_identifier(l);
	}

	if(utf8chr(LETTER_CHARS "_", c)) {
		return lexer_lex_nonterminal_identifier(l);
	}

	if(utf8chr("\"" "\'", c)) {
		return lexer_lex_literal(l);
	}

	if(utf8chr(INVALID_CHARS, c)) {
		result.lexeme = "invalid";
		result.type = TokenType_Invalid;
	}

	lexer_advance(l);

	return result;
}

Token lexer_lex_terminal_identifier(Lexer *l) {
	Token result = {
		.lexeme = NULL,
		.type = TokenType_Terminal_Identifier,
		.pos = {
			.row = l->pos.row,
			.col = l->pos.col,
		},
	};
	size_t len = 1;

	if(utf8chr("_" LETTER_CHARS, lexer_advance(l)) == NULL) {
		// error
	}

	do {
		len += utf8codepointsize(lexer_current_character(l));
	} while(utf8chr(LETTER_CHARS DIGIT_CHARS "_", lexer_advance(l)) != NULL);

	result.lexeme = utf8file_copy_from(l->f, utf8file_tell(l->f) - len, len);
	lexer_undo(l);

	return result;
}

Token lexer_lex_nonterminal_identifier(Lexer *l) {
	Token result = {
		.lexeme = NULL,
		.type = TokenType_Terminal_Identifier,
		.pos = {
			.row = l->pos.row,
			.col = l->pos.col,
		},
	};
	size_t len = 1;

	do {
		len += utf8codepointsize(lexer_current_character(l));
	} while(utf8chr(LETTER_CHARS DIGIT_CHARS "_", lexer_advance(l)) != NULL);

	result.lexeme = utf8file_copy_from(l->f, utf8file_tell(l->f) - len, len);
	lexer_undo(l);

	return result;
}

static Token lexer_lex_operator(Lexer *l) {
	Token result = {
		.lexeme = NULL,
		.type = TokenType_Operator,
		.pos = {
			.row = l->pos.row,
			.col = l->pos.col,
		},
	};
        utf8_int32_t peeked = lexer_peek_character(l);

        switch(lexer_current_character(l)) {
        case '=':
		result.lexeme = "=";
                break;
	case '|':
		result.lexeme = "|";
		break;
	case '[':
		result.lexeme = "[";
		break;
	case ']':
		result.lexeme = "]";
		break;
	case '{':
		result.lexeme = "{";
		break;
	case '}':
		result.lexeme = "}";
		break;
	case '(':
		result.lexeme = "(";
		break;
	case ')':
		result.lexeme = ")";
		break;
	case ',':
		result.lexeme = ",";
		break;
	case ';':
		result.lexeme = ";";
		break;
        }

        return result;
}

static Token lexer_lex_literal(Lexer *l) {
	Token result = {
		.lexeme = NULL,
		.type = TokenType_Literal,
		.pos = {
			.row = l->pos.row,
			.col = l->pos.col,
		},
	};
	size_t len = 0;
	char end = lexer_current_character(l);

	do {
		len += utf8codepointsize(lexer_advance(l));
	} while(lexer_current_character(l) != end);

	result.lexeme = utf8file_copy_from(l->f, utf8file_tell(l->f) - len, len);

	return result;
}
