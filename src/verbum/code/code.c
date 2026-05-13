#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

#include "../../lib/utf8.h/utf8.h"
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

/*
 * Generates the code for the verbum library.
 */
static void cg_generate_verbum(CodeGenerator *cg);
/*
 * Generates the code for tokens.
 */
static void cg_generate_tokens(CodeGenerator *cg);
/*
 * Generates the code for AST
 */
static void cg_generate_ast(CodeGenerator *cg);
/*
 * Generates the code for the lexer
 */
static void cg_generate_lexer(CodeGenerator *cg);
/*
 * Generates the code for the parser
 */
static void cg_generate_parser(CodeGenerator *cg);


/* CodeGenerator utilities */
/*
 * Opens a file.
 *
 * PARAMETERS:
 * 	cg: CodeGenerator to set current file
 * 	path: specified file
 *
 * RETURNS:
 * 	true if successfully open, false otherwise
 */
static bool cg_open(CodeGenerator *cg, const char *path);
/*
 * Closes the currently open file.
 *
 * PARAMETERS:
 * 	cg: CodeGenerator to unset file
 *
 * RETURNS:
 * 	true if succesfully closed, false otherwise
 */
static bool cg_close(CodeGenerator *cg);
/*
 * Prints a character to the set file
 *
 * PARAMETERS:
 * 	cg: CodeGenerator
 * 	c: character to print
 */
static void cg_put(CodeGenerator *cg, const char c);
static void cg_println(CodeGenerator *cg, const char *restrict format, ...);
static void cg_print(CodeGenerator *cg, const char *restrict format, ...);
static void cg_repeat(CodeGenerator *cg, char c, size_t n);
static void cg_print_indent(CodeGenerator *cg);
static inline void cg_newline(CodeGenerator *cg);
static inline void cg_indent(CodeGenerator *cg);
static inline void cg_unindent(CodeGenerator *cg);
static void cg_print_lexeme(CodeGenerator *cg, Lexeme l);


CodeGenerator code_generator_new(AST *ast, Rule start, struct hashmap *tokens, struct hashmap *firstFollowSets, struct hashmap *topterminals) {
	return (CodeGenerator) {
		.ast = ast,
		.start = start,
		.tokens = tokens,
		.firstFollowSets = firstFollowSets,
		.topterminals = topterminals,
		.indent = 0,
	};
}

void code_generator_generate(CodeGenerator cg) {
	cg_generate_verbum(&cg);
	cg_generate_tokens(&cg);
	cg_generate_ast(&cg);
	cg_generate_lexer(&cg);
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
		cg_println(cg, "void verbum_token_delete(VerbumContext *ctx, Token *t);");
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
			const char *p = ((Token *) item)->lexeme;

			cg_put(cg, '\"');

			cg_print_lexeme(cg, ((Token *) item)->lexeme);


			cg_println(cg, "\"");
		}

		cg_println(cg, "%%%%");
		cg_println(cg, "void verbum_token_delete(VerbumContext *ctx, Token *t) {");
		cg_indent(cg);
		cg_println(cg, "if(t->lexeme != NULL) {");
		cg_indent(cg);
		cg_println(cg, "ctx->memory.delete((void *) t->lexeme);");
		cg_println(cg, "t->lexeme = NULL;");
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_unindent(cg);
		cg_println(cg, "}");
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


static char *cg_generate_lexer_condition_rule(CodeGenerator *cg, Rule *r);
static char *cg_generate_lexer_condition_expression(CodeGenerator *cg, Expression e);
static char *cg_generate_lexer_condition_list(CodeGenerator *cg, List e);
static char *cg_generate_lexer_condition_term(CodeGenerator *cg, Term t);
static char *cg_generate_lexer_condition_factor(CodeGenerator *cg, Factor f);
static void cg_generate_lexer_language_tokens(CodeGenerator *cg);
static void cg_generate_lexer_language_token_lexeme(CodeGenerator *cg, const char *const root, const char *l, bool isSequence);
static void cg_generate_lexer_rule(CodeGenerator *cg, Rule *r);
static void cg_generate_lexer_expression(CodeGenerator *cg, Expression *e, size_t choice, bool isMultipleChoice, size_t depth);
static void cg_generate_lexer_list(CodeGenerator *cg, List *l, size_t choice, bool isMultipleChoice, size_t depth);
static void cg_generate_lexer_term(CodeGenerator *cg, Term *t, size_t choice, bool isMultipleChoice, size_t depth);
static void cg_generate_lexer_factor(CodeGenerator *cg, Factor *f, size_t choice, bool isMultipleChoice, size_t depth);


static void cg_generate_lexer(CodeGenerator *cg) {
	if(cg_open(cg, verbum_lexer_file_h)) {
		cg_println(cg, verbum_lexer_file_h_contents);
		cg_close(cg);
	}

	if(cg_open(cg, verbum_lexer_file_c)) {
		cg_println(cg, verbum_lexer_file_c_contents);

		for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
			if(it->token1.type == TokenType_Terminal_Identifier) {
				cg_println(cg, "static size_t lexer_lex_%s(Lexer *l);", it->token1.lexeme);
			}
		}

		cg_generate_lexer_language_tokens(cg);

		cg_println(cg, "Token lexer_lex(Lexer *l) {");
		cg_indent(cg);
		cg_println(cg, "Token result = {");
		cg_indent(cg);
		cg_println(cg, ".lexeme = \"Invalid\",");
		cg_println(cg, ".tag = TokenType_Invalid,");
		cg_println(cg, ".pos = {");
		cg_indent(cg);
		cg_println(cg, ".row = l->pos.row,");
		cg_println(cg, ".col = l->pos.col,");
		cg_unindent(cg);
		cg_println(cg, "},");
		cg_unindent(cg);
		cg_println(cg, "};");
		cg_println(cg, "uint32_t c = lexer_current_character(l);");
		cg_println(cg, "size_t length = 0;");
		cg_newline(cg);
		cg_println(cg, "if(lexer_at_end(l)) {");
		cg_indent(cg);
		cg_println(cg, "return (Token) {");
		cg_indent(cg);
		cg_println(cg, ".lexeme = \"EOF\",");
		cg_println(cg, ".tag = TokenType_EOF,");
		cg_println(cg, ".pos = {");
		cg_indent(cg);
		cg_println(cg, ".row = l->pos.row,");
		cg_println(cg, ".col = l->pos.col,");
		cg_unindent(cg);
		cg_println(cg, "},");
		cg_unindent(cg);
		cg_println(cg, "};");
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_newline(cg);
		cg_println(cg, "if(utf8chr(\" \\r\\n\\t\", c)) {");
		cg_indent(cg);
		cg_println(cg, "lexer_advance(l);");
		cg_println(cg, "return (Token) {");
		cg_indent(cg);
		cg_println(cg, ".lexeme = \" \",");
		cg_println(cg, ".tag = TokenType_Whitespace,");
		cg_unindent(cg);
		cg_println(cg, "};");
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_newline(cg);
		cg_println(cg, "/* Lexer functions */");
		cg_newline(cg);
		cg_println(cg, "length = lexer_lex_builtin(l);");

		cg_println(cg, "if(length != 0) {");
		cg_indent(cg);
		// Lexeme creation
		cg_println(cg, "Lexeme lexeme = l->ctx->io.copy_from(l->stream, l->ctx->io.tell(l->stream) - (length + 1), length + 1);");
		cg_newline(cg);
		cg_println(cg, "if(lexeme == NULL) {");
		cg_indent(cg);
		cg_println(cg, "// Error");
		cg_println(cg, "return result;");
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_newline(cg);
		cg_println(cg, "result = (Token) {");
		cg_indent(cg);
		cg_println(cg, ".tag = verbum_token_get_lexeme_type(lexeme),");
		cg_println(cg, ".lexeme = lexeme,");
		cg_println(cg, ".pos = { 0 },");
		cg_unindent(cg);
		cg_println(cg, "};");
		cg_newline(cg);
		cg_println(cg, "return result;");
		cg_unindent(cg);
		cg_println(cg, "}");
		

		for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
			// Only call lexing functions for terminal types that can be reached from nonterminals
			if(it->token1.type == TokenType_Terminal_Identifier && hashmap_get(cg->topterminals, &it->token1)) {
				char *condition = cg_generate_lexer_condition_rule(cg, it);

				if(condition != NULL && *condition != '\0') {
					cg_print_indent(cg);
					cg_print(cg, "if(utf8chr(\"");
					cg_print(cg, condition);
					cg_print(cg, "\", c)) {\n");
					cg_indent(cg);
					cg_println(cg, "size_t length = lexer_lex_%s(l);", it->token1.lexeme);
					cg_newline(cg);
					cg_println(cg, "if(length != 0) {");
					cg_indent(cg);
					// Lexeme creation
					cg_println(cg, "Lexeme lexeme = l->ctx->io.copy_from(l->stream, l->ctx->io.tell(l->stream) - (length + 1), length + 1);");
					cg_newline(cg);
					cg_println(cg, "if(lexeme == NULL) {");
					cg_indent(cg);
					cg_println(cg, "// Error");
					cg_println(cg, "return result;");
					cg_unindent(cg);
					cg_println(cg, "}");
					cg_newline(cg);
					cg_println(cg, "result = (Token) {");
					cg_indent(cg);
					cg_println(cg, ".tag = TokenType_%s,", it->token1.lexeme);
					cg_println(cg, ".lexeme = lexeme,");
					cg_println(cg, ".pos = { 0 },");
					cg_unindent(cg);
					cg_println(cg, "};");
					cg_newline(cg);
					cg_println(cg, "return result;");
					cg_unindent(cg);
					cg_println(cg, "}");
					cg_unindent(cg);
					cg_println(cg, "}");
				}

				cvector_free(condition);
			}
		}

		cg_newline(cg);
		cg_println(cg, "lexer_report_error(l, lexer_current_character(l));");
		cg_println(cg, "lexer_advance(l);");
		cg_newline(cg);
		cg_println(cg, "return result;");
		cg_unindent(cg);
		cg_println(cg, "}");

		for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
			if(it->token1.type == TokenType_Terminal_Identifier) {
				cg_generate_lexer_rule(cg, it);
			}
		}

		cg_close(cg);
	}
}

static void cg_generate_lexer_language_token_lexeme(CodeGenerator *cg, const char *const root, const char *l, bool isSequence) {
	if(*l == '\0') {
		return;
	}

	cg_print_indent(cg);
	cg_print(cg, "if(utf8chr(\"");

	if(*(l) == '\\') {
		cg_print(cg, "\\\\");
	} else if(*(l) == '\"') {
		cg_print(cg, "\\\"");
	} else {
		cg_put(cg, *(l));
	}

	cg_print(cg, "\", lexer_current_character(l))) {");
	cg_newline(cg);
	cg_indent(cg);
	cg_println(cg, "lexer_advance(l);");
	//cg_println(cg, "result += 1;");
	cg_println(cg, "consumed += 1;");

	if(!isSequence && l - root + 1 == strlen(root)) {
		cg_println(cg, "goto EXIT;");
	}

	cg_generate_lexer_language_token_lexeme(cg, root, l + 1, false);
	cg_unindent(cg);
	cg_println(cg, "} else {");
	cg_indent(cg);

	for(size_t i = l - root; i != 0; i -= 1) {
		cg_println(cg, "lexer_undo(l);");
		cg_println(cg, "result -= 1;");
	}

	cg_unindent(cg);
	cg_println(cg, "}");
}

static void cg_generate_lexer_language_tokens(CodeGenerator *cg) {
	size_t i = 0;
	void *item = 0;

	cg_println(cg, "static size_t lexer_lex_builtin(Lexer *l) {");
	cg_indent(cg);
	cg_println(cg, "size_t result = 0;");
	cg_println(cg, "size_t consumed = 0;");


	while(hashmap_iter(cg->tokens, &i, &item)) {
		Token *token = item;

		cg_generate_lexer_language_token_lexeme(cg, token->lexeme, token->lexeme, false);
	}


	cg_print(cg, "EXIT:");
	cg_newline(cg);

	cg_println(cg, "result += consumed;");

	cg_println(cg, "return result;");
	cg_unindent(cg);
	cg_println(cg, "}");
}

static void cg_generate_lexer_rule(CodeGenerator *cg, Rule *r) {
	cg_println(cg, "static size_t lexer_lex_%s(Lexer *l) {", r->token1.lexeme);
	cg_indent(cg);
	cg_println(cg, "size_t result = 0;");
	cg_newline(cg);
	cg_generate_lexer_expression(cg, r->expression1, 0, !cvector_empty(r->expression1->list2), 0);
	cg_newline(cg);
	cg_print(cg, "EXIT:");
	cg_newline(cg);
	cg_println(cg, "return result;");
	cg_unindent(cg);
	cg_println(cg, "}");
	cg_newline(cg);
}

static void cg_generate_lexer_expression(CodeGenerator *cg, Expression *e, size_t choice, bool isMultipleChoice, size_t depth) {
	cg_println(cg, "size_t consumed = 0;");

	if(isMultipleChoice && e->list2 != NULL) {
		cg_println(cg, "if(consumed == 0) {");
		cg_indent(cg);
	}

	cg_generate_lexer_list(cg, &e->list1, choice, isMultipleChoice, depth);


	if(isMultipleChoice && e->list2 != NULL) {
		cg_unindent(cg);
		cg_println(cg, "}");
	}

	for(List *it = cvector_begin(e->list2); it != cvector_end(e->list2); it += 1) {
		cg_println(cg, "if(consumed == 0) {");
		cg_indent(cg);
		cg_generate_lexer_list(cg, it, choice, !cvector_empty(e->list2), depth);
		cg_unindent(cg);
		cg_println(cg, "}");
	}

	cg_println(cg, "result += consumed;");
}

static void cg_generate_lexer_list(CodeGenerator *cg, List *l, size_t choice, bool isMultipleChoice, size_t depth) {
	cg_generate_lexer_term(cg, &l->term1, choice, isMultipleChoice, depth);

	for(Term *it = cvector_begin(l->term2); it != cvector_end(l->term2); it += 1) {
		if(isMultipleChoice) {
			cg_println(cg, "if(consumed != 0) {");
			cg_indent(cg);
		}

		cg_generate_lexer_term(cg, it, choice, isMultipleChoice, depth);

		if(isMultipleChoice) {
			cg_unindent(cg);
			cg_println(cg, "}");
		}
	}

}

static void cg_generate_lexer_term(CodeGenerator *cg, Term *t, size_t choice, bool isMultipleChoice, size_t depth) {
	cg_generate_lexer_factor(cg, &t->factor1, choice, isMultipleChoice, depth);
}

static void cg_generate_lexer_factor(CodeGenerator *cg, Factor *f, size_t choice, bool isMultipleChoice, size_t depth) {
	switch(f->tag) {
	case FactorType_Literal: {
			cg_generate_lexer_language_token_lexeme(cg, f->literal.lexeme, f->literal.lexeme, true);
		}
		break;
	case FactorType_Terminal_Identifier:
		cg_println(cg, "consumed += lexer_lex_%s(l);", f->terminal_identifier.lexeme);
		break;
	case FactorType_Optional: {
			cvector(char) condition = cg_generate_lexer_condition_expression(cg, *f->optional);
			cg_println(cg, "if(utf8chr(\"%s\", lexer_current_character(l))) {", condition);
			cg_indent(cg);
			cg_generate_lexer_expression(cg, f->optional, choice, isMultipleChoice, depth + 1);
			cg_unindent(cg);
			cg_println(cg, "}");
			cvector_free(condition);
		}
		break;
	case FactorType_Grouping:
		cg_println(cg, "{");
		cg_indent(cg);
		cg_generate_lexer_expression(cg, f->grouping, choice, isMultipleChoice, depth + 1);
		cg_unindent(cg);
		cg_println(cg, "}");
		break;
	case FactorType_Repetition: {
			cvector(char) condition = cg_generate_lexer_condition_expression(cg, *f->repetition);
			cg_println(cg, "while(utf8chr(\"%s\", lexer_current_character(l))) {", condition);
			cg_indent(cg);
			cg_generate_lexer_expression(cg, f->repetition, choice, isMultipleChoice, depth + 1);
			cg_unindent(cg);
			cg_println(cg, "}");
			cvector_free(condition);
		}

		break;
	default:
		break;
	}
}

static char *cg_generate_lexer_condition_rule(CodeGenerator *cg, Rule *r) {
	const FirstFollowSet *ffs = hashmap_get(cg->firstFollowSets, &(FirstFollowSet){ .t = r->token1 });
	cvector(char) result = NULL;

	if(ffs != NULL) {
		size_t i = 0;
		void *item;

		while(hashmap_iter(ffs->firsts, &i, &item)) {
			Token *token = item;

			if(token->type == TokenType_Literal) {
				const char *p = token->lexeme;

				while(*p != '\0') {
					if(*p == '\\' || *p == '\"') {
						cvector_push_back(result, '\\');
					}

					cvector_push_back(result, *p);
					p += 1;
				}
			} else if(token->type == TokenType_Terminal_Identifier) {
				char *temp = cg_generate_lexer_condition_rule(cg, &(Rule) { .token1 = *token });

				if(temp) {
					for (char *it = temp; *it != '\0'; it += 1) {
						cvector_push_back(result, *it);
					}

					cvector_free(temp);
				}
			}
		}
	}

	cvector_push_back(result, '\0');

	return result;
}

static char *cg_generate_lexer_condition_expression(CodeGenerator *cg, Expression e) {
	cvector(char) result = NULL;
	cvector(char) l1 = cg_generate_lexer_condition_list(cg, e.list1);

	if(!cvector_empty(e.list2)) {
		if(!cvector_empty(l1)) {
			char *curr = l1;

			while(*curr != '\0') {
				cvector_push_back(result, *curr);
				curr += 1;
			}

			cvector_free(l1);
		}

		for(List *it = cvector_begin(e.list2); it != cvector_end(e.list2); it += 1) {
			cvector(char) l2 = cg_generate_lexer_condition_list(cg, *it);

			if(!cvector_empty(l2)) {
				char *curr = l2;

				while(*curr != '\0') {
					cvector_push_back(result, *curr);
					curr += 1;
				}

				cvector_free(l2);
			}
		}
	} else {
		result = l1;
	}

	cvector_push_back(result, '\0');

	return result;
}

static char *cg_generate_lexer_condition_list(CodeGenerator *cg, List l) {
	cvector(char) result = NULL;
	cvector(char) t1 = cg_generate_lexer_condition_term(cg, l.term1);

	if(l.term1.factor1.tag == FactorType_Optional || l.term1.factor1.tag == FactorType_Repetition) {
		for(char *it = cvector_begin(t1); it != cvector_end(t1); it += 1) {
			cvector_push_back(result, *it);
		}

		cvector_free(t1);

		for(Term *it = cvector_begin(l.term2); it != cvector_end(l.term2); it += 1) {
			cvector(char) t2 = cg_generate_lexer_condition_term(cg, *it);

			for(char *it = cvector_begin(t2); it != cvector_end(t2); it += 1) {
				cvector_push_back(result, *it);
			}

			cvector_free(t2);

			if(it->factor1.tag != FactorType_Optional && it->factor1.tag != FactorType_Repetition) {
				break;
			}
		}
	} else {
		result = t1;
	}

	cvector_push_back(result, '\0');

	return result;
}

static char *cg_generate_lexer_condition_term(CodeGenerator *cg, Term t) {
	cvector(char) result = NULL;
	cvector(char) f1 = cg_generate_lexer_condition_factor(cg, t.factor1);
	
	if(t.factor2 != NULL) {
		cvector(char) f2 = cg_generate_lexer_condition_factor(cg, *t.factor2);

		for(char *it = cvector_begin(f1); it != cvector_end(f1); it += 1) {
			if(!utf8chr(f2, *it)) {
				cvector_push_back(result, *it);
			}
		}

		cvector_free(f1);
		cvector_free(f2);
	} else {
		result = f1;
	}

	cvector_push_back(result, '\0');

	return result; 
}

static char *cg_generate_lexer_condition_factor(CodeGenerator *cg, Factor f) {
	cvector(char) result = NULL;

	switch(f.tag) {
	case FactorType_NonTerminal_Identifier:
		break;
	case FactorType_Terminal_Identifier:
		result = cg_generate_lexer_condition_rule(cg, &(Rule) { .token1 = f.terminal_identifier});
		break;
	case FactorType_Repetition:
		result = cg_generate_lexer_condition_expression(cg, *f.repetition);
		break;
	case FactorType_Optional:
		result = cg_generate_lexer_condition_expression(cg, *f.optional);
		break;
	case FactorType_Grouping:
		result = cg_generate_lexer_condition_expression(cg, *f.grouping);
		break;
	case FactorType_Literal:
		cvector_push_back(result, f.literal.lexeme[0]);
		cvector_push_back(result, '\0');
		break;
	default:
		break;
	}

	return result;
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
	size_t choice;
	bool isMultipleChoice;
	// Values
	int numNamed;
} MemberInfo;


static uint64_t member_info_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int member_info_compare(const void *a, const void *b, void *udata);

static size_t cg_generate_ast_rule_definition(CodeGenerator *cg, Rule r, struct hashmap *members);
static void cg_generate_ast_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members);
static void cg_generate_ast_list(CodeGenerator *cg, Rule r, List l, size_t choice, bool isMultipleChoice, struct hashmap *members);
static void cg_generate_ast_term(CodeGenerator *cg, Rule r, Term t, size_t choice, bool isMultipleChoice, struct hashmap *members);
static void cg_generate_ast_factor(CodeGenerator *cg, Rule r, Factor f, size_t choice, bool isMultipleChoice, struct hashmap *members);
static void cg_generate_ast_rule_function_new_signature(CodeGenerator *cg, Rule r, struct hashmap *members, size_t choices);
static void cg_generate_ast_rule_function_new_definition(CodeGenerator *cg, Rule r, struct hashmap *members, size_t choices);
static void cg_generate_ast_rule_function_delete_signature(CodeGenerator *cg, Rule r, struct hashmap *members);
static void cg_generate_ast_rule_function_delete_definition(CodeGenerator *cg, Rule r, struct hashmap *members, size_t choices);

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
			size_t count = cg_generate_ast_rule_definition(cg, *it, members);
			cg_generate_ast_rule_function_new_signature(cg, *it, members, count);
			cg_generate_ast_rule_function_delete_signature(cg, *it, members);
			fclose(cg->fp);
			cg->fp = fopen(verbum_ast_file_c, "a");
			cg_generate_ast_rule_function_new_definition(cg, *it, members, count);
			cg_generate_ast_rule_function_delete_definition(cg, *it, members, count);
			fclose(cg->fp);
			hashmap_free(members);
		}
	}

	cg->fp = fopen(verbum_ast_file_h, "a");
	cg_println(cg, "typedef %s AST;", cg->start.token1.lexeme);
	cg_newline(cg);
	cg_println(cg, "#endif");
	cg_close(cg);
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

static void cg_generate_ast_rule_function_new_signature(CodeGenerator *cg, Rule r, struct hashmap *members, size_t choices) {
	if(choices > 1) {
		for(size_t choice = 0; choice < choices; choice += 1) {
			cvector(MemberInfo) mis = NULL;

			{
				size_t j = 0;
				void *item;

				while(hashmap_iter(members, &j, &item)) {
					const MemberInfo *mi = item;

					if(mi->choice == choice) {
						cvector_push_back(mis, *mi);
					}
				}
			}

			cg_print(cg, "struct %s *verbum_ast_new_%s_choice%zu(struct VerbumContext *ctx", r.token1.lexeme, r.token1.lexeme, choice);

			for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
				cg_print(cg, ", ");

				for(int i = 0; i < it->numNamed + 1; i += 1) {
					if(it->stat == MemberStat_Token || it->stat == MemberStat_Literal) {
						cg_print(cg, "Token %s_%d", it->type, i);
					} else {
						cg_print(cg, "struct %s *%s_%d", it->type, it->type, i);
					}

					if(i < it->numNamed) {
						cg_print(cg, ", ");

					}
				}
			}

			cvector_free(mis);
			cg_println(cg, ");");
		}
	} else {
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

		if(choices > 1) {
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
}

static void cg_generate_ast_rule_function_new_definition(CodeGenerator *cg, Rule r, struct hashmap *members, size_t choices) {
	if(choices > 1) {
		for(size_t i = 0; i < choices; i += 1) {
			cvector(MemberInfo) mis = NULL;

			{
				size_t j = 0;
				void *item;

				while(hashmap_iter(members, &j, &item)) {
					const MemberInfo *mi = item;

					if(mi->choice == i) {
						cvector_push_back(mis, *mi);
					}
				}
			}

			cg_print(cg, "struct %s *verbum_ast_new_%s_choice%zu(struct VerbumContext *ctx",
					r.token1.lexeme, r.token1.lexeme, i);

			for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
				cg_print(cg, ", ");

				for(int i = 0; i < it->numNamed + 1; i += 1) {
					if(it->stat == MemberStat_Token || it->stat == MemberStat_Literal) {
						cg_print(cg, "Token %s_%d", it->type, i);
					} else {
						cg_print(cg, "struct %s *%s_%d", it->type, it->type, i);
					}

					if(i < it->numNamed) {
						cg_print(cg, ", ");

					}
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
					if(it->isMultipleChoice) {
						cg_println(cg, "result->choice%zu.%s_%d = %s_%d;", it->choice, it->type, i, it->type, i);
					} else {
						cg_println(cg, "result->%s_%d = %s_%d;", it->type, i, it->type, i);
					}
				}
			}

			cg_newline(cg);
			cg_println(cg, "result->tag = %sType_%zu;", r.token1.lexeme, i);
			cg_unindent(cg);
			cg_println(cg, "}");
			cg_newline(cg);
			cg_println(cg, "return result;");
			cg_unindent(cg);
			cg_println(cg, "}");
			cvector_free(mis);
		}
	} else {
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

		if(choices > 1) {
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
				if(it->isMultipleChoice) {
					cg_println(cg, "result->choice%zu.%s_%d = %s_%d;",
							it->choice, it->type, i, it->type, i);
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
}

static void cg_generate_ast_rule_function_delete_signature(CodeGenerator *cg, Rule r, struct hashmap *members) {
	cg_println(cg, "void verbum_ast_delete_%s(struct VerbumContext *ctx, struct %s *d);", r.token1.lexeme, r.token1.lexeme);
}

static void cg_generate_ast_rule_function_delete_definition(CodeGenerator *cg, Rule r, struct hashmap *members, size_t choices) {
	cg_println(cg, "void verbum_ast_delete_%s(struct VerbumContext *ctx, struct %s *%s) {",
			r.token1.lexeme, r.token1.lexeme, r.token1.lexeme);
	cg_indent(cg);

	if(choices > 1) {
		cg_println(cg, "switch(%s->tag) {", r.token1.lexeme);

		for(size_t i = 0; i < choices; i += 1) {
			cvector(MemberInfo) mis = NULL;

			{
				size_t j = 0;
				void *item;

				while(hashmap_iter(members, &j, &item)) {
					const MemberInfo *mi = item;

					if(mi->choice == i) {
						cvector_push_back(mis, *mi);
					}
				}
			}

			cg_println(cg, "case %sType_%zu:", r.token1.lexeme, i);
			cg_indent(cg);

			for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
				for(int i = 0; i < it->numNamed + 1; i += 1) {
					if(it->stat == MemberStat_Token || it->stat == MemberStat_Literal) {
						cg_println(cg, "verbum_token_delete(ctx, &%s->choice%zu.%s_%d);",
								r.token1.lexeme, it->choice, it->type, i);
					} else if(it->stat != MemberStat_Token && it->stat != MemberStat_Literal) {
						cg_println(cg, "verbum_ast_delete_%s(ctx, %s->choice%zu.%s_%d);",
								it->type, r.token1.lexeme, it->choice, it->type, i);
					}
				}
			}

			cg_unindent(cg);
			cg_println(cg, "break;");
			cvector_free(mis);
		}

		cg_println(cg, "}");
		cg_println(cg, "ctx->memory.delete(%s);", r.token1.lexeme);
		cg_unindent(cg);
		cg_println(cg, "}");
	} else {
		cvector(MemberInfo) mis = NULL;

		{
			size_t i = 0;
			void *item;

			while(hashmap_iter(members, &i, &item)) {
				const MemberInfo *mi = item;

				cvector_push_back(mis, *mi);
			}
		}

		for(MemberInfo *it = cvector_begin(mis); it != cvector_end(mis); it += 1) {
			for(int i = 0; i < it->numNamed + 1; i += 1) {
				if(it->stat != MemberStat_Token && it->stat != MemberStat_Literal) {
					if(it->isMultipleChoice) {
						cg_println(cg, "verbum_ast_delete_%s(ctx, %s->choice%zu.%s_%d);",
								it->type, r.token1.lexeme, it->choice, it->type, i);
					} else {
						cg_println(cg, "verbum_ast_delete_%s(ctx, %s->%s_%d);",
								it->type, r.token1.lexeme, it->type, i);
					}
				}
			}
		}

		cvector_free(mis);
		cg_println(cg, "ctx->memory.delete(%s);", r.token1.lexeme);
		cg_unindent(cg);
		cg_println(cg, "}");
	}
}

/* Parser generation */
static void cg_generate_parser_panic(CodeGenerator *cg);
static void cg_generate_parser_rule(CodeGenerator *cg, Rule r);
static void cg_generate_parser_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members);
static void cg_generate_parser_list(CodeGenerator *cg, Rule r, List l, size_t choice, bool multipleChoice, struct hashmap *members);
static void cg_generate_parser_term(CodeGenerator *cg, Rule r, Term t, size_t choice, bool multipleChoice, struct hashmap *members);
static void cg_generate_parser_factor(CodeGenerator *cg, Rule r, Factor f, size_t choice, bool multipleChoice, struct hashmap *members);

static void cg_generate_parser(CodeGenerator *cg) {
	if(!cg_open(cg, verbum_parser_file_h)) {
		// Error
		return;
	}

	cg_println(cg, verbum_parser_file_h_contents, cg->start.token1.lexeme);
	cg_close(cg);

	if(!cg_open(cg, verbum_parser_file_c)) {
		// Error
		return;
	}

	cg_println(cg, "#include <stdarg.h>");
	cg_println(cg, "#include <stdio.h>");
	cg_newline(cg);
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
	cg_generate_parser_panic(cg);

	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type == TokenType_NonTerminal_Identifier) {
			cg_generate_parser_rule(cg, *it);
		}
	}

	cg_close(cg);
}

static void cg_generate_parser_panic(CodeGenerator *cg) {
	cg_println(cg, "static void parser_panic(Parser *p, const char *format, ...) {");
	cg_indent(cg);
	cg_println(cg, "va_list list;");
	cg_println(cg, "Token t = { 0 };");
	cg_newline(cg);
	cg_println(cg, "va_start(list, format);");
	cg_println(cg, "fprintf(stderr, \"Error! (%%s)\", lexer_get_source(p->l));");
	cg_println(cg, "vfprintf(stderr, format, list);");
	cg_println(cg, "va_end(list);");
	cg_newline(cg);
	cg_println(cg, "while(!parser_at_end(p)) {");
	cg_indent(cg);
	cg_println(cg, "Token t = parser_current(p);");
	cg_unindent(cg);
	cg_println(cg, "}");
	cg_unindent(cg);
	cg_println(cg, "}");
}

static void cg_generate_parser_rule(CodeGenerator *cg, Rule r) {
	cg_println(cg, "static %s *parser_parse_%s(Parser *p) {", r.token1.lexeme, r.token1.lexeme);
	cg_indent(cg);
	cg_println(cg, "%s *result = NULL;", r.token1.lexeme);
	cg_println(cg, "size_t cp = parser_save(p);");
	cg_generate_parser_expression(cg, r, *r.expression1, NULL);
	cg_println(cg, "parser_rewind(p, cp);");
	cg_newline(cg);
	cg_print(cg, "EXIT:");
	cg_newline(cg);
	cg_println(cg, "parser_commit(p);");
	cg_newline(cg);
	cg_println(cg, "return result;");
	cg_unindent(cg);
	cg_println(cg, "}");
}

static void cg_generate_new_call(CodeGenerator *cg, Rule r, struct hashmap *members) {
	size_t i = 0;
	void *item;

	while(hashmap_iter(members, &i, &item)) {
		const MemberInfo *mi = item;

		for(size_t j = 0; j < mi->numNamed + 1; j += 1) {
			cg_print(cg, ", ");
			cg_print(cg, "%s_%zu", mi->type, j);
		}
	}
}

static void cg_generate_parser_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members) {
	struct hashmap *mems = hashmap_new_with_allocator(memory_new, memory_resize, memory_delete,
					     sizeof(MemberInfo), 0, 0, 0,
					     member_info_hash, member_info_compare, NULL, NULL);
	if(!cvector_empty(e.list2)) {

		size_t choice = 0;

		cg_println(cg, "{");
		cg_indent(cg);
		cg_generate_parser_list(cg, r, e.list1, choice, true, mems);
		cg_newline(cg);
		//cg_println(cg, "result = verbum_ast_new_%s_choice%zu(ctx, )");
		cg_newline(cg);
		cg_print_indent(cg);
		cg_print(cg, "result = verbum_ast_new_%s_choice%zu(p->ctx", r.token1.lexeme, choice);
		cg_generate_new_call(cg, r, mems);
		cg_print(cg, ");");
		cg_newline(cg);
		cg_println(cg, "parser_commit(p);");
		cg_println(cg, "result->tag = %sType_%zu;", r.token1.lexeme, choice);
		cg_println(cg, "return result;");
		cg_unindent(cg);
		cg_println(cg, "}");
		cg_print(cg, "EXIT_%zu:", choice);
		cg_newline(cg);
		hashmap_clear(mems, false);

		for(List *it = cvector_begin(e.list2); it != cvector_end(e.list2); it += 1) {
			choice += 1;
			cg_println(cg, "parser_rewind(p, cp);");
			cg_println(cg, "{");
			cg_indent(cg);
			cg_generate_parser_list(cg, r, *it, choice, true, mems);
			cg_newline(cg);
			cg_print_indent(cg);
			cg_print(cg, "result = verbum_ast_new_%s_choice%zu(p->ctx", r.token1.lexeme, choice);
			cg_generate_new_call(cg, r, mems);
			cg_print(cg, ");");
			cg_newline(cg);
			cg_println(cg, "parser_commit(p);");
			cg_println(cg, "result->tag = %sType_%zu;", r.token1.lexeme, choice);
			cg_println(cg, "return result;");
			cg_unindent(cg);
			cg_println(cg, "}");
			cg_print(cg, "EXIT_%zu:", choice);
			cg_newline(cg);
			hashmap_clear(mems, false);
		}
	} else {
		cg_generate_parser_list(cg, r, e.list1, 0, false, mems);
		cg_print_indent(cg);
		cg_print(cg, "result = verbum_ast_new_%s(p->ctx", r.token1.lexeme);
		cg_generate_new_call(cg, r, mems);
		cg_print(cg, ");");
		cg_newline(cg);
		cg_println(cg, "goto EXIT;");
	}

	hashmap_free(mems);
}

static void cg_generate_parser_list(CodeGenerator *cg, Rule r, List l, size_t choice, bool multipleChoice, struct hashmap *members) {
	if(!cvector_empty(l.term2)) {
		cg_generate_parser_term(cg, r, l.term1, choice, multipleChoice, members);

		for(Term *it = cvector_begin(l.term2); it != cvector_end(l.term2); it += 1) {
			cg_generate_parser_term(cg, r, *it, choice, multipleChoice, members);
		}
	} else {
		cg_generate_parser_term(cg, r, l.term1, choice, multipleChoice, members);
	}
}

static void cg_generate_parser_term(CodeGenerator *cg, Rule r, Term t, size_t choice, bool multipleChoice, struct hashmap *members) {
	cg_generate_parser_factor(cg, r, t.factor1, choice, multipleChoice, members);
}

static void cg_generate_parser_factor(CodeGenerator *cg, Rule r, Factor f, size_t choice, bool multipleChoice, struct hashmap *members) {
	switch(f.tag) {
	case FactorType_NonTerminal_Identifier: {
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = f.nonterminal_identifier.lexeme,
					.stat = MemberStat_Pointer,
					.choice = choice,
					.isMultipleChoice = multipleChoice,
				});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Pointer,
						.type = f.nonterminal_identifier.lexeme,
						.choice = choice,
						.isMultipleChoice = multipleChoice,
				};
				hashmap_set(members, mi);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
			}

			mi = hashmap_get(members, &(MemberInfo) {
					.type = f.nonterminal_identifier.lexeme,
					.stat = MemberStat_Pointer,
					.choice = choice,
					.isMultipleChoice = multipleChoice,
			});

			cg_println(cg, "%s *%s_%zu = parser_parse_%s(p);", mi->type, mi->type, mi->numNamed, mi->type);

			const FirstFollowSet *ffs = hashmap_get(cg->firstFollowSets, &(FirstFollowSet) { .t = f.nonterminal_identifier} );

			if(!ffs->nullable) {
				cg_println(cg, "if(%s_%zu == NULL) {", mi->type, mi->numNamed);
				cg_indent(cg);
				if(multipleChoice) {
					cg_println(cg, "goto EXIT_%zu;", choice);
				} else {
					cg_println(cg, "goto EXIT;");
				}
				cg_println(cg, "// Error cleanup");
				cg_unindent(cg);
				cg_println(cg, "}");
			}
		}
		break;
	case FactorType_Terminal_Identifier: {
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = f.terminal_identifier.lexeme,
					.stat = MemberStat_Token,
					.choice = choice,
					.isMultipleChoice = multipleChoice,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Token,
						.type = f.terminal_identifier.lexeme,
						.choice = choice,
						.isMultipleChoice = multipleChoice,
				};
				hashmap_set(members, mi);
			} else {
				MemberInfo mi2 = *mi;

				mi2.numNamed += 1;
				hashmap_set(members, &mi2);
			}

			mi = hashmap_get(members, &(MemberInfo) {
					.type = f.terminal_identifier.lexeme,
					.stat = MemberStat_Token,
					.choice = choice,
					.isMultipleChoice = multipleChoice,
					});

			cg_println(cg, "if(!parser_match(p, TokenType_%s)) {", f.literal.lexeme);
			cg_indent(cg);

			if(multipleChoice) {
				cg_println(cg, "goto EXIT_%zu;", choice);
			} else {
				cg_println(cg, "goto EXIT;");
			}

			cg_println(cg, "// Error, cleanup");
			cg_unindent(cg);
			cg_println(cg, "}");
			cg_println(cg, "Token %s_%zu = parser_previous(p);", f.terminal_identifier.lexeme, mi->numNamed);
			cg_println(cg, "parser_drop(p);");
		}
		break;
	case FactorType_Literal: {
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = "literal",
					.stat = MemberStat_Literal,
					.choice = choice,
					.isMultipleChoice = multipleChoice,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Literal,
						.type = "literal",
						.choice = choice,
						.isMultipleChoice = multipleChoice,
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
					.choice = choice,
					.isMultipleChoice = multipleChoice,
			});

			cg_println(cg, "if(!parser_match(p, verbum_token_get_lexeme_type(\"%s\"))) {", f.literal.lexeme);
			cg_indent(cg);

			if(multipleChoice) {
				cg_println(cg, "goto EXIT_%zu;", choice);
			} else {
				cg_println(cg, "goto EXIT;");
			}

			cg_println(cg, "// Error, cleanup");
			cg_unindent(cg);
			cg_println(cg, "}");
			cg_println(cg, "Token literal_%zu = parser_previous(p);", mi->numNamed);
			cg_println(cg, "parser_drop(p);");
		}
		break;
	default:
		break;
	}

}

static size_t cg_generate_ast_rule_definition(CodeGenerator *cg, Rule r, struct hashmap *members) {
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

		return cvector_size(r.expression1->list2) + 1;
	} else {
		cg_println(cg, "typedef struct %s {", r.token1.lexeme);
		cg_indent(cg);
		cg_generate_ast_expression(cg, r, *(r.expression1), members);
		cg_unindent(cg);
		cg_println(cg, "} %s;", r.token1.lexeme);
		cg_newline(cg);

		return 1;
	}
}

static void cg_generate_ast_expression(CodeGenerator *cg, Rule r, Expression e, struct hashmap *members) {
	if(cvector_size(e.list2) == 0) {
		cg_generate_ast_list(cg, r, e.list1, 0, false, members);
	} else {
		int offset = 0;

		cg_println(cg, "union {");
		cg_indent(cg);
		cg_println(cg, "struct {");
		cg_indent(cg);
		cg_generate_ast_list(cg, r, e.list1, offset, true, members); 
		cg_unindent(cg);
		cg_println(cg, "} choice%d;", offset);
		offset += 1;

		for(List *it = cvector_begin(e.list2); it != cvector_end(e.list2); it += 1) {
			cg_println(cg, "struct {");
			cg_indent(cg);
			cg_generate_ast_list(cg, r, *it, offset, true, members); 
			cg_unindent(cg);
			cg_println(cg, "} choice%d;", offset);
			offset += 1;
		}

		cg_unindent(cg);
		cg_println(cg, "};");
	}
}

static void cg_generate_ast_list(CodeGenerator *cg, Rule r, List l, size_t choice, bool isMultipleChoice, struct hashmap *members) {
	cg_generate_ast_term(cg, r, l.term1, choice, isMultipleChoice, members);

	for(Term *it = cvector_begin(l.term2); it != cvector_end(l.term2); it += 1) {
		cg_generate_ast_term(cg, r, *it, choice, isMultipleChoice, members);
	}
}

static void cg_generate_ast_term(CodeGenerator *cg, Rule r, Term t, size_t choice, bool isMultipleChoice, struct hashmap *members) {
	cg_generate_ast_factor(cg, r, t.factor1, choice, isMultipleChoice, members);
}

static void cg_generate_ast_factor(CodeGenerator *cg, Rule r, Factor f, size_t choice, bool isMultipleChoice, struct hashmap *members) {
	switch (f.tag) {
	case FactorType_NonTerminal_Identifier: {
			const MemberInfo *mi = hashmap_get(members, &(MemberInfo) {
					.type = f.nonterminal_identifier.lexeme,
					.stat = MemberStat_Pointer,
					.choice = choice,
					.isMultipleChoice = isMultipleChoice,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Pointer,
						.type = f.nonterminal_identifier.lexeme,
						.choice = choice,
						.isMultipleChoice = isMultipleChoice,
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
					.choice = choice,
					.isMultipleChoice = isMultipleChoice,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Token,
						.type = f.terminal_identifier.lexeme,
						.choice = choice,
						.isMultipleChoice = isMultipleChoice,
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
					.choice = choice,
					.isMultipleChoice = isMultipleChoice,
					});

			if(mi == NULL) {
				mi = &(MemberInfo) {
						.numNamed = 0,
						.stat = MemberStat_Literal,
						.type = "literal",
						.choice = choice,
						.isMultipleChoice = isMultipleChoice,
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

	if(ua->stat == ub->stat && ua->choice == ub->choice && ua->isMultipleChoice == ub->isMultipleChoice) {
		return strcmp(ua->type, ub->type);
	}

	return 1;
}

/* Utilities */
static void cg_repeat(CodeGenerator *cg, char c, size_t n) {
	while(n != 0) {
		fputc(c, cg->fp);
		n -= 1;
	}
}

static void cg_print_indent(CodeGenerator *cg) {
	cg_repeat(cg, '\t', cg->indent);
}

static void cg_println(CodeGenerator *cg, const char *restrict format, ...) {
	va_list args;

	va_start(args, format);
	cg_print_indent(cg);
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

static void cg_print_lexeme(CodeGenerator *cg, Lexeme l) {
	/* Step through each character to accomadate for quote or backslash for proper
	 * c strings, if not a lexeme of " will we result in """, and thus be an unclosed
	 * c string
	 */
	while(*(l) != '\0') {
		// Prepend backslash
		if(*(l) == '\\' || *(l) == '\"') {
			cg_put(cg, '\\');
		}

		cg_put(cg, *(l));
		l += 1;
	}
}
