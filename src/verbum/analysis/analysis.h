#ifndef VERBUM_ANALYZER_H
#define VERBUM_ANALYZER_H

#include <stdbool.h>

#include "../../lib/hashmap.c/hashmap.h"
#include "../../lib/c-vector/cvector.h"

#include "../token/token.h"
#include "../ast/ast.h"


/* FirstFollowSet is a key value pair
 *
 * MEMBERS:
 * 	t: key for a terminal and nonterminals
 * 	tokens: a set, implemented as a hashmap, that contains the associated first or follow
 * 		of a token
 * 	nullable: can the string derived be null?
 */
typedef struct FirstFollowSet {
	struct hashmap *firsts;
	struct hashmap *follows;
	Token t;
	bool nullable;
} FirstFollowSet;

/* Analyzer
 *
 * MEMBERS:
 * 	tokens: hashmap of Token
 * 	sets: hashmap of FirstFollowSet
 * 	start: the start symbol
 * 	cycles: rules that should be used as a pointer in code generation (hashmap of tokens)
 * 	ast: ast to analyze
 */
typedef struct Analyzer {
	struct hashmap *tokens;
	struct hashmap *topterminals;
	struct hashmap *sets;
	AST *ast;
	Rule start;
} Analyzer;

Analyzer *analyzer_new(AST *ast);
void analyzer_delete(Analyzer *a);
void analyzer_analyze(Analyzer *a);


#endif
