#include <stdio.h>

#include "lib/c-vector/cvector.h"

#include "verbum/token/token.h"
#include "verbum/analysis/analysis.h"
#include "verbum/parser/parser.h"
#include "verbum/code/code.h"


int main() {
	Parser *p = parser_new("ebnf.ebnf");
	AST *ast = parser_parse(p);

	cvector(Token) ts = analysis_gather_tokens(ast);

	code_generate_token(ts);
	ast_print(ast);
	parser_delete(p);
	ast_delete(ast);

	return 0;
}
