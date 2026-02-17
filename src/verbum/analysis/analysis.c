#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "../../lib/try.h/try.h"
#include "../../lib/c-vector/cvector.h"
#include "../../lib/uthash.h/uthash.h"
#include "../../lib/hashmap.c/hashmap.h"

#include "../memory/memory.h"
#include "../ast/ast.h"
#include "../token/token.h"

#include "analysis.h"



static uint64_t token_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int token_compare(const void *a, const void *b, void *udata);
static uint64_t rule_set_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int rule_set_compare(const void *a, const void *b, void *udata);



Analyzer *analyzer_new(AST *ast) {
	Analyzer *result = try(memory_new(1 * sizeof(*result)), result == NULL, { return NULL; });

	result->tokens = hashmap_new_with_allocator(
			 memory_new, memory_resize, memory_delete,
			 sizeof(Token), 0, 0, 0,
			 token_hash, token_compare, NULL, NULL);
	result->firsts = hashmap_new_with_allocator(
			 memory_new, memory_resize, memory_delete,
			 sizeof(RuleSet), 0, 0, 0,
			 rule_set_hash, rule_set_compare, NULL, NULL);
	result->follows = hashmap_new_with_allocator(
			  memory_new, memory_resize, memory_delete,
			  sizeof(RuleSet), 0, 0, 0,
			  rule_set_hash, rule_set_compare, NULL, NULL);
	result->ast = ast;

	return result;
}

void analyzer_delete(Analyzer *ea) {
	hashmap_free(ea->tokens);
	hashmap_free(ea->firsts);
	hashmap_free(ea->follows);
	memory_delete(ea);
}

/*
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
*/
/*
static bool analysis_gather_first_grammar(Grammar g1, FirstFollowSet **ffs);
static bool analysis_gather_first_rule(Rule rule, FirstFollowSet **ffs);
static bool analysis_gather_first_expression(Expression e1, FirstFollowSet **ffs);
static bool analysis_gather_first_list(List l1, FirstFollowSet **ffs);
static bool analysis_gather_first_term(Term t1, FirstFollowSet **ffs);
static bool analysis_gather_first_factor(Factor f1, FirstFollowSet **ffs);

FirstFollowSet *analysis_gather_first(AST *ast) {
	FirstFollowSet *result = NULL;
	analysis_gather_first_grammar(*ast, &result);
	return result;
}

// Return true iff nullable, else false
static bool analysis_gather_first_grammar(Grammar g1, FirstFollowSet **ffs) {
	bool changed = true;

	while(changed) {
		changed = false;

		for(Rule *it = cvector_begin(g1.rule1); it != cvector_end(g1.rule1); it += 1) {
			if(it->token1.type != TokenType_Terminal_Identifier) {
				// Gather first and follow for 
				changed = analysis_gather_first_rule(*it, ffs);
			}
		}
	}

	return true;
}

static bool analysis_gather_first_rule(Rule rule, FirstFollowSet **ffs) {
	FirstFollowSet *rule_set = try(memory_new(1 * sizeof(*rule_set)), rule_set == NULL, { return false; });
	cvector(Token) first = NULL;
	cvector(Token) follow = NULL;

	rule_set->first = first;
	rule_set->token_name = rule.token1.lexeme;
	analysis_gather_first_expression(*(rule.expression1), ffs);

	HASH_ADD_KEYPTR(hh, *ffs, rule.token1.lexeme, strlen(rule.token1.lexeme), rule_set);

	return true;
}

static bool analysis_gather_first_expression(Expression e1, FirstFollowSet **ffs) {
	bool nullable = analysis_gather_first_list(e1.list1, ffs);
}

static bool analysis_gather_first_list(List l1, FirstFollowSet **ffs) {
	bool nullable = analysis_gather_first_term(l1.term1, ffs);

	for(Term *it = cvector_begin(l1.term2); it != cvector_end(l1.term2); it += 1) {
		if(!analysis_gather_first_term(*it, ffs)) {
			nullable = false;
		}
	}

	return nullable;
}

static bool analysis_gather_first_term(Term t1, FirstFollowSet **ffs);
static bool analysis_gather_first_factor(Factor f1, FirstFollowSet **ffs) {
	switch(f1.tag) {
	case FactorType_Terminal_Identifier:
		// nullable, false
		break;
	case FactorType_NonTerminal_Identifier:
		break;
	case FactorType_Literal:
		// nullable, false
		break;
	case FactorType_Optional:
		// nullable, true
		break;
	case FactorType_Repetition:
		// nullable, true
		break;
	case FactorType_Grouping:
		break;
	default:
		break;
	}
	return true;
}
*/
static void analysis_ebnf_analyze_tokens_grammar(Grammar g1, EBNFAnalyzer *ea);
static void analysis_ebnf_analyze_tokens_rule(Rule r1, EBNFAnalyzer *ea);
static void analysis_ebnf_analyze_tokens_expression(Expression e1, EBNFAnalyzer *ea);
static void analysis_ebnf_analyze_tokens_list(List l1, EBNFAnalyzer *ea);
static void analysis_ebnf_analyze_tokens_term(Term t1, EBNFAnalyzer *ea);
static void analysis_ebnf_analyze_tokens_factor(Factor f1, EBNFAnalyzer *ea);

void analysis_ebnf_analyze(AST *ast, EBNFAnalyzer *ea) {
	analysis_ebnf_analyze_tokens_grammar(*ast, ea);
}

static void analysis_ebnf_analyze_tokens_grammar(Grammar g1, EBNFAnalyzer *ea) {
	for(Rule *it = cvector_begin(g1.rule1); it != cvector_end(g1.rule1); it += 1) {
		analysis_ebnf_analyze_tokens_rule(*it, ea);
	}
}

static void analysis_ebnf_analyze_tokens_rule(Rule r1, EBNFAnalyzer *ea) {
	if(hashmap_get(ea->tokens, &r1.token1) == NULL) {
		hashmap_set(ea->tokens, &r1.token1);
	}

	analysis_ebnf_analyze_tokens_expression(*(r1.expression1), ea);
}

static void analysis_ebnf_analyze_tokens_expression(Expression e1, EBNFAnalyzer *ea) {
	analysis_ebnf_analyze_tokens_list(e1.list1, ea);

	for(List *it = cvector_begin(e1.list2); it != cvector_end(e1.list2); it += 1) {
		analysis_ebnf_analyze_tokens_list(*it, ea);
	}
}

static void analysis_ebnf_analyze_tokens_list(List l1, EBNFAnalyzer *ea) {
	analysis_ebnf_analyze_tokens_term(l1.term1, ea);

	for(Term *it = cvector_begin(l1.term2); it != cvector_end(l1.term2); it += 1) {
		analysis_ebnf_analyze_tokens_term(*it, ea);
	}
}

static void analysis_ebnf_analyze_tokens_term(Term t1, EBNFAnalyzer *ea) {
	analysis_ebnf_analyze_tokens_factor(t1.factor1, ea);

	if(t1.factor2 != NULL) {
		analysis_ebnf_analyze_tokens_factor(*(t1.factor2), ea);
	}
}

static void analysis_ebnf_analyze_tokens_factor(Factor f1, EBNFAnalyzer *ea) {
	switch(f1.tag) {
	case FactorType_NonTerminal_Identifier:
	case FactorType_Terminal_Identifier:
	case FactorType_Literal:
		if(hashmap_get(ea->tokens, &f1.literal) == NULL) {
			hashmap_set(ea->tokens, &f1.literal);
		}
		break;
	case FactorType_Optional:
	case FactorType_Repetition:
	case FactorType_Grouping:
		analysis_ebnf_analyze_tokens_expression(*(f1.repetition), ea);
		break;
	default:
		break;
	}
}

static uint64_t token_hash(const void *item, uint64_t seed0, uint64_t seed1) {
	const Token *token = item;

	return hashmap_sip(token->lexeme, strlen(token->lexeme), seed0, seed1);
}

static int token_compare(const void *a, const void *b, void *udata) {
	const Token *ua = a;
	const Token *ub = b;

	if(ua->type == ub->type) {
		return strcmp(ua->lexeme, ub->lexeme);
	}

	return 1;
}

static uint64_t rule_set_hash(const void *item, uint64_t seed0, uint64_t seed1) {
	const RuleSet *ruleset = item;

	return hashmap_sip(ruleset->rule->token1.lexeme, strlen(ruleset->rule->token1.lexeme), seed0, seed1);
}

static int rule_set_compare(const void *a, const void *b, void *udata) {
	const RuleSet *ua = a;
	const RuleSet *ub = b;

	return strcmp(ua->rule->token1.lexeme, ub->rule->token1.lexeme);
}
