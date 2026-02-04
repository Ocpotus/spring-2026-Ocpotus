#include "../../lib/c-vector/cvector.h"
#include "../ast/ast.h"
#include "../lexer/lexer.h"
#include "../memory/memory.h"
#include "../unit/unit.h"

#include "internal/internal.h"

#include "parser.h"


/* Somewhat useless indirection */
static AST parser_parse_internal(Parser *p);
//static BNF parser_parse_bnf(Parser *p);

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

Unit parser_parse(Parser *p) {
	Unit result = NULL;

	while(!parser_at_end(p)) {
		cvector_push_back(result, parser_parse_internal(p));
	}

	return result;
}

static AST parser_parse_internal(Parser *p) {
	return (AST) {
		//.bnf = parser_parse_bnf(p),
		.tag = ASTType_BNF,
	};
}
/*
static BNF parser_parse_bnf(Parser *p) {


} */
