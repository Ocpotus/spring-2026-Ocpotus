#include <stdarg.h>
#include <stdio.h>

#include "verbum.h"
#include "verbum_ast.h"
#include "verbum_lexer.h"
#include "verbum_token.h"
#include "verbum_parser.h"


static start *parser_parse_start(Parser *p);
static expression *parser_parse_expression(Parser *p);
static term *parser_parse_term(Parser *p);
static factor *parser_parse_factor(Parser *p);
static expressionOptional0 *parser_parse_expressionOptional0(Parser *p);
static termOptional0 *parser_parse_termOptional0(Parser *p);

Parser *parser_new(VerbumContext *ctx, const char *path) {
	Parser *result = ctx->memory.new(1 * sizeof(*result));

	if(result != NULL) {
		result->ctx = ctx;
		result->l = lexer_new(ctx, path);
		result->save = NULL;
		result->savepos = 0;
		result->savedepth = 0;
	}

	return result;
}

static size_t parser_save(Parser *p) {
	p->savedepth += 1;
	return p->savepos;
}

static void parser_rewind(Parser *p, size_t checkpoint) {
	p->savepos = checkpoint;
}
static void parser_commit(Parser *p) {
	if(p->savedepth > 0) {
		p->savedepth -= 1;
	}
}

static void parser_drop(Parser *p) {
	p->save[p->savepos - 1].lexeme = NULL;
}

void parser_delete(Parser *p) {
	cvector_free(p->save);
	lexer_delete(p->l);
	p->ctx->memory.delete(p);
}

AST *parser_parse(Parser *p) {
	start *result = parser_parse_internal(p);

	return result;
}

Token parser_advance2(Parser *p) {
	if(!parser_at_end(p)) {
		Token t;

		do {
			t = lexer_get_token(p->l);
		} while(t.tag == TokenType_Whitespace);

		p->previous = p->current;
		p->current = p->peek;
		p->peek = t;
		p->error = NULL;
	}

	return parser_current(p);
}

Token parser_advance(Parser *p) {
	if(p->savepos < cvector_size(p->save)) {
		return p->save[p->savepos++];
	}

	Token t;

	do {
		t = lexer_get_token(p->l);
	} while(t.tag == TokenType_Whitespace);

	if(p->savedepth > 0) {
		cvector_push_back(p->save, t);
		p->savepos += 1;
	} else {
		cvector_clear(p->save);
		p->save = NULL;
		cvector_push_back(p->save, t);
		p->savepos = 1;
	}

	return t;
}

bool parser_at_end(Parser *p) {
	return parser_current(p).tag == TokenType_EOF;
}

Token parser_previous(Parser *p) {
	if(p->savepos == 0) {
		return (Token) {
			.tag = TokenType_Whitespace,
			.lexeme = NULL,
		};
	}

	return p->save[p->savepos - 1];
}

Token parser_current(Parser *p) {
	return parser_peek(p, 0);
}

Token parser_peek(Parser *p, size_t peek) {
	size_t idx = p->savepos + peek;

	while(idx >= cvector_size(p->save)) {
		Token t = lexer_get_token(p->l);

		if(t.tag != TokenType_Whitespace) {
			cvector_push_back(p->save, t);

			if(t.tag == TokenType_EOF) {
				break;
			}
		}
	}

	if(idx >= cvector_size(p->save)) {
		return p->save[cvector_size(p->save) - 1];
	}

	return p->save[idx];
}

Token parser_peek2(Parser *p) {
	return p->peek;
}

bool parser_check(Parser *p, TokenType tt) {
	return parser_current(p).tag == tt;
}

bool parser_check2(Parser *p, const char *tl) {
	return verbum_token_get_lexeme_type(parser_current(p).lexeme) == verbum_token_get_lexeme_type(tl);
}

bool parser_previous_is(Parser *p, TokenType tt) {
	return parser_previous(p).tag == tt;
}

bool parser_match(Parser *p, TokenType tt) {
	if(parser_check(p, tt)) {
		parser_advance(p);

		return true;
	}

	return false;
}

bool parser_match2(Parser *p, const char *tl) {
	if(parser_check2(p, tl)) {
		parser_advance(p);

		return true;
	}

	return false;
}

bool parser_match_any(Parser *p, TokenType *tts, size_t n) {
	for(size_t i = 0; i < n; i++) {
		if(parser_match(p, tts[i])) {
			return true;
		}
	}

	return false;
}

const char *parser_set_error(Parser *p, const char *error) {
	p->error = error;

	return error;
}

void parser_reset_error(Parser *p) {
	p->error = NULL;
}

bool parser_errored(Parser *p) {
	return p->error != NULL;
}

start *parser_parse_internal(Parser *p) {
	return parser_parse_start(p);
}

static void parser_panic(Parser *p, const char *format, ...) {
	va_list list;
	Token t = { 0 };

	va_start(list, format);
	fprintf(stderr, "Error! (%s)", lexer_get_source(p->l));
	vfprintf(stderr, format, list);
	va_end(list);

	while(!parser_at_end(p)) {
		Token t = parser_current(p);
	}
}
static start *parser_parse_start(Parser *p) {
	start *result = NULL;
	size_t cp = parser_save(p);
	expression *expression_0 = parser_parse_expression(p);
	if(expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	result = verbum_ast_new_start(p->ctx, expression_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static expression *parser_parse_expression(Parser *p) {
	expression *result = NULL;
	size_t cp = parser_save(p);
	term *term_0 = parser_parse_term(p);
	if(term_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	expressionOptional0 *expressionOptional0_0 = parser_parse_expressionOptional0(p);
	expression *expression_0 = parser_parse_expression(p);
	if(expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	result = verbum_ast_new_expression(p->ctx, expression_0, expressionOptional0_0, term_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static term *parser_parse_term(Parser *p) {
	term *result = NULL;
	size_t cp = parser_save(p);
	factor *factor_0 = parser_parse_factor(p);
	if(factor_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	termOptional0 *termOptional0_0 = parser_parse_termOptional0(p);
	term *term_0 = parser_parse_term(p);
	if(term_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	result = verbum_ast_new_term(p->ctx, factor_0, term_0, termOptional0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static factor *parser_parse_factor(Parser *p) {
	factor *result = NULL;
	size_t cp = parser_save(p);
	if(!parser_match(p, TokenType_NUMBER)) {
		goto EXIT;
		// Error, cleanup
	}
	Token NUMBER_0 = parser_previous(p);
	parser_drop(p);
	result = verbum_ast_new_factor(p->ctx, NUMBER_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static expressionOptional0 *parser_parse_expressionOptional0(Parser *p) {
	expressionOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("+"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_expressionOptional0_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = expressionOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("-"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_expressionOptional0_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = expressionOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_expressionOptional0_choice2(p->ctx);
		parser_commit(p);
		result->tag = expressionOptional0Type_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static termOptional0 *parser_parse_termOptional0(Parser *p) {
	termOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("*"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_termOptional0_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = termOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("/"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_termOptional0_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = termOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_termOptional0_choice2(p->ctx);
		parser_commit(p);
		result->tag = termOptional0Type_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
