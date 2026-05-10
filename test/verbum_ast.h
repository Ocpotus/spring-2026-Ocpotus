#ifndef VERBUM_AST_H
#define VERBUM_AST_H
#include "verbum.h"
#include "verbum_token.h"
typedef struct grammar grammar;
typedef struct rule rule;
typedef struct expression expression;
typedef struct list list;
typedef struct term term;
typedef struct factor factor;
typedef struct grammarRepetition0 grammarRepetition0;
typedef struct ruleGroup0 ruleGroup0;
typedef struct expressionRepetition0 expressionRepetition0;
typedef struct listRepetition0 listRepetition0;
typedef struct termOptional0 termOptional0;
typedef struct grammar {
	struct grammarRepetition0 *grammarRepetition0_0;
} grammar;

struct grammar *verbum_ast_new_grammar(struct VerbumContext *ctx, struct grammarRepetition0 *grammarRepetition0_0);
void verbum_ast_delete_grammar(struct VerbumContext *ctx, struct grammar *d);
typedef struct rule {
	struct ruleGroup0 *ruleGroup0_0;
	Token literal_0;
	struct expression *expression_0;
	Token literal_1;

} rule;

struct rule *verbum_ast_new_rule(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0, struct ruleGroup0 *ruleGroup0_0);
void verbum_ast_delete_rule(struct VerbumContext *ctx, struct rule *d);
typedef struct expression {
	struct list *list_0;
	struct expressionRepetition0 *expressionRepetition0_0;
} expression;

struct expression *verbum_ast_new_expression(struct VerbumContext *ctx, struct list *list_0, struct expressionRepetition0 *expressionRepetition0_0);
void verbum_ast_delete_expression(struct VerbumContext *ctx, struct expression *d);
typedef struct list {
	struct term *term_0;
	struct listRepetition0 *listRepetition0_0;
} list;

struct list *verbum_ast_new_list(struct VerbumContext *ctx, struct listRepetition0 *listRepetition0_0, struct term *term_0);
void verbum_ast_delete_list(struct VerbumContext *ctx, struct list *d);
typedef struct term {
	struct factor *factor_0;
	struct termOptional0 *termOptional0_0;
} term;

struct term *verbum_ast_new_term(struct VerbumContext *ctx, struct factor *factor_0, struct termOptional0 *termOptional0_0);
void verbum_ast_delete_term(struct VerbumContext *ctx, struct term *d);
typedef enum factorType {
	factorType_0,
	factorType_1,
	factorType_2,
	factorType_3,
	factorType_4,
	factorType_5,
} factorType;
typedef struct factor {

	factorType tag;
	union {
		struct {
			Token NONTERMINAL_IDENTIFIER_0;
		} choice0;
		struct {
			Token TERMINAL_IDENTIFIER_0;
		} choice1;
		struct {
			Token LITERAL_0;
		} choice2;
		struct {
			Token literal_0;
			struct expression *expression_0;
			Token literal_1;

		} choice3;
		struct {
			Token literal_0;
			struct expression *expression_0;
			Token literal_1;

		} choice4;
		struct {
			Token literal_0;
			struct expression *expression_0;
			Token literal_1;

		} choice5;
	};
} factor;
struct factor *verbum_ast_new_factor_choice0(struct VerbumContext *ctx, Token NONTERMINAL_IDENTIFIER_0);
struct factor *verbum_ast_new_factor_choice1(struct VerbumContext *ctx, Token TERMINAL_IDENTIFIER_0);
struct factor *verbum_ast_new_factor_choice2(struct VerbumContext *ctx, Token LITERAL_0);
struct factor *verbum_ast_new_factor_choice3(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0);
struct factor *verbum_ast_new_factor_choice4(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0);
struct factor *verbum_ast_new_factor_choice5(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0);
void verbum_ast_delete_factor(struct VerbumContext *ctx, struct factor *d);
typedef enum grammarRepetition0Type {
	grammarRepetition0Type_0,
	grammarRepetition0Type_1,
	grammarRepetition0Type_2,
} grammarRepetition0Type;
typedef struct grammarRepetition0 {

	grammarRepetition0Type tag;
	union {
		struct {
			struct rule *rule_0;
			struct grammarRepetition0 *grammarRepetition0_0;
		} choice0;
		struct {
			Token COMMENT_0;
			struct grammarRepetition0 *grammarRepetition0_0;
		} choice1;
		struct {
		} choice2;
	};
} grammarRepetition0;
struct grammarRepetition0 *verbum_ast_new_grammarRepetition0_choice0(struct VerbumContext *ctx, struct rule *rule_0, struct grammarRepetition0 *grammarRepetition0_0);
struct grammarRepetition0 *verbum_ast_new_grammarRepetition0_choice1(struct VerbumContext *ctx, struct grammarRepetition0 *grammarRepetition0_0, Token COMMENT_0);
struct grammarRepetition0 *verbum_ast_new_grammarRepetition0_choice2(struct VerbumContext *ctx);
void verbum_ast_delete_grammarRepetition0(struct VerbumContext *ctx, struct grammarRepetition0 *d);
typedef enum ruleGroup0Type {
	ruleGroup0Type_0,
	ruleGroup0Type_1,
} ruleGroup0Type;
typedef struct ruleGroup0 {

	ruleGroup0Type tag;
	union {
		struct {
			Token NONTERMINAL_IDENTIFIER_0;
		} choice0;
		struct {
			Token TERMINAL_IDENTIFIER_0;
		} choice1;
	};
} ruleGroup0;
struct ruleGroup0 *verbum_ast_new_ruleGroup0_choice0(struct VerbumContext *ctx, Token NONTERMINAL_IDENTIFIER_0);
struct ruleGroup0 *verbum_ast_new_ruleGroup0_choice1(struct VerbumContext *ctx, Token TERMINAL_IDENTIFIER_0);
void verbum_ast_delete_ruleGroup0(struct VerbumContext *ctx, struct ruleGroup0 *d);
typedef enum expressionRepetition0Type {
	expressionRepetition0Type_0,
	expressionRepetition0Type_1,
} expressionRepetition0Type;
typedef struct expressionRepetition0 {

	expressionRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct list *list_0;
			struct expressionRepetition0 *expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} expressionRepetition0;
struct expressionRepetition0 *verbum_ast_new_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct list *list_0, struct expressionRepetition0 *expressionRepetition0_0);
struct expressionRepetition0 *verbum_ast_new_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_expressionRepetition0(struct VerbumContext *ctx, struct expressionRepetition0 *d);
typedef enum listRepetition0Type {
	listRepetition0Type_0,
	listRepetition0Type_1,
} listRepetition0Type;
typedef struct listRepetition0 {

	listRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct term *term_0;
			struct listRepetition0 *listRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} listRepetition0;
struct listRepetition0 *verbum_ast_new_listRepetition0_choice0(struct VerbumContext *ctx, struct listRepetition0 *listRepetition0_0, Token literal_0, struct term *term_0);
struct listRepetition0 *verbum_ast_new_listRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_listRepetition0(struct VerbumContext *ctx, struct listRepetition0 *d);
typedef enum termOptional0Type {
	termOptional0Type_0,
	termOptional0Type_1,
} termOptional0Type;
typedef struct termOptional0 {

	termOptional0Type tag;
	union {
		struct {
			Token literal_0;
			struct factor *factor_0;
		} choice0;
		struct {
		} choice1;
	};
} termOptional0;
struct termOptional0 *verbum_ast_new_termOptional0_choice0(struct VerbumContext *ctx, Token literal_0, struct factor *factor_0);
struct termOptional0 *verbum_ast_new_termOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_termOptional0(struct VerbumContext *ctx, struct termOptional0 *d);
typedef grammar AST;

#endif
