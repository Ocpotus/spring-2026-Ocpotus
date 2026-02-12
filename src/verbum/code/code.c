#include <stdio.h>

#include "../../lib/c-vector/cvector.h"

#include "../ast/ast.h"
#include "../token/token.h"

#include "code.h"

void code_generate_token(cvector(Token) ts) {
	FILE *f = stdout;

	fprintf(f, "typedef enum TokenType {\n");

	int operatorTokenVal = 1;

	for(Token *it = cvector_begin(ts); it != cvector_end(ts); it += 1) {
		if(it->type == TokenType_Terminal_Identifier || it->type == TokenType_NonTerminal_Identifier) {
			fprintf(f, "\tTokenType_%s,\n", it->lexeme);
		} else {
			fprintf(f, "\tTokenType_%d, // %s\n", operatorTokenVal, it->lexeme);
			operatorTokenVal += 1;
		}
	}

	fprintf(f, "} TokenType;\n");
}



#ifdef JAUNTY
#include "../../lib/c-vector/cvector.h"

#include "../ast/ast.h"

#include "code.h"


static const char *const tokenText[];
static const char *const lexerText[];

static void code_generate_lexer(Rule r);

void code_generate(AST *ast) {
	for(Rule *it = cvector_begin(ast->rule1); it != cvector_end(ast->rule1); it += 1) {

	}
}
static const char *const lexerText[] = {

};

static const char *const lexerText[] = {
	// Public h
	"#ifndef VERBUM_LEXER_H"
	"#define VERBUM_LEXER_H"
	"#include \"../token/token.h\""
	"/* Opaque declaration */"
	"typedef struct Lexer Lexer;"
	"/* Constructs a new Lexer"
	" *"
	" * PARAMETERS:"
	" * 	path: path of file to open"
	" *"
	" * RETURNS:"
	" * 	A pointer to a Lexer or NULL on failure"
	" */"
	"Lexer *lexer_new(const char *path);"
	"/* Deletes a Lexer"
	" *"
	" * PARAMETERS:"
	" * 	l: a pointer to a lexer"
	" */"
	"void lexer_delete(Lexer *l);"
	"/* Retrieves a token"
	" *"
	" * PARAMETERS:"
	" * 	l: a pointer to a Lexer"
	" *"
	" * RETURNS:"
	" * 	The next Token in the stream"
	" */"
	"Token lexer_get_token(Lexer *l);"
	"#endif",
	// Public c
	"#include \"../../lib/utf8file/utf8file.h\""
	"#include \"../memory/memory.h\""
	"#include \"internal/internal.h\""
	"#include \"lexer.h\""
	"Lexer *lexer_new(const char *path) {"
	"	Lexer *result = memory_new(1 * sizeof(*result));"
	"	if(result != NULL) {"
		"	result->f = utf8file_open(path);"
		"	result->pos.row = 1;"
		"	result->pos.col = 1;"
		"	if(result->f == NULL) {"
			"	memory_delete(result);"
		"	}"
	"	}"
	"	return result;"
	"}"
	"void lexer_delete(Lexer *l) {"
	"	utf8file_close(l->f);"
	"	memory_delete(l);"
	"}"
	"Token lexer_get_token(Lexer *l) {"
	"	return lexer_lex(l);"
	"}",
	// Private h
	"#ifndef VERBUM_LEXER_INTERNAL_H"
	"#define VERBUM_LEXER_INTERNAL_H"
	"#include <stdbool.h>"
	"#include \"../../../lib/utf8.h/utf8.h\""
	"#include \"../../../lib/utf8file/utf8file.h\""
	"#include \"../../token/token.h\""
	"/* Lexer struct"
	" *"
	" * MEMBERS:"
	" * 	f: a pointer to a UTF8File to read from"
	" * 	pos:"
	" * 		row: current row in the file"
	" * 		column: current column in the file"
	" * 	cc: current character"
	" */"
	"typedef struct Lexer {"
	"	UTF8File *f;"
	"	struct {"
		"	uint32_t row;"
		"	uint32_t col;"
	"	} pos;"
	"	utf8_int32_t cc;"
	"} Lexer;"
	"/* Advances a Lexer's position"
	" *"
	" * PARAMETERS:"
	" * 	l: pointer to a Lexer to advance"
	" * "
	" * RETURNS:"
	" * 	The retrieved character from the given Lexer's stream"
	" */"
	"utf8_int32_t lexer_advance(Lexer *l);"
	"/* Retrieves the current character of a Lexer"
	" *"
	" * PARAMETERS:"
	" * 	l: a pointer to a Lexer to process"
	" *"
	" * RETURNS:"
	" * 	The current character in the Lexer's stream"
	" */"
	"utf8_int32_t lexer_current_character(Lexer *l);"
	"/* Peeks a character in a Lexer's stream"
	" *"
	" * PARAMETERS:"
	" * 	l: a pointer to a Lexer to process"
	" *"
	" * RETURNS:"
	" * 	The next character in the Lexer's stream"
	" */"
	"utf8_int32_t lexer_peek_character(Lexer *l);"
	"/* Undos the previous action by a Lexer"
	" *"
	" * PARAMETERS:"
	" * 	l: a pointer to a Lexer to process"
	" */"
	"void lexer_undo(Lexer *l);"
	"/* Checks if a Lexer is at the end of its stream"
	" *"
	" * PARAMETERS:"
	" * 	l: a pointer to a Lexer to check"
	" *"
	" * RETURNS:"
	" *	true if the given Lexer is at the end, false otherwise"
	" */"
	"bool lexer_at_end(Lexer *l);"
	"/* Reports an error encountered by the Lexer"
	" *"
	" * PARAMETERS:"
	" * 	l: a pointer to a Lexer to propogate the error from"
	" * 	c: the character that caused the error"
	" */"
	"void lexer_report_error(Lexer *l, utf8_int32_t c);"
	"/* Retrieves a token"
	" *"
	" * PARAMETERS:"
	" * 	l: a pointer to a Lexer"
	" *"
	" * RETURNS:"
	" * 	The next Token in the stream"
	" */"
	"Token lexer_lex(Lexer *l);"
	"#endif",
	// Private c (top)
	"#include <stdio.h>"
	"#include <stdbool.h>"
	"#include <string.h>"
	"#include <ctype.h>"
	"#include \"../../../lib/utf8.h/utf8.h\""
	"#include \"../../../lib/utf8file/utf8file.h\""
	"#include \"../../token/token.h\""
	"#include \"internal.h\""
	"utf8_int32_t lexer_advance(Lexer *l) {"
	"	utf8_int32_t result = '\0';"
	"	if(!lexer_at_end(l)) {"
		"	result = utf8file_get_codepoint(l->f);"
		"	if(result == '\n') {"
			"	l->pos.row += 1;"
			"	l->pos.col = 1;"
		"	} else {"
			"	l->pos.col += 1;"
		"	}"
		"	l->cc = result;"
	"	}"
	"	return result;"
	"}"
	"utf8_int32_t lexer_current_character(Lexer *l) {"
	"	return l->cc;"
	"}"
	"utf8_int32_t lexer_peek_character(Lexer *l) {"
	"	utf8_int32_t result = utf8file_get_codepoint(l->f);"
	"	utf8file_unget_codepoint(l->f);"
	"	return result;"
	"}"
	"void lexer_undo(Lexer *l) {"
	"	utf8file_unget_codepoint(l->f);"
	"}"
	"bool lexer_at_end(Lexer *l) {"
	"	return utf8file_at_end(l->f);"
	"}"
	"void lexer_report_error(Lexer *l, utf8_int32_t c) {"
	"	fprintf(stderr, \"%s: (%d:%d) unrecognized token '%lc'\n\", utf8file_path(l->f), l->pos.row, l->pos.col, c);"
	"}",
};
#endif
