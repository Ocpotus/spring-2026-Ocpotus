#include <stdio.h>
#include <stdbool.h>

#include "../../lib/hashmap.c/hashmap.h"
#include "../../lib/c-vector/cvector.h"

#include "../memory/memory.h"
#include "../ast/ast.h"
#include "../token/token.h"

#include "src_defines.h"

#include "code.h"


static const char *verbum_token_file_gperf = "verbum_token.gperf";
static const char *verbum_token_file_h = "verbum_token.h";
static const char *verbum_token_file_c = "verbum_token.c";
static const char *verbum_lexer_file_h = "verbum_lexer.h";
static const char *verbum_lexer_file_c = "verbum_lexer.c";
static const char *verbum_parser_file_h = "verbum_parser.h";
static const char *verbum_parser_file_c = "verbum_parser.c";
static const char *verbum_ast_file_h = "verbum_ast.h";
static const char *verbum_ast_file_c = "verbum_ast.c";
static const char *verbum_utf8_h_file = "utf8.h";
static const char *verbum_utf8file_file_h = "utf8file.h";
static const char *verbum_utf8file_file_c = "utf8file.c";
static const char *verbum_gperf_command_sh = "gperf -G -L ANSI-C -H token_hash_keyword -N token_is_keyword verbum_token.gperf > token.c";

static void generate_libraries(CodeGenerator *cg);
static void generate_tokens(CodeGenerator *cg);
static void generate_lexer(CodeGenerator *cg);
static void generate_ast(CodeGenerator *cg);
static void generate_parser(CodeGenerator *cg);

CodeGenerator code_generator_new(AST *ast, Rule start, struct hashmap *tokens, struct hashmap *firstFollowSets) {
	return (CodeGenerator) {
		.ast = ast,
		.start = start,
		.tokens = tokens,
		.firstFollowSets = firstFollowSets,
	};
}

void code_generator_generate(CodeGenerator cg) {
	generate_libraries(&cg);
	//generate_tokens(&cg);
	//generate_lexer(&cg);
	generate_ast(&cg);
	//generate_parser(&cg);
}

static void generate_libraries(CodeGenerator *cg) {
}

static void generate_tokens(CodeGenerator *cg) {
	FILE *fp = fopen(verbum_token_file_gperf, "w");

	if(fp != NULL) {
		void *item;
		size_t i = 0;

		fprintf(fp, "%%{#include <stdio.h>\n"
			    "#include <stdlib.h>\n"
			    "#include <string.h>\n"
			    "#include <stdbool.h>\n"
			    "#include \"../memory/memory.h\"\n"
			    "#include \"token.h\"\n"
			    "%%}\n");
		fprintf(fp, "%%%%\n");

		while(hashmap_iter(cg->tokens, &i, &item)) {
			Token *token = item;

			fputc('\"', fp);

			/* Step through each character to accomadate for quote or backslash for proper
			 * c strings, if not a lexeme of " will we result in """, and thus be an unclosed
			 * c string
			 */
			while(*(token->lexeme) != '\0') {
				// Prepend backslash
				if(*(token->lexeme) == '\\' || *(token->lexeme) == '\"') {
					fputc('\\', fp);
				}

				fputc(*(token->lexeme), fp);
				token->lexeme += 1;
			}

			fprintf(fp, "\"\n");
		}

		fprintf(fp, "%%%%\n");
		fclose(fp);
	}

	// For now, portability is not a concern.
#if defined(__linux__)
	// This is unsafe, but will do for now
	system(verbum_gperf_command_sh);
#elif defined(_WIN32) || defined(_WIN64)
	exit(0);
#endif
}
static void generate_lexer(CodeGenerator *cg) {
}



typedef enum MemberStat {
	MemberStat_Pointer = 0x1 << 0,
	MemberStat_Optional = 0x1 << 1,
	MemberStat_Repetition = 0x1 << 2,
	MemberStat_Token,
} MemberStat;

typedef struct MemberInfo {
	// Keys
	const char *type;
	bool stat;
	// Values
	int numNamed;
} MemberInfo;

static uint64_t member_info_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int member_info_compare(const void *a, const void *b, void *udata);

static void generate_rule(CodeGenerator *cg, Rule r);
static void generate_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members);
static void generate_list(CodeGenerator *cg, Rule r, List l, struct hashmap *members);
static void generate_term(CodeGenerator *cg, Rule r, Term t, struct hashmap *members);
static void generate_factor(CodeGenerator *cg, Rule r, Factor f, struct hashmap *members);

static void generate_ast(CodeGenerator *cg) {
	cg->fp = fopen(verbum_ast_file_h, "w+");

	if(cg->fp == NULL) {
		// Error
		return;
	}

	fprintf(cg->fp, "#include \"%s\"\n", verbum_token_file_h);

	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type != TokenType_Terminal_Identifier) {
			fprintf(cg->fp, "typedef struct %s %s;\n", it->token1.lexeme, it->token1.lexeme);
		}
	}

	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type != TokenType_Terminal_Identifier) {
			generate_rule(cg, *it);
		}
	}

	fclose(cg->fp);
}

static void generate_parser(CodeGenerator *cg) {
	cg->fp = fopen(verbum_parser_file_h, "w+");

	if(cg->fp == NULL) {
		// Error
		return;
	}

	fprintf(cg->fp, verbum_parser_file_h_contents, verbum_ast_file_h, verbum_lexer_file_h, verbum_token_file_h);
	fclose(cg->fp);
	cg->fp = fopen(verbum_parser_file_c, "w+");

	if(cg->fp == NULL) {
		// Error
		return;
	}

	fprintf(cg->fp, verbum_parser_file_c_contents, verbum_ast_file_h, verbum_lexer_file_h, verbum_token_file_h, verbum_parser_file_h);
	fclose(cg->fp);
}

static void generate_rule(CodeGenerator *cg, Rule r) {
	if(!cvector_empty(r.expression1->list2)) {
		fprintf(cg->fp, "typedef enum %c%sType {\n", r.token1.lexeme[0], r.token1.lexeme + 1);

		for(size_t i = 0; i < cvector_size(r.expression1->list2) + 1; i += 1) {
			fprintf(cg->fp, "%sType_%zu,\n", r.token1.lexeme, i);
		}

		fprintf(cg->fp, "} %sType;\n", r.token1.lexeme);
		fprintf(cg->fp, "typedef struct %s {\n", r.token1.lexeme);
		fprintf(cg->fp, "%sType tag;\n", r.token1.lexeme);

		struct hashmap *members = hashmap_new_with_allocator(
					 memory_new, memory_resize, memory_delete,
					 sizeof(MemberInfo), 0, 0, 0,
					 member_info_hash, member_info_compare, NULL, NULL);

		generate_expression(cg, r, *(r.expression1), members);
		fprintf(cg->fp, "} %s;\n", r.token1.lexeme);
		hashmap_free(members);
	} else {
		fprintf(cg->fp, "typedef struct %s {\n", r.token1.lexeme);
		struct hashmap *members = hashmap_new_with_allocator(
					 memory_new, memory_resize, memory_delete,
					 sizeof(MemberInfo), 0, 0, 0,
					 member_info_hash, member_info_compare, NULL, NULL);
		generate_expression(cg, r, *(r.expression1), members);
		fprintf(cg->fp, "} %s;\n", r.token1.lexeme);
		fputc('\n', cg->fp);
		hashmap_free(members);
	}
}

static void generate_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members) {
	if(cvector_size(e.list2) == 0) {
		generate_list(cg, r, e.list1, members);
	} else {
		fprintf(cg->fp, "union {\n");

		if(e.list1.term2 != NULL) {
			fprintf(cg->fp, "struct { ");
			generate_list(cg, r, e.list1, members); 
			fprintf(cg->fp, "} choice0;\n");
		} else {
			generate_list(cg, r, e.list1, members); 
		}

		for(List *it = cvector_begin(e.list2); it != cvector_end(e.list2); it += 1) {
			if(e.list1.term2 != NULL) {
				fprintf(cg->fp, "struct { ");
				generate_list(cg, r, *it, members); 
				fprintf(cg->fp, "} choice0;\n");
			} else {
				generate_list(cg, r, *it, members); 
			}
		}

		fprintf(cg->fp, "};\n");
	}
}

static void generate_list(CodeGenerator *cg, Rule r, List l, struct hashmap *members) {
	generate_term(cg, r, l.term1, members);

	for(Term *it = cvector_begin(l.term2); it != cvector_end(l.term2); it += 1) {
		generate_term(cg, r, *it, members);
	}
}

static void generate_term(CodeGenerator *cg, Rule r, Term t, struct hashmap *members) {
	generate_factor(cg, r, t.factor1, members);
}

static void generate_factor(CodeGenerator *cg, Rule r, Factor f, struct hashmap *members) {
	switch (f.tag) {
	case FactorType_NonTerminal_Identifier: {
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = f.nonterminal_identifier.lexeme,
					.stat = MemberStat_Pointer,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Pointer,
						.type = f.nonterminal_identifier.lexeme,
				};
				hashmap_set(members, mi);
				fprintf(cg->fp, "struct %s *%s%d;\n", 
				f.nonterminal_identifier.lexeme, 
				f.nonterminal_identifier.lexeme, mi->numNamed);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
				fprintf(cg->fp, "struct %s *%s%d;\n", 
				f.nonterminal_identifier.lexeme, 
				f.nonterminal_identifier.lexeme, mi2.numNamed);
			}
		}
		break;
	case FactorType_Terminal_Identifier: {
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = f.terminal_identifier.lexeme,
					.stat = MemberStat_Token,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Token,
						.type = f.terminal_identifier.lexeme,
				};
				hashmap_set(members, mi);
				fprintf(cg->fp, "Token %s%d;\n", f.terminal_identifier.lexeme, mi->numNamed);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
				fprintf(cg->fp, "Token %s%d;\n", f.terminal_identifier.lexeme, mi2.numNamed);
			}
		}
		break;
	case FactorType_Grouping:
		generate_expression(cg, r, *f.grouping, members);
		break;
	case FactorType_Literal:
		break;
	case FactorType_Repetition:
		fprintf(cg->fp, "cvector(struct %s_Item*) items;\n", r.token1.lexeme);
		break;
	case FactorType_Optional:
		fprintf(cg->fp, "struct %s_Opt *maybe_item;\n", r.token1.lexeme);
		break;
	default:
		break;
	}
}

static uint64_t member_info_hash(const void *item, uint64_t seed0, uint64_t seed1) {
	const MemberInfo *mi = item;

	return hashmap_sip(mi->type, strlen(mi->type), seed0, seed1);
}

static int member_info_compare(const void *a, const void *b, void *udata) {
	const MemberInfo *ua = a;
	const MemberInfo *ub = b;

	if(ua->stat == ub->stat) {
		return strcmp(ua->type, ub->type);
	}

	return 1;
}
