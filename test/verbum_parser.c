#include <stdarg.h>
#include <stdio.h>

#include "verbum.h"
#include "verbum_ast.h"
#include "verbum_lexer.h"
#include "verbum_token.h"
#include "verbum_parser.h"


static translation_unit *parser_parse_translation_unit(Parser *p);
static external_declaration *parser_parse_external_declaration(Parser *p);
static function_definition *parser_parse_function_definition(Parser *p);
static declaration_specifier *parser_parse_declaration_specifier(Parser *p);
static storage_class_specifier *parser_parse_storage_class_specifier(Parser *p);
static type_specifier *parser_parse_type_specifier(Parser *p);
static struct_or_union_specifier *parser_parse_struct_or_union_specifier(Parser *p);
static struct_or_union *parser_parse_struct_or_union(Parser *p);
static struct_declaration *parser_parse_struct_declaration(Parser *p);
static specifier_qualifier *parser_parse_specifier_qualifier(Parser *p);
static struct_declarator_list *parser_parse_struct_declarator_list(Parser *p);
static struct_declarator *parser_parse_struct_declarator(Parser *p);
static declarator *parser_parse_declarator(Parser *p);
static pointer *parser_parse_pointer(Parser *p);
static type_qualifier *parser_parse_type_qualifier(Parser *p);
static direct_declarator *parser_parse_direct_declarator(Parser *p);
static constant_expression *parser_parse_constant_expression(Parser *p);
static conditional_expression *parser_parse_conditional_expression(Parser *p);
static logical_or_expression *parser_parse_logical_or_expression(Parser *p);
static logical_and_expression *parser_parse_logical_and_expression(Parser *p);
static inclusive_or_expression *parser_parse_inclusive_or_expression(Parser *p);
static exclusive_or_expression *parser_parse_exclusive_or_expression(Parser *p);
static and_expression *parser_parse_and_expression(Parser *p);
static equality_expression *parser_parse_equality_expression(Parser *p);
static relational_expression *parser_parse_relational_expression(Parser *p);
static shift_expression *parser_parse_shift_expression(Parser *p);
static additive_expression *parser_parse_additive_expression(Parser *p);
static multiplicative_expression *parser_parse_multiplicative_expression(Parser *p);
static cast_expression *parser_parse_cast_expression(Parser *p);
static unary_expression *parser_parse_unary_expression(Parser *p);
static postfix_expression *parser_parse_postfix_expression(Parser *p);
static primary_expression *parser_parse_primary_expression(Parser *p);
static constant *parser_parse_constant(Parser *p);
static expression *parser_parse_expression(Parser *p);
static assignment_expression *parser_parse_assignment_expression(Parser *p);
static assignment_operator *parser_parse_assignment_operator(Parser *p);
static unary_operator *parser_parse_unary_operator(Parser *p);
static type_name *parser_parse_type_name(Parser *p);
static parameter_type_list *parser_parse_parameter_type_list(Parser *p);
static parameter_list *parser_parse_parameter_list(Parser *p);
static parameter_declaration *parser_parse_parameter_declaration(Parser *p);
static abstract_declarator *parser_parse_abstract_declarator(Parser *p);
static direct_abstract_declarator *parser_parse_direct_abstract_declarator(Parser *p);
static enum_specifier *parser_parse_enum_specifier(Parser *p);
static enumerator_list *parser_parse_enumerator_list(Parser *p);
static enumerator *parser_parse_enumerator(Parser *p);
static typedef_name *parser_parse_typedef_name(Parser *p);
static declaration *parser_parse_declaration(Parser *p);
static init_declarator *parser_parse_init_declarator(Parser *p);
static initializer *parser_parse_initializer(Parser *p);
static initializer_list *parser_parse_initializer_list(Parser *p);
static compound_statement *parser_parse_compound_statement(Parser *p);
static statement *parser_parse_statement(Parser *p);
static labeled_statement *parser_parse_labeled_statement(Parser *p);
static expression_statement *parser_parse_expression_statement(Parser *p);
static selection_statement *parser_parse_selection_statement(Parser *p);
static iteration_statement *parser_parse_iteration_statement(Parser *p);
static jump_statement *parser_parse_jump_statement(Parser *p);
static translation_unitRepetition0 *parser_parse_translation_unitRepetition0(Parser *p);
static function_definitionRepetition0 *parser_parse_function_definitionRepetition0(Parser *p);
static function_definitionRepetition1 *parser_parse_function_definitionRepetition1(Parser *p);
static struct_or_union_specifierRepetition0 *parser_parse_struct_or_union_specifierRepetition0(Parser *p);
static struct_or_union_specifierRepetition1 *parser_parse_struct_or_union_specifierRepetition1(Parser *p);
static struct_declarationRepetition0 *parser_parse_struct_declarationRepetition0(Parser *p);
static struct_declarator_listRepetition0 *parser_parse_struct_declarator_listRepetition0(Parser *p);
static struct_declaratorOptional0 *parser_parse_struct_declaratorOptional0(Parser *p);
static declaratorOptional0 *parser_parse_declaratorOptional0(Parser *p);
static pointerRepetition0 *parser_parse_pointerRepetition0(Parser *p);
static pointerOptional0 *parser_parse_pointerOptional0(Parser *p);
static direct_declaratorGroup0 *parser_parse_direct_declaratorGroup0(Parser *p);
static direct_declaratorOptional0 *parser_parse_direct_declaratorOptional0(Parser *p);
static direct_declaratorRepetition1 *parser_parse_direct_declaratorRepetition1(Parser *p);
static direct_declaratorRepetition0 *parser_parse_direct_declaratorRepetition0(Parser *p);
static conditional_expressionOptional0 *parser_parse_conditional_expressionOptional0(Parser *p);
static logical_or_expressionRepetition0 *parser_parse_logical_or_expressionRepetition0(Parser *p);
static logical_and_expressionRepetition0 *parser_parse_logical_and_expressionRepetition0(Parser *p);
static inclusive_or_expressionRepetition0 *parser_parse_inclusive_or_expressionRepetition0(Parser *p);
static exclusive_or_expressionRepetition0 *parser_parse_exclusive_or_expressionRepetition0(Parser *p);
static and_expressionRepetition0 *parser_parse_and_expressionRepetition0(Parser *p);
static equality_expressionGroup0 *parser_parse_equality_expressionGroup0(Parser *p);
static equality_expressionRepetition0 *parser_parse_equality_expressionRepetition0(Parser *p);
static relational_expressionGroup0 *parser_parse_relational_expressionGroup0(Parser *p);
static relational_expressionRepetition0 *parser_parse_relational_expressionRepetition0(Parser *p);
static shift_expressionGroup0 *parser_parse_shift_expressionGroup0(Parser *p);
static shift_expressionRepetition0 *parser_parse_shift_expressionRepetition0(Parser *p);
static additive_expressionGroup0 *parser_parse_additive_expressionGroup0(Parser *p);
static additive_expressionRepetition0 *parser_parse_additive_expressionRepetition0(Parser *p);
static multiplicative_expressionGroup0 *parser_parse_multiplicative_expressionGroup0(Parser *p);
static multiplicative_expressionRepetition0 *parser_parse_multiplicative_expressionRepetition0(Parser *p);
static unary_expressionGroup0 *parser_parse_unary_expressionGroup0(Parser *p);
static postfix_expressionRepetition1 *parser_parse_postfix_expressionRepetition1(Parser *p);
static postfix_expressionRepetition0 *parser_parse_postfix_expressionRepetition0(Parser *p);
static expressionRepetition0 *parser_parse_expressionRepetition0(Parser *p);
static type_nameRepetition0 *parser_parse_type_nameRepetition0(Parser *p);
static type_nameOptional0 *parser_parse_type_nameOptional0(Parser *p);
static parameter_type_listOptional0 *parser_parse_parameter_type_listOptional0(Parser *p);
static parameter_listRepetition0 *parser_parse_parameter_listRepetition0(Parser *p);
static parameter_declarationRepetition0 *parser_parse_parameter_declarationRepetition0(Parser *p);
static parameter_declarationOptional0 *parser_parse_parameter_declarationOptional0(Parser *p);
static abstract_declaratorOptional0 *parser_parse_abstract_declaratorOptional0(Parser *p);
static direct_abstract_declaratorOptional0 *parser_parse_direct_abstract_declaratorOptional0(Parser *p);
static direct_abstract_declaratorOptional1 *parser_parse_direct_abstract_declaratorOptional1(Parser *p);
static direct_abstract_declaratorOptional2 *parser_parse_direct_abstract_declaratorOptional2(Parser *p);
static direct_abstract_declaratorOptional3 *parser_parse_direct_abstract_declaratorOptional3(Parser *p);
static enum_specifierOptional0 *parser_parse_enum_specifierOptional0(Parser *p);
static enumerator_listRepetition0 *parser_parse_enumerator_listRepetition0(Parser *p);
static enumeratorOptional0 *parser_parse_enumeratorOptional0(Parser *p);
static declarationRepetition0 *parser_parse_declarationRepetition0(Parser *p);
static declarationRepetition1 *parser_parse_declarationRepetition1(Parser *p);
static init_declaratorOptional0 *parser_parse_init_declaratorOptional0(Parser *p);
static initializerOptional0 *parser_parse_initializerOptional0(Parser *p);
static initializer_listRepetition0 *parser_parse_initializer_listRepetition0(Parser *p);
static compound_statementRepetition0 *parser_parse_compound_statementRepetition0(Parser *p);
static compound_statementRepetition1 *parser_parse_compound_statementRepetition1(Parser *p);
static expression_statementOptional0 *parser_parse_expression_statementOptional0(Parser *p);
static selection_statementOptional0 *parser_parse_selection_statementOptional0(Parser *p);
static iteration_statementOptional0 *parser_parse_iteration_statementOptional0(Parser *p);
static iteration_statementOptional1 *parser_parse_iteration_statementOptional1(Parser *p);
static iteration_statementOptional2 *parser_parse_iteration_statementOptional2(Parser *p);
static jump_statementOptional0 *parser_parse_jump_statementOptional0(Parser *p);

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
	translation_unit *result = parser_parse_internal(p);

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

translation_unit *parser_parse_internal(Parser *p) {
	return parser_parse_translation_unit(p);
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
static translation_unit *parser_parse_translation_unit(Parser *p) {
	translation_unit *result = NULL;
	size_t cp = parser_save(p);
	translation_unitRepetition0 *translation_unitRepetition0_0 = parser_parse_translation_unitRepetition0(p);
	result = verbum_ast_new_translation_unit(p->ctx, translation_unitRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static external_declaration *parser_parse_external_declaration(Parser *p) {
	external_declaration *result = NULL;
	size_t cp = parser_save(p);
	{
		function_definition *function_definition_0 = parser_parse_function_definition(p);
		if(function_definition_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_external_declaration_choice0(p->ctx, function_definition_0);
		parser_commit(p);
		result->tag = external_declarationType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		declaration *declaration_0 = parser_parse_declaration(p);
		if(declaration_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_external_declaration_choice1(p->ctx, declaration_0);
		parser_commit(p);
		result->tag = external_declarationType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static function_definition *parser_parse_function_definition(Parser *p) {
	function_definition *result = NULL;
	size_t cp = parser_save(p);
	function_definitionRepetition0 *function_definitionRepetition0_0 = parser_parse_function_definitionRepetition0(p);
	declarator *declarator_0 = parser_parse_declarator(p);
	if(declarator_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	function_definitionRepetition1 *function_definitionRepetition1_0 = parser_parse_function_definitionRepetition1(p);
	compound_statement *compound_statement_0 = parser_parse_compound_statement(p);
	if(compound_statement_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	result = verbum_ast_new_function_definition(p->ctx, function_definitionRepetition0_0, compound_statement_0, declarator_0, function_definitionRepetition1_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static declaration_specifier *parser_parse_declaration_specifier(Parser *p) {
	declaration_specifier *result = NULL;
	size_t cp = parser_save(p);
	{
		storage_class_specifier *storage_class_specifier_0 = parser_parse_storage_class_specifier(p);
		if(storage_class_specifier_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_declaration_specifier_choice0(p->ctx, storage_class_specifier_0);
		parser_commit(p);
		result->tag = declaration_specifierType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		type_specifier *type_specifier_0 = parser_parse_type_specifier(p);
		if(type_specifier_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_declaration_specifier_choice1(p->ctx, type_specifier_0);
		parser_commit(p);
		result->tag = declaration_specifierType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		type_qualifier *type_qualifier_0 = parser_parse_type_qualifier(p);
		if(type_qualifier_0 == NULL) {
			goto EXIT_2;
			// Error cleanup
		}

		result = verbum_ast_new_declaration_specifier_choice2(p->ctx, type_qualifier_0);
		parser_commit(p);
		result->tag = declaration_specifierType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static storage_class_specifier *parser_parse_storage_class_specifier(Parser *p) {
	storage_class_specifier *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("auto"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_storage_class_specifier_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = storage_class_specifierType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("register"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_storage_class_specifier_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = storage_class_specifierType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("static"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_storage_class_specifier_choice2(p->ctx, literal_0);
		parser_commit(p);
		result->tag = storage_class_specifierType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("extern"))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_storage_class_specifier_choice3(p->ctx, literal_0);
		parser_commit(p);
		result->tag = storage_class_specifierType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("typedef"))) {
			goto EXIT_4;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_storage_class_specifier_choice4(p->ctx, literal_0);
		parser_commit(p);
		result->tag = storage_class_specifierType_4;
		return result;
	}
EXIT_4:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static type_specifier *parser_parse_type_specifier(Parser *p) {
	type_specifier *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("void"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_type_specifier_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_specifierType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("char"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_type_specifier_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_specifierType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("short"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_type_specifier_choice2(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_specifierType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("int"))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_type_specifier_choice3(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_specifierType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("long"))) {
			goto EXIT_4;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_type_specifier_choice4(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_specifierType_4;
		return result;
	}
EXIT_4:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("float"))) {
			goto EXIT_5;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_type_specifier_choice5(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_specifierType_5;
		return result;
	}
EXIT_5:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("double"))) {
			goto EXIT_6;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_type_specifier_choice6(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_specifierType_6;
		return result;
	}
EXIT_6:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("signed"))) {
			goto EXIT_7;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_type_specifier_choice7(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_specifierType_7;
		return result;
	}
EXIT_7:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("unsigned"))) {
			goto EXIT_8;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_type_specifier_choice8(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_specifierType_8;
		return result;
	}
EXIT_8:
	parser_rewind(p, cp);
	{
		struct_or_union_specifier *struct_or_union_specifier_0 = parser_parse_struct_or_union_specifier(p);
		if(struct_or_union_specifier_0 == NULL) {
			goto EXIT_9;
			// Error cleanup
		}

		result = verbum_ast_new_type_specifier_choice9(p->ctx, struct_or_union_specifier_0);
		parser_commit(p);
		result->tag = type_specifierType_9;
		return result;
	}
EXIT_9:
	parser_rewind(p, cp);
	{
		enum_specifier *enum_specifier_0 = parser_parse_enum_specifier(p);
		if(enum_specifier_0 == NULL) {
			goto EXIT_10;
			// Error cleanup
		}

		result = verbum_ast_new_type_specifier_choice10(p->ctx, enum_specifier_0);
		parser_commit(p);
		result->tag = type_specifierType_10;
		return result;
	}
EXIT_10:
	parser_rewind(p, cp);
	{
		typedef_name *typedef_name_0 = parser_parse_typedef_name(p);
		if(typedef_name_0 == NULL) {
			goto EXIT_11;
			// Error cleanup
		}

		result = verbum_ast_new_type_specifier_choice11(p->ctx, typedef_name_0);
		parser_commit(p);
		result->tag = type_specifierType_11;
		return result;
	}
EXIT_11:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_or_union_specifier *parser_parse_struct_or_union_specifier(Parser *p) {
	struct_or_union_specifier *result = NULL;
	size_t cp = parser_save(p);
	{
		struct_or_union *struct_or_union_0 = parser_parse_struct_or_union(p);
		if(struct_or_union_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("{"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		struct_declaration *struct_declaration_0 = parser_parse_struct_declaration(p);
		if(struct_declaration_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		struct_or_union_specifierRepetition0 *struct_or_union_specifierRepetition0_0 = parser_parse_struct_or_union_specifierRepetition0(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("}"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_struct_or_union_specifier_choice0(p->ctx, literal_0, literal_1, struct_or_union_specifierRepetition0_0, struct_declaration_0, struct_or_union_0, IDENTIFIER_0);
		parser_commit(p);
		result->tag = struct_or_union_specifierType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		struct_or_union *struct_or_union_0 = parser_parse_struct_or_union(p);
		if(struct_or_union_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type("{"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		struct_declaration *struct_declaration_0 = parser_parse_struct_declaration(p);
		if(struct_declaration_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		struct_or_union_specifierRepetition1 *struct_or_union_specifierRepetition1_0 = parser_parse_struct_or_union_specifierRepetition1(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("}"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_struct_or_union_specifier_choice1(p->ctx, struct_or_union_specifierRepetition1_0, literal_0, literal_1, struct_declaration_0, struct_or_union_0);
		parser_commit(p);
		result->tag = struct_or_union_specifierType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		struct_or_union *struct_or_union_0 = parser_parse_struct_or_union(p);
		if(struct_or_union_0 == NULL) {
			goto EXIT_2;
			// Error cleanup
		}
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_struct_or_union_specifier_choice2(p->ctx, struct_or_union_0, IDENTIFIER_0);
		parser_commit(p);
		result->tag = struct_or_union_specifierType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_or_union *parser_parse_struct_or_union(Parser *p) {
	struct_or_union *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("struct"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_struct_or_union_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = struct_or_unionType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("union"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_struct_or_union_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = struct_or_unionType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_declaration *parser_parse_struct_declaration(Parser *p) {
	struct_declaration *result = NULL;
	size_t cp = parser_save(p);
	struct_declarationRepetition0 *struct_declarationRepetition0_0 = parser_parse_struct_declarationRepetition0(p);
	struct_declarator_list *struct_declarator_list_0 = parser_parse_struct_declarator_list(p);
	if(struct_declarator_list_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	result = verbum_ast_new_struct_declaration(p->ctx, struct_declarationRepetition0_0, struct_declarator_list_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static specifier_qualifier *parser_parse_specifier_qualifier(Parser *p) {
	specifier_qualifier *result = NULL;
	size_t cp = parser_save(p);
	{
		type_specifier *type_specifier_0 = parser_parse_type_specifier(p);
		if(type_specifier_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_specifier_qualifier_choice0(p->ctx, type_specifier_0);
		parser_commit(p);
		result->tag = specifier_qualifierType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		type_qualifier *type_qualifier_0 = parser_parse_type_qualifier(p);
		if(type_qualifier_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_specifier_qualifier_choice1(p->ctx, type_qualifier_0);
		parser_commit(p);
		result->tag = specifier_qualifierType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_declarator_list *parser_parse_struct_declarator_list(Parser *p) {
	struct_declarator_list *result = NULL;
	size_t cp = parser_save(p);
	struct_declarator *struct_declarator_0 = parser_parse_struct_declarator(p);
	if(struct_declarator_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	struct_declarator_listRepetition0 *struct_declarator_listRepetition0_0 = parser_parse_struct_declarator_listRepetition0(p);
	result = verbum_ast_new_struct_declarator_list(p->ctx, struct_declarator_0, struct_declarator_listRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_declarator *parser_parse_struct_declarator(Parser *p) {
	struct_declarator *result = NULL;
	size_t cp = parser_save(p);
	{
		declarator *declarator_0 = parser_parse_declarator(p);
		if(declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_struct_declarator_choice0(p->ctx, declarator_0);
		parser_commit(p);
		result->tag = struct_declaratorType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		struct_declaratorOptional0 *struct_declaratorOptional0_0 = parser_parse_struct_declaratorOptional0(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(":"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		constant_expression *constant_expression_0 = parser_parse_constant_expression(p);
		if(constant_expression_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_struct_declarator_choice1(p->ctx, literal_0, struct_declaratorOptional0_0, constant_expression_0);
		parser_commit(p);
		result->tag = struct_declaratorType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static declarator *parser_parse_declarator(Parser *p) {
	declarator *result = NULL;
	size_t cp = parser_save(p);
	declaratorOptional0 *declaratorOptional0_0 = parser_parse_declaratorOptional0(p);
	direct_declarator *direct_declarator_0 = parser_parse_direct_declarator(p);
	if(direct_declarator_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	result = verbum_ast_new_declarator(p->ctx, direct_declarator_0, declaratorOptional0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static pointer *parser_parse_pointer(Parser *p) {
	pointer *result = NULL;
	size_t cp = parser_save(p);
	if(!parser_match(p, verbum_token_get_lexeme_type("*"))) {
		goto EXIT;
		// Error, cleanup
	}
	Token literal_0 = parser_previous(p);
	parser_drop(p);
	pointerRepetition0 *pointerRepetition0_0 = parser_parse_pointerRepetition0(p);
	pointerOptional0 *pointerOptional0_0 = parser_parse_pointerOptional0(p);
	result = verbum_ast_new_pointer(p->ctx, literal_0, pointerOptional0_0, pointerRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static type_qualifier *parser_parse_type_qualifier(Parser *p) {
	type_qualifier *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("const"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_type_qualifier_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_qualifierType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("volatile"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_type_qualifier_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = type_qualifierType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_declarator *parser_parse_direct_declarator(Parser *p) {
	direct_declarator *result = NULL;
	size_t cp = parser_save(p);
	direct_declaratorGroup0 *direct_declaratorGroup0_0 = parser_parse_direct_declaratorGroup0(p);
	if(direct_declaratorGroup0_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	direct_declaratorRepetition0 *direct_declaratorRepetition0_0 = parser_parse_direct_declaratorRepetition0(p);
	result = verbum_ast_new_direct_declarator(p->ctx, direct_declaratorGroup0_0, direct_declaratorRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static constant_expression *parser_parse_constant_expression(Parser *p) {
	constant_expression *result = NULL;
	size_t cp = parser_save(p);
	conditional_expression *conditional_expression_0 = parser_parse_conditional_expression(p);
	if(conditional_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	result = verbum_ast_new_constant_expression(p->ctx, conditional_expression_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static conditional_expression *parser_parse_conditional_expression(Parser *p) {
	conditional_expression *result = NULL;
	size_t cp = parser_save(p);
	logical_or_expression *logical_or_expression_0 = parser_parse_logical_or_expression(p);
	if(logical_or_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	conditional_expressionOptional0 *conditional_expressionOptional0_0 = parser_parse_conditional_expressionOptional0(p);
	result = verbum_ast_new_conditional_expression(p->ctx, conditional_expressionOptional0_0, logical_or_expression_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static logical_or_expression *parser_parse_logical_or_expression(Parser *p) {
	logical_or_expression *result = NULL;
	size_t cp = parser_save(p);
	logical_and_expression *logical_and_expression_0 = parser_parse_logical_and_expression(p);
	if(logical_and_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	logical_or_expressionRepetition0 *logical_or_expressionRepetition0_0 = parser_parse_logical_or_expressionRepetition0(p);
	result = verbum_ast_new_logical_or_expression(p->ctx, logical_and_expression_0, logical_or_expressionRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static logical_and_expression *parser_parse_logical_and_expression(Parser *p) {
	logical_and_expression *result = NULL;
	size_t cp = parser_save(p);
	inclusive_or_expression *inclusive_or_expression_0 = parser_parse_inclusive_or_expression(p);
	if(inclusive_or_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	logical_and_expressionRepetition0 *logical_and_expressionRepetition0_0 = parser_parse_logical_and_expressionRepetition0(p);
	result = verbum_ast_new_logical_and_expression(p->ctx, logical_and_expressionRepetition0_0, inclusive_or_expression_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static inclusive_or_expression *parser_parse_inclusive_or_expression(Parser *p) {
	inclusive_or_expression *result = NULL;
	size_t cp = parser_save(p);
	exclusive_or_expression *exclusive_or_expression_0 = parser_parse_exclusive_or_expression(p);
	if(exclusive_or_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	inclusive_or_expressionRepetition0 *inclusive_or_expressionRepetition0_0 = parser_parse_inclusive_or_expressionRepetition0(p);
	result = verbum_ast_new_inclusive_or_expression(p->ctx, inclusive_or_expressionRepetition0_0, exclusive_or_expression_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static exclusive_or_expression *parser_parse_exclusive_or_expression(Parser *p) {
	exclusive_or_expression *result = NULL;
	size_t cp = parser_save(p);
	and_expression *and_expression_0 = parser_parse_and_expression(p);
	if(and_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	exclusive_or_expressionRepetition0 *exclusive_or_expressionRepetition0_0 = parser_parse_exclusive_or_expressionRepetition0(p);
	result = verbum_ast_new_exclusive_or_expression(p->ctx, exclusive_or_expressionRepetition0_0, and_expression_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static and_expression *parser_parse_and_expression(Parser *p) {
	and_expression *result = NULL;
	size_t cp = parser_save(p);
	equality_expression *equality_expression_0 = parser_parse_equality_expression(p);
	if(equality_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	and_expressionRepetition0 *and_expressionRepetition0_0 = parser_parse_and_expressionRepetition0(p);
	result = verbum_ast_new_and_expression(p->ctx, and_expressionRepetition0_0, equality_expression_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static equality_expression *parser_parse_equality_expression(Parser *p) {
	equality_expression *result = NULL;
	size_t cp = parser_save(p);
	relational_expression *relational_expression_0 = parser_parse_relational_expression(p);
	if(relational_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	equality_expressionRepetition0 *equality_expressionRepetition0_0 = parser_parse_equality_expressionRepetition0(p);
	result = verbum_ast_new_equality_expression(p->ctx, relational_expression_0, equality_expressionRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static relational_expression *parser_parse_relational_expression(Parser *p) {
	relational_expression *result = NULL;
	size_t cp = parser_save(p);
	shift_expression *shift_expression_0 = parser_parse_shift_expression(p);
	if(shift_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	relational_expressionRepetition0 *relational_expressionRepetition0_0 = parser_parse_relational_expressionRepetition0(p);
	result = verbum_ast_new_relational_expression(p->ctx, shift_expression_0, relational_expressionRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static shift_expression *parser_parse_shift_expression(Parser *p) {
	shift_expression *result = NULL;
	size_t cp = parser_save(p);
	additive_expression *additive_expression_0 = parser_parse_additive_expression(p);
	if(additive_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	shift_expressionRepetition0 *shift_expressionRepetition0_0 = parser_parse_shift_expressionRepetition0(p);
	result = verbum_ast_new_shift_expression(p->ctx, shift_expressionRepetition0_0, additive_expression_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static additive_expression *parser_parse_additive_expression(Parser *p) {
	additive_expression *result = NULL;
	size_t cp = parser_save(p);
	multiplicative_expression *multiplicative_expression_0 = parser_parse_multiplicative_expression(p);
	if(multiplicative_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	additive_expressionRepetition0 *additive_expressionRepetition0_0 = parser_parse_additive_expressionRepetition0(p);
	result = verbum_ast_new_additive_expression(p->ctx, additive_expressionRepetition0_0, multiplicative_expression_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static multiplicative_expression *parser_parse_multiplicative_expression(Parser *p) {
	multiplicative_expression *result = NULL;
	size_t cp = parser_save(p);
	cast_expression *cast_expression_0 = parser_parse_cast_expression(p);
	if(cast_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	multiplicative_expressionRepetition0 *multiplicative_expressionRepetition0_0 = parser_parse_multiplicative_expressionRepetition0(p);
	result = verbum_ast_new_multiplicative_expression(p->ctx, cast_expression_0, multiplicative_expressionRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static cast_expression *parser_parse_cast_expression(Parser *p) {
	cast_expression *result = NULL;
	size_t cp = parser_save(p);
	{
		unary_expression *unary_expression_0 = parser_parse_unary_expression(p);
		if(unary_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_cast_expression_choice0(p->ctx, unary_expression_0);
		parser_commit(p);
		result->tag = cast_expressionType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		type_name *type_name_0 = parser_parse_type_name(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		cast_expression *cast_expression_0 = parser_parse_cast_expression(p);
		if(cast_expression_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_cast_expression_choice1(p->ctx, literal_0, literal_1, type_name_0, cast_expression_0);
		parser_commit(p);
		result->tag = cast_expressionType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static unary_expression *parser_parse_unary_expression(Parser *p) {
	unary_expression *result = NULL;
	size_t cp = parser_save(p);
	{
		postfix_expression *postfix_expression_0 = parser_parse_postfix_expression(p);
		if(postfix_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_unary_expression_choice0(p->ctx, postfix_expression_0);
		parser_commit(p);
		result->tag = unary_expressionType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("++"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		unary_expression *unary_expression_0 = parser_parse_unary_expression(p);
		if(unary_expression_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_unary_expression_choice1(p->ctx, literal_0, unary_expression_0);
		parser_commit(p);
		result->tag = unary_expressionType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("--"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		unary_expression *unary_expression_0 = parser_parse_unary_expression(p);
		if(unary_expression_0 == NULL) {
			goto EXIT_2;
			// Error cleanup
		}

		result = verbum_ast_new_unary_expression_choice2(p->ctx, literal_0, unary_expression_0);
		parser_commit(p);
		result->tag = unary_expressionType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		unary_operator *unary_operator_0 = parser_parse_unary_operator(p);
		if(unary_operator_0 == NULL) {
			goto EXIT_3;
			// Error cleanup
		}
		cast_expression *cast_expression_0 = parser_parse_cast_expression(p);
		if(cast_expression_0 == NULL) {
			goto EXIT_3;
			// Error cleanup
		}

		result = verbum_ast_new_unary_expression_choice3(p->ctx, unary_operator_0, cast_expression_0);
		parser_commit(p);
		result->tag = unary_expressionType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("sizeof"))) {
			goto EXIT_4;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		unary_expressionGroup0 *unary_expressionGroup0_0 = parser_parse_unary_expressionGroup0(p);

		result = verbum_ast_new_unary_expression_choice4(p->ctx, literal_0, unary_expressionGroup0_0);
		parser_commit(p);
		result->tag = unary_expressionType_4;
		return result;
	}
EXIT_4:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static postfix_expression *parser_parse_postfix_expression(Parser *p) {
	postfix_expression *result = NULL;
	size_t cp = parser_save(p);
	primary_expression *primary_expression_0 = parser_parse_primary_expression(p);
	if(primary_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	postfix_expressionRepetition0 *postfix_expressionRepetition0_0 = parser_parse_postfix_expressionRepetition0(p);
	result = verbum_ast_new_postfix_expression(p->ctx, primary_expression_0, postfix_expressionRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static primary_expression *parser_parse_primary_expression(Parser *p) {
	primary_expression *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_primary_expression_choice0(p->ctx, IDENTIFIER_0);
		parser_commit(p);
		result->tag = primary_expressionType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		constant *constant_0 = parser_parse_constant(p);
		if(constant_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_primary_expression_choice1(p->ctx, constant_0);
		parser_commit(p);
		result->tag = primary_expressionType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, TokenType_STRING)) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token STRING_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_primary_expression_choice2(p->ctx, STRING_0);
		parser_commit(p);
		result->tag = primary_expressionType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
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
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_primary_expression_choice3(p->ctx, literal_0, literal_1, expression_0);
		parser_commit(p);
		result->tag = primary_expressionType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static constant *parser_parse_constant(Parser *p) {
	constant *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, TokenType_INTEGER_CONSTANT)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token INTEGER_CONSTANT_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_constant_choice0(p->ctx, INTEGER_CONSTANT_0);
		parser_commit(p);
		result->tag = constantType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, TokenType_CHARACTER_CONSTANT)) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token CHARACTER_CONSTANT_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_constant_choice1(p->ctx, CHARACTER_CONSTANT_0);
		parser_commit(p);
		result->tag = constantType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, TokenType_FLOATING_CONSTANT)) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token FLOATING_CONSTANT_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_constant_choice2(p->ctx, FLOATING_CONSTANT_0);
		parser_commit(p);
		result->tag = constantType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, TokenType_ENUMERATION_CONSTANT)) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token ENUMERATION_CONSTANT_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_constant_choice3(p->ctx, ENUMERATION_CONSTANT_0);
		parser_commit(p);
		result->tag = constantType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static expression *parser_parse_expression(Parser *p) {
	expression *result = NULL;
	size_t cp = parser_save(p);
	assignment_expression *assignment_expression_0 = parser_parse_assignment_expression(p);
	if(assignment_expression_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	expressionRepetition0 *expressionRepetition0_0 = parser_parse_expressionRepetition0(p);
	result = verbum_ast_new_expression(p->ctx, assignment_expression_0, expressionRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static assignment_expression *parser_parse_assignment_expression(Parser *p) {
	assignment_expression *result = NULL;
	size_t cp = parser_save(p);
	{
		conditional_expression *conditional_expression_0 = parser_parse_conditional_expression(p);
		if(conditional_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_assignment_expression_choice0(p->ctx, conditional_expression_0);
		parser_commit(p);
		result->tag = assignment_expressionType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		unary_expression *unary_expression_0 = parser_parse_unary_expression(p);
		if(unary_expression_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		assignment_operator *assignment_operator_0 = parser_parse_assignment_operator(p);
		if(assignment_operator_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		assignment_expression *assignment_expression_0 = parser_parse_assignment_expression(p);
		if(assignment_expression_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_assignment_expression_choice1(p->ctx, assignment_expression_0, assignment_operator_0, unary_expression_0);
		parser_commit(p);
		result->tag = assignment_expressionType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static assignment_operator *parser_parse_assignment_operator(Parser *p) {
	assignment_operator *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("="))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_assignment_operator_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("*="))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("/="))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice2(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("%="))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice3(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("+="))) {
			goto EXIT_4;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice4(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_4;
		return result;
	}
EXIT_4:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("-="))) {
			goto EXIT_5;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice5(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_5;
		return result;
	}
EXIT_5:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("<<="))) {
			goto EXIT_6;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice6(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_6;
		return result;
	}
EXIT_6:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(">>="))) {
			goto EXIT_7;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice7(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_7;
		return result;
	}
EXIT_7:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("&="))) {
			goto EXIT_8;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice8(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_8;
		return result;
	}
EXIT_8:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("^="))) {
			goto EXIT_9;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice9(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_9;
		return result;
	}
EXIT_9:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("|="))) {
			goto EXIT_10;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_assignment_operator_choice10(p->ctx, literal_0);
		parser_commit(p);
		result->tag = assignment_operatorType_10;
		return result;
	}
EXIT_10:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static unary_operator *parser_parse_unary_operator(Parser *p) {
	unary_operator *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("&"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_unary_operator_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = unary_operatorType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("*"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_unary_operator_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = unary_operatorType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("+"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_unary_operator_choice2(p->ctx, literal_0);
		parser_commit(p);
		result->tag = unary_operatorType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("-"))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_unary_operator_choice3(p->ctx, literal_0);
		parser_commit(p);
		result->tag = unary_operatorType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("~"))) {
			goto EXIT_4;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_unary_operator_choice4(p->ctx, literal_0);
		parser_commit(p);
		result->tag = unary_operatorType_4;
		return result;
	}
EXIT_4:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("!"))) {
			goto EXIT_5;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_unary_operator_choice5(p->ctx, literal_0);
		parser_commit(p);
		result->tag = unary_operatorType_5;
		return result;
	}
EXIT_5:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static type_name *parser_parse_type_name(Parser *p) {
	type_name *result = NULL;
	size_t cp = parser_save(p);
	type_nameRepetition0 *type_nameRepetition0_0 = parser_parse_type_nameRepetition0(p);
	type_nameOptional0 *type_nameOptional0_0 = parser_parse_type_nameOptional0(p);
	result = verbum_ast_new_type_name(p->ctx, type_nameRepetition0_0, type_nameOptional0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static parameter_type_list *parser_parse_parameter_type_list(Parser *p) {
	parameter_type_list *result = NULL;
	size_t cp = parser_save(p);
	parameter_list *parameter_list_0 = parser_parse_parameter_list(p);
	if(parameter_list_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	parameter_type_listOptional0 *parameter_type_listOptional0_0 = parser_parse_parameter_type_listOptional0(p);
	result = verbum_ast_new_parameter_type_list(p->ctx, parameter_list_0, parameter_type_listOptional0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static parameter_list *parser_parse_parameter_list(Parser *p) {
	parameter_list *result = NULL;
	size_t cp = parser_save(p);
	parameter_declaration *parameter_declaration_0 = parser_parse_parameter_declaration(p);
	if(parameter_declaration_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	parameter_listRepetition0 *parameter_listRepetition0_0 = parser_parse_parameter_listRepetition0(p);
	result = verbum_ast_new_parameter_list(p->ctx, parameter_listRepetition0_0, parameter_declaration_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static parameter_declaration *parser_parse_parameter_declaration(Parser *p) {
	parameter_declaration *result = NULL;
	size_t cp = parser_save(p);
	declaration_specifier *declaration_specifier_0 = parser_parse_declaration_specifier(p);
	if(declaration_specifier_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	parameter_declarationRepetition0 *parameter_declarationRepetition0_0 = parser_parse_parameter_declarationRepetition0(p);
	parameter_declarationOptional0 *parameter_declarationOptional0_0 = parser_parse_parameter_declarationOptional0(p);
	result = verbum_ast_new_parameter_declaration(p->ctx, parameter_declarationRepetition0_0, declaration_specifier_0, parameter_declarationOptional0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static abstract_declarator *parser_parse_abstract_declarator(Parser *p) {
	abstract_declarator *result = NULL;
	size_t cp = parser_save(p);
	{
		pointer *pointer_0 = parser_parse_pointer(p);
		if(pointer_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		abstract_declaratorOptional0 *abstract_declaratorOptional0_0 = parser_parse_abstract_declaratorOptional0(p);


		result = verbum_ast_new_abstract_declarator_choice0(p->ctx, abstract_declaratorOptional0_0, pointer_0);
		parser_commit(p);
		result->tag = abstract_declaratorType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		direct_abstract_declarator *direct_abstract_declarator_0 = parser_parse_direct_abstract_declarator(p);
		if(direct_abstract_declarator_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_abstract_declarator_choice1(p->ctx, direct_abstract_declarator_0);
		parser_commit(p);
		result->tag = abstract_declaratorType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_abstract_declarator *parser_parse_direct_abstract_declarator(Parser *p) {
	direct_abstract_declarator *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		abstract_declarator *abstract_declarator_0 = parser_parse_abstract_declarator(p);
		if(abstract_declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_direct_abstract_declarator_choice0(p->ctx, literal_0, literal_1, abstract_declarator_0);
		parser_commit(p);
		result->tag = direct_abstract_declaratorType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		direct_abstract_declaratorOptional0 *direct_abstract_declaratorOptional0_0 = parser_parse_direct_abstract_declaratorOptional0(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("["))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		direct_abstract_declaratorOptional1 *direct_abstract_declaratorOptional1_0 = parser_parse_direct_abstract_declaratorOptional1(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("]"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_direct_abstract_declarator_choice1(p->ctx, literal_0, literal_1, direct_abstract_declaratorOptional1_0, direct_abstract_declaratorOptional0_0);
		parser_commit(p);
		result->tag = direct_abstract_declaratorType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		direct_abstract_declaratorOptional2 *direct_abstract_declaratorOptional2_0 = parser_parse_direct_abstract_declaratorOptional2(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		direct_abstract_declaratorOptional3 *direct_abstract_declaratorOptional3_0 = parser_parse_direct_abstract_declaratorOptional3(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_direct_abstract_declarator_choice2(p->ctx, literal_0, literal_1, direct_abstract_declaratorOptional2_0, direct_abstract_declaratorOptional3_0);
		parser_commit(p);
		result->tag = direct_abstract_declaratorType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static enum_specifier *parser_parse_enum_specifier(Parser *p) {
	enum_specifier *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("enum"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		enum_specifierOptional0 *enum_specifierOptional0_0 = parser_parse_enum_specifierOptional0(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("{"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		enumerator_list *enumerator_list_0 = parser_parse_enumerator_list(p);
		if(enumerator_list_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type("}"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_2 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_enum_specifier_choice0(p->ctx, literal_0, literal_1, literal_2, enumerator_list_0, enum_specifierOptional0_0);
		parser_commit(p);
		result->tag = enum_specifierType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("enum"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_enum_specifier_choice1(p->ctx, literal_0, IDENTIFIER_0);
		parser_commit(p);
		result->tag = enum_specifierType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static enumerator_list *parser_parse_enumerator_list(Parser *p) {
	enumerator_list *result = NULL;
	size_t cp = parser_save(p);
	enumerator *enumerator_0 = parser_parse_enumerator(p);
	if(enumerator_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	enumerator_listRepetition0 *enumerator_listRepetition0_0 = parser_parse_enumerator_listRepetition0(p);
	result = verbum_ast_new_enumerator_list(p->ctx, enumerator_0, enumerator_listRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static enumerator *parser_parse_enumerator(Parser *p) {
	enumerator *result = NULL;
	size_t cp = parser_save(p);
	if(!parser_match(p, TokenType_IDENTIFIER)) {
		goto EXIT;
		// Error, cleanup
	}
	Token IDENTIFIER_0 = parser_previous(p);
	parser_drop(p);
	enumeratorOptional0 *enumeratorOptional0_0 = parser_parse_enumeratorOptional0(p);
	result = verbum_ast_new_enumerator(p->ctx, IDENTIFIER_0, enumeratorOptional0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static typedef_name *parser_parse_typedef_name(Parser *p) {
	typedef_name *result = NULL;
	size_t cp = parser_save(p);
	if(!parser_match(p, TokenType_IDENTIFIER)) {
		goto EXIT;
		// Error, cleanup
	}
	Token IDENTIFIER_0 = parser_previous(p);
	parser_drop(p);
	result = verbum_ast_new_typedef_name(p->ctx, IDENTIFIER_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static declaration *parser_parse_declaration(Parser *p) {
	declaration *result = NULL;
	size_t cp = parser_save(p);
	declarationRepetition0 *declarationRepetition0_0 = parser_parse_declarationRepetition0(p);
	declarationRepetition1 *declarationRepetition1_0 = parser_parse_declarationRepetition1(p);
	if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
		goto EXIT;
		// Error, cleanup
	}
	Token literal_0 = parser_previous(p);
	parser_drop(p);
	result = verbum_ast_new_declaration(p->ctx, literal_0, declarationRepetition1_0, declarationRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static init_declarator *parser_parse_init_declarator(Parser *p) {
	init_declarator *result = NULL;
	size_t cp = parser_save(p);
	declarator *declarator_0 = parser_parse_declarator(p);
	if(declarator_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	init_declaratorOptional0 *init_declaratorOptional0_0 = parser_parse_init_declaratorOptional0(p);
	result = verbum_ast_new_init_declarator(p->ctx, init_declaratorOptional0_0, declarator_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static initializer *parser_parse_initializer(Parser *p) {
	initializer *result = NULL;
	size_t cp = parser_save(p);
	{
		assignment_expression *assignment_expression_0 = parser_parse_assignment_expression(p);
		if(assignment_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_initializer_choice0(p->ctx, assignment_expression_0);
		parser_commit(p);
		result->tag = initializerType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("{"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		initializer_list *initializer_list_0 = parser_parse_initializer_list(p);
		if(initializer_list_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		initializerOptional0 *initializerOptional0_0 = parser_parse_initializerOptional0(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("}"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_initializer_choice1(p->ctx, initializer_list_0, literal_0, literal_1, initializerOptional0_0);
		parser_commit(p);
		result->tag = initializerType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static initializer_list *parser_parse_initializer_list(Parser *p) {
	initializer_list *result = NULL;
	size_t cp = parser_save(p);
	initializer *initializer_0 = parser_parse_initializer(p);
	if(initializer_0 == NULL) {
		goto EXIT;
		// Error cleanup
	}
	initializer_listRepetition0 *initializer_listRepetition0_0 = parser_parse_initializer_listRepetition0(p);
	result = verbum_ast_new_initializer_list(p->ctx, initializer_0, initializer_listRepetition0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static compound_statement *parser_parse_compound_statement(Parser *p) {
	compound_statement *result = NULL;
	size_t cp = parser_save(p);
	if(!parser_match(p, verbum_token_get_lexeme_type("{"))) {
		goto EXIT;
		// Error, cleanup
	}
	Token literal_0 = parser_previous(p);
	parser_drop(p);
	compound_statementRepetition0 *compound_statementRepetition0_0 = parser_parse_compound_statementRepetition0(p);
	compound_statementRepetition1 *compound_statementRepetition1_0 = parser_parse_compound_statementRepetition1(p);
	if(!parser_match(p, verbum_token_get_lexeme_type("}"))) {
		goto EXIT;
		// Error, cleanup
	}
	Token literal_1 = parser_previous(p);
	parser_drop(p);
	result = verbum_ast_new_compound_statement(p->ctx, literal_0, literal_1, compound_statementRepetition0_0, compound_statementRepetition1_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static statement *parser_parse_statement(Parser *p) {
	statement *result = NULL;
	size_t cp = parser_save(p);
	{
		labeled_statement *labeled_statement_0 = parser_parse_labeled_statement(p);
		if(labeled_statement_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_statement_choice0(p->ctx, labeled_statement_0);
		parser_commit(p);
		result->tag = statementType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		expression_statement *expression_statement_0 = parser_parse_expression_statement(p);
		if(expression_statement_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_statement_choice1(p->ctx, expression_statement_0);
		parser_commit(p);
		result->tag = statementType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		compound_statement *compound_statement_0 = parser_parse_compound_statement(p);
		if(compound_statement_0 == NULL) {
			goto EXIT_2;
			// Error cleanup
		}

		result = verbum_ast_new_statement_choice2(p->ctx, compound_statement_0);
		parser_commit(p);
		result->tag = statementType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		selection_statement *selection_statement_0 = parser_parse_selection_statement(p);
		if(selection_statement_0 == NULL) {
			goto EXIT_3;
			// Error cleanup
		}

		result = verbum_ast_new_statement_choice3(p->ctx, selection_statement_0);
		parser_commit(p);
		result->tag = statementType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);
	{
		iteration_statement *iteration_statement_0 = parser_parse_iteration_statement(p);
		if(iteration_statement_0 == NULL) {
			goto EXIT_4;
			// Error cleanup
		}

		result = verbum_ast_new_statement_choice4(p->ctx, iteration_statement_0);
		parser_commit(p);
		result->tag = statementType_4;
		return result;
	}
EXIT_4:
	parser_rewind(p, cp);
	{
		jump_statement *jump_statement_0 = parser_parse_jump_statement(p);
		if(jump_statement_0 == NULL) {
			goto EXIT_5;
			// Error cleanup
		}

		result = verbum_ast_new_statement_choice5(p->ctx, jump_statement_0);
		parser_commit(p);
		result->tag = statementType_5;
		return result;
	}
EXIT_5:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static labeled_statement *parser_parse_labeled_statement(Parser *p) {
	labeled_statement *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(":"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_labeled_statement_choice0(p->ctx, literal_0, statement_0, IDENTIFIER_0);
		parser_commit(p);
		result->tag = labeled_statementType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("case"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		constant_expression *constant_expression_0 = parser_parse_constant_expression(p);
		if(constant_expression_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(":"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_labeled_statement_choice1(p->ctx, literal_0, literal_1, statement_0, constant_expression_0);
		parser_commit(p);
		result->tag = labeled_statementType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("default"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(":"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_2;
			// Error cleanup
		}

		result = verbum_ast_new_labeled_statement_choice2(p->ctx, literal_0, literal_1, statement_0);
		parser_commit(p);
		result->tag = labeled_statementType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static expression_statement *parser_parse_expression_statement(Parser *p) {
	expression_statement *result = NULL;
	size_t cp = parser_save(p);
	expression_statementOptional0 *expression_statementOptional0_0 = parser_parse_expression_statementOptional0(p);
	if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
		goto EXIT;
		// Error, cleanup
	}
	Token literal_0 = parser_previous(p);
	parser_drop(p);
	result = verbum_ast_new_expression_statement(p->ctx, literal_0, expression_statementOptional0_0);
	goto EXIT;
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static selection_statement *parser_parse_selection_statement(Parser *p) {
	selection_statement *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("if"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_2 = parser_previous(p);
		parser_drop(p);
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		selection_statementOptional0 *selection_statementOptional0_0 = parser_parse_selection_statementOptional0(p);


		result = verbum_ast_new_selection_statement_choice0(p->ctx, literal_0, literal_1, literal_2, expression_0, selection_statementOptional0_0, statement_0);
		parser_commit(p);
		result->tag = selection_statementType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("switch"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_2 = parser_previous(p);
		parser_drop(p);
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_selection_statement_choice1(p->ctx, literal_0, literal_1, literal_2, expression_0, statement_0);
		parser_commit(p);
		result->tag = selection_statementType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static iteration_statement *parser_parse_iteration_statement(Parser *p) {
	iteration_statement *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("while"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_2 = parser_previous(p);
		parser_drop(p);
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_iteration_statement_choice0(p->ctx, literal_0, literal_1, literal_2, expression_0, statement_0);
		parser_commit(p);
		result->tag = iteration_statementType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("do"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type("while"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_2 = parser_previous(p);
		parser_drop(p);
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_3 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_4 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_iteration_statement_choice1(p->ctx, literal_0, literal_1, literal_2, literal_3, literal_4, expression_0, statement_0);
		parser_commit(p);
		result->tag = iteration_statementType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("for"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		iteration_statementOptional0 *iteration_statementOptional0_0 = parser_parse_iteration_statementOptional0(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_2 = parser_previous(p);
		parser_drop(p);
		iteration_statementOptional1 *iteration_statementOptional1_0 = parser_parse_iteration_statementOptional1(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_3 = parser_previous(p);
		parser_drop(p);
		iteration_statementOptional2 *iteration_statementOptional2_0 = parser_parse_iteration_statementOptional2(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_4 = parser_previous(p);
		parser_drop(p);
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_2;
			// Error cleanup
		}

		result = verbum_ast_new_iteration_statement_choice2(p->ctx, literal_0, literal_1, literal_2, literal_3, literal_4, iteration_statementOptional2_0, statement_0, iteration_statementOptional0_0, iteration_statementOptional1_0);
		parser_commit(p);
		result->tag = iteration_statementType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static jump_statement *parser_parse_jump_statement(Parser *p) {
	jump_statement *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("goto"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_jump_statement_choice0(p->ctx, literal_0, literal_1, IDENTIFIER_0);
		parser_commit(p);
		result->tag = jump_statementType_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("continue"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_jump_statement_choice1(p->ctx, literal_0, literal_1);
		parser_commit(p);
		result->tag = jump_statementType_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("break"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_jump_statement_choice2(p->ctx, literal_0, literal_1);
		parser_commit(p);
		result->tag = jump_statementType_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("return"))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		jump_statementOptional0 *jump_statementOptional0_0 = parser_parse_jump_statementOptional0(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(";"))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_jump_statement_choice3(p->ctx, literal_0, literal_1, jump_statementOptional0_0);
		parser_commit(p);
		result->tag = jump_statementType_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static translation_unitRepetition0 *parser_parse_translation_unitRepetition0(Parser *p) {
	translation_unitRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		external_declaration *external_declaration_0 = parser_parse_external_declaration(p);
		if(external_declaration_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		translation_unitRepetition0 *translation_unitRepetition0_0 = parser_parse_translation_unitRepetition0(p);


		result = verbum_ast_new_translation_unitRepetition0_choice0(p->ctx, translation_unitRepetition0_0, external_declaration_0);
		parser_commit(p);
		result->tag = translation_unitRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_translation_unitRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = translation_unitRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static function_definitionRepetition0 *parser_parse_function_definitionRepetition0(Parser *p) {
	function_definitionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		declaration_specifier *declaration_specifier_0 = parser_parse_declaration_specifier(p);
		if(declaration_specifier_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		function_definitionRepetition0 *function_definitionRepetition0_0 = parser_parse_function_definitionRepetition0(p);


		result = verbum_ast_new_function_definitionRepetition0_choice0(p->ctx, function_definitionRepetition0_0, declaration_specifier_0);
		parser_commit(p);
		result->tag = function_definitionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_function_definitionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = function_definitionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static function_definitionRepetition1 *parser_parse_function_definitionRepetition1(Parser *p) {
	function_definitionRepetition1 *result = NULL;
	size_t cp = parser_save(p);
	{
		declaration *declaration_0 = parser_parse_declaration(p);
		if(declaration_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		function_definitionRepetition1 *function_definitionRepetition1_0 = parser_parse_function_definitionRepetition1(p);


		result = verbum_ast_new_function_definitionRepetition1_choice0(p->ctx, declaration_0, function_definitionRepetition1_0);
		parser_commit(p);
		result->tag = function_definitionRepetition1Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_function_definitionRepetition1_choice1(p->ctx);
		parser_commit(p);
		result->tag = function_definitionRepetition1Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_or_union_specifierRepetition0 *parser_parse_struct_or_union_specifierRepetition0(Parser *p) {
	struct_or_union_specifierRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		struct_declaration *struct_declaration_0 = parser_parse_struct_declaration(p);
		if(struct_declaration_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		struct_or_union_specifierRepetition0 *struct_or_union_specifierRepetition0_0 = parser_parse_struct_or_union_specifierRepetition0(p);


		result = verbum_ast_new_struct_or_union_specifierRepetition0_choice0(p->ctx, struct_or_union_specifierRepetition0_0, struct_declaration_0);
		parser_commit(p);
		result->tag = struct_or_union_specifierRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_struct_or_union_specifierRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = struct_or_union_specifierRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_or_union_specifierRepetition1 *parser_parse_struct_or_union_specifierRepetition1(Parser *p) {
	struct_or_union_specifierRepetition1 *result = NULL;
	size_t cp = parser_save(p);
	{
		struct_declaration *struct_declaration_0 = parser_parse_struct_declaration(p);
		if(struct_declaration_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		struct_or_union_specifierRepetition1 *struct_or_union_specifierRepetition1_0 = parser_parse_struct_or_union_specifierRepetition1(p);


		result = verbum_ast_new_struct_or_union_specifierRepetition1_choice0(p->ctx, struct_or_union_specifierRepetition1_0, struct_declaration_0);
		parser_commit(p);
		result->tag = struct_or_union_specifierRepetition1Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_struct_or_union_specifierRepetition1_choice1(p->ctx);
		parser_commit(p);
		result->tag = struct_or_union_specifierRepetition1Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_declarationRepetition0 *parser_parse_struct_declarationRepetition0(Parser *p) {
	struct_declarationRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		specifier_qualifier *specifier_qualifier_0 = parser_parse_specifier_qualifier(p);
		if(specifier_qualifier_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		struct_declarationRepetition0 *struct_declarationRepetition0_0 = parser_parse_struct_declarationRepetition0(p);


		result = verbum_ast_new_struct_declarationRepetition0_choice0(p->ctx, struct_declarationRepetition0_0, specifier_qualifier_0);
		parser_commit(p);
		result->tag = struct_declarationRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_struct_declarationRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = struct_declarationRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_declarator_listRepetition0 *parser_parse_struct_declarator_listRepetition0(Parser *p) {
	struct_declarator_listRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(","))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		struct_declarator *struct_declarator_0 = parser_parse_struct_declarator(p);
		if(struct_declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		struct_declarator_listRepetition0 *struct_declarator_listRepetition0_0 = parser_parse_struct_declarator_listRepetition0(p);


		result = verbum_ast_new_struct_declarator_listRepetition0_choice0(p->ctx, literal_0, struct_declarator_0, struct_declarator_listRepetition0_0);
		parser_commit(p);
		result->tag = struct_declarator_listRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_struct_declarator_listRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = struct_declarator_listRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static struct_declaratorOptional0 *parser_parse_struct_declaratorOptional0(Parser *p) {
	struct_declaratorOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		declarator *declarator_0 = parser_parse_declarator(p);
		if(declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_struct_declaratorOptional0_choice0(p->ctx, declarator_0);
		parser_commit(p);
		result->tag = struct_declaratorOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_struct_declaratorOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = struct_declaratorOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static declaratorOptional0 *parser_parse_declaratorOptional0(Parser *p) {
	declaratorOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		pointer *pointer_0 = parser_parse_pointer(p);
		if(pointer_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_declaratorOptional0_choice0(p->ctx, pointer_0);
		parser_commit(p);
		result->tag = declaratorOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_declaratorOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = declaratorOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static pointerRepetition0 *parser_parse_pointerRepetition0(Parser *p) {
	pointerRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		type_qualifier *type_qualifier_0 = parser_parse_type_qualifier(p);
		if(type_qualifier_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		pointerRepetition0 *pointerRepetition0_0 = parser_parse_pointerRepetition0(p);


		result = verbum_ast_new_pointerRepetition0_choice0(p->ctx, type_qualifier_0, pointerRepetition0_0);
		parser_commit(p);
		result->tag = pointerRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_pointerRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = pointerRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static pointerOptional0 *parser_parse_pointerOptional0(Parser *p) {
	pointerOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		pointer *pointer_0 = parser_parse_pointer(p);
		if(pointer_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_pointerOptional0_choice0(p->ctx, pointer_0);
		parser_commit(p);
		result->tag = pointerOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_pointerOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = pointerOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_declaratorGroup0 *parser_parse_direct_declaratorGroup0(Parser *p) {
	direct_declaratorGroup0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_direct_declaratorGroup0_choice0(p->ctx, IDENTIFIER_0);
		parser_commit(p);
		result->tag = direct_declaratorGroup0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		declarator *declarator_0 = parser_parse_declarator(p);
		if(declarator_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_direct_declaratorGroup0_choice1(p->ctx, literal_0, literal_1, declarator_0);
		parser_commit(p);
		result->tag = direct_declaratorGroup0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_declaratorOptional0 *parser_parse_direct_declaratorOptional0(Parser *p) {
	direct_declaratorOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		constant_expression *constant_expression_0 = parser_parse_constant_expression(p);
		if(constant_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_direct_declaratorOptional0_choice0(p->ctx, constant_expression_0);
		parser_commit(p);
		result->tag = direct_declaratorOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_direct_declaratorOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = direct_declaratorOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_declaratorRepetition1 *parser_parse_direct_declaratorRepetition1(Parser *p) {
	direct_declaratorRepetition1 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);
		direct_declaratorRepetition1 *direct_declaratorRepetition1_0 = parser_parse_direct_declaratorRepetition1(p);


		result = verbum_ast_new_direct_declaratorRepetition1_choice0(p->ctx, direct_declaratorRepetition1_0, IDENTIFIER_0);
		parser_commit(p);
		result->tag = direct_declaratorRepetition1Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_direct_declaratorRepetition1_choice1(p->ctx);
		parser_commit(p);
		result->tag = direct_declaratorRepetition1Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_declaratorRepetition0 *parser_parse_direct_declaratorRepetition0(Parser *p) {
	direct_declaratorRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("["))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		direct_declaratorOptional0 *direct_declaratorOptional0_0 = parser_parse_direct_declaratorOptional0(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("]"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		direct_declaratorRepetition0 *direct_declaratorRepetition0_0 = parser_parse_direct_declaratorRepetition0(p);


		result = verbum_ast_new_direct_declaratorRepetition0_choice0(p->ctx, literal_0, literal_1, direct_declaratorOptional0_0, direct_declaratorRepetition0_0);
		parser_commit(p);
		result->tag = direct_declaratorRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		parameter_type_list *parameter_type_list_0 = parser_parse_parameter_type_list(p);
		if(parameter_type_list_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		direct_declaratorRepetition0 *direct_declaratorRepetition0_0 = parser_parse_direct_declaratorRepetition0(p);

		result = verbum_ast_new_direct_declaratorRepetition0_choice1(p->ctx, literal_0, literal_1, parameter_type_list_0, direct_declaratorRepetition0_0);
		parser_commit(p);
		result->tag = direct_declaratorRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		direct_declaratorRepetition1 *direct_declaratorRepetition1_0 = parser_parse_direct_declaratorRepetition1(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		direct_declaratorRepetition0 *direct_declaratorRepetition0_0 = parser_parse_direct_declaratorRepetition0(p);

		result = verbum_ast_new_direct_declaratorRepetition0_choice2(p->ctx, literal_0, literal_1, direct_declaratorRepetition1_0, direct_declaratorRepetition0_0);
		parser_commit(p);
		result->tag = direct_declaratorRepetition0Type_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_direct_declaratorRepetition0_choice3(p->ctx);
		parser_commit(p);
		result->tag = direct_declaratorRepetition0Type_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static conditional_expressionOptional0 *parser_parse_conditional_expressionOptional0(Parser *p) {
	conditional_expressionOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("?"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type(":"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		conditional_expression *conditional_expression_0 = parser_parse_conditional_expression(p);
		if(conditional_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_conditional_expressionOptional0_choice0(p->ctx, literal_0, literal_1, expression_0, conditional_expression_0);
		parser_commit(p);
		result->tag = conditional_expressionOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_conditional_expressionOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = conditional_expressionOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static logical_or_expressionRepetition0 *parser_parse_logical_or_expressionRepetition0(Parser *p) {
	logical_or_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("||"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		logical_and_expression *logical_and_expression_0 = parser_parse_logical_and_expression(p);
		if(logical_and_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		logical_or_expressionRepetition0 *logical_or_expressionRepetition0_0 = parser_parse_logical_or_expressionRepetition0(p);


		result = verbum_ast_new_logical_or_expressionRepetition0_choice0(p->ctx, literal_0, logical_and_expression_0, logical_or_expressionRepetition0_0);
		parser_commit(p);
		result->tag = logical_or_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_logical_or_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = logical_or_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static logical_and_expressionRepetition0 *parser_parse_logical_and_expressionRepetition0(Parser *p) {
	logical_and_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("&&"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		inclusive_or_expression *inclusive_or_expression_0 = parser_parse_inclusive_or_expression(p);
		if(inclusive_or_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		logical_and_expressionRepetition0 *logical_and_expressionRepetition0_0 = parser_parse_logical_and_expressionRepetition0(p);


		result = verbum_ast_new_logical_and_expressionRepetition0_choice0(p->ctx, logical_and_expressionRepetition0_0, literal_0, inclusive_or_expression_0);
		parser_commit(p);
		result->tag = logical_and_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_logical_and_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = logical_and_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static inclusive_or_expressionRepetition0 *parser_parse_inclusive_or_expressionRepetition0(Parser *p) {
	inclusive_or_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("|"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		exclusive_or_expression *exclusive_or_expression_0 = parser_parse_exclusive_or_expression(p);
		if(exclusive_or_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		inclusive_or_expressionRepetition0 *inclusive_or_expressionRepetition0_0 = parser_parse_inclusive_or_expressionRepetition0(p);


		result = verbum_ast_new_inclusive_or_expressionRepetition0_choice0(p->ctx, inclusive_or_expressionRepetition0_0, literal_0, exclusive_or_expression_0);
		parser_commit(p);
		result->tag = inclusive_or_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_inclusive_or_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = inclusive_or_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static exclusive_or_expressionRepetition0 *parser_parse_exclusive_or_expressionRepetition0(Parser *p) {
	exclusive_or_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("^"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		and_expression *and_expression_0 = parser_parse_and_expression(p);
		if(and_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		exclusive_or_expressionRepetition0 *exclusive_or_expressionRepetition0_0 = parser_parse_exclusive_or_expressionRepetition0(p);


		result = verbum_ast_new_exclusive_or_expressionRepetition0_choice0(p->ctx, exclusive_or_expressionRepetition0_0, literal_0, and_expression_0);
		parser_commit(p);
		result->tag = exclusive_or_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_exclusive_or_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = exclusive_or_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static and_expressionRepetition0 *parser_parse_and_expressionRepetition0(Parser *p) {
	and_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("&"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		equality_expression *equality_expression_0 = parser_parse_equality_expression(p);
		if(equality_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		and_expressionRepetition0 *and_expressionRepetition0_0 = parser_parse_and_expressionRepetition0(p);


		result = verbum_ast_new_and_expressionRepetition0_choice0(p->ctx, literal_0, and_expressionRepetition0_0, equality_expression_0);
		parser_commit(p);
		result->tag = and_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_and_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = and_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static equality_expressionGroup0 *parser_parse_equality_expressionGroup0(Parser *p) {
	equality_expressionGroup0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("=="))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_equality_expressionGroup0_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = equality_expressionGroup0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("!="))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_equality_expressionGroup0_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = equality_expressionGroup0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static equality_expressionRepetition0 *parser_parse_equality_expressionRepetition0(Parser *p) {
	equality_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		equality_expressionGroup0 *equality_expressionGroup0_0 = parser_parse_equality_expressionGroup0(p);
		if(equality_expressionGroup0_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		relational_expression *relational_expression_0 = parser_parse_relational_expression(p);
		if(relational_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		equality_expressionRepetition0 *equality_expressionRepetition0_0 = parser_parse_equality_expressionRepetition0(p);


		result = verbum_ast_new_equality_expressionRepetition0_choice0(p->ctx, relational_expression_0, equality_expressionGroup0_0, equality_expressionRepetition0_0);
		parser_commit(p);
		result->tag = equality_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_equality_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = equality_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static relational_expressionGroup0 *parser_parse_relational_expressionGroup0(Parser *p) {
	relational_expressionGroup0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("<"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_relational_expressionGroup0_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = relational_expressionGroup0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(">"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_relational_expressionGroup0_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = relational_expressionGroup0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("<="))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_relational_expressionGroup0_choice2(p->ctx, literal_0);
		parser_commit(p);
		result->tag = relational_expressionGroup0Type_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(">="))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_relational_expressionGroup0_choice3(p->ctx, literal_0);
		parser_commit(p);
		result->tag = relational_expressionGroup0Type_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static relational_expressionRepetition0 *parser_parse_relational_expressionRepetition0(Parser *p) {
	relational_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		relational_expressionGroup0 *relational_expressionGroup0_0 = parser_parse_relational_expressionGroup0(p);
		if(relational_expressionGroup0_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		shift_expression *shift_expression_0 = parser_parse_shift_expression(p);
		if(shift_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		relational_expressionRepetition0 *relational_expressionRepetition0_0 = parser_parse_relational_expressionRepetition0(p);


		result = verbum_ast_new_relational_expressionRepetition0_choice0(p->ctx, shift_expression_0, relational_expressionGroup0_0, relational_expressionRepetition0_0);
		parser_commit(p);
		result->tag = relational_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_relational_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = relational_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static shift_expressionGroup0 *parser_parse_shift_expressionGroup0(Parser *p) {
	shift_expressionGroup0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("<<"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_shift_expressionGroup0_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = shift_expressionGroup0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(">>"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_shift_expressionGroup0_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = shift_expressionGroup0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static shift_expressionRepetition0 *parser_parse_shift_expressionRepetition0(Parser *p) {
	shift_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		shift_expressionGroup0 *shift_expressionGroup0_0 = parser_parse_shift_expressionGroup0(p);
		if(shift_expressionGroup0_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		additive_expression *additive_expression_0 = parser_parse_additive_expression(p);
		if(additive_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		shift_expressionRepetition0 *shift_expressionRepetition0_0 = parser_parse_shift_expressionRepetition0(p);


		result = verbum_ast_new_shift_expressionRepetition0_choice0(p->ctx, shift_expressionRepetition0_0, shift_expressionGroup0_0, additive_expression_0);
		parser_commit(p);
		result->tag = shift_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_shift_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = shift_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static additive_expressionGroup0 *parser_parse_additive_expressionGroup0(Parser *p) {
	additive_expressionGroup0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("+"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_additive_expressionGroup0_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = additive_expressionGroup0Type_0;
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

		result = verbum_ast_new_additive_expressionGroup0_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = additive_expressionGroup0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static additive_expressionRepetition0 *parser_parse_additive_expressionRepetition0(Parser *p) {
	additive_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		additive_expressionGroup0 *additive_expressionGroup0_0 = parser_parse_additive_expressionGroup0(p);
		if(additive_expressionGroup0_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		multiplicative_expression *multiplicative_expression_0 = parser_parse_multiplicative_expression(p);
		if(multiplicative_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		additive_expressionRepetition0 *additive_expressionRepetition0_0 = parser_parse_additive_expressionRepetition0(p);


		result = verbum_ast_new_additive_expressionRepetition0_choice0(p->ctx, additive_expressionRepetition0_0, additive_expressionGroup0_0, multiplicative_expression_0);
		parser_commit(p);
		result->tag = additive_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_additive_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = additive_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static multiplicative_expressionGroup0 *parser_parse_multiplicative_expressionGroup0(Parser *p) {
	multiplicative_expressionGroup0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("*"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_multiplicative_expressionGroup0_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = multiplicative_expressionGroup0Type_0;
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

		result = verbum_ast_new_multiplicative_expressionGroup0_choice1(p->ctx, literal_0);
		parser_commit(p);
		result->tag = multiplicative_expressionGroup0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("%"))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);

		result = verbum_ast_new_multiplicative_expressionGroup0_choice2(p->ctx, literal_0);
		parser_commit(p);
		result->tag = multiplicative_expressionGroup0Type_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static multiplicative_expressionRepetition0 *parser_parse_multiplicative_expressionRepetition0(Parser *p) {
	multiplicative_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		multiplicative_expressionGroup0 *multiplicative_expressionGroup0_0 = parser_parse_multiplicative_expressionGroup0(p);
		if(multiplicative_expressionGroup0_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		cast_expression *cast_expression_0 = parser_parse_cast_expression(p);
		if(cast_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		multiplicative_expressionRepetition0 *multiplicative_expressionRepetition0_0 = parser_parse_multiplicative_expressionRepetition0(p);


		result = verbum_ast_new_multiplicative_expressionRepetition0_choice0(p->ctx, multiplicative_expressionGroup0_0, cast_expression_0, multiplicative_expressionRepetition0_0);
		parser_commit(p);
		result->tag = multiplicative_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_multiplicative_expressionRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = multiplicative_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static unary_expressionGroup0 *parser_parse_unary_expressionGroup0(Parser *p) {
	unary_expressionGroup0 *result = NULL;
	size_t cp = parser_save(p);
	{
		unary_expression *unary_expression_0 = parser_parse_unary_expression(p);
		if(unary_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_unary_expressionGroup0_choice0(p->ctx, unary_expression_0);
		parser_commit(p);
		result->tag = unary_expressionGroup0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		type_name *type_name_0 = parser_parse_type_name(p);

		result = verbum_ast_new_unary_expressionGroup0_choice1(p->ctx, type_name_0);
		parser_commit(p);
		result->tag = unary_expressionGroup0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static postfix_expressionRepetition1 *parser_parse_postfix_expressionRepetition1(Parser *p) {
	postfix_expressionRepetition1 *result = NULL;
	size_t cp = parser_save(p);
	{
		assignment_expression *assignment_expression_0 = parser_parse_assignment_expression(p);
		if(assignment_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		postfix_expressionRepetition1 *postfix_expressionRepetition1_0 = parser_parse_postfix_expressionRepetition1(p);


		result = verbum_ast_new_postfix_expressionRepetition1_choice0(p->ctx, assignment_expression_0, postfix_expressionRepetition1_0);
		parser_commit(p);
		result->tag = postfix_expressionRepetition1Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_postfix_expressionRepetition1_choice1(p->ctx);
		parser_commit(p);
		result->tag = postfix_expressionRepetition1Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static postfix_expressionRepetition0 *parser_parse_postfix_expressionRepetition0(Parser *p) {
	postfix_expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("["))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		if(!parser_match(p, verbum_token_get_lexeme_type("]"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		postfix_expressionRepetition0 *postfix_expressionRepetition0_0 = parser_parse_postfix_expressionRepetition0(p);


		result = verbum_ast_new_postfix_expressionRepetition0_choice0(p->ctx, literal_0, literal_1, expression_0, postfix_expressionRepetition0_0);
		parser_commit(p);
		result->tag = postfix_expressionRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("("))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		postfix_expressionRepetition1 *postfix_expressionRepetition1_0 = parser_parse_postfix_expressionRepetition1(p);
		if(!parser_match(p, verbum_token_get_lexeme_type(")"))) {
			goto EXIT_1;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);
		postfix_expressionRepetition0 *postfix_expressionRepetition0_0 = parser_parse_postfix_expressionRepetition0(p);

		result = verbum_ast_new_postfix_expressionRepetition0_choice1(p->ctx, literal_0, literal_1, postfix_expressionRepetition1_0, postfix_expressionRepetition0_0);
		parser_commit(p);
		result->tag = postfix_expressionRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("."))) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_2;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);
		postfix_expressionRepetition0 *postfix_expressionRepetition0_0 = parser_parse_postfix_expressionRepetition0(p);

		result = verbum_ast_new_postfix_expressionRepetition0_choice2(p->ctx, literal_0, postfix_expressionRepetition0_0, IDENTIFIER_0);
		parser_commit(p);
		result->tag = postfix_expressionRepetition0Type_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("->"))) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_3;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);
		postfix_expressionRepetition0 *postfix_expressionRepetition0_0 = parser_parse_postfix_expressionRepetition0(p);

		result = verbum_ast_new_postfix_expressionRepetition0_choice3(p->ctx, literal_0, postfix_expressionRepetition0_0, IDENTIFIER_0);
		parser_commit(p);
		result->tag = postfix_expressionRepetition0Type_3;
		return result;
	}
EXIT_3:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("++"))) {
			goto EXIT_4;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		postfix_expressionRepetition0 *postfix_expressionRepetition0_0 = parser_parse_postfix_expressionRepetition0(p);

		result = verbum_ast_new_postfix_expressionRepetition0_choice4(p->ctx, literal_0, postfix_expressionRepetition0_0);
		parser_commit(p);
		result->tag = postfix_expressionRepetition0Type_4;
		return result;
	}
EXIT_4:
	parser_rewind(p, cp);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("--"))) {
			goto EXIT_5;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		postfix_expressionRepetition0 *postfix_expressionRepetition0_0 = parser_parse_postfix_expressionRepetition0(p);

		result = verbum_ast_new_postfix_expressionRepetition0_choice5(p->ctx, literal_0, postfix_expressionRepetition0_0);
		parser_commit(p);
		result->tag = postfix_expressionRepetition0Type_5;
		return result;
	}
EXIT_5:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_postfix_expressionRepetition0_choice6(p->ctx);
		parser_commit(p);
		result->tag = postfix_expressionRepetition0Type_6;
		return result;
	}
EXIT_6:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static expressionRepetition0 *parser_parse_expressionRepetition0(Parser *p) {
	expressionRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(","))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		assignment_expression *assignment_expression_0 = parser_parse_assignment_expression(p);
		if(assignment_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		expressionRepetition0 *expressionRepetition0_0 = parser_parse_expressionRepetition0(p);


		result = verbum_ast_new_expressionRepetition0_choice0(p->ctx, literal_0, assignment_expression_0, expressionRepetition0_0);
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
static type_nameRepetition0 *parser_parse_type_nameRepetition0(Parser *p) {
	type_nameRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		specifier_qualifier *specifier_qualifier_0 = parser_parse_specifier_qualifier(p);
		if(specifier_qualifier_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		type_nameRepetition0 *type_nameRepetition0_0 = parser_parse_type_nameRepetition0(p);


		result = verbum_ast_new_type_nameRepetition0_choice0(p->ctx, type_nameRepetition0_0, specifier_qualifier_0);
		parser_commit(p);
		result->tag = type_nameRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_type_nameRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = type_nameRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static type_nameOptional0 *parser_parse_type_nameOptional0(Parser *p) {
	type_nameOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		abstract_declarator *abstract_declarator_0 = parser_parse_abstract_declarator(p);
		if(abstract_declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_type_nameOptional0_choice0(p->ctx, abstract_declarator_0);
		parser_commit(p);
		result->tag = type_nameOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_type_nameOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = type_nameOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static parameter_type_listOptional0 *parser_parse_parameter_type_listOptional0(Parser *p) {
	parameter_type_listOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(","))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		if(!parser_match(p, verbum_token_get_lexeme_type("..."))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_1 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_parameter_type_listOptional0_choice0(p->ctx, literal_0, literal_1);
		parser_commit(p);
		result->tag = parameter_type_listOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_parameter_type_listOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = parameter_type_listOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static parameter_listRepetition0 *parser_parse_parameter_listRepetition0(Parser *p) {
	parameter_listRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(","))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		parameter_declaration *parameter_declaration_0 = parser_parse_parameter_declaration(p);
		if(parameter_declaration_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		parameter_listRepetition0 *parameter_listRepetition0_0 = parser_parse_parameter_listRepetition0(p);


		result = verbum_ast_new_parameter_listRepetition0_choice0(p->ctx, parameter_listRepetition0_0, parameter_declaration_0, literal_0);
		parser_commit(p);
		result->tag = parameter_listRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_parameter_listRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = parameter_listRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static parameter_declarationRepetition0 *parser_parse_parameter_declarationRepetition0(Parser *p) {
	parameter_declarationRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		declaration_specifier *declaration_specifier_0 = parser_parse_declaration_specifier(p);
		if(declaration_specifier_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		parameter_declarationRepetition0 *parameter_declarationRepetition0_0 = parser_parse_parameter_declarationRepetition0(p);


		result = verbum_ast_new_parameter_declarationRepetition0_choice0(p->ctx, parameter_declarationRepetition0_0, declaration_specifier_0);
		parser_commit(p);
		result->tag = parameter_declarationRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_parameter_declarationRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = parameter_declarationRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static parameter_declarationOptional0 *parser_parse_parameter_declarationOptional0(Parser *p) {
	parameter_declarationOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		declarator *declarator_0 = parser_parse_declarator(p);
		if(declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_parameter_declarationOptional0_choice0(p->ctx, declarator_0);
		parser_commit(p);
		result->tag = parameter_declarationOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{
		abstract_declarator *abstract_declarator_0 = parser_parse_abstract_declarator(p);
		if(abstract_declarator_0 == NULL) {
			goto EXIT_1;
			// Error cleanup
		}

		result = verbum_ast_new_parameter_declarationOptional0_choice1(p->ctx, abstract_declarator_0);
		parser_commit(p);
		result->tag = parameter_declarationOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_parameter_declarationOptional0_choice2(p->ctx);
		parser_commit(p);
		result->tag = parameter_declarationOptional0Type_2;
		return result;
	}
EXIT_2:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static abstract_declaratorOptional0 *parser_parse_abstract_declaratorOptional0(Parser *p) {
	abstract_declaratorOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		direct_abstract_declarator *direct_abstract_declarator_0 = parser_parse_direct_abstract_declarator(p);
		if(direct_abstract_declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_abstract_declaratorOptional0_choice0(p->ctx, direct_abstract_declarator_0);
		parser_commit(p);
		result->tag = abstract_declaratorOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_abstract_declaratorOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = abstract_declaratorOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_abstract_declaratorOptional0 *parser_parse_direct_abstract_declaratorOptional0(Parser *p) {
	direct_abstract_declaratorOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		direct_abstract_declarator *direct_abstract_declarator_0 = parser_parse_direct_abstract_declarator(p);
		if(direct_abstract_declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_direct_abstract_declaratorOptional0_choice0(p->ctx, direct_abstract_declarator_0);
		parser_commit(p);
		result->tag = direct_abstract_declaratorOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_direct_abstract_declaratorOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = direct_abstract_declaratorOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_abstract_declaratorOptional1 *parser_parse_direct_abstract_declaratorOptional1(Parser *p) {
	direct_abstract_declaratorOptional1 *result = NULL;
	size_t cp = parser_save(p);
	{
		constant_expression *constant_expression_0 = parser_parse_constant_expression(p);
		if(constant_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_direct_abstract_declaratorOptional1_choice0(p->ctx, constant_expression_0);
		parser_commit(p);
		result->tag = direct_abstract_declaratorOptional1Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_direct_abstract_declaratorOptional1_choice1(p->ctx);
		parser_commit(p);
		result->tag = direct_abstract_declaratorOptional1Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_abstract_declaratorOptional2 *parser_parse_direct_abstract_declaratorOptional2(Parser *p) {
	direct_abstract_declaratorOptional2 *result = NULL;
	size_t cp = parser_save(p);
	{
		direct_abstract_declarator *direct_abstract_declarator_0 = parser_parse_direct_abstract_declarator(p);
		if(direct_abstract_declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_direct_abstract_declaratorOptional2_choice0(p->ctx, direct_abstract_declarator_0);
		parser_commit(p);
		result->tag = direct_abstract_declaratorOptional2Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_direct_abstract_declaratorOptional2_choice1(p->ctx);
		parser_commit(p);
		result->tag = direct_abstract_declaratorOptional2Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static direct_abstract_declaratorOptional3 *parser_parse_direct_abstract_declaratorOptional3(Parser *p) {
	direct_abstract_declaratorOptional3 *result = NULL;
	size_t cp = parser_save(p);
	{
		parameter_type_list *parameter_type_list_0 = parser_parse_parameter_type_list(p);
		if(parameter_type_list_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_direct_abstract_declaratorOptional3_choice0(p->ctx, parameter_type_list_0);
		parser_commit(p);
		result->tag = direct_abstract_declaratorOptional3Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_direct_abstract_declaratorOptional3_choice1(p->ctx);
		parser_commit(p);
		result->tag = direct_abstract_declaratorOptional3Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static enum_specifierOptional0 *parser_parse_enum_specifierOptional0(Parser *p) {
	enum_specifierOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, TokenType_IDENTIFIER)) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token IDENTIFIER_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_enum_specifierOptional0_choice0(p->ctx, IDENTIFIER_0);
		parser_commit(p);
		result->tag = enum_specifierOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_enum_specifierOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = enum_specifierOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static enumerator_listRepetition0 *parser_parse_enumerator_listRepetition0(Parser *p) {
	enumerator_listRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(","))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		enumerator *enumerator_0 = parser_parse_enumerator(p);
		if(enumerator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		enumerator_listRepetition0 *enumerator_listRepetition0_0 = parser_parse_enumerator_listRepetition0(p);


		result = verbum_ast_new_enumerator_listRepetition0_choice0(p->ctx, enumerator_0, enumerator_listRepetition0_0, literal_0);
		parser_commit(p);
		result->tag = enumerator_listRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_enumerator_listRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = enumerator_listRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static enumeratorOptional0 *parser_parse_enumeratorOptional0(Parser *p) {
	enumeratorOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("="))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		constant_expression *constant_expression_0 = parser_parse_constant_expression(p);
		if(constant_expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_enumeratorOptional0_choice0(p->ctx, literal_0, constant_expression_0);
		parser_commit(p);
		result->tag = enumeratorOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_enumeratorOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = enumeratorOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static declarationRepetition0 *parser_parse_declarationRepetition0(Parser *p) {
	declarationRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		declaration_specifier *declaration_specifier_0 = parser_parse_declaration_specifier(p);
		if(declaration_specifier_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		declarationRepetition0 *declarationRepetition0_0 = parser_parse_declarationRepetition0(p);


		result = verbum_ast_new_declarationRepetition0_choice0(p->ctx, declaration_specifier_0, declarationRepetition0_0);
		parser_commit(p);
		result->tag = declarationRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_declarationRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = declarationRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static declarationRepetition1 *parser_parse_declarationRepetition1(Parser *p) {
	declarationRepetition1 *result = NULL;
	size_t cp = parser_save(p);
	{
		init_declarator *init_declarator_0 = parser_parse_init_declarator(p);
		if(init_declarator_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		declarationRepetition1 *declarationRepetition1_0 = parser_parse_declarationRepetition1(p);


		result = verbum_ast_new_declarationRepetition1_choice0(p->ctx, declarationRepetition1_0, init_declarator_0);
		parser_commit(p);
		result->tag = declarationRepetition1Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_declarationRepetition1_choice1(p->ctx);
		parser_commit(p);
		result->tag = declarationRepetition1Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static init_declaratorOptional0 *parser_parse_init_declaratorOptional0(Parser *p) {
	init_declaratorOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("="))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		initializer *initializer_0 = parser_parse_initializer(p);
		if(initializer_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_init_declaratorOptional0_choice0(p->ctx, literal_0, initializer_0);
		parser_commit(p);
		result->tag = init_declaratorOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_init_declaratorOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = init_declaratorOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static initializerOptional0 *parser_parse_initializerOptional0(Parser *p) {
	initializerOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(","))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);


		result = verbum_ast_new_initializerOptional0_choice0(p->ctx, literal_0);
		parser_commit(p);
		result->tag = initializerOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_initializerOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = initializerOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static initializer_listRepetition0 *parser_parse_initializer_listRepetition0(Parser *p) {
	initializer_listRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type(","))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		initializer *initializer_0 = parser_parse_initializer(p);
		if(initializer_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		initializer_listRepetition0 *initializer_listRepetition0_0 = parser_parse_initializer_listRepetition0(p);


		result = verbum_ast_new_initializer_listRepetition0_choice0(p->ctx, literal_0, initializer_0, initializer_listRepetition0_0);
		parser_commit(p);
		result->tag = initializer_listRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_initializer_listRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = initializer_listRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static compound_statementRepetition0 *parser_parse_compound_statementRepetition0(Parser *p) {
	compound_statementRepetition0 *result = NULL;
	size_t cp = parser_save(p);
	{
		declaration *declaration_0 = parser_parse_declaration(p);
		if(declaration_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		compound_statementRepetition0 *compound_statementRepetition0_0 = parser_parse_compound_statementRepetition0(p);


		result = verbum_ast_new_compound_statementRepetition0_choice0(p->ctx, declaration_0, compound_statementRepetition0_0);
		parser_commit(p);
		result->tag = compound_statementRepetition0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_compound_statementRepetition0_choice1(p->ctx);
		parser_commit(p);
		result->tag = compound_statementRepetition0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static compound_statementRepetition1 *parser_parse_compound_statementRepetition1(Parser *p) {
	compound_statementRepetition1 *result = NULL;
	size_t cp = parser_save(p);
	{
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}
		compound_statementRepetition1 *compound_statementRepetition1_0 = parser_parse_compound_statementRepetition1(p);


		result = verbum_ast_new_compound_statementRepetition1_choice0(p->ctx, statement_0, compound_statementRepetition1_0);
		parser_commit(p);
		result->tag = compound_statementRepetition1Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_compound_statementRepetition1_choice1(p->ctx);
		parser_commit(p);
		result->tag = compound_statementRepetition1Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static expression_statementOptional0 *parser_parse_expression_statementOptional0(Parser *p) {
	expression_statementOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_expression_statementOptional0_choice0(p->ctx, expression_0);
		parser_commit(p);
		result->tag = expression_statementOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_expression_statementOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = expression_statementOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static selection_statementOptional0 *parser_parse_selection_statementOptional0(Parser *p) {
	selection_statementOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		if(!parser_match(p, verbum_token_get_lexeme_type("else"))) {
			goto EXIT_0;
			// Error, cleanup
		}
		Token literal_0 = parser_previous(p);
		parser_drop(p);
		statement *statement_0 = parser_parse_statement(p);
		if(statement_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_selection_statementOptional0_choice0(p->ctx, literal_0, statement_0);
		parser_commit(p);
		result->tag = selection_statementOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_selection_statementOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = selection_statementOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static iteration_statementOptional0 *parser_parse_iteration_statementOptional0(Parser *p) {
	iteration_statementOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_iteration_statementOptional0_choice0(p->ctx, expression_0);
		parser_commit(p);
		result->tag = iteration_statementOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_iteration_statementOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = iteration_statementOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static iteration_statementOptional1 *parser_parse_iteration_statementOptional1(Parser *p) {
	iteration_statementOptional1 *result = NULL;
	size_t cp = parser_save(p);
	{
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_iteration_statementOptional1_choice0(p->ctx, expression_0);
		parser_commit(p);
		result->tag = iteration_statementOptional1Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_iteration_statementOptional1_choice1(p->ctx);
		parser_commit(p);
		result->tag = iteration_statementOptional1Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static iteration_statementOptional2 *parser_parse_iteration_statementOptional2(Parser *p) {
	iteration_statementOptional2 *result = NULL;
	size_t cp = parser_save(p);
	{
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_iteration_statementOptional2_choice0(p->ctx, expression_0);
		parser_commit(p);
		result->tag = iteration_statementOptional2Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_iteration_statementOptional2_choice1(p->ctx);
		parser_commit(p);
		result->tag = iteration_statementOptional2Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
static jump_statementOptional0 *parser_parse_jump_statementOptional0(Parser *p) {
	jump_statementOptional0 *result = NULL;
	size_t cp = parser_save(p);
	{
		expression *expression_0 = parser_parse_expression(p);
		if(expression_0 == NULL) {
			goto EXIT_0;
			// Error cleanup
		}


		result = verbum_ast_new_jump_statementOptional0_choice0(p->ctx, expression_0);
		parser_commit(p);
		result->tag = jump_statementOptional0Type_0;
		return result;
	}
EXIT_0:
	parser_rewind(p, cp);
	{

		result = verbum_ast_new_jump_statementOptional0_choice1(p->ctx);
		parser_commit(p);
		result->tag = jump_statementOptional0Type_1;
		return result;
	}
EXIT_1:
	parser_rewind(p, cp);

EXIT:
	parser_commit(p);

	return result;
}
