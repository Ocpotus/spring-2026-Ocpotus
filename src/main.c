#include <stdio.h>

#include "verbum/lexer/lexer.h"
#include "verbum/token/token.h"


int main() {
	Lexer *l = lexer_new("ebnf.ebnf");
	Token t = { 0 };

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

	lexer_delete(l);
	printf("Hello world!\n");

	return 0;
}
