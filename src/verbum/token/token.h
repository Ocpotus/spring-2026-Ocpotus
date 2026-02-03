#ifndef VERBUM_TOKEN_H
#define VERBUM_TOKEN_H

#include <stdint.h>

/* Identifier and keyword charset */
#define RULE_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_1234567890-"
/* Operator charset */
#define RULE_START_CHAR '<'
#define RULE_END_CHAR '>'
#define OR_CHAR '|'

#define OPERATOR_CHARS "=:|"
/* Literal charset */
#define LITERAL_CHARS "\'\""
/* Invalid charset */
#define INVALID_CHARS ",?&^!+*/%~)(][}{.;"
/* Whitespace charset */
#define WHITE_SPACE " \t\n\v\f\r"
/* Invalid charset for an identifier or keyword */
#define INVALID_RULE_CHARS OPERATOR_CHARS INVALID_CHARS WHITE_SPACE LITERAL_CHARS


/* Simple alias for const char * */
typedef const char *Lexeme;

/* Possible Token types of the C programming language */
typedef enum TokenType {
        TokenType_Invalid = -2,
        TokenType_EOF = -1, // EOF

	TokenType_Whitespace,
        TokenType_RuleName, // <abc>, <ABC>, <_aBc>, <a123_b>, <a123-b>
	TokenType_Literal, // "hello", 'hello'

	TokenType_Evaluate, // ::=

        TokenType_Or, // |
} TokenType;

/* Token
 *
 * MEMBERS:
 *	lexeme: lexeme processed
 *	type: the type of token processed
 *	pos:
 *		row: row in the file processed
 *		col: column in the file processed
 */
typedef struct Token {
	Lexeme lexeme;
	TokenType type;
	struct {
		uint32_t row;
		uint32_t col;
	} pos;
} Token;
/* Deletes a Token
 *
 * PARAMETERS:
 * 	t: Token to delete
 */
void token_delete(Token t);


#endif
