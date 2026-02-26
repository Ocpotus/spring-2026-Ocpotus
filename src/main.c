#include <stdbool.h>
#include <stdio.h>

#include "lib/hashmap.c/hashmap.h"

#include "verbum/token/token.h"
#include "verbum/analysis/analysis.h"
#include "verbum/parser/parser.h"


int main() {
	Parser *p = parser_new("ebnf.ebnf");
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

	//ast_print(ast);
	analyzer_delete(a);
	ast_delete(ast);
	parser_delete(p);

	return 0;
}
