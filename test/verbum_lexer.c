#include <stdio.h>
#include <stdint.h>

#include "utf8.h"

#include "verbum_lexer.h"
#include "verbum_token.h"
#include "verbum.h"


/* Advances a Lexer's position
 *
 * PARAMETERS:
 * 	l: pointer to a Lexer to advance
 * 
 * RETURNS:
 * 	The retrieved character from the given Lexer's stream
 */
static uint32_t lexer_advance(Lexer *l);

/* Retrieves the current character of a Lexer
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to process
 *
 * RETURNS:
 * 	The current character in the Lexer's stream
 */
static uint32_t lexer_current_character(Lexer *l);

/* Peeks a character in a Lexer's stream
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to process
 *
 * RETURNS:
 * 	The next character in the Lexer's stream
 */
static uint32_t lexer_peek_character(Lexer *l);

/* Undos the previous action by a Lexer
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to process
 */
static void lexer_undo(Lexer *l);

/* Checks if a Lexer is at the end of its stream
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to check
 *
 * RETURNS:
 *	true if the given Lexer is at the end, false otherwise
 */
static bool lexer_at_end(Lexer *l);

/* Reports an error encountered by the Lexer
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to propogate the error from
 * 	c: the character that caused the error
 */
static void lexer_report_error(Lexer *l, uint32_t c);

/* Retrieves a token
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer
 *
 * RETURNS:
 * 	The next Token in the stream
 */
static Token lexer_lex(Lexer *l);

/* Lexer struct
 *
 * MEMBERS:
 * 	f: a pointer to a UTF8File to read from
 * 	pos:
 * 		row: current row in the file
 * 		column: current column in the file
 * 	cc: current character
 */
typedef struct Lexer {
	void *stream;
	const char *path;
	VerbumContext *ctx;
	struct {
		uint32_t row;
		uint32_t col;
	} pos;
	uint32_t cc;
} Lexer;

Lexer *lexer_new(VerbumContext *ctx, const char *path) {
	Lexer *result = ctx->memory.new(1 * sizeof(*result));

	if(result != NULL) {
		result->ctx = ctx;
		result->stream = result->ctx->io.open(path);
		result->path = path;
		result->pos.row = 1;
		result->pos.col = 1;
		result->cc = lexer_advance(result);

		if(result->stream == NULL) {
			result->ctx->memory.delete(result);

			result = NULL;
		}
	}

	return result;
}

void lexer_delete(Lexer *l) {
	l->ctx->io.close(l->stream);
	l->ctx->memory.delete(l);
}

Token lexer_get_token(Lexer *l) {
	return lexer_lex(l);
}

const char *lexer_get_source(Lexer *l) {
	return l->ctx->io.source(l->stream);
}

uint32_t lexer_advance(Lexer *l) {
	uint32_t result = '\0';

	if(!lexer_at_end(l)) {
		result = l->ctx->io.get(l->stream);

		if(result == '\n') {
			l->pos.row += 1;
			l->pos.col = 1;
		} else {
			l->pos.col += 1;
		}

		l->cc = result;
	}

	return result;
}

uint32_t lexer_current_character(Lexer *l) {
	return l->cc;
}

uint32_t lexer_peek_character(Lexer *l) {
	uint32_t result = l->ctx->io.get(l->stream);

	l->ctx->io.unget(l->stream);

	return result;
}

void lexer_undo(Lexer *l) {
	l->ctx->io.unget(l->stream);
}

bool lexer_at_end(Lexer *l) {
	return l->ctx->io.at_end(l->stream);
}

void lexer_report_error(Lexer *l, uint32_t c) {
	fprintf(stderr, "%s: (%d:%d) unrecognized token '%lc'\n", l->path, l->pos.row, l->pos.col, c);
}

static size_t lexer_lex_NUMBER(Lexer *l);
static size_t lexer_lex_DIGIT(Lexer *l);
static size_t lexer_lex_builtin(Lexer *l) {
	size_t result = 0;
	size_t consumed = 0;
	if(utf8chr("*", lexer_current_character(l))) {
		lexer_advance(l);
		consumed += 1;
		goto EXIT;
	} else {
	}
	if(utf8chr("-", lexer_current_character(l))) {
		lexer_advance(l);
		consumed += 1;
		goto EXIT;
	} else {
	}
	if(utf8chr("/", lexer_current_character(l))) {
		lexer_advance(l);
		consumed += 1;
		goto EXIT;
	} else {
	}
	if(utf8chr("+", lexer_current_character(l))) {
		lexer_advance(l);
		consumed += 1;
		goto EXIT;
	} else {
	}
EXIT:
	result += consumed;
	return result;
}
Token lexer_lex(Lexer *l) {
	Token result = {
		.lexeme = "Invalid",
		.tag = TokenType_Invalid,
		.pos = {
			.row = l->pos.row,
			.col = l->pos.col,
		},
	};
	uint32_t c = lexer_current_character(l);
	size_t length = 0;

	if(lexer_at_end(l)) {
		return (Token) {
			.lexeme = "EOF",
			.tag = TokenType_EOF,
			.pos = {
				.row = l->pos.row,
				.col = l->pos.col,
			},
		};
	}

	if(utf8chr(" \r\n\t", c)) {
		lexer_advance(l);
		return (Token) {
			.lexeme = " ",
			.tag = TokenType_Whitespace,
		};
	}

	/* Lexer functions */

	length = lexer_lex_builtin(l);
	if(length != 0) {
		Lexeme lexeme = l->ctx->io.copy_from(l->stream, l->ctx->io.tell(l->stream) - (length + 1), length + 1);

		if(lexeme == NULL) {
			// Error
			return result;
		}

		result = (Token) {
			.tag = verbum_token_get_lexeme_type(lexeme),
			.lexeme = lexeme,
			.pos = { 0 },
		};

		return result;
	}
	if(utf8chr("5327041896", c)) {
		size_t length = lexer_lex_NUMBER(l);

		if(length != 0) {
			Lexeme lexeme = l->ctx->io.copy_from(l->stream, l->ctx->io.tell(l->stream) - (length + 1), length + 1);

			if(lexeme == NULL) {
				// Error
				return result;
			}

			result = (Token) {
				.tag = TokenType_NUMBER,
				.lexeme = lexeme,
				.pos = { 0 },
			};

			return result;
		}
	}

	lexer_report_error(l, lexer_current_character(l));
	lexer_advance(l);

	return result;
}
static size_t lexer_lex_NUMBER(Lexer *l) {
	size_t result = 0;

	size_t consumed = 0;
	consumed += lexer_lex_DIGIT(l);
	while(utf8chr("5327041896", lexer_current_character(l))) {
		size_t consumed = 0;
		consumed += lexer_lex_DIGIT(l);
		result += consumed;
	}
	result += consumed;

EXIT:
	return result;
}

static size_t lexer_lex_DIGIT(Lexer *l) {
	size_t result = 0;

	size_t consumed = 0;
	if(consumed == 0) {
		if(utf8chr("0", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	if(consumed == 0) {
		if(utf8chr("1", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	if(consumed == 0) {
		if(utf8chr("2", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	if(consumed == 0) {
		if(utf8chr("3", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	if(consumed == 0) {
		if(utf8chr("4", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	if(consumed == 0) {
		if(utf8chr("5", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	if(consumed == 0) {
		if(utf8chr("6", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	if(consumed == 0) {
		if(utf8chr("7", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	if(consumed == 0) {
		if(utf8chr("8", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	if(consumed == 0) {
		if(utf8chr("9", lexer_current_character(l))) {
			lexer_advance(l);
			consumed += 1;
		} else {
		}
	}
	result += consumed;

EXIT:
	return result;
}

