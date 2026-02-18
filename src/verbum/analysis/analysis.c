#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "../../lib/try.h/try.h"
#include "../../lib/c-vector/cvector.h"
#include "../../lib/hashmap.c/hashmap.h"

#include "../memory/memory.h"
#include "../ast/ast.h"
#include "../token/token.h"

#include "analysis.h"


/* Token analysis */
static bool analyzer_analyze_tokens(Analyzer *a);
static void analyzer_analyze_tokens_grammar(Analyzer *a, Grammar g1);
static void analyzer_analyze_tokens_rule(Analyzer *a, Rule r1);
static void analyzer_analyze_tokens_expression(Analyzer *a, Expression e1);
static void analyzer_analyze_tokens_list(Analyzer *a, List l1);
static void analyzer_analyze_tokens_term(Analyzer *a, Term t1);
static void analyzer_analyze_tokens_factor(Analyzer *a, Factor f1);
/* First analysis */
static void analyzer_analyze_firsts(Analyzer *a, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_grammar(Analyzer *a, Grammar g, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_rule(Analyzer *a, Rule r, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_expression(Analyzer *a, Expression e, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_list(Analyzer *a, List l, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_term(Analyzer *a, Term t, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_factor(Analyzer *a, Factor f, FirstFollowSet *ffs);
/* Follow analysis */
static bool analyzer_analyze_follows(Analyzer *a);

/* FirstFollow set utils */
static FirstFollowSet first_follow_set_new();
static void first_follow_set_delete(FirstFollowSet *ffs);

/* Hash functions */
static uint64_t token_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int token_compare(const void *a, const void *b, void *udata);
static uint64_t rule_set_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int rule_set_compare(const void *a, const void *b, void *udata);

/* Utils */
static void set_union(struct hashmap *d, struct hashmap *s);

Analyzer *analyzer_new(AST *ast) {
	Analyzer *result = try(memory_new(1 * sizeof(*result)), result == NULL, { return NULL; });

	result->tokens = hashmap_new_with_allocator(
			 memory_new, memory_resize, memory_delete,
			 sizeof(Token), 0, 0, 0,
			 token_hash, token_compare, NULL, NULL);
	result->firsts = hashmap_new_with_allocator(
			 memory_new, memory_resize, memory_delete,
			 sizeof(FirstFollowSet), 0, 0, 0,
			 rule_set_hash, rule_set_compare, NULL, NULL);
	result->follows = hashmap_new_with_allocator(
			  memory_new, memory_resize, memory_delete,
			  sizeof(FirstFollowSet), 0, 0, 0,
			  rule_set_hash, rule_set_compare, NULL, NULL);
	result->ast = ast;

	return result;
}

void analyzer_delete(Analyzer *a) {
	hashmap_free(a->tokens);

	{
		void *item;
		size_t i = 0;

		while(hashmap_iter(a->firsts, &i, &item)) {
			FirstFollowSet *ffs = item;

			first_follow_set_delete(ffs);
		}

		hashmap_free(a->firsts);
	}

	hashmap_free(a->follows);
	memory_delete(a);
}

void analyzer_analyze(Analyzer *a) {
	analyzer_analyze_tokens(a);
	analyzer_analyze_firsts(a, NULL);
}

static bool analyzer_analyze_tokens(Analyzer *a) {
	analyzer_analyze_tokens_grammar(a, *(a->ast));

	return true;
}

static void analyzer_analyze_tokens_grammar(Analyzer *a, Grammar g1) {
	for(Rule *it = cvector_begin(g1.rule1); it != cvector_end(g1.rule1); it += 1) {
		analyzer_analyze_tokens_rule(a, *it);
	}
}

static void analyzer_analyze_tokens_rule(Analyzer *a, Rule r1) {
	if(hashmap_get(a->tokens, &r1.token1) == NULL) {
		hashmap_set(a->tokens, &r1.token1);
	}

	analyzer_analyze_tokens_expression(a, *(r1.expression1));
}

static void analyzer_analyze_tokens_expression(Analyzer *a, Expression e1) {
	analyzer_analyze_tokens_list(a, e1.list1);

	for(List *it = cvector_begin(e1.list2); it != cvector_end(e1.list2); it += 1) {
		analyzer_analyze_tokens_list(a, *it);
	}
}

static void analyzer_analyze_tokens_list(Analyzer *a, List l1) {
	analyzer_analyze_tokens_term(a, l1.term1);

	for(Term *it = cvector_begin(l1.term2); it != cvector_end(l1.term2); it += 1) {
		analyzer_analyze_tokens_term(a, *it);
	}
}

static void analyzer_analyze_tokens_term(Analyzer *a, Term t1) {
	analyzer_analyze_tokens_factor(a, t1.factor1);

	if(t1.factor2 != NULL) {
		analyzer_analyze_tokens_factor(a, *(t1.factor2));
	}
}

static void analyzer_analyze_tokens_factor(Analyzer *a, Factor f1) {
	switch(f1.tag) {
	case FactorType_NonTerminal_Identifier:
	case FactorType_Terminal_Identifier:
	case FactorType_Literal:
		if(hashmap_get(a->tokens, &f1.literal) == NULL) {
			hashmap_set(a->tokens, &f1.literal);
		}
		break;
	case FactorType_Optional:
	case FactorType_Repetition:
	case FactorType_Grouping:
		analyzer_analyze_tokens_expression(a, *(f1.repetition));
		break;
	default:
		break;
	}
}

static void analyzer_analyze_firsts(Analyzer *a, FirstFollowSet *ffs) {
	analyzer_analyze_firsts_grammar(a, *(a->ast), NULL);
}

static void analyzer_analyze_firsts_grammar(Analyzer *a, Grammar g, FirstFollowSet *ffs) {
	bool changed = true;

	while(changed) {
		changed = false;

		for(Rule *it = cvector_begin(g.rule1); it != cvector_end(g.rule1); it += 1) {
			const FirstFollowSet *ffsp = hashmap_get(a->firsts, &(FirstFollowSet) { .t = it->token1 });
			FirstFollowSet ffs;

			if(ffsp == NULL) {
				ffs = first_follow_set_new();
				ffs.t = it->token1;
			} else {
				ffs = *ffsp;
			}

			size_t oldcount = hashmap_count(ffs.tokens);

			analyzer_analyze_firsts_expression(a, *(it->expression1), &ffs);

			if(hashmap_count(ffs.tokens) > oldcount) {
				changed = true;
				hashmap_set(a->firsts, &ffs);
			}
		}
	}
}

static void analyzer_analyze_firsts_expression(Analyzer *a, Expression e, FirstFollowSet *ffs) {
	analyzer_analyze_firsts_list(a, e.list1, ffs);

	for(List *it = cvector_begin(e.list2); it != cvector_end(e.list2); it += 1) {
		analyzer_analyze_firsts_list(a, *it, ffs);
	}
}

static void analyzer_analyze_firsts_list(Analyzer *a, List l, FirstFollowSet *ffs) {
	FirstFollowSet temp = first_follow_set_new();

	ffs->nullable = temp.nullable;
	analyzer_analyze_firsts_term(a, l.term1, &temp);
	set_union(ffs->tokens, temp.tokens);
	first_follow_set_delete(&temp);

	for(Term *it = cvector_begin(l.term2); ffs->nullable && it != cvector_end(l.term2); it += 1) {
		temp = first_follow_set_new();
		analyzer_analyze_firsts_term(a, *it, &temp);
		set_union(ffs->tokens, temp.tokens);
		
		if(temp.nullable == false) {
			ffs->nullable = false;
			first_follow_set_delete(&temp);

			break;
		}

		first_follow_set_delete(&temp);
	}
}

static void analyzer_analyze_firsts_term(Analyzer *a, Term t, FirstFollowSet *ffs) {
	FirstFollowSet f1 = first_follow_set_new();

	analyzer_analyze_firsts_factor(a, t.factor1, &f1);

	if(t.factor2 != NULL) {
		FirstFollowSet f2 = first_follow_set_new();
		void *item;
		size_t i = 0;

		analyzer_analyze_firsts_factor(a, *t.factor2, &f2);

		while(hashmap_iter(f2.tokens, &i, &item)) {
			hashmap_delete(f1.tokens, item);
		}

		if(f2.nullable) {
			f1.nullable = false;
		}

		first_follow_set_delete(&f2);
	}

	set_union(ffs->tokens, f1.tokens);
	ffs->nullable = f1.nullable;
	first_follow_set_delete(&f1);
}

static void analyzer_analyze_firsts_factor(Analyzer *a, Factor f, FirstFollowSet *ffs) {
	switch(f.tag) {
	case FactorType_Terminal_Identifier:
		hashmap_set(ffs->tokens, &f.terminal_identifier);
		ffs->nullable = false;
		break;
	case FactorType_Literal:
		hashmap_set(ffs->tokens, &f.literal);
		ffs->nullable = false;
		break;
	case FactorType_NonTerminal_Identifier: {
			const FirstFollowSet *nonterm_set = hashmap_get(a->firsts,
									&(FirstFollowSet) { .t = f.nonterminal_identifier });

			if(nonterm_set != NULL) {
				set_union(ffs->tokens, nonterm_set->tokens);
				ffs->nullable = nonterm_set->nullable;
			}
		}
		break;
	case FactorType_Optional:
		analyzer_analyze_firsts_expression(a, *f.optional, ffs);
		ffs->nullable = true;
		break;
	case FactorType_Repetition:
		analyzer_analyze_firsts_expression(a, *f.repetition, ffs);
		ffs->nullable = true;
		break;
	case FactorType_Grouping:
		analyzer_analyze_firsts_expression(a, *f.grouping, ffs);
		break;
	default:
		break;
	}
}

static FirstFollowSet first_follow_set_new() {
	return (FirstFollowSet) {
		.nullable = false,
		.t = (Token) { 0 },
		.tokens = hashmap_new_with_allocator(
			  memory_new, memory_resize, memory_delete,
			  sizeof(Token), 0, 0, 0,
			  token_hash, token_compare, NULL, NULL),
	};
}

static void first_follow_set_delete(FirstFollowSet *ffs) {
	hashmap_free(ffs->tokens);
	*ffs = (FirstFollowSet) {
		.nullable = false,
		.t = (Token) { 0 },
		.tokens = NULL,
	};
}

/* Hashmap functions */
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
	const FirstFollowSet *set = item;

	return hashmap_sip(set->t.lexeme, strlen(set->t.lexeme), seed0, seed1);
}

static int rule_set_compare(const void *a, const void *b, void *udata) {
	const FirstFollowSet *ua = a;
	const FirstFollowSet *ub = b;

	return strcmp(ua->t.lexeme, ub->t.lexeme);
}

static void set_union(struct hashmap *d, struct hashmap *s) {
	size_t i = 0;
	void *item;

	while(hashmap_iter(s, &i, &item)) {
		hashmap_set(d, item);
	}
}
