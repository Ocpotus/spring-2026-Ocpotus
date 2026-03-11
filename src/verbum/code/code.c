#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

#include "../../lib/hashmap.c/hashmap.h"
#include "../../lib/c-vector/cvector.h"

#include "../memory/memory.h"
#include "../ast/ast.h"
#include "../token/token.h"

#include "src_defines.h"

#include "code.h"


static const char *verbum_file_h = "verbum.h";
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

static void cg_generate_verbum(CodeGenerator *cg);
static void generate_tokens(CodeGenerator *cg);
static void generate_lexer(CodeGenerator *cg);
static void generate_ast(CodeGenerator *cg);
static void generate_ast_rule_function_new_signature(CodeGenerator *cg, Rule r, struct hashmap *members);
static void generate_ast_rule_function_new_definition(CodeGenerator *cg, Rule r, struct hashmap *members);
static void generate_ast_rule_function_delete_signature(CodeGenerator *cg, Rule r, struct hashmap *members);
static void generate_ast_rule_function_delete_definition(CodeGenerator *cg, Rule r, struct hashmap *members);
static void generate_parser(CodeGenerator *cg);
static void generate_repetition(CodeGenerator *cg, char c, size_t n);
static void generate_indent(CodeGenerator *cg);

static void cg_println(CodeGenerator *cg, const char *restrict format, ...);
static void cg_print(CodeGenerator *cg, const char *restrict format, ...);
static inline void cg_indent(CodeGenerator *cg);
static inline void cg_unindent(CodeGenerator *cg);
static inline void cg_newline(CodeGenerator *cg);
static bool cg_open(CodeGenerator *cg, const char *path);
static bool cg_close(CodeGenerator *cg);

CodeGenerator code_generator_new(AST *ast, Rule start, struct hashmap *tokens, struct hashmap *firstFollowSets) {
	return (CodeGenerator) {
		.ast = ast,
		.start = start,
		.tokens = tokens,
		.firstFollowSets = firstFollowSets,
		.indent = 0,
	};
}

void code_generator_generate(CodeGenerator cg) {
	cg_generate_verbum(&cg);
	//generate_tokens(&cg);
	//generate_lexer(&cg);
	generate_ast(&cg);
	//generate_parser(&cg);
}

static void cg_generate_verbum(CodeGenerator *cg) {
	if(cg_open(cg, verbum_file_h)) {
		cg_println(cg, "#ifndef VERBUM_H\n");
		cg_println(cg, "#define VERBUM_H\n");
		generate_repetition(cg, '\n', 1);
		cg_println(cg, "#include <stdint.h>\n");
		cg_println(cg, "#include <stdlib.h>\n");
		cg_println(cg, "#include <stdbool.h>");
		generate_repetition(cg, '\n', 2);
		cg_println(cg, verbum_file_h_contents);
		generate_repetition(cg, '\n', 2);
		cg_println(cg, "#endif");
		cg_close(cg);
	}
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
	MemberStat stat;
	// Values
	int numNamed;
} MemberInfo;

static uint64_t member_info_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int member_info_compare(const void *a, const void *b, void *udata);

static void generate_ast_rule_definition(CodeGenerator *cg, Rule r, struct hashmap *members);
static void generate_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members);
static void generate_list(CodeGenerator *cg, Rule r, List l, struct hashmap *members);
static void generate_term(CodeGenerator *cg, Rule r, Term t, struct hashmap *members);
static void generate_factor(CodeGenerator *cg, Rule r, Factor f, struct hashmap *members);

// This function is dumb... it opens h file writes and closes then opens c file writes and closes and repeats.
// but it suffices for now
static void generate_ast(CodeGenerator *cg) {
	cg->fp = fopen(verbum_ast_file_h, "w");

	if(cg->fp == NULL) {
		// Error
		return;
	}

	//cg_println(cg, "#include \"%s\"\n", verbum_token_file_h);
	cg_println(cg, "#ifndef VERBUM_AST_H\n");
	cg_println(cg, "#define VERBUM_AST_H\n");
	cg_println(cg, "#include \"%s\"\n", verbum_file_h);
	cg_println(cg, "typedef struct Token { int i;} Token;\n", verbum_token_file_h);

	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type != TokenType_Terminal_Identifier) {
			cg_println(cg, "typedef struct %s %s;\n", it->token1.lexeme, it->token1.lexeme);
		}
	}

	fclose(cg->fp);
	cg->fp = fopen(verbum_ast_file_c, "w");
	cg_println(cg, "#include \"%s\"\n", verbum_file_h);
	cg_println(cg, "#include \"%s\"\n", verbum_ast_file_h);
	generate_repetition(cg, '\n', 2);
	fclose(cg->fp);

	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type != TokenType_Terminal_Identifier) {
			struct hashmap *members = hashmap_new_with_allocator(
						  memory_new, memory_resize, memory_delete,
						  sizeof(MemberInfo), 0, 0, 0,
						  member_info_hash, member_info_compare, NULL, NULL);

			cg->fp = fopen(verbum_ast_file_h, "a");
			generate_ast_rule_definition(cg, *it, members);
			generate_ast_rule_function_new_signature(cg, *it, members);
			generate_ast_rule_function_delete_signature(cg, *it, members);
			fclose(cg->fp);
			cg->fp = fopen(verbum_ast_file_c, "a");
			generate_ast_rule_function_new_definition(cg, *it, members);
			generate_ast_rule_function_delete_definition(cg, *it, members);
			fclose(cg->fp);
			hashmap_free(members);
		}
	}

	fclose(cg->fp);
	cg->fp = fopen(verbum_ast_file_h, "a");
	cg_println(cg, "#endif");
	fclose(cg->fp);


	/* cg->fp = fopen(verbum_ast_file_c, "w+");

	if(cg->fp == NULL) {
		// Error
		return;
	}

	fclose(cg->fp); */
}

static void generate_ast_rule_function_new_signature(CodeGenerator *cg, Rule r, struct hashmap *members) {
	cvector(MemberInfo) mis = NULL;

	{
		size_t i = 0;
		void *item;

		while(hashmap_iter(members, &i, &item)) {
			const MemberInfo *mi = item;

			cvector_push_back(mis, *mi);
		}

	}

	cg_println(cg, "struct %s *verbum_ast_new_%s(struct VerbumContext *ctx, ", r.token1.lexeme, r.token1.lexeme);


	for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
		for(int i = 0; i < it->numNamed + 1; i += 1) {
			if(it->stat == MemberStat_Token) {
				cg_println(cg, "Token %s_%d", it->type, i);
			} else {
				cg_println(cg, "struct %s *%s_%d", it->type, it->type, i);
			}

			if(i != it->numNamed) {
				cg_println(cg, ", ");
			}
		}

		if(it + 1 != cvector_end(mis)) {
			cg_println(cg, ", ");
		}
	}

	cvector_free(mis);
	cg_println(cg, ");\n");
}

static void generate_ast_rule_function_new_definition(CodeGenerator *cg, Rule r, struct hashmap *members) {
	cvector(MemberInfo) mis = NULL;

	{
		size_t i = 0;
		void *item;

		while(hashmap_iter(members, &i, &item)) {
			const MemberInfo *mi = item;

			cvector_push_back(mis, *mi);
		}

	}

	cg_println(cg, "struct %s *verbum_ast_new_%s(struct VerbumContext *ctx, ", r.token1.lexeme, r.token1.lexeme);


	for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
		for(int i = 0; i < it->numNamed + 1; i += 1) {
			if(it->stat == MemberStat_Token) {
				cg_println(cg, "Token %s_%d", it->type, i);
			} else {
				cg_println(cg, "struct %s *%s_%d", it->type, it->type, i);
			}

			if(i != it->numNamed) {
				cg_println(cg, ", ");
			}
		}

		if(it + 1 != cvector_end(mis)) {
			cg_println(cg, ", ");
		}
	}

	cg_println(cg, ") {\n");
	cg_indent(cg);
	cg_println(cg, "struct %s *result = ctx->memory.new(sizeof(*result));\n", r.token1.lexeme);
	cg_newline(cg);
	cg_println(cg, "if(result != NULL) {\n");
	cg_indent(cg);

	for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
		for(int i = 0; i < it->numNamed + 1; i += 1) {
			if(it->stat == MemberStat_Token) {
				cg_println(cg, "result->%s_%d = %s_%d;\n", it->type, i, it->type, i);
			} else {
				cg_println(cg, "result->%s_%d = %s_%d;\n", it->type, i, it->type, i);
			}
		}
	}

	cg_unindent(cg);
	cg_println(cg, "}\n");
	cg_newline(cg);
	cg_println(cg, "return result;\n");
	cg_unindent(cg);
	cg_println(cg, "}\n");
	cvector_free(mis);
}

static void generate_ast_rule_function_delete_signature(CodeGenerator *cg, Rule r, struct hashmap *members) {
	cg_println(cg, "void verbum_ast_delete_%s(struct VerbumContext *ctx, struct %s *d);\n", r.token1.lexeme, r.token1.lexeme);
}

static void generate_ast_rule_function_delete_definition(CodeGenerator *cg, Rule r, struct hashmap *members) {
	cg_println(cg, "void verbum_ast_delete_%s(struct VerbumContext *ctx, struct %s *%s) {\n", r.token1.lexeme, r.token1.lexeme, r.token1.lexeme);
	cg_indent(cg);

	cvector(MemberInfo) mis = NULL;

	{
		size_t i = 0;
		void *item;

		while(hashmap_iter(members, &i, &item)) {
			const MemberInfo *mi = item;

			cvector_push_back(mis, *mi);
		}

		for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
			for(int i = 0; i < it->numNamed + 1; i += 1) {
				if(it->stat == MemberStat_Token) {
					//cg_println(cg, "result->%s_%d = %s_%d;\n", it->type, i, it->type, i);
				} else {
					cg_println(cg, "ctx->memory.delete(%s->%s_%d);\n", r.token1.lexeme, it->type, i);
				}
			}
		}

		cvector_free(mis);
	}

	cg_println(cg, "ctx->memory.delete(%s);\n", r.token1.lexeme);

	cg_unindent(cg);
	cg_println(cg, "}\n");
}

static void generate_parser(CodeGenerator *cg) {
	cg->fp = fopen(verbum_parser_file_h, "w+");

	if(cg->fp == NULL) {
		// Error
		return;
	}

	cg_println(cg, verbum_parser_file_h_contents, verbum_ast_file_h, verbum_lexer_file_h, verbum_token_file_h);
	fclose(cg->fp);
	cg->fp = fopen(verbum_parser_file_c, "w+");

	if(cg->fp == NULL) {
		// Error
		return;
	}

	cg_println(cg, verbum_parser_file_c_contents, verbum_ast_file_h, verbum_lexer_file_h, verbum_token_file_h, verbum_parser_file_h);
	fclose(cg->fp);
}

static void generate_ast_rule_definition(CodeGenerator *cg, Rule r, struct hashmap *members) {
	if(!cvector_empty(r.expression1->list2)) {
		int offset = 0;
		cg_println(cg, "typedef enum %c%sType {\n", r.token1.lexeme[0], r.token1.lexeme + 1);
		cg_indent(cg);

		/* if(r.expression1->list1.term1.factor1.tag != FactorType_Literal &&
		   r.expression1->list1.term1.factor1.tag != FactorType_Epsilon) { */
			cg_println(cg, "%sType_%zu,\n", r.token1.lexeme, (size_t) 0);
			offset = 1;
		//}

		for(List *it = cvector_begin(r.expression1->list2); it != cvector_end(r.expression1->list2); it += 1) {
			//if(it->term1.factor1.tag != FactorType_Literal && it->term1.factor1.tag != FactorType_Epsilon) {
				cg_println(cg, "%sType_%zu,\n",
					     r.token1.lexeme,
					     it - cvector_begin(r.expression1->list2) + offset);
			//}
		}

		cg_unindent(cg);
		cg_println(cg, "} %sType;\n", r.token1.lexeme);
		cg_println(cg, "typedef struct %s {\n", r.token1.lexeme);
		cg_indent(cg);
		cg_println(cg, "%sType tag;\n", r.token1.lexeme);
		generate_expression(cg, r, *(r.expression1), members);
		cg_unindent(cg);
		cg_println(cg, "} %s;\n", r.token1.lexeme);

	} else {
		cg_println(cg, "typedef struct %s {\n", r.token1.lexeme);
		cg_indent(cg);
		generate_expression(cg, r, *(r.expression1), members);
		cg_unindent(cg);
		cg_println(cg, "} %s;\n", r.token1.lexeme);
		fputc('\n', cg->fp);
	}
}

static void generate_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members) {
	if(cvector_size(e.list2) == 0) {
		generate_list(cg, r, e.list1, members);
	} else {
		int offset = 0;

		cg_println(cg, "union {\n");
		cg_indent(cg);

		if(e.list1.term2 != NULL) {
			/* if(e.list1.term2->factor1.tag != FactorType_Literal &&
			   e.list1.term2->factor1.tag != FactorType_Epsilon) { */
				generate_list(cg, r, e.list1, members); 
				offset += 1;
			//}
		} else {
			generate_list(cg, r, e.list1, members); 
		}

		for(List *it = cvector_begin(e.list2); it != cvector_end(e.list2); it += 1) {
			if(e.list1.term2 != NULL) {//&&
			   /* e.list1.term2->factor1.tag != FactorType_Literal &&
			   e.list1.term2->factor1.tag != FactorType_Epsilon) { */
				generate_list(cg, r, *it, members); 
			} else {
				generate_list(cg, r, *it, members); 
			}

		}

		cg_unindent(cg);
		cg_println(cg, "};\n");
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
				cg_println(cg, "struct %s *%s_%d;\n", 
				f.nonterminal_identifier.lexeme, 
				f.nonterminal_identifier.lexeme, mi->numNamed);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
				cg_println(cg, "struct %s *%s_%d;\n", 
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
				cg_println(cg, "Token %s_%d;\n", f.terminal_identifier.lexeme, mi->numNamed);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
				cg_println(cg, "Token %s_%d;\n", f.terminal_identifier.lexeme, mi2.numNamed);
			}
		}
		break;
	case FactorType_Grouping:
		generate_expression(cg, r, *f.grouping, members);
		break;
	case FactorType_Literal:
		break;
	case FactorType_Repetition:
		break;
	case FactorType_Optional:
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

static void generate_repetition(CodeGenerator *cg, char c, size_t n) {
	while(n != 0) {
		fputc(c, cg->fp);
		n -= 1;
	}
}

static void generate_indent(CodeGenerator *cg) {
	generate_repetition(cg, '\t', cg->indent);
}

static void cg_println(CodeGenerator *cg, const char *restrict format, ...) {
	va_list args;

	va_start(args, format);
	generate_indent(cg);
	vfprintf(cg->fp, format, args);
	va_end(args);
}

static void cg_print(CodeGenerator *cg, const char *restrict format, ...) {
	va_list args;

	va_start(args, format);
	vfprintf(cg->fp, format, args);
	va_end(args);
}

static inline void cg_indent(CodeGenerator *cg) {
	cg->indent += 1;
}

static inline void cg_unindent(CodeGenerator *cg) {
	cg->indent -= 1;
}

static inline void cg_newline(CodeGenerator *cg) {
	cg_println(cg, "\n");
}

static bool cg_open(CodeGenerator *cg, const char *path) {
	cg->fp = fopen(path, "w+");

	return cg->fp != NULL;
}

static bool cg_close(CodeGenerator *cg) {
	if(cg->fp == NULL) {
		return false;
	}

	return fclose(cg->fp) == 0;
}
