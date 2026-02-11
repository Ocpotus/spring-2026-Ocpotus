#include <stdio.h>

#include "../../lib/try.h/try.h"
#include "../../lib/c-vector/cvector.h"
#include "../../lib/c-vector/cvector_utils.h"

#include "../memory/memory.h"

#include "ast.h"


static void ast_delete_grammar(Grammar g1);
static void ast_delete_rule(Rule r1);
static void ast_delete_expression(Expression e1);
static void ast_delete_list(List l1);
static void ast_delete_term(Term t1);
static void ast_delete_factor(Factor f1);


Factor ast_new_factor1(Token t) {
	return (Factor) {
		.nonterminal_identifier = t,
		.tag = FactorType_NonTerminal_Identifier,
	};
}

Factor ast_new_factor2(Token t) {
	return (Factor) {
		.terminal_identifier = t,
		.tag = FactorType_Terminal_Identifier,
	};
}

Factor ast_new_factor3(Token t) {
	return (Factor) {
		.literal = t,
		.tag = FactorType_Literal,
	};
}

Factor ast_new_factor4(Expression e) {
	return (Factor) {
		.optional = memory_copy(&e, sizeof(e)),
		.tag = FactorType_Optional,
	};
}

Factor ast_new_factor5(Expression e) {
	return (Factor) {
		.repetition = memory_copy(&e, sizeof(e)),
		.tag = FactorType_Repetition,
	};
}

Factor ast_new_factor6(Expression e) {
	return (Factor) {
		.grouping = memory_copy(&e, sizeof(e)),
		.tag = FactorType_Grouping,
	};
}


Term ast_new_term(Factor f1, cvector(Factor) f2) {
	return (Term) {
		.factor1 = f1,
		.factor2 = f2,
	};
}

List ast_new_list(Term t1, cvector(Term) t2) {
	return (List) {
		.term1 = t1,
		.term2 = t2,
	};
}

Expression ast_new_expression(List l1, cvector(List) l2) {
	return (Expression) {
		.list1 = l1,
		.list2 = l2,
	};
}

Rule ast_new_rule(Token t1, Expression e1) {
	return (Rule) {
		.token1 = t1,
		.expression1 = memory_copy(&e1, sizeof(e1)),
	};
}

Grammar ast_new_grammar(cvector(Rule) r1) {
	return (Grammar) {
		.rule1 = r1,
	};
}

void ast_delete(AST *ast) {
	ast_delete_grammar(*ast);
	memory_delete(ast);

}

AST *ast_new(Grammar g1) {
	AST *result = try(memory_copy(&g1, sizeof(*result)), result == NULL, { return NULL; });

	return result;
}

static void ast_delete_grammar(Grammar g1) {
	cvector_for_each(g1.rule1, ast_delete_rule);
	cvector_free(g1.rule1);
}

static void ast_delete_rule(Rule r1) {
	token_delete(r1.token1);

	if(r1.expression1 != NULL) {
		ast_delete_expression(*(r1.expression1));
	}

	memory_delete(r1.expression1);
}

static void ast_delete_expression(Expression e1) {
	ast_delete_list(e1.list1);

	if(e1.list2 != NULL) {
		cvector_free_each_and_free(e1.list2, ast_delete_list);
	}
}

static void ast_delete_list(List l1) {
	ast_delete_term(l1.term1);

	if(l1.term2 != NULL) {
		cvector_free_each_and_free(l1.term2, ast_delete_term);
	}
}

static void ast_delete_term(Term t1) {
	ast_delete_factor(t1.factor1);

	if(t1.factor2 != NULL) {
		ast_delete_factor(*(t1.factor2));
		memory_delete(t1.factor2);
	}
}

static void ast_delete_factor(Factor f1) {
	switch(f1.tag) {
	case FactorType_NonTerminal_Identifier:
		token_delete(f1.nonterminal_identifier);
		break;
	case FactorType_Terminal_Identifier:
		token_delete(f1.terminal_identifier);
		break;
	case FactorType_Literal:
		token_delete(f1.literal);
		break;
	case FactorType_Optional:
		ast_delete_expression(*(f1.optional));
		memory_delete(f1.optional);
		break;
	case FactorType_Repetition:
		ast_delete_expression(*(f1.grouping));
		memory_delete(f1.grouping);
		break;
	case FactorType_Grouping:
		ast_delete_expression(*(f1.grouping));
		memory_delete(f1.grouping);
		break;
	default:
		break;
	}
}

static void ast_print_grammar(Grammar g1);
static void ast_print_rule(Rule r1);
static void ast_print_expression(Expression e1);
static void ast_print_list(List l1);
static void ast_print_term(Term t1);
static void ast_print_factor(Factor f1);

void ast_print(AST *ast) {
	ast_print_grammar(*ast);
}

static void ast_print_grammar(Grammar g1) {
	cvector_for_each(g1.rule1, ast_print_rule);
}

static void ast_print_rule(Rule r1) {
	printf("%c%s", r1.token1.type == TokenType_Terminal_Identifier ? '$' : '\0',r1.token1.lexeme);
	printf("\t=");
	ast_print_expression(*(r1.expression1));
	printf(";\n");
}

static void ast_print_expression(Expression e1) {
	ast_print_list(e1.list1);

	if(e1.list2 != NULL) {
		for(List *it = cvector_begin(e1.list2); it != cvector_end(e1.list2); it += 1) {
			printf("|");
			ast_print_list(*it);
		}
	}
}

static void ast_print_list(List l1) {
	ast_print_term(l1.term1);

	if(l1.term2 != NULL) {
		for(Term *it = cvector_begin(l1.term2); it != cvector_end(l1.term2); it += 1) {
			printf(",");
			ast_print_term(*it);
		}
	}
}

static void ast_print_term(Term t1) {
	ast_print_factor(t1.factor1);

	if(t1.factor2 != NULL) {
		printf("-");
		ast_print_factor(*t1.factor2);
	}
}

static void ast_print_factor(Factor f1) {
	switch(f1.tag) {
	case FactorType_NonTerminal_Identifier:
		printf(" %s ", f1.nonterminal_identifier.lexeme);
		break;
	case FactorType_Terminal_Identifier:
		printf(" $%s ", f1.terminal_identifier.lexeme);
		break;
	case FactorType_Literal:
		printf(" \"%s\" ", f1.literal.lexeme);
		break;
	case FactorType_Optional:
		printf(" [ ");
		ast_print_expression(*(f1.optional));
		printf(" ] ");
		break;
	case FactorType_Repetition:
		printf(" { ");
		ast_print_expression(*(f1.grouping));
		printf(" } ");
		break;
	case FactorType_Grouping:
		printf(" ( ");
		ast_print_expression(*(f1.grouping));
		printf(" ) ");
		break;
	default:
		break;
	}
}
