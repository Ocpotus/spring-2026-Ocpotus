#include <stdio.h>
#include <stdbool.h>

#include "../../lib/hashmap.c/hashmap.h"
#include "../../lib/c-vector/cvector.h"

#include "../memory/memory.h"
#include "../ast/ast.h"
#include "../token/token.h"

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
static const char *verbum_parser_file_h_contents;
static const char *verbum_parser_file_c_contents;
static const char *verbum_lexer_file_h_contents;

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
		.indent = 0,
	};
}

void code_generator_generate(CodeGenerator cg) {
	generate_tokens(&cg);
	generate_lexer(&cg);
	generate_ast(&cg);
	generate_parser(&cg);
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

/*
grammar        			= { rule } ;
rule           			= ( $NONTERMINAL_IDENTIFIER | $TERMINAL_IDENTIFIER ) , "=" , expression , ";" ;
expression     			= list , { "|" , list } ;
list           			= term , { "," , term } ;
term	       			= factor , [ "-" , factor ] ;
factor         			= $NONTERMINAL_IDENTIFIER
				| $TERMINAL_IDENTIFIER
				| $LITERAL
				| "[" , expression , "]"
				| "{" , expression , "}"
				| "(" , expression , ")"
				;
*/

static void generate_lexer(CodeGenerator *cg) {
	cg->fp = fopen(verbum_lexer_file_h, "w+");

	if(cg->fp == NULL) {
		// Error
		return;
	}

	fprintf(cg->fp, verbum_lexer_file_h_contents, verbum_token_file_h, verbum_utf8_h_file, verbum_utf8file_file_h);
	fclose(cg->fp);
/*
	for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
		if(it->token1.type == TokenType_Terminal_Identifier) {

		}
	} */
}

static void generate_indent(CodeGenerator *cg);
static void generate_whitespace(CodeGenerator *cg);
static void generate_rule(CodeGenerator *cg, Rule r);
static void generate_expression(CodeGenerator *cg, Expression e, struct hashmap *members);
static void generate_list(CodeGenerator *cg, List l, struct hashmap *members);
static void generate_term(CodeGenerator *cg, Term t, struct hashmap *members);
static void generate_factor(CodeGenerator *cg, Factor f, struct hashmap *members);

static uint64_t member_hash(const void *item, uint64_t seed0, uint64_t seed1);
static int member_compare(const void *a, const void *b, void *udata);

typedef enum MemberType {
	MemberType_Pointer,
	MemberType_Token,
	MemberType_Vector,
	MemberType_Optional,
} MemberType;

typedef struct Member {
	Token t;
	size_t count;
	MemberType tag;
} Member;

static void generate_ast(CodeGenerator *cg) {
	cg->fp = fopen(verbum_ast_file_h, "w+");

	if(cg->fp != NULL) {
		for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
			if(it->token1.type != TokenType_Terminal_Identifier) {
				fprintf(cg->fp, "typedef struct %s %s;\n", it->token1.lexeme, it->token1.lexeme);
			}
		}

		/* fprintf(cg->fp, "typedef %s AST;\n", cg->start.token1.lexeme);
		fputc('\n', cg->fp); */

		for(Rule *it = cvector_begin(cg->ast->rule1); it != cvector_end(cg->ast->rule1); it += 1) {
			if(it->token1.type != TokenType_Terminal_Identifier) {
				generate_rule(cg, *it);
			}
		}

		fclose(cg->fp);
	}
}

static void generate_rule(CodeGenerator *cg, Rule r) {
	if(!cvector_empty(r.expression1->list2)) {
		/* generate_indent(cg);
		fprintf(cg->fp, "typedef enum %sType {\n", r.token1.lexeme); */
		cg->indent += 1;

		for(size_t i = 0; i < cvector_size(r.expression1->list2) + 1; i += 1) {
			generate_indent(cg);
/* 			fprintf(cg->fp, "%sType_%zu,\n", r.token1.lexeme, i); */
		}

		/* generate_indent(cg);
		fprintf(cg->fp, "%sType_Invalid,\n", r.token1.lexeme);
		fprintf(cg->fp, "} %sType;\n", r.token1.lexeme);
		fputc('\n', cg->fp);
		fprintf(cg->fp, "typedef struct %s {\n", r.token1.lexeme); */
		cg->indent += 1;
		struct hashmap *members = hashmap_new_with_allocator(
					 memory_new, memory_resize, memory_delete,
					 sizeof(Token), 0, 0, 0,
					 member_hash, member_compare, NULL, NULL);
		generate_expression(cg, *(r.expression1), members);
		cg->indent -= 1;
		/* fprintf(cg->fp, "} %s;\n", r.token1.lexeme);
		fputc('\n', cg->fp); */
		hashmap_free(members);
	} else {
		fprintf(cg->fp, "typedef struct %s {\n", r.token1.lexeme);
		cg->indent += 1;
		struct hashmap *members = hashmap_new_with_allocator(
					 memory_new, memory_resize, memory_delete,
					 sizeof(Token), 0, 0, 0,
					 member_hash, member_compare, NULL, NULL);
		generate_expression(cg, *(r.expression1), members);
		cg->indent -= 1;
		fprintf(cg->fp, "} %s;\n", r.token1.lexeme);
		fputc('\n', cg->fp);
		hashmap_free(members);
	}
}

static void generate_expression(CodeGenerator *cg, Expression e, struct hashmap *members) {
}

static void generate_factor(CodeGenerator *cg, Factor f, struct hashmap *members) {
	switch(f.tag) {
	case FactorType_NonTerminal_Identifier: {
			const Member *mi = hashmap_get(members, &(Member) { .t = f.nonterminal_identifier});
			
			if(mi == NULL) {
			}
		}
		break;
	case FactorType_Terminal_Identifier:
		break;
	case FactorType_Literal:
		break;
	case FactorType_Optional:
		break;
	case FactorType_Repetition:
		break;
	case FactorType_Grouping:
		break;
	default:
		break;
	}
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
	// Generate parser for rules
	fclose(cg->fp);
}

static void generate_indent(CodeGenerator *cg) {
	for(size_t i = 0; i < cg->indent; i += 1) {
		fputc('\t', cg->fp);
	}
}

/* Hashmap functions */
static uint64_t member_hash(const void *item, uint64_t seed0, uint64_t seed1) {
	const Token *token = item;

	return hashmap_sip(token->lexeme, strlen(token->lexeme), seed0, seed1);
}

static int member_compare(const void *a, const void *b, void *udata) {
	const Token *ua = a;
	const Token *ub = b;

	if(ua->type == ub->type) {
		return strcmp(ua->lexeme, ub->lexeme);
	}

	return 1;
}


static const char *verbum_parser_file_h_contents =
"#ifndef VERBUM_PARSER_H\n"
"#define VERBUM_PARSER_H\n"
"#include <stdlib.h>\n"
"#include <stdbool.h>\n"
"#include \"%s\"\n"
"#include \"%s\"\n"
"#include \"%s\"\n"
"/* Opaque declaration */\n"
"typedef struct Parser Parser;\n"
"\n"
"/* Constructs a new Parser\n"
" *\n"
" * PARAMETERS:\n"
" * 	path: path to a file to parse\n"
" *\n"
" * RETURNS:\n"
" * 	Success: a pointer to a Parser\n"
" * 	Failure: NULL\n"
" */\n"
"Parser *parser_new(const char *path);\n"
"\n"
"/* Deletes a Parser\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: Parser to delete\n"
" */\n"
"void parser_delete(Parser *p);\n"
"\n"
"/* Executes the parsing process for a Parser\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: Parser to execute\n"
" *\n"
" * RETURNS:\n"
" * 	A pointer to a Unit representing the parsed\n"
" * 	file passed in with the path in parser_new\n"
" */\n"
"AST *parser_parse(Parser *p);\n"
"\n"
"\n"
"/* Parser struct\n"
" *\n"
" * MEMBERS:\n"
" * 	l: file Lexer\n"
" * 	previous: previously processed Token from l\n"
" * 	current: the current token in l\n"
" * 	peek: the peeked token in l\n"
" */\n"
"typedef struct Parser {\n"
"	Lexer *l;\n"
"	Token previous;\n"
"	Token current;\n"
"	Token peek;\n"
"	const char *error;\n"
"} Parser;\n"
"\n"
"\n"
"/* Advances the parser\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: parser to advance\n"
" *\n"
" * RETURNS:\n"
" * 	the next token\n"
" */\n"
"Token parser_advance(Parser *p);\n"
"\n"
"/* Retrieves the previous token\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: the parser to get the previous token\n"
" *\n"
" * RETURNS:\n"
" * 	the previous token\n"
" */\n"
"Token parser_previous(Parser *p);\n"
"\n"
"/* Retrieves the current token\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: the parser to get the current token\n"
" *\n"
" * RETURNS:\n"
" * 	the current token\n"
" */\n"
"Token parser_current(Parser *p);\n"
"\n"
"/* Checks if a Parser's previously processed Token is of a certain TokenType\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: Parser to check\n"
" * 	tt: TokenType to check for\n"
" *\n"
" * RETURNS:\n"
" * 	If the previously parsed token is of the given type\n"
" */\n"
"bool parser_previous_is(Parser *p, TokenType tt);\n"
"\n"
"/* Peeks the next token without advancing\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: the parser to get the next token\n"
" *\n"
" * RETURNS:\n"
" *	the peeked token\n"
" */\n"
"Token parser_peek(Parser *p);\n"
"\n"
"/* Checks if the next token is of the desired type\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: the parser to check\n"
" * 	tt: the desired token type\n"
" *\n"
" * RETURNS:\n"
" * 	if the next token is of the desired type\n"
" */\n"
"bool parser_check(Parser *p, TokenType tt);\n"
"\n"
"/* Checks and advances if the next token is of the desired type\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: parser to match to\n"
" * 	tt: desired type\n"
" *\n"
" * RETURNS:\n"
" * 	true: if the match was successful\n"
" * 	false: if the match was unsuccessful\n"
" */\n"
"bool parser_match(Parser *p, TokenType tt);\n"
"\n"
"/* Checks and advances if the next token is any of the desired types\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: parser to match to\n"
" * 	tts: an array of expected TokenTypes\n"
" * 	n: length of tts\n"
" *\n"
" * RETURNS:\n"
" * 	true: if the match was successful\n"
" * 	false: if the match was unsuccessful\n"
" */\n"
"bool parser_match_any(Parser *p, TokenType *tts, size_t n);\n"
"\n"
"/* Checks if the parser is at the end of the token stream\n"
" *\n"
" * PARAMETERS:\n"
" * 	p: parser to check\n"
" *\n"
" * RETURNS:\n"
" * 	true: if the parser is at the end\n"
" * 	false: if the parser is not at the end\n"
" */\n"
"bool parser_at_end(Parser *p);\n"
"\n"
"const char *parser_set_error(Parser *p, const char *error);\n"
"\n"
"void parser_reset_error(Parser *p);\n"
"\n"
"bool parser_errored(Parser *p);\n"
"\n"
"AST parser_parse_internal(Parser *p);\n"
"#endif\n";

static const char *verbum_parser_file_c_contents = 
"#include \"%s\"\n"
"#include \"%s\"\n"
"#include \"%s\"\n"
"#include \"%s\"\n"
"\n"
"Parser *parser_new(const char *path) {\n"
"	Parser *result = memory_new(1 * sizeof(*result));\n"
"\n"
"	if(result != NULL) {\n"
"		result->l = lexer_new(path);\n"
"		result->previous = (Token) {\n"
"			.type = TokenType_Whitespace,\n"
"			.lexeme = NULL,\n"
"		};\n"
"		result->current = lexer_get_token(result->l);\n"
"		result->peek = lexer_get_token(result->l);\n"
"	}\n"
"\n"
"	return result;\n"
"}\n"

"void parser_delete(Parser *p) {\n"
"	lexer_delete(p->l);\n"
"	memory_delete(p);\n"
"}\n"
"\n"
"AST *parser_parse(Parser *p) {\n"
"	Grammar g1 = parser_parse_internal(p);\n"
"	AST *result = memory_copy(&g1, sizeof(*result));\n"
"\n"
"	return result;\n"
"}\n"
"\n"
"\n"
"Token parser_advance(Parser *p) {\n"
"	if(!parser_at_end(p)) {\n"
"		Token t;\n"
"\n"
"		do {\n"
"			t = lexer_get_token(p->l);\n"
"		} while(t.type == TokenType_Whitespace);\n"
"\n"
"		p->previous = p->current;\n"
"		p->current = p->peek;\n"
"		p->peek = t;\n"
"		p->error = NULL;\n"
"	}\n"
"\n"
"	return parser_current(p);\n"
"}\n"
"\n"
"bool parser_at_end(Parser *p) {\n"
"	return parser_current(p).type == TokenType_EOF;\n"
"}\n"
"\n"
"Token parser_previous(Parser *p) {\n"
"	return p->previous;\n"
"}\n"
"\n"
"Token parser_current(Parser *p) {\n"
"	return p->current;\n"
"}\n"
"\n"
"Token parser_peek(Parser *p) {\n"
"	return p->peek;\n"
"}\n"
"\n"
"bool parser_check(Parser *p, TokenType tt) {\n"
"	return parser_current(p).type == tt;\n"
"}\n"
"\n"
"bool parser_previous_is(Parser *p, TokenType tt) {\n"
"	return parser_previous(p).type == tt;\n"
"}\n"
"\n"
"bool parser_match(Parser *p, TokenType tt) {\n"
"	if(parser_check(p, tt)) {\n"
"		parser_advance(p);\n"
"\n"
"		return true;\n"
"	}\n"
"\n"
"	return false;\n"
"}\n"
"\n"
"bool parser_match_any(Parser *p, TokenType *tts, size_t n) {\n"
"	for(size_t i = 0; i < n; i++) {\n"
"		if(parser_match(p, tts[i])) {\n"
"			return true;\n"
"		}\n"
"	}\n"
"\n"
"	return false;\n"
"}\n"
"\n"
"const char *parser_set_error(Parser *p, const char *error) {\n"
"	p->error = error;\n"
"\n"
"	return error;\n"
"}\n"
"\n"
"void parser_reset_error(Parser *p) {\n"
"	p->error = NULL;\n"
"}\n"
"\n"
"bool parser_errored(Parser *p) {\n"
"	return p->error != NULL;\n"
"}\n"
"\n"
"Grammar parser_parse_internal(Parser *p) {\n"
"	return parser_parse_grammar(p);\n"
"}\n";


static const char *verbum_lexer_file_h_contents =
"#ifndef VERBUM_LEXER_H\n"
"#define VERBUM_LEXER_H\n"
"\n"
"#include <stdbool.h>\n"
"#include <stdint.h>\n"
"#include \"%s\"\n" // token
"#include \"%s\"\n" //utf8.h
"#include \"%s\"\n" //utffile8.h
"\n"
"\n"
"/* Opaque declaration */\n"
"typedef struct Lexer Lexer;\n"
"\n"
"/* Constructs a new Lexer\n"
" *\n"
" * PARAMETERS:\n"
" * 	path: path of file to open\n"
" *\n"
" * RETURNS:\n"
" * 	A pointer to a Lexer or NULL on failure\n"
" */\n"
"Lexer *lexer_new(const char *path);\n"
"\n"
"/* Deletes a Lexer\n"
" *\n"
" * PARAMETERS:\n"
" * 	l: a pointer to a lexer\n"
" */\n"
"void lexer_delete(Lexer *l);\n"
"\n"
"/* Retrieves a token\n"
" *\n"
" * PARAMETERS:\n"
" * 	l: a pointer to a Lexer\n"
" *\n"
" * RETURNS:\n"
" * 	The next Token in the stream\n"
" */\n"
"Token lexer_get_token(Lexer *l);\n"
"\n"
"\n"
"\n"
"\n"
"/* Lexer struct\n"
" *\n"
" * MEMBERS:\n"
" * 	f: a pointer to a UTF8File to read from\n"
" * 	pos:\n"
" * 		row: current row in the file\n"
" * 		column: current column in the file\n"
" * 	cc: current character\n"
" */\n"
"typedef struct Lexer {\n"
"	UTF8File *f;\n"
"	struct {\n"
"		uint32_t row;\n"
"		uint32_t col;\n"
"	} pos;\n"
"	utf8_int32_t cc;\n"
"} Lexer;\n"
"\n"
"/* Advances a Lexer's position\n"
" *\n"
" * PARAMETERS:\n"
" * 	l: pointer to a Lexer to advance\n"
" * \n"
" * RETURNS:\n"
" * 	The retrieved character from the given Lexer's stream\n"
" */\n"
"utf8_int32_t lexer_advance(Lexer *l);\n"
"\n"
"/* Retrieves the current character of a Lexer\n"
" *\n"
" * PARAMETERS:\n"
" * 	l: a pointer to a Lexer to process\n"
" *\n"
" * RETURNS:\n"
" * 	The current character in the Lexer's stream\n"
" */\n"
"utf8_int32_t lexer_current_character(Lexer *l);\n"
"\n"
"/* Peeks a character in a Lexer's stream\n"
" *\n"
" * PARAMETERS:\n"
" * 	l: a pointer to a Lexer to process\n"
" *\n"
" * RETURNS:\n"
" * 	The next character in the Lexer's stream\n"
" */\n"
"utf8_int32_t lexer_peek_character(Lexer *l);\n"
"\n"
"/* Undos the previous action by a Lexer\n"
" *\n"
" * PARAMETERS:\n"
" * 	l: a pointer to a Lexer to process\n"
" */\n"
"void lexer_undo(Lexer *l);\n"
"\n"
"/* Checks if a Lexer is at the end of its stream\n"
" *\n"
" * PARAMETERS:\n"
" * 	l: a pointer to a Lexer to check\n"
" *\n"
" * RETURNS:\n"
" *	true if the given Lexer is at the end, false otherwise\n"
" */\n"
"bool lexer_at_end(Lexer *l);\n"
"\n"
"/* Reports an error encountered by the Lexer\n"
" *\n"
" * PARAMETERS:\n"
" * 	l: a pointer to a Lexer to propogate the error from\n"
" * 	c: the character that caused the error\n"
" */\n"
"void lexer_report_error(Lexer *l, utf8_int32_t c);\n"
"\n"
"/* Retrieves a token\n"
" *\n"
" * PARAMETERS:\n"
" * 	l: a pointer to a Lexer\n"
" *\n"
" * RETURNS:\n"
" * 	The next Token in the stream\n"
" */\n"
"Token lexer_lex(Lexer *l);\n"
"\n"
"\n"
"#endif\n";
