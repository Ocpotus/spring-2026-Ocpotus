#include <stdbool.h>
#include <stdio.h>

#include "../../../lib/c-vector/cvector.h"

#include "../../memory/memory.h"
#include "../../ast/ast.h"
#include "../../token/token.h"
#include "../../lexer/lexer.h"

#include "internal.h"


static Grammar parser_parse_grammar(Parser *p);
static Rule parser_parse_rule(Parser *p);
static Expression parser_parse_expression(Parser *p);
static List parser_parse_list(Parser *p);
static Term parser_parse_term(Parser *p);
static Factor parser_parse_factor(Parser *p);

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

Grammar parser_parse_internal(Parser *p) {
	return parser_parse_grammar(p);
}

static Grammar parser_parse_grammar(Parser *p) {
	cvector(Rule) rl1 = NULL;

	while(!parser_match(p, TokenType_EOF)) {
		Rule r1 = parser_parse_rule(p);

		if(p->error != NULL) {
			return (Grammar) { 0 };
		}

		cvector_push_back(rl1, r1);
	}

	return (Grammar) {
		.rule1 = rl1,
	};
}

static Rule parser_parse_rule(Parser *p) {
	static TokenType tts[] = { TokenType_NonTerminal_Identifier, TokenType_Terminal_Identifier };

	if(parser_match_any(p, tts, sizeof(tts) / sizeof(*tts))) {
		Token t1 = parser_previous(p);
		Expression e1 = { 0 };

		if(!parser_match(p, TokenType_Equal)) {
			return (Rule) { 0 };
		}

		e1 = parser_parse_expression(p);

		if(p->error != NULL) {
			return (Rule) { 0 };
		}

		if(!parser_match(p, TokenType_Semicolon)) {
			return (Rule) { 0 };
		}

		Rule r = { .token1 = t1, .expression1 = memory_copy(&e1, sizeof(e1))};
		/* return (Rule) {
			.token1 = t1,
			.expression1 = memory_copy(&e1, sizeof(e1)),
		}; */
		if(r.expression1 == NULL) {
			printf("e is null\n");
		}
		return r;
	}
	
	return (Rule) { 0 };
}

static Expression parser_parse_expression(Parser *p) {
	List l1 = parser_parse_list(p);
	cvector(List) ll1 = NULL;

	if(p->error != NULL) {
		return (Expression) { 0 };
	}

	while(parser_match(p, TokenType_Pipe)) {
		List t2 = parser_parse_list(p);

		if(p->error != NULL) {
			return (Expression) { 0 };
		}

		cvector_push_back(ll1, t2);
	}

	return (Expression) {
		.list1 = l1,
		.list2 = ll1,
	};
}

static List parser_parse_list(Parser *p) {
	Term t1 = parser_parse_term(p);
	cvector(Term) tl1 = NULL;

	if(p->error != NULL) {
		return (List) { 0 };
	}

	while(parser_match(p, TokenType_Comma)) {
		Term t2 = parser_parse_term(p);

		if(p->error != NULL) {
			return (List) { 0 };
		}

		cvector_push_back(tl1, t2);
	}

	return (List) {
		.term1 = t1,
		.term2 = tl1,
	};
}

static Term parser_parse_term(Parser *p) {
	Factor f1 = parser_parse_factor(p);

	if(p->error != NULL) {
		return (Term) { 0 };
	}

	if(parser_match(p, TokenType_Hyphen)) {
		Factor f2 = parser_parse_factor(p);

		if(p->error != NULL) {
			return (Term) { 0 };
		}

		return (Term) {
			.factor1 = f1,
			.factor2 = memory_copy(&f2, sizeof(f2)),
		};
	}

	return (Term) {
		.factor1 = f1,
		.factor2 = NULL,
	};
}

static Factor parser_parse_factor(Parser *p) {
	if(parser_match(p, TokenType_NonTerminal_Identifier)) {
		return ast_new_factor1(parser_previous(p));
	}

	if(parser_match(p, TokenType_Terminal_Identifier)) {
		return ast_new_factor2(parser_previous(p));
	}

	if(parser_match(p, TokenType_Literal)) {
		return ast_new_factor3(parser_previous(p));
	}

	if(parser_match(p, TokenType_LeftBracket)) {
		Expression e = parser_parse_expression(p);

		if(parser_match(p, TokenType_RightBracket)) {
			return ast_new_factor4(e);
		} else {
			return (Factor) { 0 };
		}
	}

	if(parser_match(p, TokenType_LeftBrace)) {
		Expression e = parser_parse_expression(p);

		if(parser_match(p, TokenType_RightBrace)) {
			return ast_new_factor4(e);
		} else {
			return (Factor) { 0 };
		}
	}

	if(parser_match(p, TokenType_LeftParenthesis)) {
		Expression e = parser_parse_expression(p);

		if(parser_match(p, TokenType_RightParenthesis)) {
			return ast_new_factor4(e);

		} else {
			return (Factor) { 0 };
		}
	}

	return (Factor) { 0 };
}
