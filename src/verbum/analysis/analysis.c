#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "../../lib/try.h/try.h"
#include "../../lib/c-vector/cvector.h"
#include "../../lib/hashmap.c/hashmap.h"

#include "../token/token.h"
#include "../memory/memory.h"
#include "../ast/ast.h"
#include "../token/token.h"

#include "analysis.h"


/* Analyzer */
static FirstFollowSet *analyzer_get_first_follow_set(Analyzer *a, Token token);
/* Token analysis */
static void analyzer_analyze_tokens(Analyzer *a);
static void analyzer_analyze_tokens_grammar(Analyzer *a, Grammar g1);
static void analyzer_analyze_tokens_rule(Analyzer *a, Rule r1);
static void analyzer_analyze_tokens_expression(Analyzer *a, Expression e1);
static void analyzer_analyze_tokens_list(Analyzer *a, List l1);
static void analyzer_analyze_tokens_term(Analyzer *a, Term t1);
static void analyzer_analyze_tokens_factor(Analyzer *a, Factor f1);
/* First analysis */
static void analyzer_analyze_firsts(Analyzer *a);
static void analyzer_analyze_firsts_grammar(Analyzer *a, Grammar g, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_rule(Analyzer *a, Rule r, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_expression(Analyzer *a, Expression e, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_list(Analyzer *a, List l, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_term(Analyzer *a, Term t, FirstFollowSet *ffs);
static void analyzer_analyze_firsts_factor(Analyzer *a, Factor f, FirstFollowSet *ffs);
/* Follow analysis */
static void analyzer_analyze_follows(Analyzer *a);
static void analyzer_analyze_follows_grammar(Analyzer *a, Grammar g, FirstFollowSet *ffs);
static void analyzer_analyze_follows_rule(Analyzer *a, Rule r, FirstFollowSet *ffs);
static void analyzer_analyze_follows_expression(Analyzer *a, Expression e, FirstFollowSet *ffs);
static void analyzer_analyze_follows_list(Analyzer *a, List l, FirstFollowSet *ffs);
static void analyzer_analyze_follows_term(Analyzer *a, Term t, FirstFollowSet *ffs);
static void analyzer_analyze_follows_factor(Analyzer *a, Factor f, FirstFollowSet *ffs);
/* Start symbol analysis */
static void analyzer_analyze_start_symbol(Analyzer *a);
static void analyzer_analyze_start_symbol_grammar(Analyzer *a, Grammar g, cvector(Rule) rules);
static void analyzer_analyze_start_symbol_rule(Analyzer *a, Rule r, cvector(Rule) rules);
static void analyzer_analyze_start_symbol_expression(Analyzer *a, Expression e, cvector(Rule) rules);
static void analyzer_analyze_start_symbol_list(Analyzer *a, List l, cvector(Rule) rules);
static void analyzer_analyze_start_symbol_term(Analyzer *a, Term t, cvector(Rule) rules);
static void analyzer_analyze_start_symbol_factor(Analyzer *a, Factor f, cvector(Rule) rules);

typedef struct HoistContext {
	cvector(Rule) newRules;
	Token ruleName;
	int nOptional;
	int nRepetition;
	int nGroup;
} HoistContext;
/* Scan anonymous expressions */
static bool analyzer_analyze_anonymous_expression(Analyzer *a, HoistContext *hc);
static bool analyzer_analyze_anonymous_expression_grammar(Analyzer *a, Grammar *g, HoistContext *hc);
static bool analyzer_analyze_anonymous_expression_rule(Analyzer *a, Rule *r, HoistContext *hc);
static bool analyzer_analyze_anonymous_expression_expression(Analyzer *a, Expression *e, HoistContext *hc);
static bool analyzer_analyze_anonymous_expression_list(Analyzer *a, List *l, HoistContext *hc);
static bool analyzer_analyze_anonymous_expression_term(Analyzer *a, Term *t, HoistContext *hc);
static bool analyzer_analyze_anonymous_expression_factor(Analyzer *a, Factor *f, HoistContext *hc);

/* FirstFollow set utils */
static FirstFollowSet first_follow_set_new();
static void first_follow_set_delete(FirstFollowSet *ffs);

/* Hash functions */
static uint64_t token_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int token_compare(const void *a, const void *b, void *udata);
static uint64_t first_follow_set_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int first_follow_set_compare(const void *a, const void *b, void *udata);

/* Utils */
static void set_union(struct hashmap *d, struct hashmap *s);

Analyzer *analyzer_new(AST *ast) {
	Analyzer *result = try(memory_new(1 * sizeof(*result)), result == NULL, { return NULL; });

	result->tokens = hashmap_new_with_allocator(
			 memory_new, memory_resize, memory_delete,
			 sizeof(Token), 0, 0, 0,
			 token_hash, token_compare, NULL, NULL);
	result->sets = hashmap_new_with_allocator(
		       memory_new, memory_resize, memory_delete,
		       sizeof(FirstFollowSet), 0, 0, 0,
		       first_follow_set_hash, first_follow_set_compare, NULL, NULL);
	result->start = (Rule) { 0 };
	result->ast = ast;

	return result;
}

void analyzer_delete(Analyzer *a) {
	hashmap_free(a->tokens);

	{
		void *item;
		size_t i = 0;

		while(hashmap_iter(a->sets, &i, &item)) {
			FirstFollowSet *ffs = item;

			first_follow_set_delete(ffs);
		}

		hashmap_free(a->sets);
	}

	memory_delete(a);
}

/* There are multiple pass throughs of analysis.
 * Essentially each analyze_X takes every possible path
 * This approach may be computationally redundant (multiple passthroughs)
 * and can add more time.
 *
 * TODO: perhaps there would be a way to translate the grammar into a graph
 * 	 which may or may not reduce the computational load on each passthrough
 * 	 or eliminate passthroughs
 */
void analyzer_analyze(Analyzer *a) {
	analyzer_analyze_tokens(a);
	analyzer_analyze_start_symbol(a);
	analyzer_analyze_anonymous_expression(a, NULL);
	analyzer_analyze_firsts(a);
	analyzer_analyze_follows(a);
}

static void analyzer_analyze_tokens(Analyzer *a) {
	analyzer_analyze_tokens_grammar(a, *(a->ast));
}

static FirstFollowSet *analyzer_get_first_follow_set(Analyzer *a, Token token) {
	return (FirstFollowSet *)hashmap_get(a->sets, &(FirstFollowSet) { .t = token });
}

static void analyzer_analyze_tokens_grammar(Analyzer *a, Grammar g1) {
	for(Rule *it = cvector_begin(g1.rule1); it != cvector_end(g1.rule1); it += 1) {
		// Skip terminal declarations, bc they will be handled by lexer.
		if(it->token1.type != TokenType_Terminal_Identifier) {
			analyzer_analyze_tokens_rule(a, *it);
		}
	}
}

static void analyzer_analyze_tokens_rule(Analyzer *a, Rule r1) {
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

	if(optional_is_valid(t1.factor2)) {
		analyzer_analyze_tokens_factor(a, *(t1.factor2));
	}
}

static void analyzer_analyze_tokens_factor(Analyzer *a, Factor f1) {
	switch(f1.tag) {
	case FactorType_NonTerminal_Identifier:
	case FactorType_Terminal_Identifier:
		break;
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

static void analyzer_analyze_firsts(Analyzer *a) {
	analyzer_analyze_firsts_grammar(a, *(a->ast), NULL);
}

static void analyzer_analyze_firsts_grammar(Analyzer *a, Grammar g, FirstFollowSet *ffs) {
	bool changed = true;

	while(changed) {
		changed = false;

		for(Rule *it = cvector_begin(g.rule1); it != cvector_end(g.rule1); it += 1) {
			const FirstFollowSet *ffsp = analyzer_get_first_follow_set(a, it->token1);
			FirstFollowSet ffs;
			size_t oldcount;

			if(ffsp == NULL) {
				ffs = first_follow_set_new();

				ffs.t = it->token1;
				oldcount = hashmap_count(ffs.firsts);
				analyzer_analyze_firsts_expression(a, *(it->expression1), &ffs);

				if(hashmap_count(ffs.firsts) > oldcount) {
					changed = true;
					hashmap_set(a->sets, &ffs);
				} else {
					first_follow_set_delete(&ffs);
				}

			} else {
				ffs = *ffsp;
				oldcount = hashmap_count(ffs.firsts);
				analyzer_analyze_firsts_expression(a, *(it->expression1), &ffs);

				if(hashmap_count(ffs.firsts) > oldcount) {
					changed = true;
					hashmap_set(a->sets, &ffs);
				}
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

	analyzer_analyze_firsts_term(a, l.term1, &temp);
	ffs->nullable = temp.nullable;
	set_union(ffs->firsts, temp.firsts);
	first_follow_set_delete(&temp);

	for(Term *it = cvector_begin(l.term2); ffs->nullable && it != cvector_end(l.term2); it += 1) {
		temp = first_follow_set_new();
		analyzer_analyze_firsts_term(a, *it, &temp);
		set_union(ffs->firsts, temp.firsts);
		
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

	if(optional_is_valid(t.factor2)) {
		FirstFollowSet f2 = first_follow_set_new();
		void *item;
		size_t i = 0;

		analyzer_analyze_firsts_factor(a, *t.factor2, &f2);

		while(hashmap_iter(f2.firsts, &i, &item)) {
			hashmap_delete(f1.firsts, item);
		}

		if(f2.nullable) {
			f1.nullable = false;
		}

		first_follow_set_delete(&f2);
	}

	set_union(ffs->firsts, f1.firsts);
	ffs->nullable = f1.nullable;
	first_follow_set_delete(&f1);
}

static void analyzer_analyze_firsts_factor(Analyzer *a, Factor f, FirstFollowSet *ffs) {
	switch(f.tag) {
	case FactorType_Terminal_Identifier:
		hashmap_set(ffs->firsts, &f.terminal_identifier);
		ffs->nullable = false;
		break;
	case FactorType_Literal:
		hashmap_set(ffs->firsts, &f.literal);
		ffs->nullable = false;
		break;
	case FactorType_NonTerminal_Identifier: {
			FirstFollowSet *nonterm_set = analyzer_get_first_follow_set(a, f.nonterminal_identifier);

			if(nonterm_set != NULL) {
				set_union(ffs->firsts, nonterm_set->firsts);
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

static void analyzer_analyze_follows(Analyzer *a) {
	analyzer_analyze_follows_grammar(a, *(a->ast), NULL);
}

static void analyzer_analyze_follows_grammar(Analyzer *a, Grammar g, FirstFollowSet *ffs) {
	bool changed = true;

	while(changed) {
		changed = false;

		for(Rule *it = cvector_begin(g.rule1); it != cvector_end(g.rule1); it += 1) {
			const FirstFollowSet *ffsp = analyzer_get_first_follow_set(a, it->token1);
			FirstFollowSet ffs;
			size_t oldcount;

			if(ffsp == NULL) {
				ffs = first_follow_set_new();
				ffs.t = it->token1;
				oldcount = hashmap_count(ffs.follows);
				analyzer_analyze_follows_expression(a, *(it->expression1), &ffs);

				if(hashmap_count(ffs.follows) > oldcount) {
					changed = true;
					hashmap_set(a->sets, &ffs);
				} else {
					first_follow_set_delete(&ffs);
				}
			} else {
				ffs = *ffsp;
				oldcount = hashmap_count(ffs.follows);
				analyzer_analyze_follows_expression(a, *(it->expression1), &ffs);

				if(hashmap_count(ffs.follows) > oldcount) {
					changed = true;
				}
			}
		}
	}

}

static void analyzer_analyze_follows_rule(Analyzer *a, Rule r, FirstFollowSet *ffs);

static void analyzer_analyze_follows_expression(Analyzer *a, Expression e, FirstFollowSet *ffs) {
	analyzer_analyze_follows_list(a, e.list1, ffs);

	for(List *it = cvector_begin(e.list2); it != cvector_end(e.list2); it += 1) {
		analyzer_analyze_follows_list(a, *it, ffs);
	}
}

static void analyzer_analyze_follows_list(Analyzer *a, List l, FirstFollowSet *ffs) {
	if(cvector_empty(l.term2)) {
		analyzer_analyze_follows_term(a, l.term1, ffs);
		return;
	}

	// This is an ease of use, simplifies the following algorithm
	cvector(Term) tempTerms = NULL;
	cvector_copy(l.term2, tempTerms); // may be able to just push to l.term2, then pop when done.
	cvector_insert(tempTerms, 0, l.term1);

	for(Term *it1 = cvector_begin(tempTerms); it1 != cvector_end(tempTerms); it1 += 1) {
		bool allFollowNullable = true;

		for(Term *it2 = it1 + 1; it2 != cvector_end(tempTerms); it2 += 1) {
			FirstFollowSet nextFirst = first_follow_set_new();

			analyzer_analyze_firsts_term(a, *it2, &nextFirst);
			analyzer_analyze_follows_factor(a, it1->factor1, &nextFirst);

			if(!nextFirst.nullable) {
				allFollowNullable = false;
				first_follow_set_delete(&nextFirst);
				break;
			}

			first_follow_set_delete(&nextFirst);
		}

		if(allFollowNullable) {
			analyzer_analyze_follows_factor(a, it1->factor1, ffs);
		}
	}

	cvector_free(tempTerms);
}

static void analyzer_analyze_follows_term(Analyzer *a, Term t, FirstFollowSet *ffs) {
	analyzer_analyze_follows_factor(a, t.factor1, ffs);

	if(optional_is_valid(t.factor2)) {
		analyzer_analyze_follows_factor(a, *(t.factor2), ffs);
	}
}

static void analyzer_analyze_follows_factor(Analyzer *a, Factor f, FirstFollowSet *ffs) {
	switch(f.tag) {
	case FactorType_NonTerminal_Identifier: {
			const FirstFollowSet *ntffs = analyzer_get_first_follow_set(a, f.nonterminal_identifier);

			if(ntffs != NULL) {
				set_union(ntffs->follows, ffs->firsts);
				set_union(ntffs->follows, ffs->follows);
			} else {
				FirstFollowSet n = first_follow_set_new();

				n.t = f.nonterminal_identifier;
				set_union(n.follows, ffs->firsts);
				set_union(n.follows, ffs->follows);
				hashmap_set(a->sets, &n);
			}
		}
		break;
	case FactorType_Optional:
		analyzer_analyze_follows_expression(a, *(f.optional), ffs);
		break;
	case FactorType_Repetition: {
			FirstFollowSet temp = first_follow_set_new();
			set_union(temp.follows, ffs->firsts);
			set_union(temp.follows, ffs->follows);
			analyzer_analyze_firsts_expression(a, *(f.repetition), &temp);
			analyzer_analyze_follows_expression(a, *(f.repetition), &temp);
			first_follow_set_delete(&temp);
		}
		break;
	case FactorType_Grouping:
		analyzer_analyze_follows_expression(a, *(f.grouping), ffs);
		break;
	case FactorType_Terminal_Identifier:
		break;
	case FactorType_Literal:
		break;
	default:
		break;
	}
}

static void analyzer_analyze_start_symbol(Analyzer *a) {
	analyzer_analyze_start_symbol_grammar(a, *(a->ast), NULL);
}

static void analyzer_analyze_start_symbol_grammar(Analyzer *a, Grammar g, cvector(Rule) rules) {
	cvector(Rule) rs = NULL;
	cvector_copy(g.rule1, rs);

	for(Rule *it = cvector_begin(g.rule1); it != cvector_end(g.rule1); it += 1) {
		analyzer_analyze_start_symbol_expression(a, *(it->expression1), rs);
	}

	if(cvector_size(rs) == 1) {
		a->start = rs[0];
	} else {
		// Multiple start symbols error
	}

	cvector_free(rs);
}

static void analyzer_analyze_start_symbol_rule(Analyzer *a, Rule r, cvector(Rule) rules);

static void analyzer_analyze_start_symbol_expression(Analyzer *a, Expression e, cvector(Rule) rules) {
	analyzer_analyze_start_symbol_list(a, e.list1, rules);

	for(List *it = cvector_begin(e.list2); it != cvector_end(e.list2); it += 1) {
		analyzer_analyze_start_symbol_list(a, *it, rules);
	}
}

static void analyzer_analyze_start_symbol_list(Analyzer *a, List l, cvector(Rule) rules) {
	analyzer_analyze_start_symbol_term(a, l.term1, rules);

	for(Term *it = cvector_begin(l.term2); it != cvector_end(l.term2); it += 1) {
		analyzer_analyze_start_symbol_term(a, *it, rules);
	}
}

static void analyzer_analyze_start_symbol_term(Analyzer *a, Term t, cvector(Rule) rules) {
	analyzer_analyze_start_symbol_factor(a, t.factor1, rules);

	if(optional_is_valid(t.factor2)) {
		analyzer_analyze_start_symbol_factor(a, *(t.factor2), rules);
	}
}

static void analyzer_analyze_start_symbol_factor(Analyzer *a, Factor f, cvector(Rule) rules) {
	switch(f.tag) {
	case FactorType_NonTerminal_Identifier: {
			size_t i = 0;
			for(Rule *it = cvector_begin(rules); it != cvector_end(rules); it += 1) {
				if(strcmp(f.nonterminal_identifier.lexeme, it->token1.lexeme) == 0) {
					cvector_erase(rules, i);

					break;
				}

				i += 1;
			}
		}
		break;
	case FactorType_Optional:
		analyzer_analyze_start_symbol_expression(a, *(f.optional), rules);
		break;
	case FactorType_Repetition:
		analyzer_analyze_start_symbol_expression(a, *(f.repetition), rules);
		break;
	case FactorType_Grouping:
		analyzer_analyze_start_symbol_expression(a, *(f.grouping), rules);
		break;
	case FactorType_Terminal_Identifier: {
			size_t i = 0;
			for(Rule *it = cvector_begin(rules); it != cvector_end(rules); it += 1) {
				if(strcmp(f.terminal_identifier.lexeme, it->token1.lexeme) == 0) {
					cvector_erase(rules, i);

					break;
				}

				i += 1;
			}
		}
		break;
	case FactorType_Literal:
		break;
	default:
		break;

	}
}

static bool analyzer_analyze_anonymous_expression(Analyzer *a, HoistContext *hc) {
	analyzer_analyze_anonymous_expression_grammar(a, a->ast, NULL);

	return true;

}

static bool analyzer_analyze_anonymous_expression_grammar(Analyzer *a, Grammar *g, HoistContext *hc) {
	for(size_t it = 0; it < cvector_size(g->rule1); it += 1) {
		if(g->rule1[it].token1.type == TokenType_NonTerminal_Identifier) {
			HoistContext hc = {
				.newRules = NULL,
				.ruleName = g->rule1[it].token1,
				.nOptional = 0,
				.nRepetition = 0,
				.nGroup = 0,
			};

			if(analyzer_analyze_anonymous_expression_expression(a, g->rule1[it].expression1, &hc)) {
				for(Rule *it2 = cvector_begin(hc.newRules); it2 != cvector_end(hc.newRules); it2 += 1) {
					cvector_push_back(a->ast->rule1, *it2);
				}

				cvector_free(hc.newRules);
			}
		}
	}

	return true;
}

static bool analyzer_analyze_anonymous_expression_rule(Analyzer *a, Rule *r, HoistContext *hc);

static bool analyzer_analyze_anonymous_expression_expression(Analyzer *a, Expression *e, HoistContext *hc) {
	bool result = analyzer_analyze_anonymous_expression_list(a, &e->list1, hc);

	for(List *it = cvector_begin(e->list2); it != cvector_end(e->list2); it += 1) {
		result |= analyzer_analyze_anonymous_expression_list(a, it, hc);
	}

	return result;

}

static bool analyzer_analyze_anonymous_expression_list(Analyzer *a, List *l, HoistContext *hc) {
	bool result = analyzer_analyze_anonymous_expression_term(a, &l->term1, hc);

	for(Term *it = cvector_begin(l->term2); it != cvector_end(l->term2); it += 1) {
		result |= analyzer_analyze_anonymous_expression_term(a, it, hc);
	}

	return result;
}

static bool analyzer_analyze_anonymous_expression_term(Analyzer *a, Term *t, HoistContext *hc) {
	bool result = analyzer_analyze_anonymous_expression_factor(a, &t->factor1, hc);

	if(optional_is_valid(t->factor2)) {
		result |= analyzer_analyze_anonymous_expression_factor(a, t->factor2, hc);
	}

	return result;
}

static bool analyzer_analyze_anonymous_expression_factor(Analyzer *a, Factor *f, HoistContext *hc) {
	char *suffix = NULL;
	uint8_t count;

	switch(f->tag) {
	case FactorType_Optional:
		suffix = "Optional";
		count = hc->nOptional;
		hc->nOptional += 1;
		break;
	case FactorType_Repetition:
		suffix = "Repetition";
		count = hc->nRepetition;
		hc->nRepetition += 1;
		break;
	case FactorType_Grouping:
		suffix = "Group";
		count = hc->nGroup;
		hc->nGroup += 1;
		break;
	default:
		return false;
	}

	analyzer_analyze_anonymous_expression_expression(a, f->grouping, hc);

	// Create name
	size_t nl = strlen(hc->ruleName.lexeme);
	size_t sl = strlen(suffix);
	char *s = memory_new((nl + sl + 4) * sizeof(*s));

	if(s == NULL) {
		// Error
		return false;
	}

	snprintf(s, nl + sl + 4, "%s%s%d", hc->ruleName.lexeme, suffix, count);

	if(f->tag == FactorType_Optional || f->tag == FactorType_Repetition) {
		List l = { 0 };
		l.term1.factor1.tag = FactorType_Epsilon;
		cvector_push_back(f->grouping->list2, l);
	}


	Rule r = { .expression1 = f->grouping, .token1 = { .lexeme = s, .type = TokenType_NonTerminal_Identifier} };
	*f = (Factor) {
		.nonterminal_identifier = (Token) {
			.lexeme = memory_copy(s, strlen(s) + 1),
			.pos = r.token1.pos,
			.type = TokenType_NonTerminal_Identifier,
		},
		.tag = FactorType_NonTerminal_Identifier,
	};

	cvector_push_back(hc->newRules, r);

	return true;
}

static FirstFollowSet first_follow_set_new() {
	return (FirstFollowSet) {
		.nullable = false,
		.t = (Token) { 0 },
		.firsts = hashmap_new_with_allocator(
			  memory_new, memory_resize, memory_delete,
			  sizeof(Token), 0, 0, 0,
			  token_hash, token_compare, NULL, NULL),
		.follows = hashmap_new_with_allocator(
			  memory_new, memory_resize, memory_delete,
			  sizeof(Token), 0, 0, 0,
			  token_hash, token_compare, NULL, NULL),
	};
}

static void first_follow_set_delete(FirstFollowSet *ffs) {
	hashmap_free(ffs->firsts);
	hashmap_free(ffs->follows);
	*ffs = (FirstFollowSet) {
		.nullable = false,
		.t = (Token) { 0 },
		.firsts = NULL,
		.follows = NULL,
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

static uint64_t first_follow_set_hash(const void *item, uint64_t seed0, uint64_t seed1) {
	const FirstFollowSet *set = item;

	return hashmap_sip(set->t.lexeme, strlen(set->t.lexeme), seed0, seed1);
}

static int first_follow_set_compare(const void *a, const void *b, void *udata) {
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
