#include <stdbool.h>
#include <stdio.h>

#include "lib/hashmap.c/hashmap.h"

#include "verbum/token/token.h"
#include "verbum/analysis/analysis.h"
#include "verbum/parser/parser.h"
#include "verbum/code/code.h"


int main() {
	Parser *p = parser_new("c.ebnf");
	AST *ast = parser_parse(p);
	Analyzer *a = analyzer_new(ast);

	analyzer_analyze(a);

	/* {
		void *item;
		size_t i = 0;
		size_t n = 0;

		while(hashmap_iter(a->tokens, &i, &item)) {
			Token *t = item;

			printf("%s\n", t->lexeme);
			n += 1;
		}
	} */
	/* {
		void *item;
		size_t i = 0;
		size_t n = 0;

		while(hashmap_iter(a->cycles, &i, &item)) {
			Token *t = item;

			printf("cycle: %s\n", t->lexeme);
			n += 1;
		}
	} */
	/* {
		for(Rule *it = cvector_begin(a->ast->rule1); it != cvector_end(a->ast->rule1); it += 1) {
			printf("%s\n", it->token1.lexeme);
		}
	} */
	{
		printf("START: %s\n", a->start.token1.lexeme);
		void *item;
		size_t i = 0;

		while(hashmap_iter(a->sets, &i, &item)) {
			FirstFollowSet *ffs = item;
			void *item2;
			size_t j = 0;

			printf("Key '%s' (%s)\n", ffs->t.lexeme, ffs->nullable ? "NULLABLE" : "NOTNULLABLE");
			printf("Firsts: ");

			while(hashmap_iter(ffs->firsts, &j, &item2)) {
				Token *t = item2;
				printf("\"%s\" , ", t->lexeme);
			}

			j = 0;
			printf("\nFollows %zu: ", hashmap_count(ffs->follows));

			while(hashmap_iter(ffs->follows, &j, &item2)) {
				Token *t = item2;
				printf("\"%s\" , ", t->lexeme);
			}

			printf("\n----------------------------------------\n");
		}
	}

	CodeGenerator cg = code_generator_new(ast, a->start, a->tokens, a->sets);

	code_generator_generate(cg);

	ast_print(ast);
	analyzer_delete(a);
	ast_delete(ast);
	parser_delete(p);

	return 0;
}
