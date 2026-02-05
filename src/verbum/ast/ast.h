#ifndef VERBUM_AST_C
#define VERBUM_AST_C

#include "../../lib/optional.h/optional.h"
#include "../../lib/c-vector/cvector.h"

#include "../token/token.h"


typedef struct Grammar Grammar;
typedef struct Rule Rule;
typedef struct Expression Expression;
typedef struct List List;
typedef struct Term Term;
typedef struct Factor Factor;

typedef enum FactorType {
	FactorType_Invalid = -1,
	FactorType_NonTerminal_Identifier,
	FactorType_Terminal_Identifier,
	FactorType_Literal,
	FactorType_Optional,
	FactorType_Repetition,
	FactorType_Grouping,
} FactorType;

typedef struct Factor {
	union {
		Token nonterminal_identifier;
		Token terminal_identifier;
		Token literal;
		Expression *optional;
		Expression *repetition;
		Expression *grouping;
	};
	FactorType tag;
} Factor;

typedef struct Term {
	Factor factor1;
	optional(Factor) factor2;
} Term;

typedef struct List {
	Term term1;
	cvector(Term) term2;
} List;

typedef struct Expression {
	List list1;
	cvector(List) list2;
} Expression;

typedef struct Rule {
	Token token1;
	Expression *expression1;
} Rule;

typedef struct Grammar {
	cvector(Rule) rule1;
} Grammar;


Factor ast_new_factor1(Token t);
Factor ast_new_factor2(Token t);
Factor ast_new_factor3(Token t);
Factor ast_new_factor4(Expression e);
Factor ast_new_factor5(Expression e);
Factor ast_new_factor6(Expression e);
Term ast_new_term(Factor f1, cvector(Factor) f2);
List ast_new_list(Term t1, cvector(Term) t2);
Expression ast_new_expression(List l1, cvector(List) l2);
Rule ast_new_rule(Token t1, Expression e1);
Grammar ast_new_grammar(cvector(Rule) r1);

void ast_delete(Grammar g1);


#endif
