#ifndef VERBUM_AST_C
#define VERBUM_AST_C

#include "../../lib/optional.h/optional.h"
#include "../../lib/c-vector/cvector.h"

#include "../token/token.h"


/*
grammar        			= { rule } ;
rule           			= ( $NONTERMINAL_IDENTIFIER | $TERMINAL_IDENTIFIER ) , "=" , expression , ";" ;
expression     			= list , { "|" , list } ;
list           			= term , { "," , term } ;
term	       			= factor , [ "-" factor ] ;
factor         			= $NONTERMINAL_IDENTIFIER
				| $TERMINAL_IDENTIFIER
				| $LITERAL
				| "[" , expression , "]"
				| "{" , expression , "}"
				| "(" , expression , ")"
				;
*/
typedef struct Grammar Grammar;
typedef struct Rule Rule;
typedef struct Expression Expression;
typedef struct List List;
typedef struct Term Term;
typedef struct Factor Factor;

typedef struct Grammar {
	cvector(Rule) rule1;
} Grammar;

typedef struct Rule {
	union {
		Token nonterminal_identifier1;
		Token termainl_identifier1;
	};
	Expression *expression1;
} Rule;

typedef struct Expression {
	List *list1;
	cvector(List) list2;
} Expression;

typedef struct List {
	Term *term1;
	cvector(Term) term2;
} List;

typedef struct Term {
	Factor *factor1;
	optional(Factor) factor2;
} Term;

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
		Expression optional;
		Expression repetition;
		Expression grouping;
	};
	FactorType tag;
} Factor;


#endif
