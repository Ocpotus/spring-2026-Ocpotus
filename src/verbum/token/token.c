#include "../memory/memory.h"

#include "token.h"


void token_delete(Token t) {
	if(t.type == TokenType_Literal ||
	   t.type == TokenType_NonTerminal_Identifier ||
	   t.type == TokenType_Terminal_Identifier) {
		memory_delete((void *)t.lexeme);
	}
}
