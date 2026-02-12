#ifndef VERBUM_CODE_H
#define VERBUM_CODE_H

#include "../../lib/c-vector/cvector.h"

#include "../ast/ast.h"
#include "../token/token.h"


void code_generate_token(cvector(Token) ts);
void code_generate(AST *ast);


#endif
