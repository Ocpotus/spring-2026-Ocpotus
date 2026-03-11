#ifndef VERBUM_CODE_H
#define VERBUM_CODE_H

#include <stdio.h>
#include <stdlib.h>

#include "../../lib/hashmap.c/hashmap.h"

#include "../ast/ast.h"


typedef struct CodeGenerator {
	AST *ast;
	Rule start;
	struct hashmap *tokens;
	struct hashmap *firstFollowSets;
	size_t indent;
	FILE *fp;
} CodeGenerator;

CodeGenerator code_generator_new(AST *ast, Rule start, struct hashmap *tokens, struct hashmap *firstFollowSets);
void code_generator_generate(CodeGenerator cg);


#endif
