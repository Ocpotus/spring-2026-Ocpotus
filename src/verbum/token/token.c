#include "../memory/memory.h"

#include "token.h"


void token_delete(Token t) {
	memory_delete((void *)t.lexeme);
}
