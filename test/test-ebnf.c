#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "verbum_token.h"
#include "verbum_lexer.h"
#include "utf8file.h"
#include "verbum.h"
#include "verbum_token.h"
#include "verbum_parser.h"
#include "verbum_ast.h"


//memory
void *new(size_t n) {
	return malloc(n);
}

void delete(void *ptr) {
	free(ptr);
}

void *resize(void *ptr, size_t size) {
	return realloc(ptr, size);
}

void *copy(void *data, size_t size) {
	void *d = malloc(size);

	return (d == NULL) ? NULL : memcpy(d, data, size);
}
//void *stream;
uint32_t get(void *stream) {
	return utf8file_get_codepoint(stream);
}

uint32_t unget(void *stream) {
	return utf8file_unget_codepoint(stream);
}

uint32_t tell(void *stream) {
	return utf8file_tell(stream);
}

bool at_end(void *stream) {
	return utf8file_at_end(stream);
}

void *open2(const char *path) {
	return utf8file_open(path);
}

void close2(void *stream) {
	return utf8file_close(stream);
}

char *copy_from(void *stream, size_t offset, size_t nbytes) {
	return utf8file_copy_from(stream, offset, nbytes);
}
const char *source(void *stream) {
	return utf8file_path(stream);
}

void p_rg0(ruleGroup0 *rg0) {
	switch(rg0->tag) {
	case ruleGroup0Type_0:
		printf("%s", rg0->choice0.NONTERMINAL_IDENTIFIER_0.lexeme);
		break;
	case ruleGroup0Type_1:
		printf("%s", rg0->choice1.TERMINAL_IDENTIFIER_0.lexeme);
		break;
	default:
		break;
	}
}

void p_e(expression *e);

void p_f(factor *f) {
	switch(f->tag) {
	case factorType_0:
		printf("%s", f->choice0.NONTERMINAL_IDENTIFIER_0.lexeme);
		break;
	case factorType_1:
		printf("%s", f->choice1.TERMINAL_IDENTIFIER_0.lexeme);
		break;
	case factorType_2:
		printf("%s", f->choice2.LITERAL_0.lexeme);
		break;
	case factorType_3:
		printf(" %s ", f->choice3.literal_0.lexeme);
		p_e(f->choice3.expression_0);
		printf(" %s ", f->choice3.literal_1.lexeme);
		break;
	case factorType_4:
		printf(" %s ", f->choice4.literal_0.lexeme);
		p_e(f->choice4.expression_0);
		printf(" %s ", f->choice4.literal_1.lexeme);
		break;
	case factorType_5:
		printf(" %s ", f->choice5.literal_0.lexeme);
		p_e(f->choice5.expression_0);
		printf(" %s ", f->choice5.literal_1.lexeme);
		break;
	default:
		break;
	}
}

void p_to0(termOptional0 *to0) {
	switch(to0->tag) {
	case termOptional0Type_0:
		printf(" %s ", to0->choice0.literal_0.lexeme);
		p_f(to0->choice0.factor_0);
		break;
	case termOptional0Type_1:
		break;
	default:
		break;
	}
}

void p_t(term *t) {
	p_f(t->factor_0);
	p_to0(t->termOptional0_0);
}

void p_lr0(listRepetition0 *lr0) {
	switch(lr0->tag) {
	case listRepetition0Type_0:
		printf(" %s ", lr0->choice0.literal_0.lexeme);
		p_t(lr0->choice0.term_0);
		p_lr0(lr0->choice0.listRepetition0_0);
		break;
	case listRepetition0Type_1:
		break;
	default:
		break;
	}
}

void p_l(list *l) {
	p_t(l->term_0);
	p_lr0(l->listRepetition0_0);
}

void p_er0(expressionRepetition0 *er0) {
	switch(er0->tag) {
	case expressionRepetition0Type_0:
		printf(" %s ", er0->choice0.literal_0.lexeme);
		p_l(er0->choice0.list_0);
		p_er0(er0->choice0.expressionRepetition0_0);
		break;
	case expressionRepetition0Type_1:
		break;
	default:
		break;
	}
}

void p_e(expression *e) {
	p_l(e->list_0);
	p_er0(e->expressionRepetition0_0);
}

void p_r(rule *r) {
	p_rg0(r->ruleGroup0_0);
	printf(" %s ", r->literal_0.lexeme);
	p_e(r->expression_0);
	printf(" %s", r->literal_1.lexeme);
}

void p_gr0(grammarRepetition0 *gr0) {
	switch(gr0->tag) {
	case grammarRepetition0Type_0:
		p_r(gr0->choice0.rule_0);
		printf("\n");
		p_gr0(gr0->choice0.grammarRepetition0_0);
		break;
	case grammarRepetition0Type_1:
		break;
	default:
		break;
	}
}

void print(AST *a) {
	p_gr0(a->grammarRepetition0_0);
}

int main() {
	VerbumContext vc = {
		.io = {
			.source = source,
			.at_end = at_end,
			.close = close2,
			.copy_from = copy_from,
			.get = get,
			.tell = tell,
			.unget = unget,
			.open = open2,
		},
		.memory = {
			.copy = copy,
			.delete = delete,
			.new = new,
			.resize = resize,
		},
	};


	Parser *p = parser_new(&vc, "ebnf/c.ebnf");
	AST *a = parser_parse(p);
	print(a);
	parser_delete(p);
	verbum_ast_delete_grammar(&vc, a);
	putchar('\n');
	/* Lexer *l = lexer_new(&vc, "ebnf.ebnf");
	Token t = { 0 };

	do {
		t = lexer_get_token(l);

		if(t.tag == TokenType_EOF) {
			break;
		}

		if(t.tag != TokenType_Invalid && t.lexeme != NULL && t.tag != TokenType_Whitespace) {
			printf("%s %d\n", t.lexeme, t.tag);
		}

		if(t.tag != TokenType_EOF && t.tag != TokenType_Invalid && t.tag != TokenType_Whitespace) {
			vc.memory.delete((void *)t.lexeme);
		}
	} while(true);

	lexer_delete(l); */

	return 0;
}
