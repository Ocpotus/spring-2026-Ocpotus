#include "../../lib/utf8file/utf8file.h"

#include "../memory/memory.h"

#include "internal/internal.h"

#include "lexer.h"


Lexer *lexer_new(const char *path) {
	Lexer *result = memory_new(1 * sizeof(*result));

	if(result != NULL) {
		result->f = utf8file_open(path);
		result->pos.row = 1;
		result->pos.col = 1;

		if(result->f == NULL) {
			memory_delete(result);
		}
	}

	return result;
}

void lexer_delete(Lexer *l) {
	utf8file_close(l->f);
	memory_delete(l);
}

Token lexer_get_token(Lexer *l) {
	return lexer_lex(l);
}

const char *lexer_get_source(Lexer *l) {
	return utf8file_path(l->f);
}
