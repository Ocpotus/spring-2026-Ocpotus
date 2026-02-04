#ifndef C_UNIT_H
#define C_UNIT_H

#include <stdlib.h>

#include "../ast/ast.h"

#include "../../lib/c-vector/cvector.h"


/* Constructs a new unit
 *
 * RETURNS:
 * 	Success: a pointer to a unit
 * 	Failure: NULL
 */
Unit unit_new();

/* Deletes the given Unit and its contents
 *
 * PARAMETERS:
 * 	u: a pointer to a Unit
 */
void unit_delete(Unit u);

/* Retrieves the count of a Unit
 *
 * PARAMETERS:
 * 	u: Unit to inspect
 *
 * RETURNS:
 * 	AST count
 */
size_t unit_count(Unit u);

/* Appends an AST to a Unit
 *
 * PARAMETERS:
 * 	u: Unit to append to
 * 	a: AST to append
 */
void unit_append(Unit u, AST a);

/* Retrieves the AST at the given position
 *
 * PARAMETERS:
 * 	u: unit to retrieve from
 * 	i: AST number to get
 *
 * RETURNS:
 * 	An AST
 */
AST unit_get(Unit u, size_t i);


#endif
