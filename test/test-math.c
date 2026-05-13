#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "verbum.h"
#include "verbum_token.h"
#include "verbum_lexer.h"
#include "verbum_token.h"
#include "verbum_parser.h"
#include "verbum_ast.h"
#include "utf8file.h"


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

	Parser *p = parser_new(&vc, "test.math");
	AST *math_ast = parser_parse(p);

	verbum_ast_delete_start(&vc, math_ast);
	parser_delete(p);

	return 0;
}
