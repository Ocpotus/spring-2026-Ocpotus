#include "verbum.h"
#include "verbum_ast.h"


struct translation_unit *verbum_ast_new_translation_unit(struct VerbumContext *ctx, struct translation_unitRepetition0 *translation_unitRepetition0_0) {
	struct translation_unit *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->translation_unitRepetition0_0 = translation_unitRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_translation_unit(struct VerbumContext *ctx, struct translation_unit *translation_unit) {
	verbum_ast_delete_translation_unitRepetition0(ctx, translation_unit->translation_unitRepetition0_0);
	ctx->memory.delete(translation_unit);
}
struct external_declaration *verbum_ast_new_external_declaration_choice0(struct VerbumContext *ctx, struct function_definition *function_definition_0) {
	struct external_declaration *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.function_definition_0 = function_definition_0;

		result->tag = external_declarationType_0;
	}

	return result;
}
struct external_declaration *verbum_ast_new_external_declaration_choice1(struct VerbumContext *ctx, struct declaration *declaration_0) {
	struct external_declaration *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.declaration_0 = declaration_0;

		result->tag = external_declarationType_1;
	}

	return result;
}
void verbum_ast_delete_external_declaration(struct VerbumContext *ctx, struct external_declaration *external_declaration) {
	switch(external_declaration->tag) {
	case external_declarationType_0:
		verbum_ast_delete_function_definition(ctx, external_declaration->choice0.function_definition_0);
	break;
	case external_declarationType_1:
		verbum_ast_delete_declaration(ctx, external_declaration->choice1.declaration_0);
	break;
	}
	ctx->memory.delete(external_declaration);
}
struct function_definition *verbum_ast_new_function_definition(struct VerbumContext *ctx, struct function_definitionRepetition0 *function_definitionRepetition0_0, struct compound_statement *compound_statement_0, struct declarator *declarator_0, struct function_definitionRepetition1 *function_definitionRepetition1_0) {
	struct function_definition *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->function_definitionRepetition0_0 = function_definitionRepetition0_0;
		result->compound_statement_0 = compound_statement_0;
		result->declarator_0 = declarator_0;
		result->function_definitionRepetition1_0 = function_definitionRepetition1_0;
	}

	return result;
}
void verbum_ast_delete_function_definition(struct VerbumContext *ctx, struct function_definition *function_definition) {
	verbum_ast_delete_function_definitionRepetition0(ctx, function_definition->function_definitionRepetition0_0);
	verbum_ast_delete_compound_statement(ctx, function_definition->compound_statement_0);
	verbum_ast_delete_declarator(ctx, function_definition->declarator_0);
	verbum_ast_delete_function_definitionRepetition1(ctx, function_definition->function_definitionRepetition1_0);
	ctx->memory.delete(function_definition);
}
struct declaration_specifier *verbum_ast_new_declaration_specifier_choice0(struct VerbumContext *ctx, struct storage_class_specifier *storage_class_specifier_0) {
	struct declaration_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.storage_class_specifier_0 = storage_class_specifier_0;

		result->tag = declaration_specifierType_0;
	}

	return result;
}
struct declaration_specifier *verbum_ast_new_declaration_specifier_choice1(struct VerbumContext *ctx, struct type_specifier *type_specifier_0) {
	struct declaration_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.type_specifier_0 = type_specifier_0;

		result->tag = declaration_specifierType_1;
	}

	return result;
}
struct declaration_specifier *verbum_ast_new_declaration_specifier_choice2(struct VerbumContext *ctx, struct type_qualifier *type_qualifier_0) {
	struct declaration_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.type_qualifier_0 = type_qualifier_0;

		result->tag = declaration_specifierType_2;
	}

	return result;
}
void verbum_ast_delete_declaration_specifier(struct VerbumContext *ctx, struct declaration_specifier *declaration_specifier) {
	switch(declaration_specifier->tag) {
	case declaration_specifierType_0:
		verbum_ast_delete_storage_class_specifier(ctx, declaration_specifier->choice0.storage_class_specifier_0);
	break;
	case declaration_specifierType_1:
		verbum_ast_delete_type_specifier(ctx, declaration_specifier->choice1.type_specifier_0);
	break;
	case declaration_specifierType_2:
		verbum_ast_delete_type_qualifier(ctx, declaration_specifier->choice2.type_qualifier_0);
	break;
	}
	ctx->memory.delete(declaration_specifier);
}
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct storage_class_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = storage_class_specifierType_0;
	}

	return result;
}
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct storage_class_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = storage_class_specifierType_1;
	}

	return result;
}
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice2(struct VerbumContext *ctx, Token literal_0) {
	struct storage_class_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;

		result->tag = storage_class_specifierType_2;
	}

	return result;
}
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice3(struct VerbumContext *ctx, Token literal_0) {
	struct storage_class_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.literal_0 = literal_0;

		result->tag = storage_class_specifierType_3;
	}

	return result;
}
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice4(struct VerbumContext *ctx, Token literal_0) {
	struct storage_class_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice4.literal_0 = literal_0;

		result->tag = storage_class_specifierType_4;
	}

	return result;
}
void verbum_ast_delete_storage_class_specifier(struct VerbumContext *ctx, struct storage_class_specifier *storage_class_specifier) {
	switch(storage_class_specifier->tag) {
	case storage_class_specifierType_0:
		verbum_token_delete(ctx, &storage_class_specifier->choice0.literal_0);
	break;
	case storage_class_specifierType_1:
		verbum_token_delete(ctx, &storage_class_specifier->choice1.literal_0);
	break;
	case storage_class_specifierType_2:
		verbum_token_delete(ctx, &storage_class_specifier->choice2.literal_0);
	break;
	case storage_class_specifierType_3:
		verbum_token_delete(ctx, &storage_class_specifier->choice3.literal_0);
	break;
	case storage_class_specifierType_4:
		verbum_token_delete(ctx, &storage_class_specifier->choice4.literal_0);
	break;
	}
	ctx->memory.delete(storage_class_specifier);
}
struct type_specifier *verbum_ast_new_type_specifier_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = type_specifierType_0;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = type_specifierType_1;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice2(struct VerbumContext *ctx, Token literal_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;

		result->tag = type_specifierType_2;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice3(struct VerbumContext *ctx, Token literal_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.literal_0 = literal_0;

		result->tag = type_specifierType_3;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice4(struct VerbumContext *ctx, Token literal_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice4.literal_0 = literal_0;

		result->tag = type_specifierType_4;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice5(struct VerbumContext *ctx, Token literal_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice5.literal_0 = literal_0;

		result->tag = type_specifierType_5;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice6(struct VerbumContext *ctx, Token literal_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice6.literal_0 = literal_0;

		result->tag = type_specifierType_6;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice7(struct VerbumContext *ctx, Token literal_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice7.literal_0 = literal_0;

		result->tag = type_specifierType_7;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice8(struct VerbumContext *ctx, Token literal_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice8.literal_0 = literal_0;

		result->tag = type_specifierType_8;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice9(struct VerbumContext *ctx, struct struct_or_union_specifier *struct_or_union_specifier_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice9.struct_or_union_specifier_0 = struct_or_union_specifier_0;

		result->tag = type_specifierType_9;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice10(struct VerbumContext *ctx, struct enum_specifier *enum_specifier_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice10.enum_specifier_0 = enum_specifier_0;

		result->tag = type_specifierType_10;
	}

	return result;
}
struct type_specifier *verbum_ast_new_type_specifier_choice11(struct VerbumContext *ctx, struct typedef_name *typedef_name_0) {
	struct type_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice11.typedef_name_0 = typedef_name_0;

		result->tag = type_specifierType_11;
	}

	return result;
}
void verbum_ast_delete_type_specifier(struct VerbumContext *ctx, struct type_specifier *type_specifier) {
	switch(type_specifier->tag) {
	case type_specifierType_0:
		verbum_token_delete(ctx, &type_specifier->choice0.literal_0);
	break;
	case type_specifierType_1:
		verbum_token_delete(ctx, &type_specifier->choice1.literal_0);
	break;
	case type_specifierType_2:
		verbum_token_delete(ctx, &type_specifier->choice2.literal_0);
	break;
	case type_specifierType_3:
		verbum_token_delete(ctx, &type_specifier->choice3.literal_0);
	break;
	case type_specifierType_4:
		verbum_token_delete(ctx, &type_specifier->choice4.literal_0);
	break;
	case type_specifierType_5:
		verbum_token_delete(ctx, &type_specifier->choice5.literal_0);
	break;
	case type_specifierType_6:
		verbum_token_delete(ctx, &type_specifier->choice6.literal_0);
	break;
	case type_specifierType_7:
		verbum_token_delete(ctx, &type_specifier->choice7.literal_0);
	break;
	case type_specifierType_8:
		verbum_token_delete(ctx, &type_specifier->choice8.literal_0);
	break;
	case type_specifierType_9:
		verbum_ast_delete_struct_or_union_specifier(ctx, type_specifier->choice9.struct_or_union_specifier_0);
	break;
	case type_specifierType_10:
		verbum_ast_delete_enum_specifier(ctx, type_specifier->choice10.enum_specifier_0);
	break;
	case type_specifierType_11:
		verbum_ast_delete_typedef_name(ctx, type_specifier->choice11.typedef_name_0);
	break;
	}
	ctx->memory.delete(type_specifier);
}
struct struct_or_union_specifier *verbum_ast_new_struct_or_union_specifier_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct struct_or_union_specifierRepetition0 *struct_or_union_specifierRepetition0_0, struct struct_declaration *struct_declaration_0, struct struct_or_union *struct_or_union_0, Token IDENTIFIER_0) {
	struct struct_or_union_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;
		result->choice0.struct_or_union_specifierRepetition0_0 = struct_or_union_specifierRepetition0_0;
		result->choice0.struct_declaration_0 = struct_declaration_0;
		result->choice0.struct_or_union_0 = struct_or_union_0;
		result->choice0.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = struct_or_union_specifierType_0;
	}

	return result;
}
struct struct_or_union_specifier *verbum_ast_new_struct_or_union_specifier_choice1(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition1 *struct_or_union_specifierRepetition1_0, Token literal_0, Token literal_1, struct struct_declaration *struct_declaration_0, struct struct_or_union *struct_or_union_0) {
	struct struct_or_union_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.struct_or_union_specifierRepetition1_0 = struct_or_union_specifierRepetition1_0;
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.struct_declaration_0 = struct_declaration_0;
		result->choice1.struct_or_union_0 = struct_or_union_0;

		result->tag = struct_or_union_specifierType_1;
	}

	return result;
}
struct struct_or_union_specifier *verbum_ast_new_struct_or_union_specifier_choice2(struct VerbumContext *ctx, struct struct_or_union *struct_or_union_0, Token IDENTIFIER_0) {
	struct struct_or_union_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.struct_or_union_0 = struct_or_union_0;
		result->choice2.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = struct_or_union_specifierType_2;
	}

	return result;
}
void verbum_ast_delete_struct_or_union_specifier(struct VerbumContext *ctx, struct struct_or_union_specifier *struct_or_union_specifier) {
	switch(struct_or_union_specifier->tag) {
	case struct_or_union_specifierType_0:
		verbum_token_delete(ctx, &struct_or_union_specifier->choice0.literal_0);
		verbum_token_delete(ctx, &struct_or_union_specifier->choice0.literal_1);
		verbum_ast_delete_struct_or_union_specifierRepetition0(ctx, struct_or_union_specifier->choice0.struct_or_union_specifierRepetition0_0);
		verbum_ast_delete_struct_declaration(ctx, struct_or_union_specifier->choice0.struct_declaration_0);
		verbum_ast_delete_struct_or_union(ctx, struct_or_union_specifier->choice0.struct_or_union_0);
		verbum_token_delete(ctx, &struct_or_union_specifier->choice0.IDENTIFIER_0);
	break;
	case struct_or_union_specifierType_1:
		verbum_ast_delete_struct_or_union_specifierRepetition1(ctx, struct_or_union_specifier->choice1.struct_or_union_specifierRepetition1_0);
		verbum_token_delete(ctx, &struct_or_union_specifier->choice1.literal_0);
		verbum_token_delete(ctx, &struct_or_union_specifier->choice1.literal_1);
		verbum_ast_delete_struct_declaration(ctx, struct_or_union_specifier->choice1.struct_declaration_0);
		verbum_ast_delete_struct_or_union(ctx, struct_or_union_specifier->choice1.struct_or_union_0);
	break;
	case struct_or_union_specifierType_2:
		verbum_ast_delete_struct_or_union(ctx, struct_or_union_specifier->choice2.struct_or_union_0);
		verbum_token_delete(ctx, &struct_or_union_specifier->choice2.IDENTIFIER_0);
	break;
	}
	ctx->memory.delete(struct_or_union_specifier);
}
struct struct_or_union *verbum_ast_new_struct_or_union_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct struct_or_union *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = struct_or_unionType_0;
	}

	return result;
}
struct struct_or_union *verbum_ast_new_struct_or_union_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct struct_or_union *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = struct_or_unionType_1;
	}

	return result;
}
void verbum_ast_delete_struct_or_union(struct VerbumContext *ctx, struct struct_or_union *struct_or_union) {
	switch(struct_or_union->tag) {
	case struct_or_unionType_0:
		verbum_token_delete(ctx, &struct_or_union->choice0.literal_0);
	break;
	case struct_or_unionType_1:
		verbum_token_delete(ctx, &struct_or_union->choice1.literal_0);
	break;
	}
	ctx->memory.delete(struct_or_union);
}
struct struct_declaration *verbum_ast_new_struct_declaration(struct VerbumContext *ctx, struct struct_declarationRepetition0 *struct_declarationRepetition0_0, struct struct_declarator_list *struct_declarator_list_0) {
	struct struct_declaration *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->struct_declarationRepetition0_0 = struct_declarationRepetition0_0;
		result->struct_declarator_list_0 = struct_declarator_list_0;
	}

	return result;
}
void verbum_ast_delete_struct_declaration(struct VerbumContext *ctx, struct struct_declaration *struct_declaration) {
	verbum_ast_delete_struct_declarationRepetition0(ctx, struct_declaration->struct_declarationRepetition0_0);
	verbum_ast_delete_struct_declarator_list(ctx, struct_declaration->struct_declarator_list_0);
	ctx->memory.delete(struct_declaration);
}
struct specifier_qualifier *verbum_ast_new_specifier_qualifier_choice0(struct VerbumContext *ctx, struct type_specifier *type_specifier_0) {
	struct specifier_qualifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.type_specifier_0 = type_specifier_0;

		result->tag = specifier_qualifierType_0;
	}

	return result;
}
struct specifier_qualifier *verbum_ast_new_specifier_qualifier_choice1(struct VerbumContext *ctx, struct type_qualifier *type_qualifier_0) {
	struct specifier_qualifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.type_qualifier_0 = type_qualifier_0;

		result->tag = specifier_qualifierType_1;
	}

	return result;
}
void verbum_ast_delete_specifier_qualifier(struct VerbumContext *ctx, struct specifier_qualifier *specifier_qualifier) {
	switch(specifier_qualifier->tag) {
	case specifier_qualifierType_0:
		verbum_ast_delete_type_specifier(ctx, specifier_qualifier->choice0.type_specifier_0);
	break;
	case specifier_qualifierType_1:
		verbum_ast_delete_type_qualifier(ctx, specifier_qualifier->choice1.type_qualifier_0);
	break;
	}
	ctx->memory.delete(specifier_qualifier);
}
struct struct_declarator_list *verbum_ast_new_struct_declarator_list(struct VerbumContext *ctx, struct struct_declarator *struct_declarator_0, struct struct_declarator_listRepetition0 *struct_declarator_listRepetition0_0) {
	struct struct_declarator_list *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->struct_declarator_0 = struct_declarator_0;
		result->struct_declarator_listRepetition0_0 = struct_declarator_listRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_struct_declarator_list(struct VerbumContext *ctx, struct struct_declarator_list *struct_declarator_list) {
	verbum_ast_delete_struct_declarator(ctx, struct_declarator_list->struct_declarator_0);
	verbum_ast_delete_struct_declarator_listRepetition0(ctx, struct_declarator_list->struct_declarator_listRepetition0_0);
	ctx->memory.delete(struct_declarator_list);
}
struct struct_declarator *verbum_ast_new_struct_declarator_choice0(struct VerbumContext *ctx, struct declarator *declarator_0) {
	struct struct_declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.declarator_0 = declarator_0;

		result->tag = struct_declaratorType_0;
	}

	return result;
}
struct struct_declarator *verbum_ast_new_struct_declarator_choice1(struct VerbumContext *ctx, Token literal_0, struct struct_declaratorOptional0 *struct_declaratorOptional0_0, struct constant_expression *constant_expression_0) {
	struct struct_declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.struct_declaratorOptional0_0 = struct_declaratorOptional0_0;
		result->choice1.constant_expression_0 = constant_expression_0;

		result->tag = struct_declaratorType_1;
	}

	return result;
}
void verbum_ast_delete_struct_declarator(struct VerbumContext *ctx, struct struct_declarator *struct_declarator) {
	switch(struct_declarator->tag) {
	case struct_declaratorType_0:
		verbum_ast_delete_declarator(ctx, struct_declarator->choice0.declarator_0);
	break;
	case struct_declaratorType_1:
		verbum_token_delete(ctx, &struct_declarator->choice1.literal_0);
		verbum_ast_delete_struct_declaratorOptional0(ctx, struct_declarator->choice1.struct_declaratorOptional0_0);
		verbum_ast_delete_constant_expression(ctx, struct_declarator->choice1.constant_expression_0);
	break;
	}
	ctx->memory.delete(struct_declarator);
}
struct declarator *verbum_ast_new_declarator(struct VerbumContext *ctx, struct direct_declarator *direct_declarator_0, struct declaratorOptional0 *declaratorOptional0_0) {
	struct declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->direct_declarator_0 = direct_declarator_0;
		result->declaratorOptional0_0 = declaratorOptional0_0;
	}

	return result;
}
void verbum_ast_delete_declarator(struct VerbumContext *ctx, struct declarator *declarator) {
	verbum_ast_delete_direct_declarator(ctx, declarator->direct_declarator_0);
	verbum_ast_delete_declaratorOptional0(ctx, declarator->declaratorOptional0_0);
	ctx->memory.delete(declarator);
}
struct pointer *verbum_ast_new_pointer(struct VerbumContext *ctx, Token literal_0, struct pointerOptional0 *pointerOptional0_0, struct pointerRepetition0 *pointerRepetition0_0) {
	struct pointer *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->literal_0 = literal_0;
		result->pointerOptional0_0 = pointerOptional0_0;
		result->pointerRepetition0_0 = pointerRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_pointer(struct VerbumContext *ctx, struct pointer *pointer) {
	verbum_ast_delete_pointerOptional0(ctx, pointer->pointerOptional0_0);
	verbum_ast_delete_pointerRepetition0(ctx, pointer->pointerRepetition0_0);
	ctx->memory.delete(pointer);
}
struct type_qualifier *verbum_ast_new_type_qualifier_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct type_qualifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = type_qualifierType_0;
	}

	return result;
}
struct type_qualifier *verbum_ast_new_type_qualifier_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct type_qualifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = type_qualifierType_1;
	}

	return result;
}
void verbum_ast_delete_type_qualifier(struct VerbumContext *ctx, struct type_qualifier *type_qualifier) {
	switch(type_qualifier->tag) {
	case type_qualifierType_0:
		verbum_token_delete(ctx, &type_qualifier->choice0.literal_0);
	break;
	case type_qualifierType_1:
		verbum_token_delete(ctx, &type_qualifier->choice1.literal_0);
	break;
	}
	ctx->memory.delete(type_qualifier);
}
struct direct_declarator *verbum_ast_new_direct_declarator(struct VerbumContext *ctx, struct direct_declaratorGroup0 *direct_declaratorGroup0_0, struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0) {
	struct direct_declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->direct_declaratorGroup0_0 = direct_declaratorGroup0_0;
		result->direct_declaratorRepetition0_0 = direct_declaratorRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_direct_declarator(struct VerbumContext *ctx, struct direct_declarator *direct_declarator) {
	verbum_ast_delete_direct_declaratorGroup0(ctx, direct_declarator->direct_declaratorGroup0_0);
	verbum_ast_delete_direct_declaratorRepetition0(ctx, direct_declarator->direct_declaratorRepetition0_0);
	ctx->memory.delete(direct_declarator);
}
struct constant_expression *verbum_ast_new_constant_expression(struct VerbumContext *ctx, struct conditional_expression *conditional_expression_0) {
	struct constant_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->conditional_expression_0 = conditional_expression_0;
	}

	return result;
}
void verbum_ast_delete_constant_expression(struct VerbumContext *ctx, struct constant_expression *constant_expression) {
	verbum_ast_delete_conditional_expression(ctx, constant_expression->conditional_expression_0);
	ctx->memory.delete(constant_expression);
}
struct conditional_expression *verbum_ast_new_conditional_expression(struct VerbumContext *ctx, struct conditional_expressionOptional0 *conditional_expressionOptional0_0, struct logical_or_expression *logical_or_expression_0) {
	struct conditional_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->conditional_expressionOptional0_0 = conditional_expressionOptional0_0;
		result->logical_or_expression_0 = logical_or_expression_0;
	}

	return result;
}
void verbum_ast_delete_conditional_expression(struct VerbumContext *ctx, struct conditional_expression *conditional_expression) {
	verbum_ast_delete_conditional_expressionOptional0(ctx, conditional_expression->conditional_expressionOptional0_0);
	verbum_ast_delete_logical_or_expression(ctx, conditional_expression->logical_or_expression_0);
	ctx->memory.delete(conditional_expression);
}
struct logical_or_expression *verbum_ast_new_logical_or_expression(struct VerbumContext *ctx, struct logical_and_expression *logical_and_expression_0, struct logical_or_expressionRepetition0 *logical_or_expressionRepetition0_0) {
	struct logical_or_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->logical_and_expression_0 = logical_and_expression_0;
		result->logical_or_expressionRepetition0_0 = logical_or_expressionRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_logical_or_expression(struct VerbumContext *ctx, struct logical_or_expression *logical_or_expression) {
	verbum_ast_delete_logical_and_expression(ctx, logical_or_expression->logical_and_expression_0);
	verbum_ast_delete_logical_or_expressionRepetition0(ctx, logical_or_expression->logical_or_expressionRepetition0_0);
	ctx->memory.delete(logical_or_expression);
}
struct logical_and_expression *verbum_ast_new_logical_and_expression(struct VerbumContext *ctx, struct logical_and_expressionRepetition0 *logical_and_expressionRepetition0_0, struct inclusive_or_expression *inclusive_or_expression_0) {
	struct logical_and_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->logical_and_expressionRepetition0_0 = logical_and_expressionRepetition0_0;
		result->inclusive_or_expression_0 = inclusive_or_expression_0;
	}

	return result;
}
void verbum_ast_delete_logical_and_expression(struct VerbumContext *ctx, struct logical_and_expression *logical_and_expression) {
	verbum_ast_delete_logical_and_expressionRepetition0(ctx, logical_and_expression->logical_and_expressionRepetition0_0);
	verbum_ast_delete_inclusive_or_expression(ctx, logical_and_expression->inclusive_or_expression_0);
	ctx->memory.delete(logical_and_expression);
}
struct inclusive_or_expression *verbum_ast_new_inclusive_or_expression(struct VerbumContext *ctx, struct inclusive_or_expressionRepetition0 *inclusive_or_expressionRepetition0_0, struct exclusive_or_expression *exclusive_or_expression_0) {
	struct inclusive_or_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->inclusive_or_expressionRepetition0_0 = inclusive_or_expressionRepetition0_0;
		result->exclusive_or_expression_0 = exclusive_or_expression_0;
	}

	return result;
}
void verbum_ast_delete_inclusive_or_expression(struct VerbumContext *ctx, struct inclusive_or_expression *inclusive_or_expression) {
	verbum_ast_delete_inclusive_or_expressionRepetition0(ctx, inclusive_or_expression->inclusive_or_expressionRepetition0_0);
	verbum_ast_delete_exclusive_or_expression(ctx, inclusive_or_expression->exclusive_or_expression_0);
	ctx->memory.delete(inclusive_or_expression);
}
struct exclusive_or_expression *verbum_ast_new_exclusive_or_expression(struct VerbumContext *ctx, struct exclusive_or_expressionRepetition0 *exclusive_or_expressionRepetition0_0, struct and_expression *and_expression_0) {
	struct exclusive_or_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->exclusive_or_expressionRepetition0_0 = exclusive_or_expressionRepetition0_0;
		result->and_expression_0 = and_expression_0;
	}

	return result;
}
void verbum_ast_delete_exclusive_or_expression(struct VerbumContext *ctx, struct exclusive_or_expression *exclusive_or_expression) {
	verbum_ast_delete_exclusive_or_expressionRepetition0(ctx, exclusive_or_expression->exclusive_or_expressionRepetition0_0);
	verbum_ast_delete_and_expression(ctx, exclusive_or_expression->and_expression_0);
	ctx->memory.delete(exclusive_or_expression);
}
struct and_expression *verbum_ast_new_and_expression(struct VerbumContext *ctx, struct and_expressionRepetition0 *and_expressionRepetition0_0, struct equality_expression *equality_expression_0) {
	struct and_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->and_expressionRepetition0_0 = and_expressionRepetition0_0;
		result->equality_expression_0 = equality_expression_0;
	}

	return result;
}
void verbum_ast_delete_and_expression(struct VerbumContext *ctx, struct and_expression *and_expression) {
	verbum_ast_delete_and_expressionRepetition0(ctx, and_expression->and_expressionRepetition0_0);
	verbum_ast_delete_equality_expression(ctx, and_expression->equality_expression_0);
	ctx->memory.delete(and_expression);
}
struct equality_expression *verbum_ast_new_equality_expression(struct VerbumContext *ctx, struct relational_expression *relational_expression_0, struct equality_expressionRepetition0 *equality_expressionRepetition0_0) {
	struct equality_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->relational_expression_0 = relational_expression_0;
		result->equality_expressionRepetition0_0 = equality_expressionRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_equality_expression(struct VerbumContext *ctx, struct equality_expression *equality_expression) {
	verbum_ast_delete_relational_expression(ctx, equality_expression->relational_expression_0);
	verbum_ast_delete_equality_expressionRepetition0(ctx, equality_expression->equality_expressionRepetition0_0);
	ctx->memory.delete(equality_expression);
}
struct relational_expression *verbum_ast_new_relational_expression(struct VerbumContext *ctx, struct shift_expression *shift_expression_0, struct relational_expressionRepetition0 *relational_expressionRepetition0_0) {
	struct relational_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->shift_expression_0 = shift_expression_0;
		result->relational_expressionRepetition0_0 = relational_expressionRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_relational_expression(struct VerbumContext *ctx, struct relational_expression *relational_expression) {
	verbum_ast_delete_shift_expression(ctx, relational_expression->shift_expression_0);
	verbum_ast_delete_relational_expressionRepetition0(ctx, relational_expression->relational_expressionRepetition0_0);
	ctx->memory.delete(relational_expression);
}
struct shift_expression *verbum_ast_new_shift_expression(struct VerbumContext *ctx, struct shift_expressionRepetition0 *shift_expressionRepetition0_0, struct additive_expression *additive_expression_0) {
	struct shift_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->shift_expressionRepetition0_0 = shift_expressionRepetition0_0;
		result->additive_expression_0 = additive_expression_0;
	}

	return result;
}
void verbum_ast_delete_shift_expression(struct VerbumContext *ctx, struct shift_expression *shift_expression) {
	verbum_ast_delete_shift_expressionRepetition0(ctx, shift_expression->shift_expressionRepetition0_0);
	verbum_ast_delete_additive_expression(ctx, shift_expression->additive_expression_0);
	ctx->memory.delete(shift_expression);
}
struct additive_expression *verbum_ast_new_additive_expression(struct VerbumContext *ctx, struct additive_expressionRepetition0 *additive_expressionRepetition0_0, struct multiplicative_expression *multiplicative_expression_0) {
	struct additive_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->additive_expressionRepetition0_0 = additive_expressionRepetition0_0;
		result->multiplicative_expression_0 = multiplicative_expression_0;
	}

	return result;
}
void verbum_ast_delete_additive_expression(struct VerbumContext *ctx, struct additive_expression *additive_expression) {
	verbum_ast_delete_additive_expressionRepetition0(ctx, additive_expression->additive_expressionRepetition0_0);
	verbum_ast_delete_multiplicative_expression(ctx, additive_expression->multiplicative_expression_0);
	ctx->memory.delete(additive_expression);
}
struct multiplicative_expression *verbum_ast_new_multiplicative_expression(struct VerbumContext *ctx, struct cast_expression *cast_expression_0, struct multiplicative_expressionRepetition0 *multiplicative_expressionRepetition0_0) {
	struct multiplicative_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->cast_expression_0 = cast_expression_0;
		result->multiplicative_expressionRepetition0_0 = multiplicative_expressionRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_multiplicative_expression(struct VerbumContext *ctx, struct multiplicative_expression *multiplicative_expression) {
	verbum_ast_delete_cast_expression(ctx, multiplicative_expression->cast_expression_0);
	verbum_ast_delete_multiplicative_expressionRepetition0(ctx, multiplicative_expression->multiplicative_expressionRepetition0_0);
	ctx->memory.delete(multiplicative_expression);
}
struct cast_expression *verbum_ast_new_cast_expression_choice0(struct VerbumContext *ctx, struct unary_expression *unary_expression_0) {
	struct cast_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.unary_expression_0 = unary_expression_0;

		result->tag = cast_expressionType_0;
	}

	return result;
}
struct cast_expression *verbum_ast_new_cast_expression_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct type_name *type_name_0, struct cast_expression *cast_expression_0) {
	struct cast_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.type_name_0 = type_name_0;
		result->choice1.cast_expression_0 = cast_expression_0;

		result->tag = cast_expressionType_1;
	}

	return result;
}
void verbum_ast_delete_cast_expression(struct VerbumContext *ctx, struct cast_expression *cast_expression) {
	switch(cast_expression->tag) {
	case cast_expressionType_0:
		verbum_ast_delete_unary_expression(ctx, cast_expression->choice0.unary_expression_0);
	break;
	case cast_expressionType_1:
		verbum_token_delete(ctx, &cast_expression->choice1.literal_0);
		verbum_token_delete(ctx, &cast_expression->choice1.literal_1);
		verbum_ast_delete_type_name(ctx, cast_expression->choice1.type_name_0);
		verbum_ast_delete_cast_expression(ctx, cast_expression->choice1.cast_expression_0);
	break;
	}
	ctx->memory.delete(cast_expression);
}
struct unary_expression *verbum_ast_new_unary_expression_choice0(struct VerbumContext *ctx, struct postfix_expression *postfix_expression_0) {
	struct unary_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.postfix_expression_0 = postfix_expression_0;

		result->tag = unary_expressionType_0;
	}

	return result;
}
struct unary_expression *verbum_ast_new_unary_expression_choice1(struct VerbumContext *ctx, Token literal_0, struct unary_expression *unary_expression_0) {
	struct unary_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.unary_expression_0 = unary_expression_0;

		result->tag = unary_expressionType_1;
	}

	return result;
}
struct unary_expression *verbum_ast_new_unary_expression_choice2(struct VerbumContext *ctx, Token literal_0, struct unary_expression *unary_expression_0) {
	struct unary_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;
		result->choice2.unary_expression_0 = unary_expression_0;

		result->tag = unary_expressionType_2;
	}

	return result;
}
struct unary_expression *verbum_ast_new_unary_expression_choice3(struct VerbumContext *ctx, struct unary_operator *unary_operator_0, struct cast_expression *cast_expression_0) {
	struct unary_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.unary_operator_0 = unary_operator_0;
		result->choice3.cast_expression_0 = cast_expression_0;

		result->tag = unary_expressionType_3;
	}

	return result;
}
struct unary_expression *verbum_ast_new_unary_expression_choice4(struct VerbumContext *ctx, Token literal_0, struct unary_expressionGroup0 *unary_expressionGroup0_0) {
	struct unary_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice4.literal_0 = literal_0;
		result->choice4.unary_expressionGroup0_0 = unary_expressionGroup0_0;

		result->tag = unary_expressionType_4;
	}

	return result;
}
void verbum_ast_delete_unary_expression(struct VerbumContext *ctx, struct unary_expression *unary_expression) {
	switch(unary_expression->tag) {
	case unary_expressionType_0:
		verbum_ast_delete_postfix_expression(ctx, unary_expression->choice0.postfix_expression_0);
	break;
	case unary_expressionType_1:
		verbum_token_delete(ctx, &unary_expression->choice1.literal_0);
		verbum_ast_delete_unary_expression(ctx, unary_expression->choice1.unary_expression_0);
	break;
	case unary_expressionType_2:
		verbum_token_delete(ctx, &unary_expression->choice2.literal_0);
		verbum_ast_delete_unary_expression(ctx, unary_expression->choice2.unary_expression_0);
	break;
	case unary_expressionType_3:
		verbum_ast_delete_unary_operator(ctx, unary_expression->choice3.unary_operator_0);
		verbum_ast_delete_cast_expression(ctx, unary_expression->choice3.cast_expression_0);
	break;
	case unary_expressionType_4:
		verbum_token_delete(ctx, &unary_expression->choice4.literal_0);
		verbum_ast_delete_unary_expressionGroup0(ctx, unary_expression->choice4.unary_expressionGroup0_0);
	break;
	}
	ctx->memory.delete(unary_expression);
}
struct postfix_expression *verbum_ast_new_postfix_expression(struct VerbumContext *ctx, struct primary_expression *primary_expression_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0) {
	struct postfix_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->primary_expression_0 = primary_expression_0;
		result->postfix_expressionRepetition0_0 = postfix_expressionRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_postfix_expression(struct VerbumContext *ctx, struct postfix_expression *postfix_expression) {
	verbum_ast_delete_primary_expression(ctx, postfix_expression->primary_expression_0);
	verbum_ast_delete_postfix_expressionRepetition0(ctx, postfix_expression->postfix_expressionRepetition0_0);
	ctx->memory.delete(postfix_expression);
}
struct primary_expression *verbum_ast_new_primary_expression_choice0(struct VerbumContext *ctx, Token IDENTIFIER_0) {
	struct primary_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = primary_expressionType_0;
	}

	return result;
}
struct primary_expression *verbum_ast_new_primary_expression_choice1(struct VerbumContext *ctx, struct constant *constant_0) {
	struct primary_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.constant_0 = constant_0;

		result->tag = primary_expressionType_1;
	}

	return result;
}
struct primary_expression *verbum_ast_new_primary_expression_choice2(struct VerbumContext *ctx, Token STRING_0) {
	struct primary_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.STRING_0 = STRING_0;

		result->tag = primary_expressionType_2;
	}

	return result;
}
struct primary_expression *verbum_ast_new_primary_expression_choice3(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0) {
	struct primary_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.literal_0 = literal_0;
		result->choice3.literal_1 = literal_1;
		result->choice3.expression_0 = expression_0;

		result->tag = primary_expressionType_3;
	}

	return result;
}
void verbum_ast_delete_primary_expression(struct VerbumContext *ctx, struct primary_expression *primary_expression) {
	switch(primary_expression->tag) {
	case primary_expressionType_0:
		verbum_token_delete(ctx, &primary_expression->choice0.IDENTIFIER_0);
	break;
	case primary_expressionType_1:
		verbum_ast_delete_constant(ctx, primary_expression->choice1.constant_0);
	break;
	case primary_expressionType_2:
		verbum_token_delete(ctx, &primary_expression->choice2.STRING_0);
	break;
	case primary_expressionType_3:
		verbum_token_delete(ctx, &primary_expression->choice3.literal_0);
		verbum_token_delete(ctx, &primary_expression->choice3.literal_1);
		verbum_ast_delete_expression(ctx, primary_expression->choice3.expression_0);
	break;
	}
	ctx->memory.delete(primary_expression);
}
struct constant *verbum_ast_new_constant_choice0(struct VerbumContext *ctx, Token INTEGER_CONSTANT_0) {
	struct constant *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.INTEGER_CONSTANT_0 = INTEGER_CONSTANT_0;

		result->tag = constantType_0;
	}

	return result;
}
struct constant *verbum_ast_new_constant_choice1(struct VerbumContext *ctx, Token CHARACTER_CONSTANT_0) {
	struct constant *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.CHARACTER_CONSTANT_0 = CHARACTER_CONSTANT_0;

		result->tag = constantType_1;
	}

	return result;
}
struct constant *verbum_ast_new_constant_choice2(struct VerbumContext *ctx, Token FLOATING_CONSTANT_0) {
	struct constant *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.FLOATING_CONSTANT_0 = FLOATING_CONSTANT_0;

		result->tag = constantType_2;
	}

	return result;
}
struct constant *verbum_ast_new_constant_choice3(struct VerbumContext *ctx, Token ENUMERATION_CONSTANT_0) {
	struct constant *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.ENUMERATION_CONSTANT_0 = ENUMERATION_CONSTANT_0;

		result->tag = constantType_3;
	}

	return result;
}
void verbum_ast_delete_constant(struct VerbumContext *ctx, struct constant *constant) {
	switch(constant->tag) {
	case constantType_0:
		verbum_token_delete(ctx, &constant->choice0.INTEGER_CONSTANT_0);
	break;
	case constantType_1:
		verbum_token_delete(ctx, &constant->choice1.CHARACTER_CONSTANT_0);
	break;
	case constantType_2:
		verbum_token_delete(ctx, &constant->choice2.FLOATING_CONSTANT_0);
	break;
	case constantType_3:
		verbum_token_delete(ctx, &constant->choice3.ENUMERATION_CONSTANT_0);
	break;
	}
	ctx->memory.delete(constant);
}
struct expression *verbum_ast_new_expression(struct VerbumContext *ctx, struct assignment_expression *assignment_expression_0, struct expressionRepetition0 *expressionRepetition0_0) {
	struct expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->assignment_expression_0 = assignment_expression_0;
		result->expressionRepetition0_0 = expressionRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_expression(struct VerbumContext *ctx, struct expression *expression) {
	verbum_ast_delete_assignment_expression(ctx, expression->assignment_expression_0);
	verbum_ast_delete_expressionRepetition0(ctx, expression->expressionRepetition0_0);
	ctx->memory.delete(expression);
}
struct assignment_expression *verbum_ast_new_assignment_expression_choice0(struct VerbumContext *ctx, struct conditional_expression *conditional_expression_0) {
	struct assignment_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.conditional_expression_0 = conditional_expression_0;

		result->tag = assignment_expressionType_0;
	}

	return result;
}
struct assignment_expression *verbum_ast_new_assignment_expression_choice1(struct VerbumContext *ctx, struct assignment_expression *assignment_expression_0, struct assignment_operator *assignment_operator_0, struct unary_expression *unary_expression_0) {
	struct assignment_expression *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.assignment_expression_0 = assignment_expression_0;
		result->choice1.assignment_operator_0 = assignment_operator_0;
		result->choice1.unary_expression_0 = unary_expression_0;

		result->tag = assignment_expressionType_1;
	}

	return result;
}
void verbum_ast_delete_assignment_expression(struct VerbumContext *ctx, struct assignment_expression *assignment_expression) {
	switch(assignment_expression->tag) {
	case assignment_expressionType_0:
		verbum_ast_delete_conditional_expression(ctx, assignment_expression->choice0.conditional_expression_0);
	break;
	case assignment_expressionType_1:
		verbum_ast_delete_assignment_expression(ctx, assignment_expression->choice1.assignment_expression_0);
		verbum_ast_delete_assignment_operator(ctx, assignment_expression->choice1.assignment_operator_0);
		verbum_ast_delete_unary_expression(ctx, assignment_expression->choice1.unary_expression_0);
	break;
	}
	ctx->memory.delete(assignment_expression);
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = assignment_operatorType_0;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = assignment_operatorType_1;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice2(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;

		result->tag = assignment_operatorType_2;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice3(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.literal_0 = literal_0;

		result->tag = assignment_operatorType_3;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice4(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice4.literal_0 = literal_0;

		result->tag = assignment_operatorType_4;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice5(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice5.literal_0 = literal_0;

		result->tag = assignment_operatorType_5;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice6(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice6.literal_0 = literal_0;

		result->tag = assignment_operatorType_6;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice7(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice7.literal_0 = literal_0;

		result->tag = assignment_operatorType_7;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice8(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice8.literal_0 = literal_0;

		result->tag = assignment_operatorType_8;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice9(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice9.literal_0 = literal_0;

		result->tag = assignment_operatorType_9;
	}

	return result;
}
struct assignment_operator *verbum_ast_new_assignment_operator_choice10(struct VerbumContext *ctx, Token literal_0) {
	struct assignment_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice10.literal_0 = literal_0;

		result->tag = assignment_operatorType_10;
	}

	return result;
}
void verbum_ast_delete_assignment_operator(struct VerbumContext *ctx, struct assignment_operator *assignment_operator) {
	switch(assignment_operator->tag) {
	case assignment_operatorType_0:
		verbum_token_delete(ctx, &assignment_operator->choice0.literal_0);
	break;
	case assignment_operatorType_1:
		verbum_token_delete(ctx, &assignment_operator->choice1.literal_0);
	break;
	case assignment_operatorType_2:
		verbum_token_delete(ctx, &assignment_operator->choice2.literal_0);
	break;
	case assignment_operatorType_3:
		verbum_token_delete(ctx, &assignment_operator->choice3.literal_0);
	break;
	case assignment_operatorType_4:
		verbum_token_delete(ctx, &assignment_operator->choice4.literal_0);
	break;
	case assignment_operatorType_5:
		verbum_token_delete(ctx, &assignment_operator->choice5.literal_0);
	break;
	case assignment_operatorType_6:
		verbum_token_delete(ctx, &assignment_operator->choice6.literal_0);
	break;
	case assignment_operatorType_7:
		verbum_token_delete(ctx, &assignment_operator->choice7.literal_0);
	break;
	case assignment_operatorType_8:
		verbum_token_delete(ctx, &assignment_operator->choice8.literal_0);
	break;
	case assignment_operatorType_9:
		verbum_token_delete(ctx, &assignment_operator->choice9.literal_0);
	break;
	case assignment_operatorType_10:
		verbum_token_delete(ctx, &assignment_operator->choice10.literal_0);
	break;
	}
	ctx->memory.delete(assignment_operator);
}
struct unary_operator *verbum_ast_new_unary_operator_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct unary_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = unary_operatorType_0;
	}

	return result;
}
struct unary_operator *verbum_ast_new_unary_operator_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct unary_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = unary_operatorType_1;
	}

	return result;
}
struct unary_operator *verbum_ast_new_unary_operator_choice2(struct VerbumContext *ctx, Token literal_0) {
	struct unary_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;

		result->tag = unary_operatorType_2;
	}

	return result;
}
struct unary_operator *verbum_ast_new_unary_operator_choice3(struct VerbumContext *ctx, Token literal_0) {
	struct unary_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.literal_0 = literal_0;

		result->tag = unary_operatorType_3;
	}

	return result;
}
struct unary_operator *verbum_ast_new_unary_operator_choice4(struct VerbumContext *ctx, Token literal_0) {
	struct unary_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice4.literal_0 = literal_0;

		result->tag = unary_operatorType_4;
	}

	return result;
}
struct unary_operator *verbum_ast_new_unary_operator_choice5(struct VerbumContext *ctx, Token literal_0) {
	struct unary_operator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice5.literal_0 = literal_0;

		result->tag = unary_operatorType_5;
	}

	return result;
}
void verbum_ast_delete_unary_operator(struct VerbumContext *ctx, struct unary_operator *unary_operator) {
	switch(unary_operator->tag) {
	case unary_operatorType_0:
		verbum_token_delete(ctx, &unary_operator->choice0.literal_0);
	break;
	case unary_operatorType_1:
		verbum_token_delete(ctx, &unary_operator->choice1.literal_0);
	break;
	case unary_operatorType_2:
		verbum_token_delete(ctx, &unary_operator->choice2.literal_0);
	break;
	case unary_operatorType_3:
		verbum_token_delete(ctx, &unary_operator->choice3.literal_0);
	break;
	case unary_operatorType_4:
		verbum_token_delete(ctx, &unary_operator->choice4.literal_0);
	break;
	case unary_operatorType_5:
		verbum_token_delete(ctx, &unary_operator->choice5.literal_0);
	break;
	}
	ctx->memory.delete(unary_operator);
}
struct type_name *verbum_ast_new_type_name(struct VerbumContext *ctx, struct type_nameRepetition0 *type_nameRepetition0_0, struct type_nameOptional0 *type_nameOptional0_0) {
	struct type_name *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->type_nameRepetition0_0 = type_nameRepetition0_0;
		result->type_nameOptional0_0 = type_nameOptional0_0;
	}

	return result;
}
void verbum_ast_delete_type_name(struct VerbumContext *ctx, struct type_name *type_name) {
	verbum_ast_delete_type_nameRepetition0(ctx, type_name->type_nameRepetition0_0);
	verbum_ast_delete_type_nameOptional0(ctx, type_name->type_nameOptional0_0);
	ctx->memory.delete(type_name);
}
struct parameter_type_list *verbum_ast_new_parameter_type_list(struct VerbumContext *ctx, struct parameter_list *parameter_list_0, struct parameter_type_listOptional0 *parameter_type_listOptional0_0) {
	struct parameter_type_list *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->parameter_list_0 = parameter_list_0;
		result->parameter_type_listOptional0_0 = parameter_type_listOptional0_0;
	}

	return result;
}
void verbum_ast_delete_parameter_type_list(struct VerbumContext *ctx, struct parameter_type_list *parameter_type_list) {
	verbum_ast_delete_parameter_list(ctx, parameter_type_list->parameter_list_0);
	verbum_ast_delete_parameter_type_listOptional0(ctx, parameter_type_list->parameter_type_listOptional0_0);
	ctx->memory.delete(parameter_type_list);
}
struct parameter_list *verbum_ast_new_parameter_list(struct VerbumContext *ctx, struct parameter_listRepetition0 *parameter_listRepetition0_0, struct parameter_declaration *parameter_declaration_0) {
	struct parameter_list *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->parameter_listRepetition0_0 = parameter_listRepetition0_0;
		result->parameter_declaration_0 = parameter_declaration_0;
	}

	return result;
}
void verbum_ast_delete_parameter_list(struct VerbumContext *ctx, struct parameter_list *parameter_list) {
	verbum_ast_delete_parameter_listRepetition0(ctx, parameter_list->parameter_listRepetition0_0);
	verbum_ast_delete_parameter_declaration(ctx, parameter_list->parameter_declaration_0);
	ctx->memory.delete(parameter_list);
}
struct parameter_declaration *verbum_ast_new_parameter_declaration(struct VerbumContext *ctx, struct parameter_declarationRepetition0 *parameter_declarationRepetition0_0, struct declaration_specifier *declaration_specifier_0, struct parameter_declarationOptional0 *parameter_declarationOptional0_0) {
	struct parameter_declaration *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->parameter_declarationRepetition0_0 = parameter_declarationRepetition0_0;
		result->declaration_specifier_0 = declaration_specifier_0;
		result->parameter_declarationOptional0_0 = parameter_declarationOptional0_0;
	}

	return result;
}
void verbum_ast_delete_parameter_declaration(struct VerbumContext *ctx, struct parameter_declaration *parameter_declaration) {
	verbum_ast_delete_parameter_declarationRepetition0(ctx, parameter_declaration->parameter_declarationRepetition0_0);
	verbum_ast_delete_declaration_specifier(ctx, parameter_declaration->declaration_specifier_0);
	verbum_ast_delete_parameter_declarationOptional0(ctx, parameter_declaration->parameter_declarationOptional0_0);
	ctx->memory.delete(parameter_declaration);
}
struct abstract_declarator *verbum_ast_new_abstract_declarator_choice0(struct VerbumContext *ctx, struct abstract_declaratorOptional0 *abstract_declaratorOptional0_0, struct pointer *pointer_0) {
	struct abstract_declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.abstract_declaratorOptional0_0 = abstract_declaratorOptional0_0;
		result->choice0.pointer_0 = pointer_0;

		result->tag = abstract_declaratorType_0;
	}

	return result;
}
struct abstract_declarator *verbum_ast_new_abstract_declarator_choice1(struct VerbumContext *ctx, struct direct_abstract_declarator *direct_abstract_declarator_0) {
	struct abstract_declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.direct_abstract_declarator_0 = direct_abstract_declarator_0;

		result->tag = abstract_declaratorType_1;
	}

	return result;
}
void verbum_ast_delete_abstract_declarator(struct VerbumContext *ctx, struct abstract_declarator *abstract_declarator) {
	switch(abstract_declarator->tag) {
	case abstract_declaratorType_0:
		verbum_ast_delete_abstract_declaratorOptional0(ctx, abstract_declarator->choice0.abstract_declaratorOptional0_0);
		verbum_ast_delete_pointer(ctx, abstract_declarator->choice0.pointer_0);
	break;
	case abstract_declaratorType_1:
		verbum_ast_delete_direct_abstract_declarator(ctx, abstract_declarator->choice1.direct_abstract_declarator_0);
	break;
	}
	ctx->memory.delete(abstract_declarator);
}
struct direct_abstract_declarator *verbum_ast_new_direct_abstract_declarator_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct abstract_declarator *abstract_declarator_0) {
	struct direct_abstract_declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;
		result->choice0.abstract_declarator_0 = abstract_declarator_0;

		result->tag = direct_abstract_declaratorType_0;
	}

	return result;
}
struct direct_abstract_declarator *verbum_ast_new_direct_abstract_declarator_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct direct_abstract_declaratorOptional1 *direct_abstract_declaratorOptional1_0, struct direct_abstract_declaratorOptional0 *direct_abstract_declaratorOptional0_0) {
	struct direct_abstract_declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.direct_abstract_declaratorOptional1_0 = direct_abstract_declaratorOptional1_0;
		result->choice1.direct_abstract_declaratorOptional0_0 = direct_abstract_declaratorOptional0_0;

		result->tag = direct_abstract_declaratorType_1;
	}

	return result;
}
struct direct_abstract_declarator *verbum_ast_new_direct_abstract_declarator_choice2(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct direct_abstract_declaratorOptional2 *direct_abstract_declaratorOptional2_0, struct direct_abstract_declaratorOptional3 *direct_abstract_declaratorOptional3_0) {
	struct direct_abstract_declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;
		result->choice2.literal_1 = literal_1;
		result->choice2.direct_abstract_declaratorOptional2_0 = direct_abstract_declaratorOptional2_0;
		result->choice2.direct_abstract_declaratorOptional3_0 = direct_abstract_declaratorOptional3_0;

		result->tag = direct_abstract_declaratorType_2;
	}

	return result;
}
void verbum_ast_delete_direct_abstract_declarator(struct VerbumContext *ctx, struct direct_abstract_declarator *direct_abstract_declarator) {
	switch(direct_abstract_declarator->tag) {
	case direct_abstract_declaratorType_0:
		verbum_token_delete(ctx, &direct_abstract_declarator->choice0.literal_0);
		verbum_token_delete(ctx, &direct_abstract_declarator->choice0.literal_1);
		verbum_ast_delete_abstract_declarator(ctx, direct_abstract_declarator->choice0.abstract_declarator_0);
	break;
	case direct_abstract_declaratorType_1:
		verbum_token_delete(ctx, &direct_abstract_declarator->choice1.literal_0);
		verbum_token_delete(ctx, &direct_abstract_declarator->choice1.literal_1);
		verbum_ast_delete_direct_abstract_declaratorOptional1(ctx, direct_abstract_declarator->choice1.direct_abstract_declaratorOptional1_0);
		verbum_ast_delete_direct_abstract_declaratorOptional0(ctx, direct_abstract_declarator->choice1.direct_abstract_declaratorOptional0_0);
	break;
	case direct_abstract_declaratorType_2:
		verbum_token_delete(ctx, &direct_abstract_declarator->choice2.literal_0);
		verbum_token_delete(ctx, &direct_abstract_declarator->choice2.literal_1);
		verbum_ast_delete_direct_abstract_declaratorOptional2(ctx, direct_abstract_declarator->choice2.direct_abstract_declaratorOptional2_0);
		verbum_ast_delete_direct_abstract_declaratorOptional3(ctx, direct_abstract_declarator->choice2.direct_abstract_declaratorOptional3_0);
	break;
	}
	ctx->memory.delete(direct_abstract_declarator);
}
struct enum_specifier *verbum_ast_new_enum_specifier_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, struct enumerator_list *enumerator_list_0, struct enum_specifierOptional0 *enum_specifierOptional0_0) {
	struct enum_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;
		result->choice0.literal_2 = literal_2;
		result->choice0.enumerator_list_0 = enumerator_list_0;
		result->choice0.enum_specifierOptional0_0 = enum_specifierOptional0_0;

		result->tag = enum_specifierType_0;
	}

	return result;
}
struct enum_specifier *verbum_ast_new_enum_specifier_choice1(struct VerbumContext *ctx, Token literal_0, Token IDENTIFIER_0) {
	struct enum_specifier *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = enum_specifierType_1;
	}

	return result;
}
void verbum_ast_delete_enum_specifier(struct VerbumContext *ctx, struct enum_specifier *enum_specifier) {
	switch(enum_specifier->tag) {
	case enum_specifierType_0:
		verbum_token_delete(ctx, &enum_specifier->choice0.literal_0);
		verbum_token_delete(ctx, &enum_specifier->choice0.literal_1);
		verbum_token_delete(ctx, &enum_specifier->choice0.literal_2);
		verbum_ast_delete_enumerator_list(ctx, enum_specifier->choice0.enumerator_list_0);
		verbum_ast_delete_enum_specifierOptional0(ctx, enum_specifier->choice0.enum_specifierOptional0_0);
	break;
	case enum_specifierType_1:
		verbum_token_delete(ctx, &enum_specifier->choice1.literal_0);
		verbum_token_delete(ctx, &enum_specifier->choice1.IDENTIFIER_0);
	break;
	}
	ctx->memory.delete(enum_specifier);
}
struct enumerator_list *verbum_ast_new_enumerator_list(struct VerbumContext *ctx, struct enumerator *enumerator_0, struct enumerator_listRepetition0 *enumerator_listRepetition0_0) {
	struct enumerator_list *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->enumerator_0 = enumerator_0;
		result->enumerator_listRepetition0_0 = enumerator_listRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_enumerator_list(struct VerbumContext *ctx, struct enumerator_list *enumerator_list) {
	verbum_ast_delete_enumerator(ctx, enumerator_list->enumerator_0);
	verbum_ast_delete_enumerator_listRepetition0(ctx, enumerator_list->enumerator_listRepetition0_0);
	ctx->memory.delete(enumerator_list);
}
struct enumerator *verbum_ast_new_enumerator(struct VerbumContext *ctx, Token IDENTIFIER_0, struct enumeratorOptional0 *enumeratorOptional0_0) {
	struct enumerator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->IDENTIFIER_0 = IDENTIFIER_0;
		result->enumeratorOptional0_0 = enumeratorOptional0_0;
	}

	return result;
}
void verbum_ast_delete_enumerator(struct VerbumContext *ctx, struct enumerator *enumerator) {
	verbum_ast_delete_enumeratorOptional0(ctx, enumerator->enumeratorOptional0_0);
	ctx->memory.delete(enumerator);
}
struct typedef_name *verbum_ast_new_typedef_name(struct VerbumContext *ctx, Token IDENTIFIER_0) {
	struct typedef_name *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->IDENTIFIER_0 = IDENTIFIER_0;
	}

	return result;
}
void verbum_ast_delete_typedef_name(struct VerbumContext *ctx, struct typedef_name *typedef_name) {
	ctx->memory.delete(typedef_name);
}
struct declaration *verbum_ast_new_declaration(struct VerbumContext *ctx, Token literal_0, struct declarationRepetition1 *declarationRepetition1_0, struct declarationRepetition0 *declarationRepetition0_0) {
	struct declaration *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->literal_0 = literal_0;
		result->declarationRepetition1_0 = declarationRepetition1_0;
		result->declarationRepetition0_0 = declarationRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_declaration(struct VerbumContext *ctx, struct declaration *declaration) {
	verbum_ast_delete_declarationRepetition1(ctx, declaration->declarationRepetition1_0);
	verbum_ast_delete_declarationRepetition0(ctx, declaration->declarationRepetition0_0);
	ctx->memory.delete(declaration);
}
struct init_declarator *verbum_ast_new_init_declarator(struct VerbumContext *ctx, struct init_declaratorOptional0 *init_declaratorOptional0_0, struct declarator *declarator_0) {
	struct init_declarator *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->init_declaratorOptional0_0 = init_declaratorOptional0_0;
		result->declarator_0 = declarator_0;
	}

	return result;
}
void verbum_ast_delete_init_declarator(struct VerbumContext *ctx, struct init_declarator *init_declarator) {
	verbum_ast_delete_init_declaratorOptional0(ctx, init_declarator->init_declaratorOptional0_0);
	verbum_ast_delete_declarator(ctx, init_declarator->declarator_0);
	ctx->memory.delete(init_declarator);
}
struct initializer *verbum_ast_new_initializer_choice0(struct VerbumContext *ctx, struct assignment_expression *assignment_expression_0) {
	struct initializer *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.assignment_expression_0 = assignment_expression_0;

		result->tag = initializerType_0;
	}

	return result;
}
struct initializer *verbum_ast_new_initializer_choice1(struct VerbumContext *ctx, struct initializer_list *initializer_list_0, Token literal_0, Token literal_1, struct initializerOptional0 *initializerOptional0_0) {
	struct initializer *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.initializer_list_0 = initializer_list_0;
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.initializerOptional0_0 = initializerOptional0_0;

		result->tag = initializerType_1;
	}

	return result;
}
void verbum_ast_delete_initializer(struct VerbumContext *ctx, struct initializer *initializer) {
	switch(initializer->tag) {
	case initializerType_0:
		verbum_ast_delete_assignment_expression(ctx, initializer->choice0.assignment_expression_0);
	break;
	case initializerType_1:
		verbum_ast_delete_initializer_list(ctx, initializer->choice1.initializer_list_0);
		verbum_token_delete(ctx, &initializer->choice1.literal_0);
		verbum_token_delete(ctx, &initializer->choice1.literal_1);
		verbum_ast_delete_initializerOptional0(ctx, initializer->choice1.initializerOptional0_0);
	break;
	}
	ctx->memory.delete(initializer);
}
struct initializer_list *verbum_ast_new_initializer_list(struct VerbumContext *ctx, struct initializer *initializer_0, struct initializer_listRepetition0 *initializer_listRepetition0_0) {
	struct initializer_list *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->initializer_0 = initializer_0;
		result->initializer_listRepetition0_0 = initializer_listRepetition0_0;
	}

	return result;
}
void verbum_ast_delete_initializer_list(struct VerbumContext *ctx, struct initializer_list *initializer_list) {
	verbum_ast_delete_initializer(ctx, initializer_list->initializer_0);
	verbum_ast_delete_initializer_listRepetition0(ctx, initializer_list->initializer_listRepetition0_0);
	ctx->memory.delete(initializer_list);
}
struct compound_statement *verbum_ast_new_compound_statement(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct compound_statementRepetition0 *compound_statementRepetition0_0, struct compound_statementRepetition1 *compound_statementRepetition1_0) {
	struct compound_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->literal_0 = literal_0;
		result->literal_1 = literal_1;
		result->compound_statementRepetition0_0 = compound_statementRepetition0_0;
		result->compound_statementRepetition1_0 = compound_statementRepetition1_0;
	}

	return result;
}
void verbum_ast_delete_compound_statement(struct VerbumContext *ctx, struct compound_statement *compound_statement) {
	verbum_ast_delete_compound_statementRepetition0(ctx, compound_statement->compound_statementRepetition0_0);
	verbum_ast_delete_compound_statementRepetition1(ctx, compound_statement->compound_statementRepetition1_0);
	ctx->memory.delete(compound_statement);
}
struct statement *verbum_ast_new_statement_choice0(struct VerbumContext *ctx, struct labeled_statement *labeled_statement_0) {
	struct statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.labeled_statement_0 = labeled_statement_0;

		result->tag = statementType_0;
	}

	return result;
}
struct statement *verbum_ast_new_statement_choice1(struct VerbumContext *ctx, struct expression_statement *expression_statement_0) {
	struct statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.expression_statement_0 = expression_statement_0;

		result->tag = statementType_1;
	}

	return result;
}
struct statement *verbum_ast_new_statement_choice2(struct VerbumContext *ctx, struct compound_statement *compound_statement_0) {
	struct statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.compound_statement_0 = compound_statement_0;

		result->tag = statementType_2;
	}

	return result;
}
struct statement *verbum_ast_new_statement_choice3(struct VerbumContext *ctx, struct selection_statement *selection_statement_0) {
	struct statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.selection_statement_0 = selection_statement_0;

		result->tag = statementType_3;
	}

	return result;
}
struct statement *verbum_ast_new_statement_choice4(struct VerbumContext *ctx, struct iteration_statement *iteration_statement_0) {
	struct statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice4.iteration_statement_0 = iteration_statement_0;

		result->tag = statementType_4;
	}

	return result;
}
struct statement *verbum_ast_new_statement_choice5(struct VerbumContext *ctx, struct jump_statement *jump_statement_0) {
	struct statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice5.jump_statement_0 = jump_statement_0;

		result->tag = statementType_5;
	}

	return result;
}
void verbum_ast_delete_statement(struct VerbumContext *ctx, struct statement *statement) {
	switch(statement->tag) {
	case statementType_0:
		verbum_ast_delete_labeled_statement(ctx, statement->choice0.labeled_statement_0);
	break;
	case statementType_1:
		verbum_ast_delete_expression_statement(ctx, statement->choice1.expression_statement_0);
	break;
	case statementType_2:
		verbum_ast_delete_compound_statement(ctx, statement->choice2.compound_statement_0);
	break;
	case statementType_3:
		verbum_ast_delete_selection_statement(ctx, statement->choice3.selection_statement_0);
	break;
	case statementType_4:
		verbum_ast_delete_iteration_statement(ctx, statement->choice4.iteration_statement_0);
	break;
	case statementType_5:
		verbum_ast_delete_jump_statement(ctx, statement->choice5.jump_statement_0);
	break;
	}
	ctx->memory.delete(statement);
}
struct labeled_statement *verbum_ast_new_labeled_statement_choice0(struct VerbumContext *ctx, Token literal_0, struct statement *statement_0, Token IDENTIFIER_0) {
	struct labeled_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.statement_0 = statement_0;
		result->choice0.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = labeled_statementType_0;
	}

	return result;
}
struct labeled_statement *verbum_ast_new_labeled_statement_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct statement *statement_0, struct constant_expression *constant_expression_0) {
	struct labeled_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.statement_0 = statement_0;
		result->choice1.constant_expression_0 = constant_expression_0;

		result->tag = labeled_statementType_1;
	}

	return result;
}
struct labeled_statement *verbum_ast_new_labeled_statement_choice2(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct statement *statement_0) {
	struct labeled_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;
		result->choice2.literal_1 = literal_1;
		result->choice2.statement_0 = statement_0;

		result->tag = labeled_statementType_2;
	}

	return result;
}
void verbum_ast_delete_labeled_statement(struct VerbumContext *ctx, struct labeled_statement *labeled_statement) {
	switch(labeled_statement->tag) {
	case labeled_statementType_0:
		verbum_token_delete(ctx, &labeled_statement->choice0.literal_0);
		verbum_ast_delete_statement(ctx, labeled_statement->choice0.statement_0);
		verbum_token_delete(ctx, &labeled_statement->choice0.IDENTIFIER_0);
	break;
	case labeled_statementType_1:
		verbum_token_delete(ctx, &labeled_statement->choice1.literal_0);
		verbum_token_delete(ctx, &labeled_statement->choice1.literal_1);
		verbum_ast_delete_statement(ctx, labeled_statement->choice1.statement_0);
		verbum_ast_delete_constant_expression(ctx, labeled_statement->choice1.constant_expression_0);
	break;
	case labeled_statementType_2:
		verbum_token_delete(ctx, &labeled_statement->choice2.literal_0);
		verbum_token_delete(ctx, &labeled_statement->choice2.literal_1);
		verbum_ast_delete_statement(ctx, labeled_statement->choice2.statement_0);
	break;
	}
	ctx->memory.delete(labeled_statement);
}
struct expression_statement *verbum_ast_new_expression_statement(struct VerbumContext *ctx, Token literal_0, struct expression_statementOptional0 *expression_statementOptional0_0) {
	struct expression_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->literal_0 = literal_0;
		result->expression_statementOptional0_0 = expression_statementOptional0_0;
	}

	return result;
}
void verbum_ast_delete_expression_statement(struct VerbumContext *ctx, struct expression_statement *expression_statement) {
	verbum_ast_delete_expression_statementOptional0(ctx, expression_statement->expression_statementOptional0_0);
	ctx->memory.delete(expression_statement);
}
struct selection_statement *verbum_ast_new_selection_statement_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, struct expression *expression_0, struct selection_statementOptional0 *selection_statementOptional0_0, struct statement *statement_0) {
	struct selection_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;
		result->choice0.literal_2 = literal_2;
		result->choice0.expression_0 = expression_0;
		result->choice0.selection_statementOptional0_0 = selection_statementOptional0_0;
		result->choice0.statement_0 = statement_0;

		result->tag = selection_statementType_0;
	}

	return result;
}
struct selection_statement *verbum_ast_new_selection_statement_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, struct expression *expression_0, struct statement *statement_0) {
	struct selection_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.literal_2 = literal_2;
		result->choice1.expression_0 = expression_0;
		result->choice1.statement_0 = statement_0;

		result->tag = selection_statementType_1;
	}

	return result;
}
void verbum_ast_delete_selection_statement(struct VerbumContext *ctx, struct selection_statement *selection_statement) {
	switch(selection_statement->tag) {
	case selection_statementType_0:
		verbum_token_delete(ctx, &selection_statement->choice0.literal_0);
		verbum_token_delete(ctx, &selection_statement->choice0.literal_1);
		verbum_token_delete(ctx, &selection_statement->choice0.literal_2);
		verbum_ast_delete_expression(ctx, selection_statement->choice0.expression_0);
		verbum_ast_delete_selection_statementOptional0(ctx, selection_statement->choice0.selection_statementOptional0_0);
		verbum_ast_delete_statement(ctx, selection_statement->choice0.statement_0);
	break;
	case selection_statementType_1:
		verbum_token_delete(ctx, &selection_statement->choice1.literal_0);
		verbum_token_delete(ctx, &selection_statement->choice1.literal_1);
		verbum_token_delete(ctx, &selection_statement->choice1.literal_2);
		verbum_ast_delete_expression(ctx, selection_statement->choice1.expression_0);
		verbum_ast_delete_statement(ctx, selection_statement->choice1.statement_0);
	break;
	}
	ctx->memory.delete(selection_statement);
}
struct iteration_statement *verbum_ast_new_iteration_statement_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, struct expression *expression_0, struct statement *statement_0) {
	struct iteration_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;
		result->choice0.literal_2 = literal_2;
		result->choice0.expression_0 = expression_0;
		result->choice0.statement_0 = statement_0;

		result->tag = iteration_statementType_0;
	}

	return result;
}
struct iteration_statement *verbum_ast_new_iteration_statement_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, Token literal_3, Token literal_4, struct expression *expression_0, struct statement *statement_0) {
	struct iteration_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.literal_2 = literal_2;
		result->choice1.literal_3 = literal_3;
		result->choice1.literal_4 = literal_4;
		result->choice1.expression_0 = expression_0;
		result->choice1.statement_0 = statement_0;

		result->tag = iteration_statementType_1;
	}

	return result;
}
struct iteration_statement *verbum_ast_new_iteration_statement_choice2(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, Token literal_3, Token literal_4, struct iteration_statementOptional2 *iteration_statementOptional2_0, struct statement *statement_0, struct iteration_statementOptional0 *iteration_statementOptional0_0, struct iteration_statementOptional1 *iteration_statementOptional1_0) {
	struct iteration_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;
		result->choice2.literal_1 = literal_1;
		result->choice2.literal_2 = literal_2;
		result->choice2.literal_3 = literal_3;
		result->choice2.literal_4 = literal_4;
		result->choice2.iteration_statementOptional2_0 = iteration_statementOptional2_0;
		result->choice2.statement_0 = statement_0;
		result->choice2.iteration_statementOptional0_0 = iteration_statementOptional0_0;
		result->choice2.iteration_statementOptional1_0 = iteration_statementOptional1_0;

		result->tag = iteration_statementType_2;
	}

	return result;
}
void verbum_ast_delete_iteration_statement(struct VerbumContext *ctx, struct iteration_statement *iteration_statement) {
	switch(iteration_statement->tag) {
	case iteration_statementType_0:
		verbum_token_delete(ctx, &iteration_statement->choice0.literal_0);
		verbum_token_delete(ctx, &iteration_statement->choice0.literal_1);
		verbum_token_delete(ctx, &iteration_statement->choice0.literal_2);
		verbum_ast_delete_expression(ctx, iteration_statement->choice0.expression_0);
		verbum_ast_delete_statement(ctx, iteration_statement->choice0.statement_0);
	break;
	case iteration_statementType_1:
		verbum_token_delete(ctx, &iteration_statement->choice1.literal_0);
		verbum_token_delete(ctx, &iteration_statement->choice1.literal_1);
		verbum_token_delete(ctx, &iteration_statement->choice1.literal_2);
		verbum_token_delete(ctx, &iteration_statement->choice1.literal_3);
		verbum_token_delete(ctx, &iteration_statement->choice1.literal_4);
		verbum_ast_delete_expression(ctx, iteration_statement->choice1.expression_0);
		verbum_ast_delete_statement(ctx, iteration_statement->choice1.statement_0);
	break;
	case iteration_statementType_2:
		verbum_token_delete(ctx, &iteration_statement->choice2.literal_0);
		verbum_token_delete(ctx, &iteration_statement->choice2.literal_1);
		verbum_token_delete(ctx, &iteration_statement->choice2.literal_2);
		verbum_token_delete(ctx, &iteration_statement->choice2.literal_3);
		verbum_token_delete(ctx, &iteration_statement->choice2.literal_4);
		verbum_ast_delete_iteration_statementOptional2(ctx, iteration_statement->choice2.iteration_statementOptional2_0);
		verbum_ast_delete_statement(ctx, iteration_statement->choice2.statement_0);
		verbum_ast_delete_iteration_statementOptional0(ctx, iteration_statement->choice2.iteration_statementOptional0_0);
		verbum_ast_delete_iteration_statementOptional1(ctx, iteration_statement->choice2.iteration_statementOptional1_0);
	break;
	}
	ctx->memory.delete(iteration_statement);
}
struct jump_statement *verbum_ast_new_jump_statement_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token IDENTIFIER_0) {
	struct jump_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;
		result->choice0.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = jump_statementType_0;
	}

	return result;
}
struct jump_statement *verbum_ast_new_jump_statement_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1) {
	struct jump_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;

		result->tag = jump_statementType_1;
	}

	return result;
}
struct jump_statement *verbum_ast_new_jump_statement_choice2(struct VerbumContext *ctx, Token literal_0, Token literal_1) {
	struct jump_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;
		result->choice2.literal_1 = literal_1;

		result->tag = jump_statementType_2;
	}

	return result;
}
struct jump_statement *verbum_ast_new_jump_statement_choice3(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct jump_statementOptional0 *jump_statementOptional0_0) {
	struct jump_statement *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.literal_0 = literal_0;
		result->choice3.literal_1 = literal_1;
		result->choice3.jump_statementOptional0_0 = jump_statementOptional0_0;

		result->tag = jump_statementType_3;
	}

	return result;
}
void verbum_ast_delete_jump_statement(struct VerbumContext *ctx, struct jump_statement *jump_statement) {
	switch(jump_statement->tag) {
	case jump_statementType_0:
		verbum_token_delete(ctx, &jump_statement->choice0.literal_0);
		verbum_token_delete(ctx, &jump_statement->choice0.literal_1);
		verbum_token_delete(ctx, &jump_statement->choice0.IDENTIFIER_0);
	break;
	case jump_statementType_1:
		verbum_token_delete(ctx, &jump_statement->choice1.literal_0);
		verbum_token_delete(ctx, &jump_statement->choice1.literal_1);
	break;
	case jump_statementType_2:
		verbum_token_delete(ctx, &jump_statement->choice2.literal_0);
		verbum_token_delete(ctx, &jump_statement->choice2.literal_1);
	break;
	case jump_statementType_3:
		verbum_token_delete(ctx, &jump_statement->choice3.literal_0);
		verbum_token_delete(ctx, &jump_statement->choice3.literal_1);
		verbum_ast_delete_jump_statementOptional0(ctx, jump_statement->choice3.jump_statementOptional0_0);
	break;
	}
	ctx->memory.delete(jump_statement);
}
struct translation_unitRepetition0 *verbum_ast_new_translation_unitRepetition0_choice0(struct VerbumContext *ctx, struct translation_unitRepetition0 *translation_unitRepetition0_0, struct external_declaration *external_declaration_0) {
	struct translation_unitRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.translation_unitRepetition0_0 = translation_unitRepetition0_0;
		result->choice0.external_declaration_0 = external_declaration_0;

		result->tag = translation_unitRepetition0Type_0;
	}

	return result;
}
struct translation_unitRepetition0 *verbum_ast_new_translation_unitRepetition0_choice1(struct VerbumContext *ctx) {
	struct translation_unitRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = translation_unitRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_translation_unitRepetition0(struct VerbumContext *ctx, struct translation_unitRepetition0 *translation_unitRepetition0) {
	switch(translation_unitRepetition0->tag) {
	case translation_unitRepetition0Type_0:
		verbum_ast_delete_translation_unitRepetition0(ctx, translation_unitRepetition0->choice0.translation_unitRepetition0_0);
		verbum_ast_delete_external_declaration(ctx, translation_unitRepetition0->choice0.external_declaration_0);
	break;
	case translation_unitRepetition0Type_1:
	break;
	}
	ctx->memory.delete(translation_unitRepetition0);
}
struct function_definitionRepetition0 *verbum_ast_new_function_definitionRepetition0_choice0(struct VerbumContext *ctx, struct function_definitionRepetition0 *function_definitionRepetition0_0, struct declaration_specifier *declaration_specifier_0) {
	struct function_definitionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.function_definitionRepetition0_0 = function_definitionRepetition0_0;
		result->choice0.declaration_specifier_0 = declaration_specifier_0;

		result->tag = function_definitionRepetition0Type_0;
	}

	return result;
}
struct function_definitionRepetition0 *verbum_ast_new_function_definitionRepetition0_choice1(struct VerbumContext *ctx) {
	struct function_definitionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = function_definitionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_function_definitionRepetition0(struct VerbumContext *ctx, struct function_definitionRepetition0 *function_definitionRepetition0) {
	switch(function_definitionRepetition0->tag) {
	case function_definitionRepetition0Type_0:
		verbum_ast_delete_function_definitionRepetition0(ctx, function_definitionRepetition0->choice0.function_definitionRepetition0_0);
		verbum_ast_delete_declaration_specifier(ctx, function_definitionRepetition0->choice0.declaration_specifier_0);
	break;
	case function_definitionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(function_definitionRepetition0);
}
struct function_definitionRepetition1 *verbum_ast_new_function_definitionRepetition1_choice0(struct VerbumContext *ctx, struct declaration *declaration_0, struct function_definitionRepetition1 *function_definitionRepetition1_0) {
	struct function_definitionRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.declaration_0 = declaration_0;
		result->choice0.function_definitionRepetition1_0 = function_definitionRepetition1_0;

		result->tag = function_definitionRepetition1Type_0;
	}

	return result;
}
struct function_definitionRepetition1 *verbum_ast_new_function_definitionRepetition1_choice1(struct VerbumContext *ctx) {
	struct function_definitionRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = function_definitionRepetition1Type_1;
	}

	return result;
}
void verbum_ast_delete_function_definitionRepetition1(struct VerbumContext *ctx, struct function_definitionRepetition1 *function_definitionRepetition1) {
	switch(function_definitionRepetition1->tag) {
	case function_definitionRepetition1Type_0:
		verbum_ast_delete_declaration(ctx, function_definitionRepetition1->choice0.declaration_0);
		verbum_ast_delete_function_definitionRepetition1(ctx, function_definitionRepetition1->choice0.function_definitionRepetition1_0);
	break;
	case function_definitionRepetition1Type_1:
	break;
	}
	ctx->memory.delete(function_definitionRepetition1);
}
struct struct_or_union_specifierRepetition0 *verbum_ast_new_struct_or_union_specifierRepetition0_choice0(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition0 *struct_or_union_specifierRepetition0_0, struct struct_declaration *struct_declaration_0) {
	struct struct_or_union_specifierRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.struct_or_union_specifierRepetition0_0 = struct_or_union_specifierRepetition0_0;
		result->choice0.struct_declaration_0 = struct_declaration_0;

		result->tag = struct_or_union_specifierRepetition0Type_0;
	}

	return result;
}
struct struct_or_union_specifierRepetition0 *verbum_ast_new_struct_or_union_specifierRepetition0_choice1(struct VerbumContext *ctx) {
	struct struct_or_union_specifierRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = struct_or_union_specifierRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_struct_or_union_specifierRepetition0(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition0 *struct_or_union_specifierRepetition0) {
	switch(struct_or_union_specifierRepetition0->tag) {
	case struct_or_union_specifierRepetition0Type_0:
		verbum_ast_delete_struct_or_union_specifierRepetition0(ctx, struct_or_union_specifierRepetition0->choice0.struct_or_union_specifierRepetition0_0);
		verbum_ast_delete_struct_declaration(ctx, struct_or_union_specifierRepetition0->choice0.struct_declaration_0);
	break;
	case struct_or_union_specifierRepetition0Type_1:
	break;
	}
	ctx->memory.delete(struct_or_union_specifierRepetition0);
}
struct struct_or_union_specifierRepetition1 *verbum_ast_new_struct_or_union_specifierRepetition1_choice0(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition1 *struct_or_union_specifierRepetition1_0, struct struct_declaration *struct_declaration_0) {
	struct struct_or_union_specifierRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.struct_or_union_specifierRepetition1_0 = struct_or_union_specifierRepetition1_0;
		result->choice0.struct_declaration_0 = struct_declaration_0;

		result->tag = struct_or_union_specifierRepetition1Type_0;
	}

	return result;
}
struct struct_or_union_specifierRepetition1 *verbum_ast_new_struct_or_union_specifierRepetition1_choice1(struct VerbumContext *ctx) {
	struct struct_or_union_specifierRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = struct_or_union_specifierRepetition1Type_1;
	}

	return result;
}
void verbum_ast_delete_struct_or_union_specifierRepetition1(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition1 *struct_or_union_specifierRepetition1) {
	switch(struct_or_union_specifierRepetition1->tag) {
	case struct_or_union_specifierRepetition1Type_0:
		verbum_ast_delete_struct_or_union_specifierRepetition1(ctx, struct_or_union_specifierRepetition1->choice0.struct_or_union_specifierRepetition1_0);
		verbum_ast_delete_struct_declaration(ctx, struct_or_union_specifierRepetition1->choice0.struct_declaration_0);
	break;
	case struct_or_union_specifierRepetition1Type_1:
	break;
	}
	ctx->memory.delete(struct_or_union_specifierRepetition1);
}
struct struct_declarationRepetition0 *verbum_ast_new_struct_declarationRepetition0_choice0(struct VerbumContext *ctx, struct struct_declarationRepetition0 *struct_declarationRepetition0_0, struct specifier_qualifier *specifier_qualifier_0) {
	struct struct_declarationRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.struct_declarationRepetition0_0 = struct_declarationRepetition0_0;
		result->choice0.specifier_qualifier_0 = specifier_qualifier_0;

		result->tag = struct_declarationRepetition0Type_0;
	}

	return result;
}
struct struct_declarationRepetition0 *verbum_ast_new_struct_declarationRepetition0_choice1(struct VerbumContext *ctx) {
	struct struct_declarationRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = struct_declarationRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_struct_declarationRepetition0(struct VerbumContext *ctx, struct struct_declarationRepetition0 *struct_declarationRepetition0) {
	switch(struct_declarationRepetition0->tag) {
	case struct_declarationRepetition0Type_0:
		verbum_ast_delete_struct_declarationRepetition0(ctx, struct_declarationRepetition0->choice0.struct_declarationRepetition0_0);
		verbum_ast_delete_specifier_qualifier(ctx, struct_declarationRepetition0->choice0.specifier_qualifier_0);
	break;
	case struct_declarationRepetition0Type_1:
	break;
	}
	ctx->memory.delete(struct_declarationRepetition0);
}
struct struct_declarator_listRepetition0 *verbum_ast_new_struct_declarator_listRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct struct_declarator *struct_declarator_0, struct struct_declarator_listRepetition0 *struct_declarator_listRepetition0_0) {
	struct struct_declarator_listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.struct_declarator_0 = struct_declarator_0;
		result->choice0.struct_declarator_listRepetition0_0 = struct_declarator_listRepetition0_0;

		result->tag = struct_declarator_listRepetition0Type_0;
	}

	return result;
}
struct struct_declarator_listRepetition0 *verbum_ast_new_struct_declarator_listRepetition0_choice1(struct VerbumContext *ctx) {
	struct struct_declarator_listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = struct_declarator_listRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_struct_declarator_listRepetition0(struct VerbumContext *ctx, struct struct_declarator_listRepetition0 *struct_declarator_listRepetition0) {
	switch(struct_declarator_listRepetition0->tag) {
	case struct_declarator_listRepetition0Type_0:
		verbum_token_delete(ctx, &struct_declarator_listRepetition0->choice0.literal_0);
		verbum_ast_delete_struct_declarator(ctx, struct_declarator_listRepetition0->choice0.struct_declarator_0);
		verbum_ast_delete_struct_declarator_listRepetition0(ctx, struct_declarator_listRepetition0->choice0.struct_declarator_listRepetition0_0);
	break;
	case struct_declarator_listRepetition0Type_1:
	break;
	}
	ctx->memory.delete(struct_declarator_listRepetition0);
}
struct struct_declaratorOptional0 *verbum_ast_new_struct_declaratorOptional0_choice0(struct VerbumContext *ctx, struct declarator *declarator_0) {
	struct struct_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.declarator_0 = declarator_0;

		result->tag = struct_declaratorOptional0Type_0;
	}

	return result;
}
struct struct_declaratorOptional0 *verbum_ast_new_struct_declaratorOptional0_choice1(struct VerbumContext *ctx) {
	struct struct_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = struct_declaratorOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_struct_declaratorOptional0(struct VerbumContext *ctx, struct struct_declaratorOptional0 *struct_declaratorOptional0) {
	switch(struct_declaratorOptional0->tag) {
	case struct_declaratorOptional0Type_0:
		verbum_ast_delete_declarator(ctx, struct_declaratorOptional0->choice0.declarator_0);
	break;
	case struct_declaratorOptional0Type_1:
	break;
	}
	ctx->memory.delete(struct_declaratorOptional0);
}
struct declaratorOptional0 *verbum_ast_new_declaratorOptional0_choice0(struct VerbumContext *ctx, struct pointer *pointer_0) {
	struct declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.pointer_0 = pointer_0;

		result->tag = declaratorOptional0Type_0;
	}

	return result;
}
struct declaratorOptional0 *verbum_ast_new_declaratorOptional0_choice1(struct VerbumContext *ctx) {
	struct declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = declaratorOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_declaratorOptional0(struct VerbumContext *ctx, struct declaratorOptional0 *declaratorOptional0) {
	switch(declaratorOptional0->tag) {
	case declaratorOptional0Type_0:
		verbum_ast_delete_pointer(ctx, declaratorOptional0->choice0.pointer_0);
	break;
	case declaratorOptional0Type_1:
	break;
	}
	ctx->memory.delete(declaratorOptional0);
}
struct pointerRepetition0 *verbum_ast_new_pointerRepetition0_choice0(struct VerbumContext *ctx, struct type_qualifier *type_qualifier_0, struct pointerRepetition0 *pointerRepetition0_0) {
	struct pointerRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.type_qualifier_0 = type_qualifier_0;
		result->choice0.pointerRepetition0_0 = pointerRepetition0_0;

		result->tag = pointerRepetition0Type_0;
	}

	return result;
}
struct pointerRepetition0 *verbum_ast_new_pointerRepetition0_choice1(struct VerbumContext *ctx) {
	struct pointerRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = pointerRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_pointerRepetition0(struct VerbumContext *ctx, struct pointerRepetition0 *pointerRepetition0) {
	switch(pointerRepetition0->tag) {
	case pointerRepetition0Type_0:
		verbum_ast_delete_type_qualifier(ctx, pointerRepetition0->choice0.type_qualifier_0);
		verbum_ast_delete_pointerRepetition0(ctx, pointerRepetition0->choice0.pointerRepetition0_0);
	break;
	case pointerRepetition0Type_1:
	break;
	}
	ctx->memory.delete(pointerRepetition0);
}
struct pointerOptional0 *verbum_ast_new_pointerOptional0_choice0(struct VerbumContext *ctx, struct pointer *pointer_0) {
	struct pointerOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.pointer_0 = pointer_0;

		result->tag = pointerOptional0Type_0;
	}

	return result;
}
struct pointerOptional0 *verbum_ast_new_pointerOptional0_choice1(struct VerbumContext *ctx) {
	struct pointerOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = pointerOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_pointerOptional0(struct VerbumContext *ctx, struct pointerOptional0 *pointerOptional0) {
	switch(pointerOptional0->tag) {
	case pointerOptional0Type_0:
		verbum_ast_delete_pointer(ctx, pointerOptional0->choice0.pointer_0);
	break;
	case pointerOptional0Type_1:
	break;
	}
	ctx->memory.delete(pointerOptional0);
}
struct direct_declaratorGroup0 *verbum_ast_new_direct_declaratorGroup0_choice0(struct VerbumContext *ctx, Token IDENTIFIER_0) {
	struct direct_declaratorGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = direct_declaratorGroup0Type_0;
	}

	return result;
}
struct direct_declaratorGroup0 *verbum_ast_new_direct_declaratorGroup0_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct declarator *declarator_0) {
	struct direct_declaratorGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.declarator_0 = declarator_0;

		result->tag = direct_declaratorGroup0Type_1;
	}

	return result;
}
void verbum_ast_delete_direct_declaratorGroup0(struct VerbumContext *ctx, struct direct_declaratorGroup0 *direct_declaratorGroup0) {
	switch(direct_declaratorGroup0->tag) {
	case direct_declaratorGroup0Type_0:
		verbum_token_delete(ctx, &direct_declaratorGroup0->choice0.IDENTIFIER_0);
	break;
	case direct_declaratorGroup0Type_1:
		verbum_token_delete(ctx, &direct_declaratorGroup0->choice1.literal_0);
		verbum_token_delete(ctx, &direct_declaratorGroup0->choice1.literal_1);
		verbum_ast_delete_declarator(ctx, direct_declaratorGroup0->choice1.declarator_0);
	break;
	}
	ctx->memory.delete(direct_declaratorGroup0);
}
struct direct_declaratorOptional0 *verbum_ast_new_direct_declaratorOptional0_choice0(struct VerbumContext *ctx, struct constant_expression *constant_expression_0) {
	struct direct_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.constant_expression_0 = constant_expression_0;

		result->tag = direct_declaratorOptional0Type_0;
	}

	return result;
}
struct direct_declaratorOptional0 *verbum_ast_new_direct_declaratorOptional0_choice1(struct VerbumContext *ctx) {
	struct direct_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = direct_declaratorOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_direct_declaratorOptional0(struct VerbumContext *ctx, struct direct_declaratorOptional0 *direct_declaratorOptional0) {
	switch(direct_declaratorOptional0->tag) {
	case direct_declaratorOptional0Type_0:
		verbum_ast_delete_constant_expression(ctx, direct_declaratorOptional0->choice0.constant_expression_0);
	break;
	case direct_declaratorOptional0Type_1:
	break;
	}
	ctx->memory.delete(direct_declaratorOptional0);
}
struct direct_declaratorRepetition1 *verbum_ast_new_direct_declaratorRepetition1_choice0(struct VerbumContext *ctx, struct direct_declaratorRepetition1 *direct_declaratorRepetition1_0, Token IDENTIFIER_0) {
	struct direct_declaratorRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.direct_declaratorRepetition1_0 = direct_declaratorRepetition1_0;
		result->choice0.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = direct_declaratorRepetition1Type_0;
	}

	return result;
}
struct direct_declaratorRepetition1 *verbum_ast_new_direct_declaratorRepetition1_choice1(struct VerbumContext *ctx) {
	struct direct_declaratorRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = direct_declaratorRepetition1Type_1;
	}

	return result;
}
void verbum_ast_delete_direct_declaratorRepetition1(struct VerbumContext *ctx, struct direct_declaratorRepetition1 *direct_declaratorRepetition1) {
	switch(direct_declaratorRepetition1->tag) {
	case direct_declaratorRepetition1Type_0:
		verbum_ast_delete_direct_declaratorRepetition1(ctx, direct_declaratorRepetition1->choice0.direct_declaratorRepetition1_0);
		verbum_token_delete(ctx, &direct_declaratorRepetition1->choice0.IDENTIFIER_0);
	break;
	case direct_declaratorRepetition1Type_1:
	break;
	}
	ctx->memory.delete(direct_declaratorRepetition1);
}
struct direct_declaratorRepetition0 *verbum_ast_new_direct_declaratorRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct direct_declaratorOptional0 *direct_declaratorOptional0_0, struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0) {
	struct direct_declaratorRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;
		result->choice0.direct_declaratorOptional0_0 = direct_declaratorOptional0_0;
		result->choice0.direct_declaratorRepetition0_0 = direct_declaratorRepetition0_0;

		result->tag = direct_declaratorRepetition0Type_0;
	}

	return result;
}
struct direct_declaratorRepetition0 *verbum_ast_new_direct_declaratorRepetition0_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct parameter_type_list *parameter_type_list_0, struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0) {
	struct direct_declaratorRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.parameter_type_list_0 = parameter_type_list_0;
		result->choice1.direct_declaratorRepetition0_0 = direct_declaratorRepetition0_0;

		result->tag = direct_declaratorRepetition0Type_1;
	}

	return result;
}
struct direct_declaratorRepetition0 *verbum_ast_new_direct_declaratorRepetition0_choice2(struct VerbumContext *ctx, struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0, Token literal_0, Token literal_1, struct direct_declaratorRepetition1 *direct_declaratorRepetition1_0) {
	struct direct_declaratorRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.direct_declaratorRepetition0_0 = direct_declaratorRepetition0_0;
		result->choice2.literal_0 = literal_0;
		result->choice2.literal_1 = literal_1;
		result->choice2.direct_declaratorRepetition1_0 = direct_declaratorRepetition1_0;

		result->tag = direct_declaratorRepetition0Type_2;
	}

	return result;
}
struct direct_declaratorRepetition0 *verbum_ast_new_direct_declaratorRepetition0_choice3(struct VerbumContext *ctx) {
	struct direct_declaratorRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = direct_declaratorRepetition0Type_3;
	}

	return result;
}
void verbum_ast_delete_direct_declaratorRepetition0(struct VerbumContext *ctx, struct direct_declaratorRepetition0 *direct_declaratorRepetition0) {
	switch(direct_declaratorRepetition0->tag) {
	case direct_declaratorRepetition0Type_0:
		verbum_token_delete(ctx, &direct_declaratorRepetition0->choice0.literal_0);
		verbum_token_delete(ctx, &direct_declaratorRepetition0->choice0.literal_1);
		verbum_ast_delete_direct_declaratorOptional0(ctx, direct_declaratorRepetition0->choice0.direct_declaratorOptional0_0);
		verbum_ast_delete_direct_declaratorRepetition0(ctx, direct_declaratorRepetition0->choice0.direct_declaratorRepetition0_0);
	break;
	case direct_declaratorRepetition0Type_1:
		verbum_token_delete(ctx, &direct_declaratorRepetition0->choice1.literal_0);
		verbum_token_delete(ctx, &direct_declaratorRepetition0->choice1.literal_1);
		verbum_ast_delete_parameter_type_list(ctx, direct_declaratorRepetition0->choice1.parameter_type_list_0);
		verbum_ast_delete_direct_declaratorRepetition0(ctx, direct_declaratorRepetition0->choice1.direct_declaratorRepetition0_0);
	break;
	case direct_declaratorRepetition0Type_2:
		verbum_ast_delete_direct_declaratorRepetition0(ctx, direct_declaratorRepetition0->choice2.direct_declaratorRepetition0_0);
		verbum_token_delete(ctx, &direct_declaratorRepetition0->choice2.literal_0);
		verbum_token_delete(ctx, &direct_declaratorRepetition0->choice2.literal_1);
		verbum_ast_delete_direct_declaratorRepetition1(ctx, direct_declaratorRepetition0->choice2.direct_declaratorRepetition1_0);
	break;
	case direct_declaratorRepetition0Type_3:
	break;
	}
	ctx->memory.delete(direct_declaratorRepetition0);
}
struct conditional_expressionOptional0 *verbum_ast_new_conditional_expressionOptional0_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0, struct conditional_expression *conditional_expression_0) {
	struct conditional_expressionOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;
		result->choice0.expression_0 = expression_0;
		result->choice0.conditional_expression_0 = conditional_expression_0;

		result->tag = conditional_expressionOptional0Type_0;
	}

	return result;
}
struct conditional_expressionOptional0 *verbum_ast_new_conditional_expressionOptional0_choice1(struct VerbumContext *ctx) {
	struct conditional_expressionOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = conditional_expressionOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_conditional_expressionOptional0(struct VerbumContext *ctx, struct conditional_expressionOptional0 *conditional_expressionOptional0) {
	switch(conditional_expressionOptional0->tag) {
	case conditional_expressionOptional0Type_0:
		verbum_token_delete(ctx, &conditional_expressionOptional0->choice0.literal_0);
		verbum_token_delete(ctx, &conditional_expressionOptional0->choice0.literal_1);
		verbum_ast_delete_expression(ctx, conditional_expressionOptional0->choice0.expression_0);
		verbum_ast_delete_conditional_expression(ctx, conditional_expressionOptional0->choice0.conditional_expression_0);
	break;
	case conditional_expressionOptional0Type_1:
	break;
	}
	ctx->memory.delete(conditional_expressionOptional0);
}
struct logical_or_expressionRepetition0 *verbum_ast_new_logical_or_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct logical_and_expression *logical_and_expression_0, struct logical_or_expressionRepetition0 *logical_or_expressionRepetition0_0) {
	struct logical_or_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.logical_and_expression_0 = logical_and_expression_0;
		result->choice0.logical_or_expressionRepetition0_0 = logical_or_expressionRepetition0_0;

		result->tag = logical_or_expressionRepetition0Type_0;
	}

	return result;
}
struct logical_or_expressionRepetition0 *verbum_ast_new_logical_or_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct logical_or_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = logical_or_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_logical_or_expressionRepetition0(struct VerbumContext *ctx, struct logical_or_expressionRepetition0 *logical_or_expressionRepetition0) {
	switch(logical_or_expressionRepetition0->tag) {
	case logical_or_expressionRepetition0Type_0:
		verbum_token_delete(ctx, &logical_or_expressionRepetition0->choice0.literal_0);
		verbum_ast_delete_logical_and_expression(ctx, logical_or_expressionRepetition0->choice0.logical_and_expression_0);
		verbum_ast_delete_logical_or_expressionRepetition0(ctx, logical_or_expressionRepetition0->choice0.logical_or_expressionRepetition0_0);
	break;
	case logical_or_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(logical_or_expressionRepetition0);
}
struct logical_and_expressionRepetition0 *verbum_ast_new_logical_and_expressionRepetition0_choice0(struct VerbumContext *ctx, struct logical_and_expressionRepetition0 *logical_and_expressionRepetition0_0, Token literal_0, struct inclusive_or_expression *inclusive_or_expression_0) {
	struct logical_and_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.logical_and_expressionRepetition0_0 = logical_and_expressionRepetition0_0;
		result->choice0.literal_0 = literal_0;
		result->choice0.inclusive_or_expression_0 = inclusive_or_expression_0;

		result->tag = logical_and_expressionRepetition0Type_0;
	}

	return result;
}
struct logical_and_expressionRepetition0 *verbum_ast_new_logical_and_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct logical_and_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = logical_and_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_logical_and_expressionRepetition0(struct VerbumContext *ctx, struct logical_and_expressionRepetition0 *logical_and_expressionRepetition0) {
	switch(logical_and_expressionRepetition0->tag) {
	case logical_and_expressionRepetition0Type_0:
		verbum_ast_delete_logical_and_expressionRepetition0(ctx, logical_and_expressionRepetition0->choice0.logical_and_expressionRepetition0_0);
		verbum_token_delete(ctx, &logical_and_expressionRepetition0->choice0.literal_0);
		verbum_ast_delete_inclusive_or_expression(ctx, logical_and_expressionRepetition0->choice0.inclusive_or_expression_0);
	break;
	case logical_and_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(logical_and_expressionRepetition0);
}
struct inclusive_or_expressionRepetition0 *verbum_ast_new_inclusive_or_expressionRepetition0_choice0(struct VerbumContext *ctx, struct inclusive_or_expressionRepetition0 *inclusive_or_expressionRepetition0_0, Token literal_0, struct exclusive_or_expression *exclusive_or_expression_0) {
	struct inclusive_or_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.inclusive_or_expressionRepetition0_0 = inclusive_or_expressionRepetition0_0;
		result->choice0.literal_0 = literal_0;
		result->choice0.exclusive_or_expression_0 = exclusive_or_expression_0;

		result->tag = inclusive_or_expressionRepetition0Type_0;
	}

	return result;
}
struct inclusive_or_expressionRepetition0 *verbum_ast_new_inclusive_or_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct inclusive_or_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = inclusive_or_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_inclusive_or_expressionRepetition0(struct VerbumContext *ctx, struct inclusive_or_expressionRepetition0 *inclusive_or_expressionRepetition0) {
	switch(inclusive_or_expressionRepetition0->tag) {
	case inclusive_or_expressionRepetition0Type_0:
		verbum_ast_delete_inclusive_or_expressionRepetition0(ctx, inclusive_or_expressionRepetition0->choice0.inclusive_or_expressionRepetition0_0);
		verbum_token_delete(ctx, &inclusive_or_expressionRepetition0->choice0.literal_0);
		verbum_ast_delete_exclusive_or_expression(ctx, inclusive_or_expressionRepetition0->choice0.exclusive_or_expression_0);
	break;
	case inclusive_or_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(inclusive_or_expressionRepetition0);
}
struct exclusive_or_expressionRepetition0 *verbum_ast_new_exclusive_or_expressionRepetition0_choice0(struct VerbumContext *ctx, struct exclusive_or_expressionRepetition0 *exclusive_or_expressionRepetition0_0, Token literal_0, struct and_expression *and_expression_0) {
	struct exclusive_or_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.exclusive_or_expressionRepetition0_0 = exclusive_or_expressionRepetition0_0;
		result->choice0.literal_0 = literal_0;
		result->choice0.and_expression_0 = and_expression_0;

		result->tag = exclusive_or_expressionRepetition0Type_0;
	}

	return result;
}
struct exclusive_or_expressionRepetition0 *verbum_ast_new_exclusive_or_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct exclusive_or_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = exclusive_or_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_exclusive_or_expressionRepetition0(struct VerbumContext *ctx, struct exclusive_or_expressionRepetition0 *exclusive_or_expressionRepetition0) {
	switch(exclusive_or_expressionRepetition0->tag) {
	case exclusive_or_expressionRepetition0Type_0:
		verbum_ast_delete_exclusive_or_expressionRepetition0(ctx, exclusive_or_expressionRepetition0->choice0.exclusive_or_expressionRepetition0_0);
		verbum_token_delete(ctx, &exclusive_or_expressionRepetition0->choice0.literal_0);
		verbum_ast_delete_and_expression(ctx, exclusive_or_expressionRepetition0->choice0.and_expression_0);
	break;
	case exclusive_or_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(exclusive_or_expressionRepetition0);
}
struct and_expressionRepetition0 *verbum_ast_new_and_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct and_expressionRepetition0 *and_expressionRepetition0_0, struct equality_expression *equality_expression_0) {
	struct and_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.and_expressionRepetition0_0 = and_expressionRepetition0_0;
		result->choice0.equality_expression_0 = equality_expression_0;

		result->tag = and_expressionRepetition0Type_0;
	}

	return result;
}
struct and_expressionRepetition0 *verbum_ast_new_and_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct and_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = and_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_and_expressionRepetition0(struct VerbumContext *ctx, struct and_expressionRepetition0 *and_expressionRepetition0) {
	switch(and_expressionRepetition0->tag) {
	case and_expressionRepetition0Type_0:
		verbum_token_delete(ctx, &and_expressionRepetition0->choice0.literal_0);
		verbum_ast_delete_and_expressionRepetition0(ctx, and_expressionRepetition0->choice0.and_expressionRepetition0_0);
		verbum_ast_delete_equality_expression(ctx, and_expressionRepetition0->choice0.equality_expression_0);
	break;
	case and_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(and_expressionRepetition0);
}
struct equality_expressionGroup0 *verbum_ast_new_equality_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct equality_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = equality_expressionGroup0Type_0;
	}

	return result;
}
struct equality_expressionGroup0 *verbum_ast_new_equality_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct equality_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = equality_expressionGroup0Type_1;
	}

	return result;
}
void verbum_ast_delete_equality_expressionGroup0(struct VerbumContext *ctx, struct equality_expressionGroup0 *equality_expressionGroup0) {
	switch(equality_expressionGroup0->tag) {
	case equality_expressionGroup0Type_0:
		verbum_token_delete(ctx, &equality_expressionGroup0->choice0.literal_0);
	break;
	case equality_expressionGroup0Type_1:
		verbum_token_delete(ctx, &equality_expressionGroup0->choice1.literal_0);
	break;
	}
	ctx->memory.delete(equality_expressionGroup0);
}
struct equality_expressionRepetition0 *verbum_ast_new_equality_expressionRepetition0_choice0(struct VerbumContext *ctx, struct relational_expression *relational_expression_0, struct equality_expressionGroup0 *equality_expressionGroup0_0, struct equality_expressionRepetition0 *equality_expressionRepetition0_0) {
	struct equality_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.relational_expression_0 = relational_expression_0;
		result->choice0.equality_expressionGroup0_0 = equality_expressionGroup0_0;
		result->choice0.equality_expressionRepetition0_0 = equality_expressionRepetition0_0;

		result->tag = equality_expressionRepetition0Type_0;
	}

	return result;
}
struct equality_expressionRepetition0 *verbum_ast_new_equality_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct equality_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = equality_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_equality_expressionRepetition0(struct VerbumContext *ctx, struct equality_expressionRepetition0 *equality_expressionRepetition0) {
	switch(equality_expressionRepetition0->tag) {
	case equality_expressionRepetition0Type_0:
		verbum_ast_delete_relational_expression(ctx, equality_expressionRepetition0->choice0.relational_expression_0);
		verbum_ast_delete_equality_expressionGroup0(ctx, equality_expressionRepetition0->choice0.equality_expressionGroup0_0);
		verbum_ast_delete_equality_expressionRepetition0(ctx, equality_expressionRepetition0->choice0.equality_expressionRepetition0_0);
	break;
	case equality_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(equality_expressionRepetition0);
}
struct relational_expressionGroup0 *verbum_ast_new_relational_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct relational_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = relational_expressionGroup0Type_0;
	}

	return result;
}
struct relational_expressionGroup0 *verbum_ast_new_relational_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct relational_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = relational_expressionGroup0Type_1;
	}

	return result;
}
struct relational_expressionGroup0 *verbum_ast_new_relational_expressionGroup0_choice2(struct VerbumContext *ctx, Token literal_0) {
	struct relational_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;

		result->tag = relational_expressionGroup0Type_2;
	}

	return result;
}
struct relational_expressionGroup0 *verbum_ast_new_relational_expressionGroup0_choice3(struct VerbumContext *ctx, Token literal_0) {
	struct relational_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.literal_0 = literal_0;

		result->tag = relational_expressionGroup0Type_3;
	}

	return result;
}
void verbum_ast_delete_relational_expressionGroup0(struct VerbumContext *ctx, struct relational_expressionGroup0 *relational_expressionGroup0) {
	switch(relational_expressionGroup0->tag) {
	case relational_expressionGroup0Type_0:
		verbum_token_delete(ctx, &relational_expressionGroup0->choice0.literal_0);
	break;
	case relational_expressionGroup0Type_1:
		verbum_token_delete(ctx, &relational_expressionGroup0->choice1.literal_0);
	break;
	case relational_expressionGroup0Type_2:
		verbum_token_delete(ctx, &relational_expressionGroup0->choice2.literal_0);
	break;
	case relational_expressionGroup0Type_3:
		verbum_token_delete(ctx, &relational_expressionGroup0->choice3.literal_0);
	break;
	}
	ctx->memory.delete(relational_expressionGroup0);
}
struct relational_expressionRepetition0 *verbum_ast_new_relational_expressionRepetition0_choice0(struct VerbumContext *ctx, struct shift_expression *shift_expression_0, struct relational_expressionGroup0 *relational_expressionGroup0_0, struct relational_expressionRepetition0 *relational_expressionRepetition0_0) {
	struct relational_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.shift_expression_0 = shift_expression_0;
		result->choice0.relational_expressionGroup0_0 = relational_expressionGroup0_0;
		result->choice0.relational_expressionRepetition0_0 = relational_expressionRepetition0_0;

		result->tag = relational_expressionRepetition0Type_0;
	}

	return result;
}
struct relational_expressionRepetition0 *verbum_ast_new_relational_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct relational_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = relational_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_relational_expressionRepetition0(struct VerbumContext *ctx, struct relational_expressionRepetition0 *relational_expressionRepetition0) {
	switch(relational_expressionRepetition0->tag) {
	case relational_expressionRepetition0Type_0:
		verbum_ast_delete_shift_expression(ctx, relational_expressionRepetition0->choice0.shift_expression_0);
		verbum_ast_delete_relational_expressionGroup0(ctx, relational_expressionRepetition0->choice0.relational_expressionGroup0_0);
		verbum_ast_delete_relational_expressionRepetition0(ctx, relational_expressionRepetition0->choice0.relational_expressionRepetition0_0);
	break;
	case relational_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(relational_expressionRepetition0);
}
struct shift_expressionGroup0 *verbum_ast_new_shift_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct shift_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = shift_expressionGroup0Type_0;
	}

	return result;
}
struct shift_expressionGroup0 *verbum_ast_new_shift_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct shift_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = shift_expressionGroup0Type_1;
	}

	return result;
}
void verbum_ast_delete_shift_expressionGroup0(struct VerbumContext *ctx, struct shift_expressionGroup0 *shift_expressionGroup0) {
	switch(shift_expressionGroup0->tag) {
	case shift_expressionGroup0Type_0:
		verbum_token_delete(ctx, &shift_expressionGroup0->choice0.literal_0);
	break;
	case shift_expressionGroup0Type_1:
		verbum_token_delete(ctx, &shift_expressionGroup0->choice1.literal_0);
	break;
	}
	ctx->memory.delete(shift_expressionGroup0);
}
struct shift_expressionRepetition0 *verbum_ast_new_shift_expressionRepetition0_choice0(struct VerbumContext *ctx, struct shift_expressionRepetition0 *shift_expressionRepetition0_0, struct shift_expressionGroup0 *shift_expressionGroup0_0, struct additive_expression *additive_expression_0) {
	struct shift_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.shift_expressionRepetition0_0 = shift_expressionRepetition0_0;
		result->choice0.shift_expressionGroup0_0 = shift_expressionGroup0_0;
		result->choice0.additive_expression_0 = additive_expression_0;

		result->tag = shift_expressionRepetition0Type_0;
	}

	return result;
}
struct shift_expressionRepetition0 *verbum_ast_new_shift_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct shift_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = shift_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_shift_expressionRepetition0(struct VerbumContext *ctx, struct shift_expressionRepetition0 *shift_expressionRepetition0) {
	switch(shift_expressionRepetition0->tag) {
	case shift_expressionRepetition0Type_0:
		verbum_ast_delete_shift_expressionRepetition0(ctx, shift_expressionRepetition0->choice0.shift_expressionRepetition0_0);
		verbum_ast_delete_shift_expressionGroup0(ctx, shift_expressionRepetition0->choice0.shift_expressionGroup0_0);
		verbum_ast_delete_additive_expression(ctx, shift_expressionRepetition0->choice0.additive_expression_0);
	break;
	case shift_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(shift_expressionRepetition0);
}
struct additive_expressionGroup0 *verbum_ast_new_additive_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct additive_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = additive_expressionGroup0Type_0;
	}

	return result;
}
struct additive_expressionGroup0 *verbum_ast_new_additive_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct additive_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = additive_expressionGroup0Type_1;
	}

	return result;
}
void verbum_ast_delete_additive_expressionGroup0(struct VerbumContext *ctx, struct additive_expressionGroup0 *additive_expressionGroup0) {
	switch(additive_expressionGroup0->tag) {
	case additive_expressionGroup0Type_0:
		verbum_token_delete(ctx, &additive_expressionGroup0->choice0.literal_0);
	break;
	case additive_expressionGroup0Type_1:
		verbum_token_delete(ctx, &additive_expressionGroup0->choice1.literal_0);
	break;
	}
	ctx->memory.delete(additive_expressionGroup0);
}
struct additive_expressionRepetition0 *verbum_ast_new_additive_expressionRepetition0_choice0(struct VerbumContext *ctx, struct additive_expressionRepetition0 *additive_expressionRepetition0_0, struct additive_expressionGroup0 *additive_expressionGroup0_0, struct multiplicative_expression *multiplicative_expression_0) {
	struct additive_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.additive_expressionRepetition0_0 = additive_expressionRepetition0_0;
		result->choice0.additive_expressionGroup0_0 = additive_expressionGroup0_0;
		result->choice0.multiplicative_expression_0 = multiplicative_expression_0;

		result->tag = additive_expressionRepetition0Type_0;
	}

	return result;
}
struct additive_expressionRepetition0 *verbum_ast_new_additive_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct additive_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = additive_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_additive_expressionRepetition0(struct VerbumContext *ctx, struct additive_expressionRepetition0 *additive_expressionRepetition0) {
	switch(additive_expressionRepetition0->tag) {
	case additive_expressionRepetition0Type_0:
		verbum_ast_delete_additive_expressionRepetition0(ctx, additive_expressionRepetition0->choice0.additive_expressionRepetition0_0);
		verbum_ast_delete_additive_expressionGroup0(ctx, additive_expressionRepetition0->choice0.additive_expressionGroup0_0);
		verbum_ast_delete_multiplicative_expression(ctx, additive_expressionRepetition0->choice0.multiplicative_expression_0);
	break;
	case additive_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(additive_expressionRepetition0);
}
struct multiplicative_expressionGroup0 *verbum_ast_new_multiplicative_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct multiplicative_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = multiplicative_expressionGroup0Type_0;
	}

	return result;
}
struct multiplicative_expressionGroup0 *verbum_ast_new_multiplicative_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0) {
	struct multiplicative_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;

		result->tag = multiplicative_expressionGroup0Type_1;
	}

	return result;
}
struct multiplicative_expressionGroup0 *verbum_ast_new_multiplicative_expressionGroup0_choice2(struct VerbumContext *ctx, Token literal_0) {
	struct multiplicative_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;

		result->tag = multiplicative_expressionGroup0Type_2;
	}

	return result;
}
void verbum_ast_delete_multiplicative_expressionGroup0(struct VerbumContext *ctx, struct multiplicative_expressionGroup0 *multiplicative_expressionGroup0) {
	switch(multiplicative_expressionGroup0->tag) {
	case multiplicative_expressionGroup0Type_0:
		verbum_token_delete(ctx, &multiplicative_expressionGroup0->choice0.literal_0);
	break;
	case multiplicative_expressionGroup0Type_1:
		verbum_token_delete(ctx, &multiplicative_expressionGroup0->choice1.literal_0);
	break;
	case multiplicative_expressionGroup0Type_2:
		verbum_token_delete(ctx, &multiplicative_expressionGroup0->choice2.literal_0);
	break;
	}
	ctx->memory.delete(multiplicative_expressionGroup0);
}
struct multiplicative_expressionRepetition0 *verbum_ast_new_multiplicative_expressionRepetition0_choice0(struct VerbumContext *ctx, struct multiplicative_expressionGroup0 *multiplicative_expressionGroup0_0, struct cast_expression *cast_expression_0, struct multiplicative_expressionRepetition0 *multiplicative_expressionRepetition0_0) {
	struct multiplicative_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.multiplicative_expressionGroup0_0 = multiplicative_expressionGroup0_0;
		result->choice0.cast_expression_0 = cast_expression_0;
		result->choice0.multiplicative_expressionRepetition0_0 = multiplicative_expressionRepetition0_0;

		result->tag = multiplicative_expressionRepetition0Type_0;
	}

	return result;
}
struct multiplicative_expressionRepetition0 *verbum_ast_new_multiplicative_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct multiplicative_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = multiplicative_expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_multiplicative_expressionRepetition0(struct VerbumContext *ctx, struct multiplicative_expressionRepetition0 *multiplicative_expressionRepetition0) {
	switch(multiplicative_expressionRepetition0->tag) {
	case multiplicative_expressionRepetition0Type_0:
		verbum_ast_delete_multiplicative_expressionGroup0(ctx, multiplicative_expressionRepetition0->choice0.multiplicative_expressionGroup0_0);
		verbum_ast_delete_cast_expression(ctx, multiplicative_expressionRepetition0->choice0.cast_expression_0);
		verbum_ast_delete_multiplicative_expressionRepetition0(ctx, multiplicative_expressionRepetition0->choice0.multiplicative_expressionRepetition0_0);
	break;
	case multiplicative_expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(multiplicative_expressionRepetition0);
}
struct unary_expressionGroup0 *verbum_ast_new_unary_expressionGroup0_choice0(struct VerbumContext *ctx, struct unary_expression *unary_expression_0) {
	struct unary_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.unary_expression_0 = unary_expression_0;

		result->tag = unary_expressionGroup0Type_0;
	}

	return result;
}
struct unary_expressionGroup0 *verbum_ast_new_unary_expressionGroup0_choice1(struct VerbumContext *ctx, struct type_name *type_name_0) {
	struct unary_expressionGroup0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.type_name_0 = type_name_0;

		result->tag = unary_expressionGroup0Type_1;
	}

	return result;
}
void verbum_ast_delete_unary_expressionGroup0(struct VerbumContext *ctx, struct unary_expressionGroup0 *unary_expressionGroup0) {
	switch(unary_expressionGroup0->tag) {
	case unary_expressionGroup0Type_0:
		verbum_ast_delete_unary_expression(ctx, unary_expressionGroup0->choice0.unary_expression_0);
	break;
	case unary_expressionGroup0Type_1:
		verbum_ast_delete_type_name(ctx, unary_expressionGroup0->choice1.type_name_0);
	break;
	}
	ctx->memory.delete(unary_expressionGroup0);
}
struct postfix_expressionRepetition1 *verbum_ast_new_postfix_expressionRepetition1_choice0(struct VerbumContext *ctx, struct assignment_expression *assignment_expression_0, struct postfix_expressionRepetition1 *postfix_expressionRepetition1_0) {
	struct postfix_expressionRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.assignment_expression_0 = assignment_expression_0;
		result->choice0.postfix_expressionRepetition1_0 = postfix_expressionRepetition1_0;

		result->tag = postfix_expressionRepetition1Type_0;
	}

	return result;
}
struct postfix_expressionRepetition1 *verbum_ast_new_postfix_expressionRepetition1_choice1(struct VerbumContext *ctx) {
	struct postfix_expressionRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = postfix_expressionRepetition1Type_1;
	}

	return result;
}
void verbum_ast_delete_postfix_expressionRepetition1(struct VerbumContext *ctx, struct postfix_expressionRepetition1 *postfix_expressionRepetition1) {
	switch(postfix_expressionRepetition1->tag) {
	case postfix_expressionRepetition1Type_0:
		verbum_ast_delete_assignment_expression(ctx, postfix_expressionRepetition1->choice0.assignment_expression_0);
		verbum_ast_delete_postfix_expressionRepetition1(ctx, postfix_expressionRepetition1->choice0.postfix_expressionRepetition1_0);
	break;
	case postfix_expressionRepetition1Type_1:
	break;
	}
	ctx->memory.delete(postfix_expressionRepetition1);
}
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0) {
	struct postfix_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;
		result->choice0.expression_0 = expression_0;
		result->choice0.postfix_expressionRepetition0_0 = postfix_expressionRepetition0_0;

		result->tag = postfix_expressionRepetition0Type_0;
	}

	return result;
}
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0, struct postfix_expressionRepetition1 *postfix_expressionRepetition1_0) {
	struct postfix_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.literal_0 = literal_0;
		result->choice1.literal_1 = literal_1;
		result->choice1.postfix_expressionRepetition0_0 = postfix_expressionRepetition0_0;
		result->choice1.postfix_expressionRepetition1_0 = postfix_expressionRepetition1_0;

		result->tag = postfix_expressionRepetition0Type_1;
	}

	return result;
}
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice2(struct VerbumContext *ctx, Token literal_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0, Token IDENTIFIER_0) {
	struct postfix_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice2.literal_0 = literal_0;
		result->choice2.postfix_expressionRepetition0_0 = postfix_expressionRepetition0_0;
		result->choice2.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = postfix_expressionRepetition0Type_2;
	}

	return result;
}
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice3(struct VerbumContext *ctx, Token literal_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0, Token IDENTIFIER_0) {
	struct postfix_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice3.literal_0 = literal_0;
		result->choice3.postfix_expressionRepetition0_0 = postfix_expressionRepetition0_0;
		result->choice3.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = postfix_expressionRepetition0Type_3;
	}

	return result;
}
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice4(struct VerbumContext *ctx, Token literal_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0) {
	struct postfix_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice4.literal_0 = literal_0;
		result->choice4.postfix_expressionRepetition0_0 = postfix_expressionRepetition0_0;

		result->tag = postfix_expressionRepetition0Type_4;
	}

	return result;
}
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice5(struct VerbumContext *ctx, Token literal_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0) {
	struct postfix_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice5.literal_0 = literal_0;
		result->choice5.postfix_expressionRepetition0_0 = postfix_expressionRepetition0_0;

		result->tag = postfix_expressionRepetition0Type_5;
	}

	return result;
}
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice6(struct VerbumContext *ctx) {
	struct postfix_expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = postfix_expressionRepetition0Type_6;
	}

	return result;
}
void verbum_ast_delete_postfix_expressionRepetition0(struct VerbumContext *ctx, struct postfix_expressionRepetition0 *postfix_expressionRepetition0) {
	switch(postfix_expressionRepetition0->tag) {
	case postfix_expressionRepetition0Type_0:
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice0.literal_0);
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice0.literal_1);
		verbum_ast_delete_expression(ctx, postfix_expressionRepetition0->choice0.expression_0);
		verbum_ast_delete_postfix_expressionRepetition0(ctx, postfix_expressionRepetition0->choice0.postfix_expressionRepetition0_0);
	break;
	case postfix_expressionRepetition0Type_1:
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice1.literal_0);
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice1.literal_1);
		verbum_ast_delete_postfix_expressionRepetition0(ctx, postfix_expressionRepetition0->choice1.postfix_expressionRepetition0_0);
		verbum_ast_delete_postfix_expressionRepetition1(ctx, postfix_expressionRepetition0->choice1.postfix_expressionRepetition1_0);
	break;
	case postfix_expressionRepetition0Type_2:
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice2.literal_0);
		verbum_ast_delete_postfix_expressionRepetition0(ctx, postfix_expressionRepetition0->choice2.postfix_expressionRepetition0_0);
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice2.IDENTIFIER_0);
	break;
	case postfix_expressionRepetition0Type_3:
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice3.literal_0);
		verbum_ast_delete_postfix_expressionRepetition0(ctx, postfix_expressionRepetition0->choice3.postfix_expressionRepetition0_0);
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice3.IDENTIFIER_0);
	break;
	case postfix_expressionRepetition0Type_4:
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice4.literal_0);
		verbum_ast_delete_postfix_expressionRepetition0(ctx, postfix_expressionRepetition0->choice4.postfix_expressionRepetition0_0);
	break;
	case postfix_expressionRepetition0Type_5:
		verbum_token_delete(ctx, &postfix_expressionRepetition0->choice5.literal_0);
		verbum_ast_delete_postfix_expressionRepetition0(ctx, postfix_expressionRepetition0->choice5.postfix_expressionRepetition0_0);
	break;
	case postfix_expressionRepetition0Type_6:
	break;
	}
	ctx->memory.delete(postfix_expressionRepetition0);
}
struct expressionRepetition0 *verbum_ast_new_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct assignment_expression *assignment_expression_0, struct expressionRepetition0 *expressionRepetition0_0) {
	struct expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.assignment_expression_0 = assignment_expression_0;
		result->choice0.expressionRepetition0_0 = expressionRepetition0_0;

		result->tag = expressionRepetition0Type_0;
	}

	return result;
}
struct expressionRepetition0 *verbum_ast_new_expressionRepetition0_choice1(struct VerbumContext *ctx) {
	struct expressionRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = expressionRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_expressionRepetition0(struct VerbumContext *ctx, struct expressionRepetition0 *expressionRepetition0) {
	switch(expressionRepetition0->tag) {
	case expressionRepetition0Type_0:
		verbum_token_delete(ctx, &expressionRepetition0->choice0.literal_0);
		verbum_ast_delete_assignment_expression(ctx, expressionRepetition0->choice0.assignment_expression_0);
		verbum_ast_delete_expressionRepetition0(ctx, expressionRepetition0->choice0.expressionRepetition0_0);
	break;
	case expressionRepetition0Type_1:
	break;
	}
	ctx->memory.delete(expressionRepetition0);
}
struct type_nameRepetition0 *verbum_ast_new_type_nameRepetition0_choice0(struct VerbumContext *ctx, struct type_nameRepetition0 *type_nameRepetition0_0, struct specifier_qualifier *specifier_qualifier_0) {
	struct type_nameRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.type_nameRepetition0_0 = type_nameRepetition0_0;
		result->choice0.specifier_qualifier_0 = specifier_qualifier_0;

		result->tag = type_nameRepetition0Type_0;
	}

	return result;
}
struct type_nameRepetition0 *verbum_ast_new_type_nameRepetition0_choice1(struct VerbumContext *ctx) {
	struct type_nameRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = type_nameRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_type_nameRepetition0(struct VerbumContext *ctx, struct type_nameRepetition0 *type_nameRepetition0) {
	switch(type_nameRepetition0->tag) {
	case type_nameRepetition0Type_0:
		verbum_ast_delete_type_nameRepetition0(ctx, type_nameRepetition0->choice0.type_nameRepetition0_0);
		verbum_ast_delete_specifier_qualifier(ctx, type_nameRepetition0->choice0.specifier_qualifier_0);
	break;
	case type_nameRepetition0Type_1:
	break;
	}
	ctx->memory.delete(type_nameRepetition0);
}
struct type_nameOptional0 *verbum_ast_new_type_nameOptional0_choice0(struct VerbumContext *ctx, struct abstract_declarator *abstract_declarator_0) {
	struct type_nameOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.abstract_declarator_0 = abstract_declarator_0;

		result->tag = type_nameOptional0Type_0;
	}

	return result;
}
struct type_nameOptional0 *verbum_ast_new_type_nameOptional0_choice1(struct VerbumContext *ctx) {
	struct type_nameOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = type_nameOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_type_nameOptional0(struct VerbumContext *ctx, struct type_nameOptional0 *type_nameOptional0) {
	switch(type_nameOptional0->tag) {
	case type_nameOptional0Type_0:
		verbum_ast_delete_abstract_declarator(ctx, type_nameOptional0->choice0.abstract_declarator_0);
	break;
	case type_nameOptional0Type_1:
	break;
	}
	ctx->memory.delete(type_nameOptional0);
}
struct parameter_type_listOptional0 *verbum_ast_new_parameter_type_listOptional0_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1) {
	struct parameter_type_listOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.literal_1 = literal_1;

		result->tag = parameter_type_listOptional0Type_0;
	}

	return result;
}
struct parameter_type_listOptional0 *verbum_ast_new_parameter_type_listOptional0_choice1(struct VerbumContext *ctx) {
	struct parameter_type_listOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = parameter_type_listOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_parameter_type_listOptional0(struct VerbumContext *ctx, struct parameter_type_listOptional0 *parameter_type_listOptional0) {
	switch(parameter_type_listOptional0->tag) {
	case parameter_type_listOptional0Type_0:
		verbum_token_delete(ctx, &parameter_type_listOptional0->choice0.literal_0);
		verbum_token_delete(ctx, &parameter_type_listOptional0->choice0.literal_1);
	break;
	case parameter_type_listOptional0Type_1:
	break;
	}
	ctx->memory.delete(parameter_type_listOptional0);
}
struct parameter_listRepetition0 *verbum_ast_new_parameter_listRepetition0_choice0(struct VerbumContext *ctx, struct parameter_listRepetition0 *parameter_listRepetition0_0, struct parameter_declaration *parameter_declaration_0, Token literal_0) {
	struct parameter_listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.parameter_listRepetition0_0 = parameter_listRepetition0_0;
		result->choice0.parameter_declaration_0 = parameter_declaration_0;
		result->choice0.literal_0 = literal_0;

		result->tag = parameter_listRepetition0Type_0;
	}

	return result;
}
struct parameter_listRepetition0 *verbum_ast_new_parameter_listRepetition0_choice1(struct VerbumContext *ctx) {
	struct parameter_listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = parameter_listRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_parameter_listRepetition0(struct VerbumContext *ctx, struct parameter_listRepetition0 *parameter_listRepetition0) {
	switch(parameter_listRepetition0->tag) {
	case parameter_listRepetition0Type_0:
		verbum_ast_delete_parameter_listRepetition0(ctx, parameter_listRepetition0->choice0.parameter_listRepetition0_0);
		verbum_ast_delete_parameter_declaration(ctx, parameter_listRepetition0->choice0.parameter_declaration_0);
		verbum_token_delete(ctx, &parameter_listRepetition0->choice0.literal_0);
	break;
	case parameter_listRepetition0Type_1:
	break;
	}
	ctx->memory.delete(parameter_listRepetition0);
}
struct parameter_declarationRepetition0 *verbum_ast_new_parameter_declarationRepetition0_choice0(struct VerbumContext *ctx, struct parameter_declarationRepetition0 *parameter_declarationRepetition0_0, struct declaration_specifier *declaration_specifier_0) {
	struct parameter_declarationRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.parameter_declarationRepetition0_0 = parameter_declarationRepetition0_0;
		result->choice0.declaration_specifier_0 = declaration_specifier_0;

		result->tag = parameter_declarationRepetition0Type_0;
	}

	return result;
}
struct parameter_declarationRepetition0 *verbum_ast_new_parameter_declarationRepetition0_choice1(struct VerbumContext *ctx) {
	struct parameter_declarationRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = parameter_declarationRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_parameter_declarationRepetition0(struct VerbumContext *ctx, struct parameter_declarationRepetition0 *parameter_declarationRepetition0) {
	switch(parameter_declarationRepetition0->tag) {
	case parameter_declarationRepetition0Type_0:
		verbum_ast_delete_parameter_declarationRepetition0(ctx, parameter_declarationRepetition0->choice0.parameter_declarationRepetition0_0);
		verbum_ast_delete_declaration_specifier(ctx, parameter_declarationRepetition0->choice0.declaration_specifier_0);
	break;
	case parameter_declarationRepetition0Type_1:
	break;
	}
	ctx->memory.delete(parameter_declarationRepetition0);
}
struct parameter_declarationOptional0 *verbum_ast_new_parameter_declarationOptional0_choice0(struct VerbumContext *ctx, struct declarator *declarator_0) {
	struct parameter_declarationOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.declarator_0 = declarator_0;

		result->tag = parameter_declarationOptional0Type_0;
	}

	return result;
}
struct parameter_declarationOptional0 *verbum_ast_new_parameter_declarationOptional0_choice1(struct VerbumContext *ctx, struct abstract_declarator *abstract_declarator_0) {
	struct parameter_declarationOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice1.abstract_declarator_0 = abstract_declarator_0;

		result->tag = parameter_declarationOptional0Type_1;
	}

	return result;
}
struct parameter_declarationOptional0 *verbum_ast_new_parameter_declarationOptional0_choice2(struct VerbumContext *ctx) {
	struct parameter_declarationOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = parameter_declarationOptional0Type_2;
	}

	return result;
}
void verbum_ast_delete_parameter_declarationOptional0(struct VerbumContext *ctx, struct parameter_declarationOptional0 *parameter_declarationOptional0) {
	switch(parameter_declarationOptional0->tag) {
	case parameter_declarationOptional0Type_0:
		verbum_ast_delete_declarator(ctx, parameter_declarationOptional0->choice0.declarator_0);
	break;
	case parameter_declarationOptional0Type_1:
		verbum_ast_delete_abstract_declarator(ctx, parameter_declarationOptional0->choice1.abstract_declarator_0);
	break;
	case parameter_declarationOptional0Type_2:
	break;
	}
	ctx->memory.delete(parameter_declarationOptional0);
}
struct abstract_declaratorOptional0 *verbum_ast_new_abstract_declaratorOptional0_choice0(struct VerbumContext *ctx, struct direct_abstract_declarator *direct_abstract_declarator_0) {
	struct abstract_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.direct_abstract_declarator_0 = direct_abstract_declarator_0;

		result->tag = abstract_declaratorOptional0Type_0;
	}

	return result;
}
struct abstract_declaratorOptional0 *verbum_ast_new_abstract_declaratorOptional0_choice1(struct VerbumContext *ctx) {
	struct abstract_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = abstract_declaratorOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_abstract_declaratorOptional0(struct VerbumContext *ctx, struct abstract_declaratorOptional0 *abstract_declaratorOptional0) {
	switch(abstract_declaratorOptional0->tag) {
	case abstract_declaratorOptional0Type_0:
		verbum_ast_delete_direct_abstract_declarator(ctx, abstract_declaratorOptional0->choice0.direct_abstract_declarator_0);
	break;
	case abstract_declaratorOptional0Type_1:
	break;
	}
	ctx->memory.delete(abstract_declaratorOptional0);
}
struct direct_abstract_declaratorOptional0 *verbum_ast_new_direct_abstract_declaratorOptional0_choice0(struct VerbumContext *ctx, struct direct_abstract_declarator *direct_abstract_declarator_0) {
	struct direct_abstract_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.direct_abstract_declarator_0 = direct_abstract_declarator_0;

		result->tag = direct_abstract_declaratorOptional0Type_0;
	}

	return result;
}
struct direct_abstract_declaratorOptional0 *verbum_ast_new_direct_abstract_declaratorOptional0_choice1(struct VerbumContext *ctx) {
	struct direct_abstract_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = direct_abstract_declaratorOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_direct_abstract_declaratorOptional0(struct VerbumContext *ctx, struct direct_abstract_declaratorOptional0 *direct_abstract_declaratorOptional0) {
	switch(direct_abstract_declaratorOptional0->tag) {
	case direct_abstract_declaratorOptional0Type_0:
		verbum_ast_delete_direct_abstract_declarator(ctx, direct_abstract_declaratorOptional0->choice0.direct_abstract_declarator_0);
	break;
	case direct_abstract_declaratorOptional0Type_1:
	break;
	}
	ctx->memory.delete(direct_abstract_declaratorOptional0);
}
struct direct_abstract_declaratorOptional1 *verbum_ast_new_direct_abstract_declaratorOptional1_choice0(struct VerbumContext *ctx, struct constant_expression *constant_expression_0) {
	struct direct_abstract_declaratorOptional1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.constant_expression_0 = constant_expression_0;

		result->tag = direct_abstract_declaratorOptional1Type_0;
	}

	return result;
}
struct direct_abstract_declaratorOptional1 *verbum_ast_new_direct_abstract_declaratorOptional1_choice1(struct VerbumContext *ctx) {
	struct direct_abstract_declaratorOptional1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = direct_abstract_declaratorOptional1Type_1;
	}

	return result;
}
void verbum_ast_delete_direct_abstract_declaratorOptional1(struct VerbumContext *ctx, struct direct_abstract_declaratorOptional1 *direct_abstract_declaratorOptional1) {
	switch(direct_abstract_declaratorOptional1->tag) {
	case direct_abstract_declaratorOptional1Type_0:
		verbum_ast_delete_constant_expression(ctx, direct_abstract_declaratorOptional1->choice0.constant_expression_0);
	break;
	case direct_abstract_declaratorOptional1Type_1:
	break;
	}
	ctx->memory.delete(direct_abstract_declaratorOptional1);
}
struct direct_abstract_declaratorOptional2 *verbum_ast_new_direct_abstract_declaratorOptional2_choice0(struct VerbumContext *ctx, struct direct_abstract_declarator *direct_abstract_declarator_0) {
	struct direct_abstract_declaratorOptional2 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.direct_abstract_declarator_0 = direct_abstract_declarator_0;

		result->tag = direct_abstract_declaratorOptional2Type_0;
	}

	return result;
}
struct direct_abstract_declaratorOptional2 *verbum_ast_new_direct_abstract_declaratorOptional2_choice1(struct VerbumContext *ctx) {
	struct direct_abstract_declaratorOptional2 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = direct_abstract_declaratorOptional2Type_1;
	}

	return result;
}
void verbum_ast_delete_direct_abstract_declaratorOptional2(struct VerbumContext *ctx, struct direct_abstract_declaratorOptional2 *direct_abstract_declaratorOptional2) {
	switch(direct_abstract_declaratorOptional2->tag) {
	case direct_abstract_declaratorOptional2Type_0:
		verbum_ast_delete_direct_abstract_declarator(ctx, direct_abstract_declaratorOptional2->choice0.direct_abstract_declarator_0);
	break;
	case direct_abstract_declaratorOptional2Type_1:
	break;
	}
	ctx->memory.delete(direct_abstract_declaratorOptional2);
}
struct direct_abstract_declaratorOptional3 *verbum_ast_new_direct_abstract_declaratorOptional3_choice0(struct VerbumContext *ctx, struct parameter_type_list *parameter_type_list_0) {
	struct direct_abstract_declaratorOptional3 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.parameter_type_list_0 = parameter_type_list_0;

		result->tag = direct_abstract_declaratorOptional3Type_0;
	}

	return result;
}
struct direct_abstract_declaratorOptional3 *verbum_ast_new_direct_abstract_declaratorOptional3_choice1(struct VerbumContext *ctx) {
	struct direct_abstract_declaratorOptional3 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = direct_abstract_declaratorOptional3Type_1;
	}

	return result;
}
void verbum_ast_delete_direct_abstract_declaratorOptional3(struct VerbumContext *ctx, struct direct_abstract_declaratorOptional3 *direct_abstract_declaratorOptional3) {
	switch(direct_abstract_declaratorOptional3->tag) {
	case direct_abstract_declaratorOptional3Type_0:
		verbum_ast_delete_parameter_type_list(ctx, direct_abstract_declaratorOptional3->choice0.parameter_type_list_0);
	break;
	case direct_abstract_declaratorOptional3Type_1:
	break;
	}
	ctx->memory.delete(direct_abstract_declaratorOptional3);
}
struct enum_specifierOptional0 *verbum_ast_new_enum_specifierOptional0_choice0(struct VerbumContext *ctx, Token IDENTIFIER_0) {
	struct enum_specifierOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.IDENTIFIER_0 = IDENTIFIER_0;

		result->tag = enum_specifierOptional0Type_0;
	}

	return result;
}
struct enum_specifierOptional0 *verbum_ast_new_enum_specifierOptional0_choice1(struct VerbumContext *ctx) {
	struct enum_specifierOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = enum_specifierOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_enum_specifierOptional0(struct VerbumContext *ctx, struct enum_specifierOptional0 *enum_specifierOptional0) {
	switch(enum_specifierOptional0->tag) {
	case enum_specifierOptional0Type_0:
		verbum_token_delete(ctx, &enum_specifierOptional0->choice0.IDENTIFIER_0);
	break;
	case enum_specifierOptional0Type_1:
	break;
	}
	ctx->memory.delete(enum_specifierOptional0);
}
struct enumerator_listRepetition0 *verbum_ast_new_enumerator_listRepetition0_choice0(struct VerbumContext *ctx, struct enumerator *enumerator_0, struct enumerator_listRepetition0 *enumerator_listRepetition0_0, Token literal_0) {
	struct enumerator_listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.enumerator_0 = enumerator_0;
		result->choice0.enumerator_listRepetition0_0 = enumerator_listRepetition0_0;
		result->choice0.literal_0 = literal_0;

		result->tag = enumerator_listRepetition0Type_0;
	}

	return result;
}
struct enumerator_listRepetition0 *verbum_ast_new_enumerator_listRepetition0_choice1(struct VerbumContext *ctx) {
	struct enumerator_listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = enumerator_listRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_enumerator_listRepetition0(struct VerbumContext *ctx, struct enumerator_listRepetition0 *enumerator_listRepetition0) {
	switch(enumerator_listRepetition0->tag) {
	case enumerator_listRepetition0Type_0:
		verbum_ast_delete_enumerator(ctx, enumerator_listRepetition0->choice0.enumerator_0);
		verbum_ast_delete_enumerator_listRepetition0(ctx, enumerator_listRepetition0->choice0.enumerator_listRepetition0_0);
		verbum_token_delete(ctx, &enumerator_listRepetition0->choice0.literal_0);
	break;
	case enumerator_listRepetition0Type_1:
	break;
	}
	ctx->memory.delete(enumerator_listRepetition0);
}
struct enumeratorOptional0 *verbum_ast_new_enumeratorOptional0_choice0(struct VerbumContext *ctx, Token literal_0, struct constant_expression *constant_expression_0) {
	struct enumeratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.constant_expression_0 = constant_expression_0;

		result->tag = enumeratorOptional0Type_0;
	}

	return result;
}
struct enumeratorOptional0 *verbum_ast_new_enumeratorOptional0_choice1(struct VerbumContext *ctx) {
	struct enumeratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = enumeratorOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_enumeratorOptional0(struct VerbumContext *ctx, struct enumeratorOptional0 *enumeratorOptional0) {
	switch(enumeratorOptional0->tag) {
	case enumeratorOptional0Type_0:
		verbum_token_delete(ctx, &enumeratorOptional0->choice0.literal_0);
		verbum_ast_delete_constant_expression(ctx, enumeratorOptional0->choice0.constant_expression_0);
	break;
	case enumeratorOptional0Type_1:
	break;
	}
	ctx->memory.delete(enumeratorOptional0);
}
struct declarationRepetition0 *verbum_ast_new_declarationRepetition0_choice0(struct VerbumContext *ctx, struct declaration_specifier *declaration_specifier_0, struct declarationRepetition0 *declarationRepetition0_0) {
	struct declarationRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.declaration_specifier_0 = declaration_specifier_0;
		result->choice0.declarationRepetition0_0 = declarationRepetition0_0;

		result->tag = declarationRepetition0Type_0;
	}

	return result;
}
struct declarationRepetition0 *verbum_ast_new_declarationRepetition0_choice1(struct VerbumContext *ctx) {
	struct declarationRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = declarationRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_declarationRepetition0(struct VerbumContext *ctx, struct declarationRepetition0 *declarationRepetition0) {
	switch(declarationRepetition0->tag) {
	case declarationRepetition0Type_0:
		verbum_ast_delete_declaration_specifier(ctx, declarationRepetition0->choice0.declaration_specifier_0);
		verbum_ast_delete_declarationRepetition0(ctx, declarationRepetition0->choice0.declarationRepetition0_0);
	break;
	case declarationRepetition0Type_1:
	break;
	}
	ctx->memory.delete(declarationRepetition0);
}
struct declarationRepetition1 *verbum_ast_new_declarationRepetition1_choice0(struct VerbumContext *ctx, struct declarationRepetition1 *declarationRepetition1_0, struct init_declarator *init_declarator_0) {
	struct declarationRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.declarationRepetition1_0 = declarationRepetition1_0;
		result->choice0.init_declarator_0 = init_declarator_0;

		result->tag = declarationRepetition1Type_0;
	}

	return result;
}
struct declarationRepetition1 *verbum_ast_new_declarationRepetition1_choice1(struct VerbumContext *ctx) {
	struct declarationRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = declarationRepetition1Type_1;
	}

	return result;
}
void verbum_ast_delete_declarationRepetition1(struct VerbumContext *ctx, struct declarationRepetition1 *declarationRepetition1) {
	switch(declarationRepetition1->tag) {
	case declarationRepetition1Type_0:
		verbum_ast_delete_declarationRepetition1(ctx, declarationRepetition1->choice0.declarationRepetition1_0);
		verbum_ast_delete_init_declarator(ctx, declarationRepetition1->choice0.init_declarator_0);
	break;
	case declarationRepetition1Type_1:
	break;
	}
	ctx->memory.delete(declarationRepetition1);
}
struct init_declaratorOptional0 *verbum_ast_new_init_declaratorOptional0_choice0(struct VerbumContext *ctx, Token literal_0, struct initializer *initializer_0) {
	struct init_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.initializer_0 = initializer_0;

		result->tag = init_declaratorOptional0Type_0;
	}

	return result;
}
struct init_declaratorOptional0 *verbum_ast_new_init_declaratorOptional0_choice1(struct VerbumContext *ctx) {
	struct init_declaratorOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = init_declaratorOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_init_declaratorOptional0(struct VerbumContext *ctx, struct init_declaratorOptional0 *init_declaratorOptional0) {
	switch(init_declaratorOptional0->tag) {
	case init_declaratorOptional0Type_0:
		verbum_token_delete(ctx, &init_declaratorOptional0->choice0.literal_0);
		verbum_ast_delete_initializer(ctx, init_declaratorOptional0->choice0.initializer_0);
	break;
	case init_declaratorOptional0Type_1:
	break;
	}
	ctx->memory.delete(init_declaratorOptional0);
}
struct initializerOptional0 *verbum_ast_new_initializerOptional0_choice0(struct VerbumContext *ctx, Token literal_0) {
	struct initializerOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;

		result->tag = initializerOptional0Type_0;
	}

	return result;
}
struct initializerOptional0 *verbum_ast_new_initializerOptional0_choice1(struct VerbumContext *ctx) {
	struct initializerOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = initializerOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_initializerOptional0(struct VerbumContext *ctx, struct initializerOptional0 *initializerOptional0) {
	switch(initializerOptional0->tag) {
	case initializerOptional0Type_0:
		verbum_token_delete(ctx, &initializerOptional0->choice0.literal_0);
	break;
	case initializerOptional0Type_1:
	break;
	}
	ctx->memory.delete(initializerOptional0);
}
struct initializer_listRepetition0 *verbum_ast_new_initializer_listRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct initializer *initializer_0, struct initializer_listRepetition0 *initializer_listRepetition0_0) {
	struct initializer_listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.initializer_0 = initializer_0;
		result->choice0.initializer_listRepetition0_0 = initializer_listRepetition0_0;

		result->tag = initializer_listRepetition0Type_0;
	}

	return result;
}
struct initializer_listRepetition0 *verbum_ast_new_initializer_listRepetition0_choice1(struct VerbumContext *ctx) {
	struct initializer_listRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = initializer_listRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_initializer_listRepetition0(struct VerbumContext *ctx, struct initializer_listRepetition0 *initializer_listRepetition0) {
	switch(initializer_listRepetition0->tag) {
	case initializer_listRepetition0Type_0:
		verbum_token_delete(ctx, &initializer_listRepetition0->choice0.literal_0);
		verbum_ast_delete_initializer(ctx, initializer_listRepetition0->choice0.initializer_0);
		verbum_ast_delete_initializer_listRepetition0(ctx, initializer_listRepetition0->choice0.initializer_listRepetition0_0);
	break;
	case initializer_listRepetition0Type_1:
	break;
	}
	ctx->memory.delete(initializer_listRepetition0);
}
struct compound_statementRepetition0 *verbum_ast_new_compound_statementRepetition0_choice0(struct VerbumContext *ctx, struct declaration *declaration_0, struct compound_statementRepetition0 *compound_statementRepetition0_0) {
	struct compound_statementRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.declaration_0 = declaration_0;
		result->choice0.compound_statementRepetition0_0 = compound_statementRepetition0_0;

		result->tag = compound_statementRepetition0Type_0;
	}

	return result;
}
struct compound_statementRepetition0 *verbum_ast_new_compound_statementRepetition0_choice1(struct VerbumContext *ctx) {
	struct compound_statementRepetition0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = compound_statementRepetition0Type_1;
	}

	return result;
}
void verbum_ast_delete_compound_statementRepetition0(struct VerbumContext *ctx, struct compound_statementRepetition0 *compound_statementRepetition0) {
	switch(compound_statementRepetition0->tag) {
	case compound_statementRepetition0Type_0:
		verbum_ast_delete_declaration(ctx, compound_statementRepetition0->choice0.declaration_0);
		verbum_ast_delete_compound_statementRepetition0(ctx, compound_statementRepetition0->choice0.compound_statementRepetition0_0);
	break;
	case compound_statementRepetition0Type_1:
	break;
	}
	ctx->memory.delete(compound_statementRepetition0);
}
struct compound_statementRepetition1 *verbum_ast_new_compound_statementRepetition1_choice0(struct VerbumContext *ctx, struct statement *statement_0, struct compound_statementRepetition1 *compound_statementRepetition1_0) {
	struct compound_statementRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.statement_0 = statement_0;
		result->choice0.compound_statementRepetition1_0 = compound_statementRepetition1_0;

		result->tag = compound_statementRepetition1Type_0;
	}

	return result;
}
struct compound_statementRepetition1 *verbum_ast_new_compound_statementRepetition1_choice1(struct VerbumContext *ctx) {
	struct compound_statementRepetition1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = compound_statementRepetition1Type_1;
	}

	return result;
}
void verbum_ast_delete_compound_statementRepetition1(struct VerbumContext *ctx, struct compound_statementRepetition1 *compound_statementRepetition1) {
	switch(compound_statementRepetition1->tag) {
	case compound_statementRepetition1Type_0:
		verbum_ast_delete_statement(ctx, compound_statementRepetition1->choice0.statement_0);
		verbum_ast_delete_compound_statementRepetition1(ctx, compound_statementRepetition1->choice0.compound_statementRepetition1_0);
	break;
	case compound_statementRepetition1Type_1:
	break;
	}
	ctx->memory.delete(compound_statementRepetition1);
}
struct expression_statementOptional0 *verbum_ast_new_expression_statementOptional0_choice0(struct VerbumContext *ctx, struct expression *expression_0) {
	struct expression_statementOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.expression_0 = expression_0;

		result->tag = expression_statementOptional0Type_0;
	}

	return result;
}
struct expression_statementOptional0 *verbum_ast_new_expression_statementOptional0_choice1(struct VerbumContext *ctx) {
	struct expression_statementOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = expression_statementOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_expression_statementOptional0(struct VerbumContext *ctx, struct expression_statementOptional0 *expression_statementOptional0) {
	switch(expression_statementOptional0->tag) {
	case expression_statementOptional0Type_0:
		verbum_ast_delete_expression(ctx, expression_statementOptional0->choice0.expression_0);
	break;
	case expression_statementOptional0Type_1:
	break;
	}
	ctx->memory.delete(expression_statementOptional0);
}
struct selection_statementOptional0 *verbum_ast_new_selection_statementOptional0_choice0(struct VerbumContext *ctx, Token literal_0, struct statement *statement_0) {
	struct selection_statementOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.literal_0 = literal_0;
		result->choice0.statement_0 = statement_0;

		result->tag = selection_statementOptional0Type_0;
	}

	return result;
}
struct selection_statementOptional0 *verbum_ast_new_selection_statementOptional0_choice1(struct VerbumContext *ctx) {
	struct selection_statementOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = selection_statementOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_selection_statementOptional0(struct VerbumContext *ctx, struct selection_statementOptional0 *selection_statementOptional0) {
	switch(selection_statementOptional0->tag) {
	case selection_statementOptional0Type_0:
		verbum_token_delete(ctx, &selection_statementOptional0->choice0.literal_0);
		verbum_ast_delete_statement(ctx, selection_statementOptional0->choice0.statement_0);
	break;
	case selection_statementOptional0Type_1:
	break;
	}
	ctx->memory.delete(selection_statementOptional0);
}
struct iteration_statementOptional0 *verbum_ast_new_iteration_statementOptional0_choice0(struct VerbumContext *ctx, struct expression *expression_0) {
	struct iteration_statementOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.expression_0 = expression_0;

		result->tag = iteration_statementOptional0Type_0;
	}

	return result;
}
struct iteration_statementOptional0 *verbum_ast_new_iteration_statementOptional0_choice1(struct VerbumContext *ctx) {
	struct iteration_statementOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = iteration_statementOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_iteration_statementOptional0(struct VerbumContext *ctx, struct iteration_statementOptional0 *iteration_statementOptional0) {
	switch(iteration_statementOptional0->tag) {
	case iteration_statementOptional0Type_0:
		verbum_ast_delete_expression(ctx, iteration_statementOptional0->choice0.expression_0);
	break;
	case iteration_statementOptional0Type_1:
	break;
	}
	ctx->memory.delete(iteration_statementOptional0);
}
struct iteration_statementOptional1 *verbum_ast_new_iteration_statementOptional1_choice0(struct VerbumContext *ctx, struct expression *expression_0) {
	struct iteration_statementOptional1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.expression_0 = expression_0;

		result->tag = iteration_statementOptional1Type_0;
	}

	return result;
}
struct iteration_statementOptional1 *verbum_ast_new_iteration_statementOptional1_choice1(struct VerbumContext *ctx) {
	struct iteration_statementOptional1 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = iteration_statementOptional1Type_1;
	}

	return result;
}
void verbum_ast_delete_iteration_statementOptional1(struct VerbumContext *ctx, struct iteration_statementOptional1 *iteration_statementOptional1) {
	switch(iteration_statementOptional1->tag) {
	case iteration_statementOptional1Type_0:
		verbum_ast_delete_expression(ctx, iteration_statementOptional1->choice0.expression_0);
	break;
	case iteration_statementOptional1Type_1:
	break;
	}
	ctx->memory.delete(iteration_statementOptional1);
}
struct iteration_statementOptional2 *verbum_ast_new_iteration_statementOptional2_choice0(struct VerbumContext *ctx, struct expression *expression_0) {
	struct iteration_statementOptional2 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.expression_0 = expression_0;

		result->tag = iteration_statementOptional2Type_0;
	}

	return result;
}
struct iteration_statementOptional2 *verbum_ast_new_iteration_statementOptional2_choice1(struct VerbumContext *ctx) {
	struct iteration_statementOptional2 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = iteration_statementOptional2Type_1;
	}

	return result;
}
void verbum_ast_delete_iteration_statementOptional2(struct VerbumContext *ctx, struct iteration_statementOptional2 *iteration_statementOptional2) {
	switch(iteration_statementOptional2->tag) {
	case iteration_statementOptional2Type_0:
		verbum_ast_delete_expression(ctx, iteration_statementOptional2->choice0.expression_0);
	break;
	case iteration_statementOptional2Type_1:
	break;
	}
	ctx->memory.delete(iteration_statementOptional2);
}
struct jump_statementOptional0 *verbum_ast_new_jump_statementOptional0_choice0(struct VerbumContext *ctx, struct expression *expression_0) {
	struct jump_statementOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {
		result->choice0.expression_0 = expression_0;

		result->tag = jump_statementOptional0Type_0;
	}

	return result;
}
struct jump_statementOptional0 *verbum_ast_new_jump_statementOptional0_choice1(struct VerbumContext *ctx) {
	struct jump_statementOptional0 *result = ctx->memory.new(sizeof(*result));


	if(result != NULL) {

		result->tag = jump_statementOptional0Type_1;
	}

	return result;
}
void verbum_ast_delete_jump_statementOptional0(struct VerbumContext *ctx, struct jump_statementOptional0 *jump_statementOptional0) {
	switch(jump_statementOptional0->tag) {
	case jump_statementOptional0Type_0:
		verbum_ast_delete_expression(ctx, jump_statementOptional0->choice0.expression_0);
	break;
	case jump_statementOptional0Type_1:
	break;
	}
	ctx->memory.delete(jump_statementOptional0);
}
