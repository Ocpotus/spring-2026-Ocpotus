#ifndef VERBUM_TOKEN_H
#define VERBUM_TOKEN_H

#include <stdint.h>

#include "verbum.h"


typedef const char *Lexeme;

typedef enum TokenType {
	TokenType_Invalid = -3,
	TokenType_Whitespace = -2,
	TokenType_EOF = -1,
	TokenType_NONTERMINAL_IDENTIFIER,
	TokenType_TERMINAL_IDENTIFIER,
	TokenType_LITERAL,
	TokenType_LETTER,
	TokenType_DIGIT,
	TokenType_SYMBOL,
	TokenType_CHARACTER,
	TokenType_Keyword,
} TokenType;

typedef struct Token {
	Lexeme lexeme;
	TokenType tag;
	struct {
		uint32_t row;
		uint32_t col;
	} pos;
} Token;

void verbum_token_delete(VerbumContext *ctx, Token *t);

const char *verbum_token_in_language(register const char *str, register size_t len);
TokenType verbum_token_get_keyword_type(const char *lexeme);
TokenType verbum_token_get_lexeme_type(const char *lexeme);


#endif
