#include <stdarg.h>
#include <stdio.h>

#include "verbum.h"
#include "verbum_ast.h"
#include "verbum_lexer.h"
#include "verbum_token.h"
#include "verbum_parser.h"


static grammar *parser_parse_grammar(Parser *p);
static rule *parser_parse_rule(Parser *p);
static expression *parser_parse_expression(Parser *p);
static list *parser_parse_list(Parser *p);
static term *parser_parse_term(Parser *p);
static factor *parser_parse_factor(Parser *p);
static grammarRepetition0 *parser_parse_grammarRepetition0(Parser *p);
static ruleGroup0 *parser_parse_ruleGroup0(Parser *p);
static expressionRepetition0 *parser_parse_expressionRepetition0(Parser *p);
static listRepetition0 *parser_parse_listRepetition0(Parser *p);
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
	grammar *result = parser_parse_internal(p);

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

grammar *parser_parse_internal(Parser *p) {
	return parser_parse_grammar(p);
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
static grammar *parser_parse_grammar(Parser *p) {
	grammar *result = NULL;
	size_t cp = parser_save(p);
	grammarRepetition0 *grammarRepetition0_0 = parser_parse_grammarRepetition0(p);
	result = verbum_ast_new_grammar(p->ctx, grammarRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static rule *parser_parse_rule(Parser *p) {
	rule *result = NULL;
	size_t cp = parser_save(p);
	ruleGroup0 *ruleGroup0_0 = parser_parse_ruleGroup0(p);
	if(ruleGroup0_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	if(!parser_match(p, verbum_token_get_lexeme_type("="))) {
		goto EXIT;
		// Error, cleanup
	}
	Token literal_0 = parser_previous(p);
	parser_drop(p);
	expression *expression_0 = parser_parse_expression(p);
	if(expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
		goto EXIT;
		// Error, cleanup
	}
	Token literal_1 = parser_previous(p);
	parser_drop(p);
	result = verbum_ast_new_rule(p->ctx, literal_0, literal_1, expression_0, ruleGroup0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static expression *parser_parse_expression(Parser *p) {
	expression *result = NULL;
	size_t cp = parser_save(p);
	list *list_0 = parser_parse_list(p);
	if(list_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	expressionRepetition0 *expressionRepetition0_0 = parser_parse_expressionRepetition0(p);
	result = verbum_ast_new_expression(p->ctx, list_0, expressionRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static list *parser_parse_list(Parser *p) {
	list *result = NULL;
	size_t cp = parser_save(p);
	term *term_0 = parser_parse_term(p);
	if(term_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	listRepetition0 *listRepetition0_0 = parser_parse_listRepetition0(p);
	result = verbum_ast_new_list(p->ctx, listRepetition0_0, term_0);
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
	result = verbum_ast_new_term(p->ctx, factor_0, termOptional0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static factor *parser_parse_factor(Parser *p) {
	factor *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, TokenType_NONTERMINAL_IDENTIFIER)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token NONTERMINAL_IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_factor_choice0(p->ctx, NONTERMINAL_IDENTIFIER_0);
		parser_commit(p);
		result->tag = factorType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, TokenType_TERMINAL_IDENTIFIER)) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token TERMINAL_IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_factor_choice1(p->ctx, TERMINAL_IDENTIFIER_0);
		parser_commit(p);
		result->tag = factorType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, TokenType_LITERAL)) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token LITERAL_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_factor_choice2(p->ctx, LITERAL_0);
		parser_commit(p);
		result->tag = factorType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("["))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_3;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type("]"))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_factor_choice3(p->ctx, literal_0, literal_1, expression_0);
		parser_commit(p);
		result->tag = factorType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("{"))) {
			goto EXIT_4;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_4;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type("}"))) {
			goto EXIT_4;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_factor_choice4(p->ctx, literal_0, literal_1, expression_0);
		parser_commit(p);
		result->tag = factorType_4;
		return result;
	}
EXIT_4:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_5;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_5;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_5;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_factor_choice5(p->ctx, literal_0, literal_1, expression_0);
		parser_commit(p);
		result->tag = factorType_5;
		return result;
	}
EXIT_5:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static grammarRepetition0 *parser_parse_grammarRepetition0(Parser *p) {
	grammarRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		rule *rule_0 = parser_parse_rule(p);
		if(rule_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		grammarRepetition0 *grammarRepetition0_0 = parser_parse_grammarRepetition0(p);


		result = verbum_ast_new_grammarRepetition0_choice0(p->ctx, rule_0, grammarRepetition0_0);
		parser_commit(p);
		result->tag = grammarRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_grammarRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = grammarRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static ruleGroup0 *parser_parse_ruleGroup0(Parser *p) {
	ruleGroup0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, TokenType_NONTERMINAL_IDENTIFIER)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token NONTERMINAL_IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_ruleGroup0_choice0(p->ctx, NONTERMINAL_IDENTIFIER_0);
		parser_commit(p);
		result->tag = ruleGroup0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, TokenType_TERMINAL_IDENTIFIER)) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token TERMINAL_IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_ruleGroup0_choice1(p->ctx, TERMINAL_IDENTIFIER_0);
		parser_commit(p);
		result->tag = ruleGroup0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static expressionRepetition0 *parser_parse_expressionRepetition0(Parser *p) {
	expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("|"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		list *list_0 = parser_parse_list(p);
		if(list_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		expressionRepetition0 *expressionRepetition0_0 = parser_parse_expressionRepetition0(p);


		result = verbum_ast_new_expressionRepetition0_choice0(p->ctx, literal_0, list_0, expressionRepetition0_0);
		parser_commit(p);
		result->tag = expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static listRepetition0 *parser_parse_listRepetition0(Parser *p) {
	listRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(","))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		term *term_0 = parser_parse_term(p);
		if(term_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		listRepetition0 *listRepetition0_0 = parser_parse_listRepetition0(p);


		result = verbum_ast_new_listRepetition0_choice0(p->ctx, listRepetition0_0, literal_0, term_0);
		parser_commit(p);
		result->tag = listRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_listRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = listRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static termOptional0 *parser_parse_termOptional0(Parser *p) {
	termOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("-"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		factor *factor_0 = parser_parse_factor(p);
		if(factor_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_termOptional0_choice0(p->ctx, literal_0, factor_0);
		parser_commit(p);
		result->tag = termOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_termOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = termOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
