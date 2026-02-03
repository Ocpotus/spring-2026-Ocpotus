#ifndef LEXER_H
#define LEXER_H

#include "../token/token.h"


/* Opaque declaration */
typedef struct Lexer Lexer;

/* Constructs a new Lexer
 *
 * PARAMETERS:
 * 	path: path of file to open
 *
 * RETURNS:
 * 	A pointer to a Lexer or NULL on failure
 */
Lexer *lexer_new(const char *path);

/* Deletes a Lexer
 *
 * PARAMETERS:
 * 	l: a pointer to a lexer
 */
void lexer_delete(Lexer *l);

/* Retrieves a token
 *
 * PARAMETERS:
 * 	l: a pointer to a Lexer
 *
 * RETURNS:
 * 	The next Token in the stream
 */
Token lexer_get_token(Lexer *l);


#endif
