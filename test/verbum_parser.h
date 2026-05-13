#ifndef VERBUM_PARSER_H
#define VERBUM_PARSER_H

#include <stdlib.h>
#include <stdbool.h>

#include "cvector.h"

#include "verbum_ast.h"
#include "verbum_lexer.h"
#include "verbum_token.h"

/* Opaque declaration */
typedef struct Parser Parser;

/* Constructs a new Parser
 *
 * PARAMETERS:
 * 	path: path to a file to parse
 *
 * RETURNS:
 * 	Success: a pointer to a Parser
 * 	Failure: NULL
 */
Parser *parser_new(VerbumContext *ctx, const char *path);

/* Deletes a Parser
 *
 * PARAMETERS:
 * 	p: Parser to delete
 */
void parser_delete(Parser *p);

/* Executes the parsing process for a Parser
 *
 * PARAMETERS:
 * 	p: Parser to execute
 *
 * RETURNS:
 * 	A pointer to a Unit representing the parsed
 * 	file passed in with the path in parser_new
 */
AST *parser_parse(Parser *p);


/* Parser struct
 *
 * MEMBERS:
 * 	l: file Lexer
 * 	previous: previously processed Token from l
 * 	current: the current token in l
 * 	peek: the peeked token in l
 */
typedef struct Parser {
	VerbumContext *ctx;
	Lexer *l;
	Token previous;
	Token current;
	Token peek;
	const char *error;
	cvector(Token) save;
	size_t savepos;
	size_t savedepth;
} Parser;


/* Advances the parser
 *
 * PARAMETERS:
 * 	p: parser to advance
 *
 * RETURNS:
 * 	the next token
 */
Token parser_advance(Parser *p);

/* Retrieves the previous token
 *
 * PARAMETERS:
 * 	p: the parser to get the previous token
 *
 * RETURNS:
 * 	the previous token
 */
Token parser_previous(Parser *p);

/* Retrieves the current token
 *
 * PARAMETERS:
 * 	p: the parser to get the current token
 *
 * RETURNS:
 * 	the current token
 */
Token parser_current(Parser *p);

/* Checks if a Parser's previously processed Token is of a certain TokenType
 *
 * PARAMETERS:
 * 	p: Parser to check
 * 	tt: TokenType to check for
 *
 * RETURNS:
 * 	If the previously parsed token is of the given type
 */
bool parser_previous_is(Parser *p, TokenType tt);

/* Peeks the next token without advancing
 *
 * PARAMETERS:
 * 	p: the parser to get the next token
 *
 * RETURNS:
 *	the peeked token
 */
Token parser_peek2(Parser *p);
Token parser_peek(Parser *p, size_t peek);

/* Checks if the next token is of the desired type
 *
 * PARAMETERS:
 * 	p: the parser to check
 * 	tt: the desired token type
 *
 * RETURNS:
 * 	if the next token is of the desired type
 */
bool parser_check(Parser *p, TokenType tt);
bool parser_check2(Parser *p, const char *tl);

/* Checks and advances if the next token is of the desired type
 *
 * PARAMETERS:
 * 	p: parser to match to
 * 	tt: desired type
 *
 * RETURNS:
 * 	true: if the match was successful
 * 	false: if the match was unsuccessful
 */
bool parser_match(Parser *p, TokenType tt);
bool parser_match2(Parser *p, const char *tl);

/* Checks and advances if the next token is any of the desired types
 *
 * PARAMETERS:
 * 	p: parser to match to
 * 	tts: an array of expected TokenTypes
 * 	n: length of tts
 *
 * RETURNS:
 * 	true: if the match was successful
 * 	false: if the match was unsuccessful
 */
bool parser_match_any(Parser *p, TokenType *tts, size_t n);

/* Checks if the parser is at the end of the token stream
 *
 * PARAMETERS:
 * 	p: parser to check
 *
 * RETURNS:
 * 	true: if the parser is at the end
 * 	false: if the parser is not at the end
 */
bool parser_at_end(Parser *p);

const char *parser_set_error(Parser *p, const char *error);

void parser_reset_error(Parser *p);

bool parser_errored(Parser *p);

start *parser_parse_internal(Parser *p);
#endif

