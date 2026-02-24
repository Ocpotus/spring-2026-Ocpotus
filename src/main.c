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
		void *item;
		size_t i = 0;

		printf("FIRSTS FIRSTS FIRSTS FIRSTS FIRSTS FIRSTS FIRSTS FIRSTS\n");

		while(hashmap_iter(a->firsts, &i, &item)) {
			FirstFollowSet *ffs = item;
			void *item2;
			size_t j = 0;

			printf("Key '%s' (%s): ", ffs->t.lexeme, ffs->nullable ? "NULLABLE" : "NOTNULLABLE");

			while(hashmap_iter(ffs->tokens, &j, &item2)) {
				Token *t = item2;
				printf("\"%s\" , ", t->lexeme);
			}

			printf("\n----------------------------------------\n");
		}
	}
	{
		printf("FOLLOWS FOLLOWS FOLLOWS FOLLOWS FOLLOWS FOLLOWS FOLLOWS FOLLOWS\n");
		void *item;
		size_t i = 0;

		while(hashmap_iter(a->follows, &i, &item)) {
			FirstFollowSet *ffs = item;
			void *item2;
			size_t j = 0;

			printf("Key '%s' (%s): ", ffs->t.lexeme, ffs->nullable ? "NULLABLE" : "NOTNULLABLE");

			while(hashmap_iter(ffs->tokens, &j, &item2)) {
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
