#include <stdbool.h>
#include <stdlib.h>

#include "../../lib/c-vector/cvector.h"
//#include "../../lib/c-vector/cvector_utils.h"

#include "../ast/ast.h"

#include "unit.h"


Unit unit_new() {
	return NULL;
}

void unit_delete(Unit u) {
	//cvector_for_each(u, ast_delete_ast);
	cvector_free(u);
}

size_t unit_count(Unit u) {
	return cvector_capacity(u);
}

void unit_append(Unit u, AST a) {
	cvector_push_back(u, a);
}

AST unit_get(Unit u, size_t i) {
	return u[i];
}
