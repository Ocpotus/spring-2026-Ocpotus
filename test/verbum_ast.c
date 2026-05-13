#include "verbum.h"
#include "verbum_ast.h"


struct start *verbum_ast_new_start(struct VerbumContext *ctx, struct expression *expression_0) {
	struct start *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->expression_0 = expression_0;
	}

	return result;
}
void verbum_ast_delete_start(struct VerbumContext *ctx, struct start *start) {
	verbum_ast_delete_expression(ctx, start->expression_0);
	ctx->memory.delete(start);
}
struct expression *verbum_ast_new_expression(struct VerbumContext *ctx, struct expression *expression_0, struct expressionOptional0 *expressionOptional0_0, struct term *term_0) {
	struct expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->expression_0 = expression_0;
		result->expressionOptional0_0 = expressionOptional0_0;
		result->term_0 = term_0;
	}

	return result;
}
void verbum_ast_delete_expression(struct VerbumContext *ctx, struct expression *expression) {
	verbum_ast_delete_expression(ctx, expression->expression_0);
	verbum_ast_delete_expressionOptional0(ctx, expression->expressionOptional0_0);
	verbum_ast_delete_term(ctx, expression->term_0);
	ctx->memory.delete(expression);
}
struct term *verbum_ast_new_term(struct VerbumContext *ctx, struct factor *factor_0, struct term *term_0, struct termOptional0 *termOptional0_0) {
	struct term *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->factor_0 = factor_0;
		result->term_0 = term_0;
		result->termOptional0_0 = termOptional0_0;
	}

	return result;
}
void verbum_ast_delete_term(struct VerbumContext *ctx, struct term *term) {
	verbum_ast_delete_factor(ctx, term->factor_0);
	verbum_ast_delete_term(ctx, term->term_0);
	verbum_ast_delete_termOptional0(ctx, term->termOptional0_0);
	ctx->memory.delete(term);
}
struct factor *verbum_ast_new_factor(struct VerbumContext *ctx, Token NUMBER_0) {
	struct factor *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->NUMBER_0 = NUMBER_0;
	}

	return result;
}
void verbum_ast_delete_factor(struct VerbumContext *ctx, struct factor *factor) {
	ctx->memory.delete(factor);
}
struct expressionOptional0 *verbum_ast_new_expressionOptional0_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct expressionOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = expressionOptional0Type_0;
	}

	return result;
}
struct expressionOptional0 *verbum_ast_new_expressionOptional0_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct expressionOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = expressionOptional0Type_1;
	}

	return result;
}
struct expressionOptional0 *verbum_ast_new_expressionOptional0_choice2(struct VerbumContext *ctx) {
	struct expressionOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = expressionOptional0Type_2;
	}

	return result;
}
void verbum_ast_delete_expressionOptional0(struct VerbumContext *ctx, struct expressionOptional0 *expressionOptional0) {
	switch(expressionOptional0->tag) {
	case expressionOptional0Type_0:
		verbum_token_delete(ctx, &expressionOptional0->choice0.literal_0);
	break;
	case expressionOptional0Type_1:
		verbum_token_delete(ctx, &expressionOptional0->choice1.literal_0);
	break;
	case expressionOptional0Type_2:
	break;
	}
	ctx->memory.delete(expressionOptional0);
}
struct termOptional0 *verbum_ast_new_termOptional0_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct termOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = termOptional0Type_0;
	}

	return result;
}
struct termOptional0 *verbum_ast_new_termOptional0_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct termOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = termOptional0Type_1;
	}

	return result;
}
struct termOptional0 *verbum_ast_new_termOptional0_choice2(struct VerbumContext *ctx) {
	struct termOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = termOptional0Type_2;
	}

	return result;
}
void verbum_ast_delete_termOptional0(struct VerbumContext *ctx, struct termOptional0 *termOptional0) {
	switch(termOptional0->tag) {
	case termOptional0Type_0:
		verbum_token_delete(ctx, &termOptional0->choice0.literal_0);
	break;
	case termOptional0Type_1:
		verbum_token_delete(ctx, &termOptional0->choice1.literal_0);
	break;
	case termOptional0Type_2:
	break;
	}
	ctx->memory.delete(termOptional0);
}
