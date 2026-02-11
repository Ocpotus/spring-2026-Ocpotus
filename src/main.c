#include <stdio.h>

#include "verbum/parser/parser.h"


int main() {
	Parser *p = parser_new("ebnf.ebnf");
	AST *g = parser_parse(p);

	ast_print(g);

/*
	do {
		t = lexer_get_token(l);

		if(t.type != TokenType_Whitespace) {
			printf("%d %s\n", t.type, t.lexeme);
		}

		if(t.type == TokenType_Literal ||
		   t.type == TokenType_NonTerminal_Identifier ||
		   t.type == TokenType_Terminal_Identifier) {
			token_delete(t);
		}
	} while(t.type != TokenType_EOF);
*/
	parser_delete(p);
	ast_delete(g);

	return 0;
}
