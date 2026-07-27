#ifndef VERBUM_TOKEN_H
#define VERBUM_TOKEN_H

#include <stdint.h>

#include "verbum.h"


typedef const char *Lexeme;

typedef enum TokenType {
	TokenType_Invalid = -3,
	TokenType_Whitespace = -2,
	TokenType_EOF = -1,
	TokenType_IDENTIFIER,
	TokenType_LETTER,
	TokenType_DIGIT,
	TokenType_SYMBOL,
	TokenType_INTEGER_CONSTANT,
	TokenType_DECIMAL_CONSTANT,
	TokenType_OCTAL_CONSTANT,
	TokenType_HEX_CONSTANT,
	TokenType_HEX_DIGIT,
	TokenType_INTEGER_SUFFIX,
	TokenType_CHARACTER_CONSTANT,
	TokenType_C_CHAR,
	TokenType_FLOATING_CONSTANT,
	TokenType_FRACTIONAL_CONSTANT,
	TokenType_EXPONENT_PART,
	TokenType_DIGIT_SEQUENCE,
	TokenType_FLOAT_SUFFIX,
	TokenType_ENUMERATION_CONSTANT,
	TokenType_STRING,
	TokenType_STRING_CHARACTER,
	TokenType_ESCAPE_SEQUENCE,
	TokenType_OCTAL_ESCAPE,
	TokenType_OCTAL_DIGIT,
	TokenType_HEX_ESCAPE,
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
