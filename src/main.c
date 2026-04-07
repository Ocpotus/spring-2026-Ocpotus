#include <stdbool.h>
#include <stdio.h>

#include "lib/optparse99/optparse99.h"
#include "lib/hashmap.c/hashmap.h"

#include "verbum/token/token.h"
#include "verbum/analysis/analysis.h"
#include "verbum/parser/parser.h"
#include "verbum/code/code.h"

/* Helper macro for default `--help` option */
#define CLI_HELP_OPTION .short_name = 'h',\
			.long_name = "help",\
			.description = "displays this page",\
			.function = optparse_print_help,


void verbum_generate(int argc, char **argv);

int main(int argc, char *argv[]) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
	struct optparse_cmd verbum = {
		.name = "verbum",
		.about = "verbum 0.1.0 - ebnf to c parser generator",
		.description = "verbum is an ebnf to c parser generator that produces good code.",
		.usage = "verbum <SUBCOMMAND> [OPTIONS]",
		.options = (struct optparse_opt []) {
			{ CLI_HELP_OPTION },
			{ END_OF_OPTIONS },
		},
		.subcommands = (struct optparse_cmd []) {
			(struct optparse_cmd) {
				.name = "generate",
				.about = "generates parser",
				.description = "generates parser",
				.usage = "generate <FILE>",
				.options = (struct optparse_opt []) {
					{ CLI_HELP_OPTION },
					{ END_OF_OPTIONS },
				},
				.function = verbum_generate,
			},
			{ END_OF_SUBCOMMANDS },
		},


	};

#pragma GCC diagnostic pop

	optparse_parse(&verbum, &argc, &argv);

	return 0;
}

void verbum_generate(int argc, char **argv) {
	Parser *p = NULL;
	AST *ast = NULL;
	Analyzer *a = NULL;

	if(argc != 2) {
		fprintf(stderr, "Expected file got none!\n");
		exit(EXIT_FAILURE);
	}

	p = parser_new(argv[1]);
	ast = parser_parse(p);
	a = analyzer_new(ast);

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
/*
	for(TerminalDefinition *it = cvector_begin(a->terminals); it != cvector_end(a->terminals); it += 1) {
		printf("%s: %s\n", it->rule.token1.lexeme, it->pattern);
	}
*/
	CodeGenerator cg = code_generator_new(ast, a->start, a->tokens, a->sets, a->topterminals);

	code_generator_generate(cg);

	ast_print(ast);
	analyzer_delete(a);
	ast_delete(ast);
	parser_delete(p);


}
