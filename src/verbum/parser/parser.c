#include "../../lib/try.h/try.h"

#include "../ast/ast.h"
#include "../lexer/lexer.h"
#include "../memory/memory.h"

#include "internal/internal.h"

#include "parser.h"


Parser *parser_new(const char *path) {
	Parser *result = memory_new(1 * sizeof(*result));

	if(result != NULL) {
		result->l = lexer_new(path);
		result->previous = (Token) {
			.type = TokenType_Whitespace,
			.lexeme = NULL,
		};
		result->current = lexer_get_token(result->l);
		result->peek = lexer_get_token(result->l);
	}

	return result;
}

void parser_delete(Parser *p) {
	lexer_delete(p->l);
	memory_delete(p);
}

AST *parser_parse(Parser *p) {
	Grammar g1 = parser_parse_internal(p);
	AST *result = try(memory_copy(&g1, sizeof(*result)), result == NULL, { return NULL; });

	return result;
}
