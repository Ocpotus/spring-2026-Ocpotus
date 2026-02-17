#include <stdbool.h>
#include <stdio.h>

#include "lib/hashmap.c/hashmap.h"

#include "verbum/token/token.h"
#include "verbum/analysis/analysis.h"
#include "verbum/parser/parser.h"


int main() {
	Parser *p = parser_new("ebnf.ebnf");
	AST *ast = parser_parse(p);
	EBNFAnalyzer *ea = analysis_new_ebnf_analyzer();

	analysis_ebnf_analyze(ast, ea);

	//code_generate_token(ts);
	analyze_delete_ebnf_analyzer(ea);
	ast_print(ast);
	parser_delete(p);
	ast_delete(ast);

	return 0;
}
