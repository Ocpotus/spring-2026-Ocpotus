#include "verbum.h"
#include "verbum_ast.h"


struct grammar *verbum_ast_new_grammar(struct VerbumContext *ctx, struct grammarRepetition0 *grammarRepetition0_0) {
	struct grammar *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->grammarRepetition0_0 = grammarRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_grammar(struct VerbumContext *ctx, struct grammar *grammar) {
	verbum_ast_delete_grammarRepetition0(ctx, grammar->grammarRepetition0_0);
	ctx->memory.delete(grammar);
}
struct rule *verbum_ast_new_rule(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0, struct ruleGroup0 *ruleGroup0_0) {
	struct rule *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->literal_0 = literal_0;
		result->literal_1 = literal_1;
		result->expression_0 = expression_0;
		result->ruleGroup0_0 = ruleGroup0_0;
	}

	return result;
}
void verbum_ast_delete_rule(struct VerbumContext *ctx, struct rule *rule) {
	verbum_ast_delete_expression(ctx, rule->expression_0);
	verbum_ast_delete_ruleGroup0(ctx, rule->ruleGroup0_0);
	ctx->memory.delete(rule);
}
struct expression *verbum_ast_new_expression(struct VerbumContext *ctx, struct list *list_0, struct expressionRepetition0 *expressionRepetition0_0) {
	struct expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->list_0 = list_0;
		result->expressionRepetition0_0 = expressionRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_expression(struct VerbumContext *ctx, struct expression *expression) {
	verbum_ast_delete_list(ctx, expression->list_0);
	verbum_ast_delete_expressionRepetition0(ctx, expression->expressionRepetition0_0);
	ctx->memory.delete(expression);
}
struct list *verbum_ast_new_list(struct VerbumContext *ctx, struct listRepetition0 *listRepetition0_0, struct term *term_0) {
	struct list *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->listRepetition0_0 = listRepetition0_0;
		result->term_0 = term_0;
	}

	return result;
}
void verbum_ast_delete_list(struct VerbumContext *ctx, struct list *list) {
	verbum_ast_delete_listRepetition0(ctx, list->listRepetition0_0);
	verbum_ast_delete_term(ctx, list->term_0);
	ctx->memory.delete(list);
}
struct term *verbum_ast_new_term(struct VerbumContext *ctx, struct factor *factor_0, struct termOptional0 *termOptional0_0) {
	struct term *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->factor_0 = factor_0;
		result->termOptional0_0 = termOptional0_0;
	}

	return result;
}
void verbum_ast_delete_term(struct VerbumContext *ctx, struct term *term) {
	verbum_ast_delete_factor(ctx, term->factor_0);
	verbum_ast_delete_termOptional0(ctx, term->termOptional0_0);
	ctx->memory.delete(term);
}
struct factor *verbum_ast_new_factor_choice0(struct VerbumContext *ctx, Token NONTERMINAL_IDENTIFIER_0) {
	struct factor *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.NONTERMINAL_IDENTIFIER_0 = NONTERMINAL_IDENTIFIER_0;

		result->tag = factorType_0;
	}

	return result;
}
struct factor *verbum_ast_new_factor_choice1(struct VerbumContext *ctx, Token TERMINAL_IDENTIFIER_0) {
	struct factor *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.TERMINAL_IDENTIFIER_0 = TERMINAL_IDENTIFIER_0;

		result->tag = factorType_1;
	}

	return result;
}
struct factor *verbum_ast_new_factor_choice2(struct VerbumContext *ctx, Token LITERAL_0) {
	struct factor *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.LITERAL_0 = LITERAL_0;

		result->tag = factorType_2;
	}

	return result;
}
struct factor *verbum_ast_new_factor_choice3(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0) {
	struct factor *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.literal_0 = literal_0;
		result->choice3.literal_1 = literal_1;
		result->choice3.expression_0 = expression_0;

		result->tag = factorType_3;
	}

	return result;
}
struct factor *verbum_ast_new_factor_choice4(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0) {
	struct factor *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice4.literal_0 = literal_0;
		result->choice4.literal_1 = literal_1;
		result->choice4.expression_0 = expression_0;

		result->tag = factorType_4;
	}

	return result;
}
struct factor *verbum_ast_new_factor_choice5(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0) {
	struct factor *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice5.literal_0 = literal_0;
		result->choice5.literal_1 = literal_1;
		result->choice5.expression_0 = expression_0;

		result->tag = factorType_5;
	}

	return result;
}
void verbum_ast_delete_factor(struct VerbumContext *ctx, struct factor *factor) {
	switch(factor->tag) {
	case factorType_0:
		verbum_token_delete(ctx, &factor->choice0.NONTERMINAL_IDENTIFIER_0);
	break;
	case factorType_1:
		verbum_token_delete(ctx, &factor->choice1.TERMINAL_IDENTIFIER_0);
	break;
	case factorType_2:
		verbum_token_delete(ctx, &factor->choice2.LITERAL_0);
	break;
	case factorType_3:
		verbum_token_delete(ctx, &factor->choice3.literal_0);
		verbum_token_delete(ctx, &factor->choice3.literal_1);
		verbum_ast_delete_expression(ctx, factor->choice3.expression_0);
	break;
	case factorType_4:
		verbum_token_delete(ctx, &factor->choice4.literal_0);
		verbum_token_delete(ctx, &factor->choice4.literal_1);
		verbum_ast_delete_expression(ctx, factor->choice4.expression_0);
	break;
	case factorType_5:
		verbum_token_delete(ctx, &factor->choice5.literal_0);
		verbum_token_delete(ctx, &factor->choice5.literal_1);
		verbum_ast_delete_expression(ctx, factor->choice5.expression_0);
	break;
	}
	ctx->memory.delete(factor);
}
struct grammarRepetition0 *verbum_ast_new_grammarRepetition0_choice0(struct VerbumContext *ctx, struct rule *rule_0, struct grammarRepetition0 *grammarRepetition0_0) {
	struct grammarRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.rule_0 = rule_0;
		result->choice0.grammarRepetition0_0 = grammarRepetition0_0;

		result->tag = grammarRepetition0Type_0;
	}

	return result;
}
struct grammarRepetition0 *verbum_ast_new_grammarRepetition0_choice1(struct VerbumContext *ctx, struct grammarRepetition0 *grammarRepetition0_0, Token COMMENT_0) {
	struct grammarRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.grammarRepetition0_0 = grammarRepetition0_0;
		result->choice1.COMMENT_0 = COMMENT_0;

		result->tag = grammarRepetition0Type_1;
	}

	return result;
}
struct grammarRepetition0 *verbum_ast_new_grammarRepetition0_choice2(struct VerbumContext *ctx) {
	struct grammarRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = grammarRepetition0Type_2;
	}

	return result;
}
void verbum_ast_delete_grammarRepetition0(struct VerbumContext *ctx, struct grammarRepetition0 *grammarRepetition0) {
	switch(grammarRepetition0->tag) {
	case grammarRepetition0Type_0:
		verbum_ast_delete_rule(ctx, grammarRepetition0->choice0.rule_0);
		verbum_ast_delete_grammarRepetition0(ctx, grammarRepetition0->choice0.grammarRepetition0_0);
	break;
	case grammarRepetition0Type_1:
		verbum_ast_delete_grammarRepetition0(ctx, grammarRepetition0->choice1.grammarRepetition0_0);
		verbum_token_delete(ctx, &grammarRepetition0->choice1.COMMENT_0);
	break;
	case grammarRepetition0Type_2:
	break;
	}
	ctx->memory.delete(grammarRepetition0);
}
struct ruleGroup0 *verbum_ast_new_ruleGroup0_choice0(struct VerbumContext *ctx, Token NONTERMINAL_IDENTIFIER_0) {
	struct ruleGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.NONTERMINAL_IDENTIFIER_0 = NONTERMINAL_IDENTIFIER_0;

		result->tag = ruleGroup0Type_0;
	}

	return result;
}
struct ruleGroup0 *verbum_ast_new_ruleGroup0_choice1(struct VerbumContext *ctx, Token TERMINAL_IDENTIFIER_0) {
	struct ruleGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.TERMINAL_IDENTIFIER_0 = TERMINAL_IDENTIFIER_0;

		result->tag = ruleGroup0Type_1;
	}

	return result;
}
void verbum_ast_delete_ruleGroup0(struct VerbumContext *ctx, struct ruleGroup0 *ruleGroup0) {
	switch(ruleGroup0->tag) {
	case ruleGroup0Type_0:
		verbum_token_delete(ctx, &ruleGroup0->choice0.NONTERMINAL_IDENTIFIER_0);
	break;
	case ruleGroup0Type_1:
		verbum_token_delete(ctx, &ruleGroup0->choice1.TERMINAL_IDENTIFIER_0);
	break;
	}
	ctx->memory.delete(ruleGroup0);
}
struct expressionRepetition0 *verbum_ast_new_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct list *list_0, struct expressionRepetition0 *expressionRepetition0_0) {
	struct expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.list_0 = list_0;
		result->choice0.expressionRepetition0_0 = expressionRepetition0_0;

		result->tag = expressionRepetition0Type_0;
	}

	return result;
}
struct expressionRepetition0 *verbum_ast_new_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_expressionRepetition0(struct VerbumContext *ctx, struct expressionRepetition0 *expressionRepetition0) {
	switch(expressionRepetition0->tag) {
	case expressionRepetition0Type_0:
		verbum_token_delete(ctx, &expressionRepetition0->choice0.literal_0);
		verbum_ast_delete_list(ctx, expressionRepetition0->choice0.list_0);
		verbum_ast_delete_expressionRepetition0(ctx, expressionRepetition0->choice0.expressionRepetition0_0);
	break;
	case expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(expressionRepetition0);
}
struct listRepetition0 *verbum_ast_new_listRepetition0_choice0(struct VerbumContext *ctx, struct listRepetition0 *listRepetition0_0, Token literal_0, struct term *term_0) {
	struct listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.listRepetition0_0 = listRepetition0_0;
		result->choice0.literal_0 = literal_0;
		result->choice0.term_0 = term_0;

		result->tag = listRepetition0Type_0;
	}

	return result;
}
struct listRepetition0 *verbum_ast_new_listRepetition0_choice1(struct VerbumContext *ctx) {
	struct listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = listRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_listRepetition0(struct VerbumContext *ctx, struct listRepetition0 *listRepetition0) {
	switch(listRepetition0->tag) {
	case listRepetition0Type_0:
		verbum_ast_delete_listRepetition0(ctx, listRepetition0->choice0.listRepetition0_0);
		verbum_token_delete(ctx, &listRepetition0->choice0.literal_0);
		verbum_ast_delete_term(ctx, listRepetition0->choice0.term_0);
	break;
	case listRepetition0Type_1:
	break;
	}
	ctx->memory.delete(listRepetition0);
}
struct termOptional0 *verbum_ast_new_termOptional0_choice0(struct VerbumContext *ctx, Token literal_0, struct factor *factor_0) {
	struct termOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.factor_0 = factor_0;

		result->tag = termOptional0Type_0;
	}

	return result;
}
struct termOptional0 *verbum_ast_new_termOptional0_choice1(struct VerbumContext *ctx) {
	struct termOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = termOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_termOptional0(struct VerbumContext *ctx, struct termOptional0 *termOptional0) {
	switch(termOptional0->tag) {
	case termOptional0Type_0:
		verbum_token_delete(ctx, &termOptional0->choice0.literal_0);
		verbum_ast_delete_factor(ctx, termOptional0->choice0.factor_0);
	break;
	case termOptional0Type_1:
	break;
	}
	ctx->memory.delete(termOptional0);
}
