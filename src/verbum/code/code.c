#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

#include "../../lib/hashmap.c/hashmap.h"
#include "../../lib/c-vector/cvector.h"

#include "../memory/memory.h"
#include "../ast/ast.h"
#include "../token/token.h"
#include "../analysis/analysis.h"

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
static const char *verbum_gperf_command_sh = "gperf -G -L ANSI-C -H verbum_token_hash -N verbum_token_in_language verbum_token.gperf > verbum_token.c";

/* Generation functions */
static void cg_generate_verbum(CodeGenerator *cg);
static void cg_generate_tokens(CodeGenerator *cg);
static void cg_generate_lexer(CodeGenerator *cg);
static void cg_generate_ast(CodeGenerator *cg);
static void cg_generate_token_function(CodeGenerator *cg, Rule *r);

static void generate_ast_rule_function_new_signature(CodeGenerator *cg, Rule r, struct hashmap *members, bool isUnion);
static void generate_ast_rule_function_new_definition(CodeGenerator *cg, Rule r, struct hashmap *members, bool isUnion);
static void generate_ast_rule_function_delete_signature(CodeGenerator *cg, Rule r, struct hashmap *members);
static void generate_ast_rule_function_delete_definition(CodeGenerator *cg, Rule r, struct hashmap *members);
static void cg_generate_parser(CodeGenerator *cg);
static void generate_repetition(CodeGenerator *cg, char c, size_t n);
static void generate_indent(CodeGenerator *cg);

/* CodeGenerator utilities */
static bool cg_open(CodeGenerator *cg, const char *path);
static bool cg_close(CodeGenerator *cg);
static void cg_put(CodeGenerator *cg, const char c);
static void cg_println(CodeGenerator *cg, const char *restrict format, ...);
static void cg_print(CodeGenerator *cg, const char *restrict format, ...);
static inline void cg_newline(CodeGenerator *cg);
static inline void cg_indent(CodeGenerator *cg);
static inline void cg_unindent(CodeGenerator *cg);

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
	cg_generate_tokens(&cg);
	cg_generate_lexer(&cg);
	cg_generate_ast(&cg);
	cg_generate_parser(&cg);
}

static void cg_generate_verbum(CodeGenerator *cg) {
	if(cg_open(cg, verbum_file_h)) {
		cg_println(cg, "#ifndef VERBUM_H");
		cg_println(cg, "#define VERBUM_H");
		cg_newline(cg);
		cg_println(cg, "#include <stdint.h>");
		cg_println(cg, "#include <stdlib.h>");
		cg_println(cg, "#include <stdbool.h>");
		cg_newline(cg);
		cg_newline(cg);
		cg_println(cg, verbum_file_h_contents);
		cg_newline(cg);
		cg_newline(cg);
		cg_println(cg, "#endif");
		cg_close(cg);
	}
}

static void cg_generate_tokens(CodeGenerator *cg) {
	if(cg_open(cg, verbum_token_file_h)) {
		cg_println(cg, "#ifndef VERBUM_TOKEN_H");
		cg_println(cg, "#define VERBUM_TOKEN_H");
		cg_newline(cg);
		cg_println(cg, "#include <stdint.h>");
		cg_newline(cg);
		cg_println(cg, "#include \"verbum.h\"");
		cg_newline(cg);
		cg_newline(cg);
		cg_println(cg, "typedef const char *Lexeme;");
		cg_newline(cg);
		cg_println(cg, "typedef enum TokenType {");
		cg_indent(cg);
		cg_println(cg, "TokenType_Invalid = -3,");
		cg_println(cg, "TokenType_Whitespace = -2,");
		cg_println(cg, "TokenType_EOF = -1,");

		for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
			if(it->token1.type == TokenType_Terminal_Identifier) {
				cg_println(cg, "TokenType_%s,", it->token1.lexeme);
			}
		}

		cg_println(cg, "TokenType_Keyword,");
		cg_unindent(cg);
		cg_println(cg, "} TokenType;");
		cg_newline(cg);
		cg_println(cg, "typedef struct Token {");
		cg_indent(cg);
		cg_println(cg, "Lexeme lexeme;");
		cg_println(cg, "TokenType tag;");
		cg_println(cg, "struct {");
		cg_indent(cg);
		cg_println(cg, "uint32_t row;");
		cg_println(cg, "uint32_t col;");
		cg_unindent(cg);
		cg_println(cg, "} pos;");
		cg_unindent(cg);
		cg_println(cg, "} Token;");
		cg_newline(cg);
		cg_println(cg, "void token_delete(VerbumContext *ctx, Token t);");
		cg_newline(cg);
		cg_println(cg, "const char *verbum_token_in_language(register const char *str, register size_t len);");
		cg_println(cg, "TokenType verbum_token_get_keyword_type(const char *lexeme);");
		cg_println(cg, "TokenType verbum_token_get_lexeme_type(const char *lexeme);");
		cg_newline(cg);
		cg_newline(cg);
		cg_println(cg, "#endif");
		cg_close(cg);
	}

	if(cg_open(cg, verbum_token_file_gperf)) {
		void *item;
		size_t i = 0;

		cg_println(cg, "%%{");
		cg_println(cg, "#include <stdio.h>");
		cg_println(cg, "#include <stdlib.h>");
		cg_println(cg, "#include <string.h>");
		cg_println(cg, "#include <stdbool.h>");
		cg_newline(cg);
		cg_println(cg, "#include \"verbum.h\"");
		cg_println(cg, "#include \"verbum_token.h\"");
		cg_println(cg, "%%}");
		cg_println(cg, "%%%%");

		while(hashmap_iter(cg->tokens, &i, &item)) {
			Token *token = item;

			cg_put(cg, '\"');

			/* Step through each character to accomadate for quote or backslash for proper
			 * c strings, if not a lexeme of " will we result in """, and thus be an unclosed
			 * c string
			 */
			while(*(token->lexeme) != '\0') {
				// Prepend backslash
				if(*(token->lexeme) == '\\' || *(token->lexeme) == '\"') {
					cg_put(cg, '\\');
				}

				cg_put(cg, *(token->lexeme));
				token->lexeme += 1;
			}

			cg_println(cg, "\"");
		}

		cg_println(cg, "%%%%");
		cg_println(cg, "TokenType verbum_token_get_keyword_type(const char *lexeme) {");
		cg_indent(cg);
		cg_println(cg, "if(verbum_token_in_language(lexeme, strlen(lexeme)) != NULL) {");
		cg_indent(cg);
		cg_println(cg, "return verbum_token_hash(lexeme, strlen(lexeme)) + TokenType_Keyword;");
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_newline(cg);
		cg_println(cg, "return TokenType_Invalid;");
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_newline(cg);
		cg_println(cg, "TokenType verbum_token_get_lexeme_type(const char *lexeme) {");
		cg_indent(cg);
		cg_println(cg, "if(verbum_token_in_language(lexeme, strlen(lexeme)) != NULL) {");
		cg_indent(cg);
		cg_println(cg, "return verbum_token_hash(lexeme, strlen(lexeme)) + TokenType_Keyword;");
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_newline(cg);
		cg_println(cg, "return verbum_token_hash(lexeme, strlen(lexeme));");
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_close(cg);
	}

	// For now, portability is not a concern.
#if defined(__linux__)
	// This is unsafe, but will do for now
	system(verbum_gperf_command_sh);
#elif defined(_WIN32) || defined(_WIN64)
	exit(0);
#endif
}
static void cg_generate_lexer(CodeGenerator *cg) {
	if(cg_open(cg, verbum_lexer_file_h)) {
		cg_println(cg, verbum_lexer_file_h_contents);
		cg_close(cg);
	}

	if(cg_open(cg, verbum_lexer_file_c)) {
		cg_println(cg, verbum_lexer_file_c_contents);

		for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
			if(it->token1.type == TokenType_Terminal_Identifier) {
				cg_generate_token_function(cg, it);
			}
		}

		// Generate other functions
		cg_close(cg);
	}
}

typedef enum MemberStat {
	MemberStat_Pointer = 0x1 << 0,
	MemberStat_Optional = 0x1 << 1,
	MemberStat_Repetition = 0x1 << 2,
	MemberStat_Token = 0x1 << 3,
	MemberStat_Literal = 0x1 << 4,
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
static void cg_generate_ast_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members);
static void cg_generate_ast_list(CodeGenerator *cg, Rule r, List l, struct hashmap *members);
static void cg_generate_ast_term(CodeGenerator *cg, Rule r, Term t, struct hashmap *members);
static void cg_generate_ast_factor(CodeGenerator *cg, Rule r, Factor f, struct hashmap *members);

// This function is dumb... it opens h file writes and closes then opens c file writes and closes and repeats.
// but it suffices for now
static void cg_generate_ast(CodeGenerator *cg) {
	if(!cg_open(cg, verbum_ast_file_h)) {
		// Error
		return;
	}

	cg_println(cg, "#ifndef VERBUM_AST_H");
	cg_println(cg, "#define VERBUM_AST_H");
	cg_println(cg, "#include \"verbum.h\"");
	cg_println(cg, "#include \"verbum_token.h\"");

	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type != TokenType_Terminal_Identifier) {
			cg_println(cg, "typedef struct %s %s;", it->token1.lexeme, it->token1.lexeme);
		}
	}

	cg_close(cg);

	if(!cg_open(cg, verbum_ast_file_c)) {
		// Error
		return;
	}
	
	cg_println(cg, "#include \"verbum.h\"");
	cg_println(cg, "#include \"verbum_ast.h\"");
	cg_newline(cg);
	cg_newline(cg);
	cg_close(cg);

	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type != TokenType_Terminal_Identifier) {
			struct hashmap *members = hashmap_new_with_allocator(
						  memory_new, memory_resize, memory_delete,
						  sizeof(MemberInfo), 0, 0, 0,
						  member_info_hash, member_info_compare, NULL, NULL);

			cg->fp = fopen(verbum_ast_file_h, "a");
			generate_ast_rule_definition(cg, *it, members);
			generate_ast_rule_function_new_signature(cg, *it, members, it->expression1->list2 != NULL);
			generate_ast_rule_function_delete_signature(cg, *it, members);
			fclose(cg->fp);
			cg->fp = fopen(verbum_ast_file_c, "a");
			generate_ast_rule_function_new_definition(cg, *it, members, it->expression1->list2 != NULL);
			generate_ast_rule_function_delete_definition(cg, *it, members);
			fclose(cg->fp);
			hashmap_free(members);
		}
	}

	cg->fp = fopen(verbum_ast_file_h, "a");
	cg_println(cg, "typedef %s *AST;", cg->start.token1.lexeme);
	cg_newline(cg);
	cg_println(cg, "#endif");
	cg_close(cg);
}

static void cg_generate_token_function(CodeGenerator *cg, Rule *r) {
	cg_println(cg, "static Token verbum_lexer_lex_%s(Lexer *l) {", r->token1.lexeme);
	cg_indent(cg);
	cg_println(cg, "Token result = { 0 };");
	cg_newline(cg);
	cg_println(cg, "return result;");
	cg_unindent(cg);
	cg_println(cg, "}");
	cg_newline(cg);
}

/* Parser generation */
static void cg_generate_parser_rule(CodeGenerator *cg, Rule *r);
static void cg_generate_parser_expression(CodeGenerator *cg, Rule *r, Expression *e, struct hashmap *members);
static void cg_generate_parser_expression2(CodeGenerator *cg, Rule *r, Expression *e, struct hashmap *members);
static void cg_generate_parser_list(CodeGenerator *cg, Rule *r, List *l, size_t choice, bool multipleChoice, struct hashmap *members);
static void cg_generate_parser_term(CodeGenerator *cg, Rule *r, Term *t, size_t choice, bool multipleChoice, struct hashmap *members);
static void cg_generate_parser_factor(CodeGenerator *cg, Rule *r, Factor *f, size_t choice, bool multipleChoice, struct hashmap *members);

static void cg_generate_parser_rule(CodeGenerator *cg, Rule *r) {
	struct hashmap *members = NULL;

	cg_println(cg, "static %s *parser_parse_%s(Parser *p) {", r->token1.lexeme, r->token1.lexeme);
	cg_indent(cg);
	cg_println(cg, "%s *result = NULL;", r->token1.lexeme);
	cg_newline(cg);
	members = hashmap_new_with_allocator(memory_new, memory_resize, memory_delete,
					     sizeof(MemberInfo), 0, 0, 0,
					     member_info_hash, member_info_compare, NULL, NULL);
	cg_generate_parser_expression2(cg, r, r->expression1, members);
	hashmap_free(members);
	cg_println(cg, "return result;");
	cg_unindent(cg);
	cg_println(cg, "}");
	cg_newline(cg);
}

static size_t cg_generate_parser_condition(CodeGenerator *cg, Rule *r, List *l) {
	size_t result = 0;
	cvector(Term) tl = NULL;
	cvector_copy(l->term2, tl);
	cvector_insert(tl, 0, l->term1);
	bool first = true;

	for(Term *it = cvector_begin(tl); it != cvector_end(tl); it += 1) {
		bool isNullable = false;

		switch(it->factor1.tag) {
		case FactorType_Literal:
			if(!first) {
				cg_print(cg, " , ");
			}

			cg_print(cg, "verbum_token_get_lexeme_type(\"%s\")", it->factor1.literal.lexeme);
			result += 1;
			goto EXIT;
			break;
		case FactorType_Terminal_Identifier:
			if(!first) {
				cg_print(cg, " , ");
			}

			cg_print(cg, "TokenType_%s", it->factor1.terminal_identifier.lexeme);
			result += 1;
			goto EXIT;
			break;
		case FactorType_NonTerminal_Identifier: {
				const FirstFollowSet *ffs = hashmap_get(cg->firstFollowSets,
								       &(FirstFollowSet) { .t = it->factor1.nonterminal_identifier} );

				if(ffs != NULL) {
					size_t i = 0;
					void *item;

					while(hashmap_iter(ffs->firsts, &i, &item)) {
						Token *t = item;

						if(!first) {
							cg_print(cg, " , ");
						}

						if(t->type == TokenType_Terminal_Identifier) {
							cg_print(cg, "TokenType_%s", t->lexeme);
							result += 1;
						} else {
							cg_print(cg, "verbum_token_get_lexeme_type(\"%s%s\")",
									t->lexeme[0] == '"' ? "\\" : "", t->lexeme);
							result += 1;
						}

						first = false;
					}


					if(ffs->nullable) {
						void *item;
						size_t i = 0;

						isNullable = true;

						while(hashmap_iter(ffs->follows, &i, &item)) {
							Token *t = item;

							if(!first) {
								cg_print(cg, " , ");
							}

							if(t->type == TokenType_Terminal_Identifier) {
								result += 1;
								cg_print(cg, "TokenType_%s", t->lexeme);
							} else {
								result += 1;
								cg_print(cg, "verbum_token_get_lexeme_type(\"%s%s\")",
										t->lexeme[0] == '"' ? "\\" : "", t->lexeme);

							}

							first = false;
						}
					}
				}
			}
			break;
		default:
			break;
		}

		if(!isNullable) {
			break;
		}

		first = false;
	}

EXIT:
	cvector_free(tl);

	return result;
}

static void cg_generate_parser_expression2(CodeGenerator *cg, Rule *r, Expression *e, struct hashmap *members) {
	if(!cvector_empty(e->list2)) {
		size_t count = 0;
		generate_indent(cg);
		cg_print(cg, "if(parser_match_any(p, (TokenType []) { ");
		count = cg_generate_parser_condition(cg, r, &e->list1);
		cg_print(cg, " }, %zu)) {", count);
		cg_newline(cg);
		cg_indent(cg);
		cg_println(cg, "result = p->ctx->memory.new(1 * sizeof(*result));");
		cg_newline(cg);
		cg_println(cg, "if(result != NULL) {");
		cg_indent(cg);
		cg_generate_parser_list(cg, r, &e->list1, 0, true, members);
		cg_println(cg, "result->tag = %sType_0;", r->token1.lexeme);
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_unindent(cg);
		generate_indent(cg);
		cg_print(cg, "}");

		for(List *it = cvector_begin(e->list2); it != cvector_end(e->list2); it += 1) {
			if(it->term1.factor1.tag == FactorType_Epsilon) {
				cg_print(cg, " else {");
				cg_newline(cg);
			} else {
				cg_print(cg, " else if(parser_match_any(p, (TokenType []) { ");
				count = cg_generate_parser_condition(cg, r, it);
				cg_print(cg, " }, %zu)) {", count);
				cg_newline(cg);
			}

			cg_indent(cg);
			cg_println(cg, "result = p->ctx->memory.new(sizeof(*result));");
			cg_newline(cg);
			cg_println(cg, "if(result != NULL) {");
			cg_indent(cg);
			cg_generate_parser_list(cg, r, it, it - cvector_begin(e->list2) + 1, true, members);
			cg_println(cg, "result->tag = %sType_%zu;", r->token1.lexeme, it - cvector_begin(e->list2) + 1);
			cg_unindent(cg);
			cg_println(cg, "}");
			cg_unindent(cg);
			generate_indent(cg);
			cg_print(cg, "}");
		}

		cg_newline(cg);
	} else {
		cg_println(cg, "result = p->ctx->memory.new(1 * sizeof(*result));");
		cg_newline(cg);
		cg_println(cg, "if(result != NULL) {");
		cg_indent(cg);
		cg_indent(cg);
		cg_generate_parser_list(cg, r, &e->list1, 0, false, members);
		cg_unindent(cg);
		cg_unindent(cg);
		cg_println(cg, "}");
	}

	cg_newline(cg);
}

static void cg_generate_parser_expression(CodeGenerator *cg, Rule *r, Expression *e, struct hashmap *members) {
	size_t lexeme_count = 0;

	generate_indent(cg);
	cg_print(cg, "if(parser_match_any(p, (TokenType[]) { ");
	lexeme_count = cg_generate_parser_condition(cg, r, &e->list1);
	cg_print(cg, " }, %zu)) {\n", lexeme_count);
	cg_indent(cg);
	cg_println(cg, "result = p->ctx->memory.new(1 * sizeof(*result));");
	cg_newline(cg);
	cg_println(cg, "if(result != NULL) {");
	cg_indent(cg);
	cg_generate_parser_list(cg, r, &e->list1, 0, e->list2 != NULL, members);

	if(e->list2 != NULL) {
		cg_println(cg, "result->tag = %sType_0;", r->token1.lexeme);
	}

	cg_unindent(cg);
	cg_println(cg, "}");
	cg_unindent(cg);

	for(List *it = cvector_begin(e->list2); it != cvector_end(e->list2); it += 1) {
		if(it->term1.factor1.tag != FactorType_Epsilon) {
			generate_indent(cg);
			cg_print(cg, "} else if(parser_match_any(p, (TokenType[]) { ");
			lexeme_count = cg_generate_parser_condition(cg, r, it);
			cg_print(cg, " }, %zu)) {", lexeme_count);
			cg_newline(cg);
			cg_indent(cg);
			cg_println(cg, "result = p->ctx->memory.new(1 * sizeof(*result));");
			cg_newline(cg);
			cg_println(cg, "if(result != NULL) {");
			cg_indent(cg);
			cg_generate_parser_list(cg, r, it, it - cvector_begin(e->list2) + 1, true, members);
			cg_println(cg, "result->tag = %sType_%zu;", r->token1.lexeme, it - cvector_begin(e->list2) + 1);
			cg_unindent(cg);
			cg_println(cg, "}");
			cg_unindent(cg);
		}
	}

	cg_println(cg, "}");
	cg_newline(cg);
}

static void cg_generate_parser_list(CodeGenerator *cg, Rule *r, List *l, size_t choice, bool multipleChoice, struct hashmap *members) {
	cg_generate_parser_term(cg, r, &l->term1, choice, multipleChoice, members);

	for(Term *it = cvector_begin(l->term2); it != cvector_end(l->term2); it += 1) {
		cg_generate_parser_term(cg, r, it, choice, multipleChoice, members);
	}
}

static void cg_generate_parser_term(CodeGenerator *cg, Rule *r, Term *t, size_t choice, bool multipleChoice, struct hashmap *members) {
	cg_generate_parser_factor(cg, r, &t->factor1, choice, multipleChoice, members);

	if(optional_is_valid(t->factor2)) {
		cg_generate_parser_factor(cg, r, t->factor2, choice, multipleChoice, members);
	}
}

static void cg_generate_parser_factor(CodeGenerator *cg, Rule *r, Factor *f, size_t choice, bool multipleChoice, struct hashmap *members) {


	switch(f->tag) {
	case FactorType_NonTerminal_Identifier: {
			const FirstFollowSet *ffs = hashmap_get(cg->firstFollowSets, &(FirstFollowSet) { .t = f->nonterminal_identifier });
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = f->nonterminal_identifier.lexeme,
					.stat = MemberStat_Pointer,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Pointer,
						.type = f->nonterminal_identifier.lexeme,
				};
				hashmap_set(members, mi);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
			}

			mi = hashmap_get(members, &(MemberInfo) {
					.type = f->nonterminal_identifier.lexeme,
					.stat = MemberStat_Pointer,
					});

			if(multipleChoice) {
				cg_println(cg, "result->choice%zu.%s_%d = parser_parse_%s(p);", 
				choice, f->nonterminal_identifier.lexeme, mi->numNamed, f->nonterminal_identifier.lexeme);

				if(!ffs->nullable) {
					cg_newline(cg);
					cg_println(cg, "if(result->choice%zu.%s_%d == NULL) {",
							choice, f->nonterminal_identifier.lexeme, mi->numNamed);
				}
			} else {
				cg_println(cg, "result->%s_%d = parser_parse_%s(p);", 
				f->nonterminal_identifier.lexeme, mi->numNamed, f->nonterminal_identifier.lexeme);

				if(!ffs->nullable) {
					cg_newline(cg);
					cg_println(cg, "if(result->%s_%d == NULL) {",
							f->nonterminal_identifier.lexeme, mi->numNamed);
				}
			}

			if(!ffs->nullable) {
				cg_indent(cg);
				cg_println(cg, "verbum_ast_delete_%s(p->ctx, result);", r->token1.lexeme);
				cg_newline(cg);
				cg_println(cg, "//Error");
				cg_println(cg, "return NULL;");
				cg_unindent(cg);
				cg_println(cg, "}");
				cg_newline(cg);
			}
		}
		break;
	case FactorType_Terminal_Identifier: {
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = f->terminal_identifier.lexeme,
					.stat = MemberStat_Token,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Token,
						.type = f->terminal_identifier.lexeme,
				};
				hashmap_set(members, mi);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
			}

			mi = hashmap_get(members, &(MemberInfo) {
					.type = f->terminal_identifier.lexeme,
					.stat = MemberStat_Token,
					});

			cg_println(cg, "if(!parser_match(p, TokenType_%s)) {", f->literal.lexeme);
			cg_indent(cg);
			cg_println(cg, "verbum_ast_delete_%s(p->ctx, result);", r->token1.lexeme);
			cg_println(cg, "//Error");
			cg_println(cg, "return NULL;");
			cg_unindent(cg);
			cg_println(cg, "}");
			cg_newline(cg);

			if(multipleChoice) {
				cg_println(cg, "result->choice%zu.%s_%d = parser_previous(p);",
				choice, f->terminal_identifier.lexeme, mi->numNamed);
			} else {
				cg_println(cg, "result->%s_%d = parser_previous(p);",
				f->terminal_identifier.lexeme, mi->numNamed);
			}
		}
		break;
	case FactorType_Literal: {
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = "literal",
					.stat = MemberStat_Literal,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Literal,
						.type = "literal",
				};
				hashmap_set(members, mi);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
			}

			mi = hashmap_get(members, &(MemberInfo) {
					.type = "literal",
					.stat = MemberStat_Literal,
					});

			cg_println(cg, "if(!parser_match(p, verbum_token_get_lexeme_type(\"%s\"))) {", f->literal.lexeme);
			cg_indent(cg);
			cg_println(cg, "verbum_ast_delete_%s(p->ctx, result);", r->token1.lexeme);
			cg_println(cg, "//Error");
			cg_println(cg, "return NULL;");
			cg_unindent(cg);
			cg_println(cg, "}");
			cg_newline(cg);

			if(multipleChoice) {
				cg_println(cg, "result->choice%zu.literal_%d = parser_previous(p);",
				choice, mi->numNamed);
			} else {
				cg_println(cg, "result->literal_%d = parser_previous(p);",
				mi->numNamed);
			}
		}
		break;
	default:
		break;
	}
}

static void generate_ast_rule_function_new_signature(CodeGenerator *cg, Rule r, struct hashmap *members, bool isUnion) {
	cvector(MemberInfo) mis = NULL;

	{
		size_t i = 0;
		void *item;

		while(hashmap_iter(members, &i, &item)) {
			const MemberInfo *mi = item;

			cvector_push_back(mis, *mi);
		}

	}

	cg_print(cg, "struct %s *verbum_ast_new_%s(struct VerbumContext *ctx, ", r.token1.lexeme, r.token1.lexeme);

	if(isUnion) {
		cg_print(cg, "%sType tag, ", r.token1.lexeme);
	}


	for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
		for(int i = 0; i < it->numNamed + 1; i += 1) {
			if(it->stat == MemberStat_Token || it->stat == MemberStat_Literal) {
				cg_print(cg, "Token %s_%d", it->type, i);
			} else {
				cg_print(cg, "struct %s *%s_%d", it->type, it->type, i);
			}

			if(i != it->numNamed) {
				cg_print(cg, ", ");
			}
		}

		if(it + 1 != cvector_end(mis)) {
			cg_print(cg, ", ");
		}
	}

	cvector_free(mis);
	cg_println(cg, ");");
}

static void generate_ast_rule_function_new_definition(CodeGenerator *cg, Rule r, struct hashmap *members, bool isUnion) {
	cvector(MemberInfo) mis = NULL;

	{
		size_t i = 0;
		void *item;

		while(hashmap_iter(members, &i, &item)) {
			const MemberInfo *mi = item;

			cvector_push_back(mis, *mi);
		}

	}

	cg_print(cg, "struct %s *verbum_ast_new_%s(struct VerbumContext *ctx, ", r.token1.lexeme, r.token1.lexeme);

	if(isUnion) {
		cg_print(cg, "%sType tag, ", r.token1.lexeme);
	}

	for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
		for(int i = 0; i < it->numNamed + 1; i += 1) {
			if(it->stat == MemberStat_Token || it->stat == MemberStat_Literal) {
				cg_print(cg, "Token %s_%d", it->type, i);
			} else {
				cg_print(cg, "struct %s *%s_%d", it->type, it->type, i);
			}

			if(i != it->numNamed) {
				cg_print(cg, ", ");
			}
		}

		if(it + 1 != cvector_end(mis)) {
			cg_print(cg, ", ");
		}
	}

	cg_println(cg, ") {");
	cg_indent(cg);
	cg_println(cg, "struct %s *result = ctx->memory.new(sizeof(*result));\n", r.token1.lexeme);
	cg_newline(cg);
	cg_println(cg, "if(result != NULL) {");
	cg_indent(cg);

	for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
		for(int i = 0; i < it->numNamed + 1; i += 1) {
			if(it->stat == MemberStat_Token) {
				cg_println(cg, "result->%s_%d = %s_%d;", it->type, i, it->type, i);
			} else {
				cg_println(cg, "result->%s_%d = %s_%d;", it->type, i, it->type, i);
			}
		}
	}

	cg_unindent(cg);
	cg_println(cg, "}");
	cg_newline(cg);
	cg_println(cg, "return result;");
	cg_unindent(cg);
	cg_println(cg, "}");
	cvector_free(mis);
}

static void generate_ast_rule_function_delete_signature(CodeGenerator *cg, Rule r, struct hashmap *members) {
	cg_println(cg, "void verbum_ast_delete_%s(struct VerbumContext *ctx, struct %s *d);", r.token1.lexeme, r.token1.lexeme);
}

static void generate_ast_rule_function_delete_definition(CodeGenerator *cg, Rule r, struct hashmap *members) {
	cg_println(cg, "void verbum_ast_delete_%s(struct VerbumContext *ctx, struct %s *%s) {", r.token1.lexeme, r.token1.lexeme, r.token1.lexeme);
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
				if(it->stat != MemberStat_Token && it->stat != MemberStat_Literal) {
					cg_println(cg, "ctx->memory.delete(%s->%s_%d);", r.token1.lexeme, it->type, i);
				}
			}
		}

		cvector_free(mis);
	}

	cg_println(cg, "ctx->memory.delete(%s);", r.token1.lexeme);
	cg_unindent(cg);
	cg_println(cg, "}");
}

static void cg_generate_parser(CodeGenerator *cg) {
	if(!cg_open(cg, verbum_parser_file_h)) {
		// Error
		return;
	}

	cg_println(cg, verbum_parser_file_h_contents);
	cg_close(cg);

	if(!cg_open(cg, verbum_parser_file_c)) {
		// Error
		return;
	}

	cg_println(cg, "#include \"verbum.h\"");
	cg_println(cg, "#include \"verbum_ast.h\"");
	cg_println(cg, "#include \"verbum_lexer.h\"");
	cg_println(cg, "#include \"verbum_token.h\"");
	cg_println(cg, "#include \"verbum_parser.h\"");
	cg_newline(cg);
	cg_newline(cg);

	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type == TokenType_NonTerminal_Identifier) {
			cg_println(cg, "static %s *parser_parse_%s(Parser *p);", it->token1.lexeme, it->token1.lexeme);
		}
	}

	cg_newline(cg);
	cg_println(cg, verbum_parser_file_c_contents, cg->start.token1.lexeme, cg->start.token1.lexeme, cg->start.token1.lexeme);

	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type == TokenType_NonTerminal_Identifier) {
			cg_generate_parser_rule(cg, it);
		}
	}

	cg_close(cg);
}

static void generate_ast_rule_definition(CodeGenerator *cg, Rule r, struct hashmap *members) {
	if(!cvector_empty(r.expression1->list2)) {
		int offset = 0;
		cg_println(cg, "typedef enum %c%sType {", r.token1.lexeme[0], r.token1.lexeme + 1);
		cg_indent(cg);

		cg_println(cg, "%sType_%zu,", r.token1.lexeme, (size_t) 0);
		offset = 1;

		for(List *it = cvector_begin(r.expression1->list2); it != cvector_end(r.expression1->list2); it += 1) {
			cg_println(cg, "%sType_%zu,", r.token1.lexeme, it - cvector_begin(r.expression1->list2) + offset);
		}

		cg_unindent(cg);
		cg_println(cg, "} %sType;", r.token1.lexeme);
		cg_println(cg, "typedef struct %s {\n", r.token1.lexeme);
		cg_indent(cg);
		cg_println(cg, "%sType tag;", r.token1.lexeme);
		cg_generate_ast_expression(cg, r, *(r.expression1), members);
		cg_unindent(cg);
		cg_println(cg, "} %s;", r.token1.lexeme);

	} else {
		cg_println(cg, "typedef struct %s {", r.token1.lexeme);
		cg_indent(cg);
		cg_generate_ast_expression(cg, r, *(r.expression1), members);
		cg_unindent(cg);
		cg_println(cg, "} %s;", r.token1.lexeme);
		cg_newline(cg);
	}
}

static void cg_generate_ast_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members) {
	if(cvector_size(e.list2) == 0) {
		cg_generate_ast_list(cg, r, e.list1, members);
	} else {
		int offset = 0;

		cg_println(cg, "union {");
		cg_indent(cg);
		cg_println(cg, "struct {");
		cg_indent(cg);
		cg_generate_ast_list(cg, r, e.list1, members); 
		cg_unindent(cg);
		cg_println(cg, "} choice%d;", offset);
		offset += 1;

		for(List *it = cvector_begin(e.list2); it != cvector_end(e.list2); it += 1) {
			cg_println(cg, "struct {");
			cg_indent(cg);
			cg_generate_ast_list(cg, r, *it, members); 
			cg_unindent(cg);
			cg_println(cg, "} choice%d;", offset);
			offset += 1;
		}

		cg_unindent(cg);
		cg_println(cg, "};");
	}
}

static void cg_generate_ast_list(CodeGenerator *cg, Rule r, List l, struct hashmap *members) {
	cg_generate_ast_term(cg, r, l.term1, members);

	for(Term *it = cvector_begin(l.term2); it != cvector_end(l.term2); it += 1) {
		cg_generate_ast_term(cg, r, *it, members);
	}
}

static void cg_generate_ast_term(CodeGenerator *cg, Rule r, Term t, struct hashmap *members) {
	cg_generate_ast_factor(cg, r, t.factor1, members);
}

static void cg_generate_ast_factor(CodeGenerator *cg, Rule r, Factor f, struct hashmap *members) {
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
				cg_println(cg, "struct %s *%s_%d;", 
				f.nonterminal_identifier.lexeme, 
				f.nonterminal_identifier.lexeme, mi->numNamed);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
				cg_println(cg, "struct %s *%s_%d;", 
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
				cg_println(cg, "Token %s_%d;", f.terminal_identifier.lexeme, mi->numNamed);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
				cg_println(cg, "Token %s_%d;", f.terminal_identifier.lexeme, mi2.numNamed);
			}
		}
		break;
	case FactorType_Grouping:
		cg_generate_ast_expression(cg, r, *f.grouping, members);
		break;
	case FactorType_Literal: {
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = "literal",
					.stat = MemberStat_Literal,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Literal,
						.type = "literal",
				};
				hashmap_set(members, mi);
				cg_println(cg, "Token literal_%d;", mi->numNamed);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
				cg_println(cg, "Token literal_%d;\n", mi2.numNamed);
			}
		}
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

/* Utilities */
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
	fputc('\n', cg->fp);
	va_end(args);
}

static void cg_print(CodeGenerator *cg, const char *restrict format, ...) {
	va_list args;

	va_start(args, format);
	vfprintf(cg->fp, format, args);
	va_end(args);
}

static void cg_put(CodeGenerator *cg, const char c) {
	fputc(c, cg->fp);
}

static inline void cg_indent(CodeGenerator *cg) {
	cg->indent += 1;
}

static inline void cg_unindent(CodeGenerator *cg) {
	cg->indent -= 1;
}

static inline void cg_newline(CodeGenerator *cg) {
	cg_print(cg, "\n");
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
