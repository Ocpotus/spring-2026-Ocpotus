#ifndef LEXER_INTERNAL_H
#define LEXER_INTERNAL_H

#include <stdbool.h>

#include "../../../lib/utf8.h/utf8.h"
#include "../../../lib/utf8file/utf8file.h"

#include "../../token/token.h"


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
	UTF8File *f;
	struct {
		uint32_t row;
		uint32_t col;
	} pos;
	utf8_int32_t cc;
} Lexer;

/* Advances a Lexer's position
 *
 * PARAMETERS:
 * 	l: pointer to a Lexer to advance
 * 
 * RETURNS:
 * 	The retrieved character from the given Lexer's stream
 */
utf8_int32_t lexer_advance(Lexer *l);

/* Retrieves the current character of a Lexer
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to process
 *
 * RETURNS:
 * 	The current character in the Lexer's stream
 */
utf8_int32_t lexer_current_character(Lexer *l);

/* Peeks a character in a Lexer's stream
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to process
 *
 * RETURNS:
 * 	The next character in the Lexer's stream
 */
utf8_int32_t lexer_peek_character(Lexer *l);

/* Undos the previous action by a Lexer
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to process
 */
void lexer_undo(Lexer *l);

/* Checks if a Lexer is at the end of its stream
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to check
 *
 * RETURNS:
 *	true if the given Lexer is at the end, false otherwise
 */
bool lexer_at_end(Lexer *l);

/* Reports an error encountered by the Lexer
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer to propogate the error from
 * 	c: the character that caused the error
 */
void lexer_report_error(Lexer *l, utf8_int32_t c);

/* Retrieves a token
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer
 *
 * RETURNS:
 * 	The next Token in the stream
 */
Token lexer_lex(Lexer *l);


#endif
