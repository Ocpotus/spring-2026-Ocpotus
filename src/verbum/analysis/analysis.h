#ifndef VERBUM_ANALYSIS_H
#define VERBUM_ANALYSIS_H

#include "../../lib/uthash.h/uthash.h"
#include "../../lib/c-vector/cvector.h"

#include "../token/token.h"

#include "../ast/ast.h"


// At some point switch this to a proper hash map
cvector(Token) analysis_gather_tokens(AST *ast);


#endif
