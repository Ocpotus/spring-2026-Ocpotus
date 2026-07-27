/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -G -L ANSI-C -H verbum_token_hash -N verbum_token_in_language verbum_token.gperf  */
/* Computed positions: -k'1,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#line 1 "verbum_token.gperf"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "verbum.h"
#include "verbum_token.h"

#define TOTAL_KEYWORDS 78
#define MIN_WORD_LENGTH 1
#define MAX_WORD_LENGTH 8
#define MIN_HASH_VALUE 1
#define MAX_HASH_VALUE 251
/* maximum key range = 251, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
verbum_token_hash (register const char *str, register size_t len)
{
  static unsigned char asso_values[] =
    {
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252,  90, 252, 252, 252,  85,  50, 252,
      125, 120,  80,  40, 115,  25,  45,  70, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 110, 105,
       10,   5,   0, 100, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252,  95, 252,  75,  60, 252, 252,  10,  10,  10,
       55,   5,  30,   5,  40,  75, 252,  10,  20,   0,
       15,  55, 252, 252,  10,   0,   0,   0,   0,   0,
      252, 252, 252,  65,  35,  55,  20, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
      252, 252, 252, 252, 252, 252
    };
  return len + asso_values[(unsigned char)str[len - 1]] + asso_values[(unsigned char)str[0]];
}

static const char * wordlist[] =
  {
    "",
    ">",
    ">>",
    "", "",
    "short",
    "struct",
    ">=",
    ">>=",
    "enum",
    "while",
    "=",
    "==",
    "volatile",
    "else",
    "const",
    "static",
    "<=",
    "<<=",
    "case",
    "union",
    "<",
    "<<",
    "continue",
    "char",
    "break",
    "extern",
    "->",
    "register",
    "long",
    "",
    "return",
    "-=",
    "", "",
    "float",
    "sizeof",
    "typedef",
    "", "", "",
    "~",
    "|=",
    "for",
    "", "",
    "switch",
    "+=",
    "", "", "",
    "-",
    "--",
    "", "", "", "",
    "&=",
    "",
    "void",
    "",
    "signed",
    "default",
    "unsigned",
    "goto",
    "",
    "double",
    "^=",
    "",
    "auto",
    "",
    "|",
    "||",
    "", "", "", "",
    "/=",
    "int",
    "", "",
    "+",
    "++",
    "", "", "", "",
    "*=",
    "", "", "",
    ".",
    "%=",
    "...",
    "", "", "",
    "!=",
    "", "", "",
    "&",
    "&&",
    "", "", "", "",
    "if",
    "", "", "",
    "}",
    "do",
    "", "", "", "", "", "", "", "",
    "^",
    "", "", "", "", "", "", "", "", "",
    "{",
    "", "", "", "", "", "", "", "", "",
    "/",
    "", "", "", "", "", "", "", "", "",
    "]",
    "", "", "", "", "", "", "", "", "",
    "*",
    "", "", "", "", "", "", "", "", "",
    "%",
    "", "", "", "", "", "", "", "", "",
    "!",
    "", "", "", "", "", "", "", "", "",
    "[",
    "", "", "", "", "", "", "", "", "",
    "?",
    "", "", "", "", "", "", "", "", "",
    ";",
    "", "", "", "", "", "", "", "", "",
    ":",
    "", "", "", "", "", "", "", "", "",
    ",",
    "", "", "", "", "", "", "", "", "",
    ")",
    "", "", "", "", "", "", "", "", "",
    "("
  };

const char *
verbum_token_in_language (register const char *str, register size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = verbum_token_hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key];

          if (*str == *s && !strcmp (str + 1, s + 1))
            return s;
        }
    }
  return 0;
}
#line 89 "verbum_token.gperf"

void verbum_token_delete(VerbumContext *ctx, Token *t) {
	if(t->lexeme != NULL) {
		ctx->memory.delete((void *) t->lexeme);
		t->lexeme = NULL;
	}
}
TokenType verbum_token_get_keyword_type(const char *lexeme) {
	if(verbum_token_in_language(lexeme, strlen(lexeme)) != NULL) {
		return verbum_token_hash(lexeme, strlen(lexeme)) + TokenType_Keyword;
	}

	return TokenType_Invalid;
}

TokenType verbum_token_get_lexeme_type(const char *lexeme) {
	if(verbum_token_in_language(lexeme, strlen(lexeme)) != NULL) {
		return verbum_token_hash(lexeme, strlen(lexeme)) + TokenType_Keyword;
	}

	return verbum_token_hash(lexeme, strlen(lexeme));
}
