#ifndef VERBUM_ANALYZER_H
#define VERBUM_ANALYZER_H

#include <stdbool.h>

#include "../../lib/hashmap.c/hashmap.h"
#include "../../lib/uthash.h/uthash.h"
#include "../../lib/c-vector/cvector.h"

#include "../token/token.h"

#include "../ast/ast.h"


typedef struct RuleSet {
	Rule *rule;
	cvector(Token) tokens;
	bool nullable;
} RuleSet;

typedef struct Analyzer {
	struct hashmap *tokens;
	struct hashmap *firsts;
	struct hashmap *follows;
	AST *ast;
} Analyzer;

Analyzer *analyzer_new(AST *ast);
void analyzer_delete(Analyzer *ea);
void analyze_analyze(Analyzer *ea);


#endif
