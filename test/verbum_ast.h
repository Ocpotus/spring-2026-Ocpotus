#ifndef VERBUM_AST_H
#define VERBUM_AST_H
#include "verbum.h"
#include "verbum_token.h"
typedef struct start start;
typedef struct expression expression;
typedef struct term term;
typedef struct factor factor;
typedef struct expressionOptional0 expressionOptional0;
typedef struct termOptional0 termOptional0;
typedef struct start {
	struct expression *expression_0;
} start;

struct start *verbum_ast_new_start(struct VerbumContext *ctx, struct expression *expression_0);
void verbum_ast_delete_start(struct VerbumContext *ctx, struct start *d);
typedef struct expression {
	struct term *term_0;
	struct expressionOptional0 *expressionOptional0_0;
	struct expression *expression_0;
} expression;

struct expression *verbum_ast_new_expression(struct VerbumContext *ctx, struct expression *expression_0, struct expressionOptional0 *expressionOptional0_0, struct term *term_0);
void verbum_ast_delete_expression(struct VerbumContext *ctx, struct expression *d);
typedef struct term {
	struct factor *factor_0;
	struct termOptional0 *termOptional0_0;
	struct term *term_0;
} term;

struct term *verbum_ast_new_term(struct VerbumContext *ctx, struct factor *factor_0, struct term *term_0, struct termOptional0 *termOptional0_0);
void verbum_ast_delete_term(struct VerbumContext *ctx, struct term *d);
typedef struct factor {
	Token NUMBER_0;
} factor;

struct factor *verbum_ast_new_factor(struct VerbumContext *ctx, Token NUMBER_0);
void verbum_ast_delete_factor(struct VerbumContext *ctx, struct factor *d);
typedef enum expressionOptional0Type {
	expressionOptional0Type_0,
	expressionOptional0Type_1,
	expressionOptional0Type_2,
} expressionOptional0Type;
typedef struct expressionOptional0 {

	expressionOptional0Type tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
		struct {
		} choice2;
	};
} expressionOptional0;
struct expressionOptional0 *verbum_ast_new_expressionOptional0_choice0(struct VerbumContext *ctx, Token literal_0);
struct expressionOptional0 *verbum_ast_new_expressionOptional0_choice1(struct VerbumContext *ctx, Token literal_0);
struct expressionOptional0 *verbum_ast_new_expressionOptional0_choice2(struct VerbumContext *ctx);
void verbum_ast_delete_expressionOptional0(struct VerbumContext *ctx, struct expressionOptional0 *d);
typedef enum termOptional0Type {
	termOptional0Type_0,
	termOptional0Type_1,
	termOptional0Type_2,
} termOptional0Type;
typedef struct termOptional0 {

	termOptional0Type tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
		struct {
		} choice2;
	};
} termOptional0;
struct termOptional0 *verbum_ast_new_termOptional0_choice0(struct VerbumContext *ctx, Token literal_0);
struct termOptional0 *verbum_ast_new_termOptional0_choice1(struct VerbumContext *ctx, Token literal_0);
struct termOptional0 *verbum_ast_new_termOptional0_choice2(struct VerbumContext *ctx);
void verbum_ast_delete_termOptional0(struct VerbumContext *ctx, struct termOptional0 *d);
typedef start AST;

#endif
