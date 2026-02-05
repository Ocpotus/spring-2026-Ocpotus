#ifndef PARSER_INTERNAL_H
#define PARSER_INTERNAL_H

#include <stdlib.h>
#include <stdbool.h>

#include "../../token/token.h"
#include "../../lexer/lexer.h"
#include "../../ast/ast.h"


/* Parser struct
 *
 * MEMBERS:
 * 	l: file Lexer
 * 	previous: previously processed Token from l
 * 	current: the current token in l
 * 	peek: the peeked token in l
 */
typedef struct Parser {
	Lexer *l;
	Token previous;
	Token current;
	Token peek;
	const char *error;
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
Token parser_peek(Parser *p);

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

Grammar parser_parse_internal(Parser *p);


#endif
