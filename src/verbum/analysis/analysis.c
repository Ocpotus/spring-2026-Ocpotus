#include <stdbool.h>
#include <string.h>

#include "../../lib/c-vector/cvector.h"
#include "../../lib/uthash.h/uthash.h"

#include "../ast/ast.h"
#include "../token/token.h"

#include "analysis.h"


static void analysis_gather_tokens_grammar(Grammar g1, cvector(Token) *ts);
static void analysis_gather_tokens_rule(Rule r1, cvector(Token) *ts);
static void analysis_gather_tokens_expression(Expression e1, cvector(Token) *ts);
static void analysis_gather_tokens_list(List l1, cvector(Token) *ts);
static void analysis_gather_tokens_term(Term t1, cvector(Token) *ts);
static void analysis_gather_tokens_factor(Factor f1, cvector(Token) *ts);

cvector(Token) analysis_gather_tokens(AST *ast) {
	cvector(Token) result = NULL;
	analysis_gather_tokens_grammar(*ast, &result);
	return result;
}

static void analysis_gather_tokens_grammar(Grammar g1, cvector(Token) *ts) {
	for(Rule *it = cvector_begin(g1.rule1); it != cvector_end(g1.rule1); it += 1) {
		analysis_gather_tokens_rule(*it, ts);
	}
}

static void analysis_gather_tokens_rule(Rule r1, cvector(Token) *ts) {
	bool found = false;

	for(Token *it = cvector_begin(*ts); it != cvector_end(*ts); it += 1) {
		if(strcmp(it->lexeme, r1.token1.lexeme) == 0) {
			found = true;
			break;
		}
	}

	if(!found) {
		cvector_push_back(*ts, r1.token1);
	}

	analysis_gather_tokens_expression(*(r1.expression1), ts);
}

static void analysis_gather_tokens_expression(Expression e1, cvector(Token) *ts) {
	analysis_gather_tokens_list(e1.list1, ts);

	for(List *it = cvector_begin(e1.list2); it != cvector_end(e1.list2); it += 1) {
		analysis_gather_tokens_list(*it, ts);
	}
}

static void analysis_gather_tokens_list(List l1, cvector(Token) *ts) {
	analysis_gather_tokens_term(l1.term1, ts);

	for(Term *it = cvector_begin(l1.term2); it != cvector_end(l1.term2); it += 1) {
		analysis_gather_tokens_term(*it, ts);
	}
}

static void analysis_gather_tokens_term(Term t1, cvector(Token) *ts) {
	analysis_gather_tokens_factor(t1.factor1, ts);

	if(t1.factor2 != NULL) {
		analysis_gather_tokens_factor(*(t1.factor2), ts);
	}
}

static void analysis_gather_tokens_factor(Factor f1, cvector(Token) *ts) {
	switch(f1.tag) {
	case FactorType_NonTerminal_Identifier:
	case FactorType_Terminal_Identifier:
	case FactorType_Literal:
		bool found = false;

		for(Token *it = cvector_begin(*ts); it != cvector_end(*ts); it += 1) {
			if(strcmp(it->lexeme, f1.literal.lexeme) == 0) {
				found = true;
				break;
			}
		}

		if(!found) {
			cvector_push_back(*ts, f1.literal);
		}
		break;
	case FactorType_Optional:
	case FactorType_Repetition:
	case FactorType_Grouping:
		analysis_gather_tokens_expression(*(f1.repetition), ts);
		break;
	default:
		break;
	}
}
