#include <stdbool.h>
#include <stdio.h>

#include "../../token/token.h"
#include "../../lexer/lexer.h"

#include "internal.h"


Token parser_advance(Parser *p) {
	if(!parser_at_end(p)) {
		Token t;

		do {
			t = lexer_get_token(p->l);
		} while(t.type == TokenType_Whitespace);

		p->previous = p->current;
		p->current = p->peek;
		p->peek = t;
		p->error = NULL;
	}

	return parser_current(p);
}

bool parser_at_end(Parser *p) {
	return parser_current(p).type == TokenType_EOF;
}

Token parser_previous(Parser *p) {
	return p->previous;
}

Token parser_current(Parser *p) {
	return p->current;
}

Token parser_peek(Parser *p) {
	return p->peek;
}

bool parser_check(Parser *p, TokenType tt) {
	return parser_current(p).type == tt;
}

bool parser_previous_is(Parser *p, TokenType tt) {
	return parser_previous(p).type == tt;
}

bool parser_match(Parser *p, TokenType tt) {
	if(parser_check(p, tt)) {
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
