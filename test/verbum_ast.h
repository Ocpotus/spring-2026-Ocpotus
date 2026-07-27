#ifndef VERBUM_AST_H
#define VERBUM_AST_H
#include "verbum.h"
#include "verbum_token.h"
typedef struct translation_unit translation_unit;
typedef struct external_declaration external_declaration;
typedef struct function_definition function_definition;
typedef struct declaration_specifier declaration_specifier;
typedef struct storage_class_specifier storage_class_specifier;
typedef struct type_specifier type_specifier;
typedef struct struct_or_union_specifier struct_or_union_specifier;
typedef struct struct_or_union struct_or_union;
typedef struct struct_declaration struct_declaration;
typedef struct specifier_qualifier specifier_qualifier;
typedef struct struct_declarator_list struct_declarator_list;
typedef struct struct_declarator struct_declarator;
typedef struct declarator declarator;
typedef struct pointer pointer;
typedef struct type_qualifier type_qualifier;
typedef struct direct_declarator direct_declarator;
typedef struct constant_expression constant_expression;
typedef struct conditional_expression conditional_expression;
typedef struct logical_or_expression logical_or_expression;
typedef struct logical_and_expression logical_and_expression;
typedef struct inclusive_or_expression inclusive_or_expression;
typedef struct exclusive_or_expression exclusive_or_expression;
typedef struct and_expression and_expression;
typedef struct equality_expression equality_expression;
typedef struct relational_expression relational_expression;
typedef struct shift_expression shift_expression;
typedef struct additive_expression additive_expression;
typedef struct multiplicative_expression multiplicative_expression;
typedef struct cast_expression cast_expression;
typedef struct unary_expression unary_expression;
typedef struct postfix_expression postfix_expression;
typedef struct primary_expression primary_expression;
typedef struct constant constant;
typedef struct expression expression;
typedef struct assignment_expression assignment_expression;
typedef struct assignment_operator assignment_operator;
typedef struct unary_operator unary_operator;
typedef struct type_name type_name;
typedef struct parameter_type_list parameter_type_list;
typedef struct parameter_list parameter_list;
typedef struct parameter_declaration parameter_declaration;
typedef struct abstract_declarator abstract_declarator;
typedef struct direct_abstract_declarator direct_abstract_declarator;
typedef struct enum_specifier enum_specifier;
typedef struct enumerator_list enumerator_list;
typedef struct enumerator enumerator;
typedef struct typedef_name typedef_name;
typedef struct declaration declaration;
typedef struct init_declarator init_declarator;
typedef struct initializer initializer;
typedef struct initializer_list initializer_list;
typedef struct compound_statement compound_statement;
typedef struct statement statement;
typedef struct labeled_statement labeled_statement;
typedef struct expression_statement expression_statement;
typedef struct selection_statement selection_statement;
typedef struct iteration_statement iteration_statement;
typedef struct jump_statement jump_statement;
typedef struct translation_unitRepetition0 translation_unitRepetition0;
typedef struct function_definitionRepetition0 function_definitionRepetition0;
typedef struct function_definitionRepetition1 function_definitionRepetition1;
typedef struct struct_or_union_specifierRepetition0 struct_or_union_specifierRepetition0;
typedef struct struct_or_union_specifierRepetition1 struct_or_union_specifierRepetition1;
typedef struct struct_declarationRepetition0 struct_declarationRepetition0;
typedef struct struct_declarator_listRepetition0 struct_declarator_listRepetition0;
typedef struct struct_declaratorOptional0 struct_declaratorOptional0;
typedef struct declaratorOptional0 declaratorOptional0;
typedef struct pointerRepetition0 pointerRepetition0;
typedef struct pointerOptional0 pointerOptional0;
typedef struct direct_declaratorGroup0 direct_declaratorGroup0;
typedef struct direct_declaratorOptional0 direct_declaratorOptional0;
typedef struct direct_declaratorRepetition1 direct_declaratorRepetition1;
typedef struct direct_declaratorRepetition0 direct_declaratorRepetition0;
typedef struct conditional_expressionOptional0 conditional_expressionOptional0;
typedef struct logical_or_expressionRepetition0 logical_or_expressionRepetition0;
typedef struct logical_and_expressionRepetition0 logical_and_expressionRepetition0;
typedef struct inclusive_or_expressionRepetition0 inclusive_or_expressionRepetition0;
typedef struct exclusive_or_expressionRepetition0 exclusive_or_expressionRepetition0;
typedef struct and_expressionRepetition0 and_expressionRepetition0;
typedef struct equality_expressionGroup0 equality_expressionGroup0;
typedef struct equality_expressionRepetition0 equality_expressionRepetition0;
typedef struct relational_expressionGroup0 relational_expressionGroup0;
typedef struct relational_expressionRepetition0 relational_expressionRepetition0;
typedef struct shift_expressionGroup0 shift_expressionGroup0;
typedef struct shift_expressionRepetition0 shift_expressionRepetition0;
typedef struct additive_expressionGroup0 additive_expressionGroup0;
typedef struct additive_expressionRepetition0 additive_expressionRepetition0;
typedef struct multiplicative_expressionGroup0 multiplicative_expressionGroup0;
typedef struct multiplicative_expressionRepetition0 multiplicative_expressionRepetition0;
typedef struct unary_expressionGroup0 unary_expressionGroup0;
typedef struct postfix_expressionRepetition1 postfix_expressionRepetition1;
typedef struct postfix_expressionRepetition0 postfix_expressionRepetition0;
typedef struct expressionRepetition0 expressionRepetition0;
typedef struct type_nameRepetition0 type_nameRepetition0;
typedef struct type_nameOptional0 type_nameOptional0;
typedef struct parameter_type_listOptional0 parameter_type_listOptional0;
typedef struct parameter_listRepetition0 parameter_listRepetition0;
typedef struct parameter_declarationRepetition0 parameter_declarationRepetition0;
typedef struct parameter_declarationOptional0 parameter_declarationOptional0;
typedef struct abstract_declaratorOptional0 abstract_declaratorOptional0;
typedef struct direct_abstract_declaratorOptional0 direct_abstract_declaratorOptional0;
typedef struct direct_abstract_declaratorOptional1 direct_abstract_declaratorOptional1;
typedef struct direct_abstract_declaratorOptional2 direct_abstract_declaratorOptional2;
typedef struct direct_abstract_declaratorOptional3 direct_abstract_declaratorOptional3;
typedef struct enum_specifierOptional0 enum_specifierOptional0;
typedef struct enumerator_listRepetition0 enumerator_listRepetition0;
typedef struct enumeratorOptional0 enumeratorOptional0;
typedef struct declarationRepetition0 declarationRepetition0;
typedef struct declarationRepetition1 declarationRepetition1;
typedef struct init_declaratorOptional0 init_declaratorOptional0;
typedef struct initializerOptional0 initializerOptional0;
typedef struct initializer_listRepetition0 initializer_listRepetition0;
typedef struct compound_statementRepetition0 compound_statementRepetition0;
typedef struct compound_statementRepetition1 compound_statementRepetition1;
typedef struct expression_statementOptional0 expression_statementOptional0;
typedef struct selection_statementOptional0 selection_statementOptional0;
typedef struct iteration_statementOptional0 iteration_statementOptional0;
typedef struct iteration_statementOptional1 iteration_statementOptional1;
typedef struct iteration_statementOptional2 iteration_statementOptional2;
typedef struct jump_statementOptional0 jump_statementOptional0;
typedef struct translation_unit {
	struct translation_unitRepetition0 *translation_unitRepetition0_0;
} translation_unit;

struct translation_unit *verbum_ast_new_translation_unit(struct VerbumContext *ctx, struct translation_unitRepetition0 *translation_unitRepetition0_0);
void verbum_ast_delete_translation_unit(struct VerbumContext *ctx, struct translation_unit *d);
typedef enum external_declarationType {
	external_declarationType_0,
	external_declarationType_1,
} external_declarationType;
typedef struct external_declaration {

	external_declarationType tag;
	union {
		struct {
			struct function_definition *function_definition_0;
		} choice0;
		struct {
			struct declaration *declaration_0;
		} choice1;
	};
} external_declaration;
struct external_declaration *verbum_ast_new_external_declaration_choice0(struct VerbumContext *ctx, struct function_definition *function_definition_0);
struct external_declaration *verbum_ast_new_external_declaration_choice1(struct VerbumContext *ctx, struct declaration *declaration_0);
void verbum_ast_delete_external_declaration(struct VerbumContext *ctx, struct external_declaration *d);
typedef struct function_definition {
	struct function_definitionRepetition0 *function_definitionRepetition0_0;
	struct declarator *declarator_0;
	struct function_definitionRepetition1 *function_definitionRepetition1_0;
	struct compound_statement *compound_statement_0;
} function_definition;

struct function_definition *verbum_ast_new_function_definition(struct VerbumContext *ctx, struct function_definitionRepetition0 *function_definitionRepetition0_0, struct compound_statement *compound_statement_0, struct declarator *declarator_0, struct function_definitionRepetition1 *function_definitionRepetition1_0);
void verbum_ast_delete_function_definition(struct VerbumContext *ctx, struct function_definition *d);
typedef enum declaration_specifierType {
	declaration_specifierType_0,
	declaration_specifierType_1,
	declaration_specifierType_2,
} declaration_specifierType;
typedef struct declaration_specifier {

	declaration_specifierType tag;
	union {
		struct {
			struct storage_class_specifier *storage_class_specifier_0;
		} choice0;
		struct {
			struct type_specifier *type_specifier_0;
		} choice1;
		struct {
			struct type_qualifier *type_qualifier_0;
		} choice2;
	};
} declaration_specifier;
struct declaration_specifier *verbum_ast_new_declaration_specifier_choice0(struct VerbumContext *ctx, struct storage_class_specifier *storage_class_specifier_0);
struct declaration_specifier *verbum_ast_new_declaration_specifier_choice1(struct VerbumContext *ctx, struct type_specifier *type_specifier_0);
struct declaration_specifier *verbum_ast_new_declaration_specifier_choice2(struct VerbumContext *ctx, struct type_qualifier *type_qualifier_0);
void verbum_ast_delete_declaration_specifier(struct VerbumContext *ctx, struct declaration_specifier *d);
typedef enum storage_class_specifierType {
	storage_class_specifierType_0,
	storage_class_specifierType_1,
	storage_class_specifierType_2,
	storage_class_specifierType_3,
	storage_class_specifierType_4,
} storage_class_specifierType;
typedef struct storage_class_specifier {

	storage_class_specifierType tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
		struct {
			Token literal_0;
		} choice2;
		struct {
			Token literal_0;
		} choice3;
		struct {
			Token literal_0;
		} choice4;
	};
} storage_class_specifier;
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice0(struct VerbumContext *ctx, Token literal_0);
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice1(struct VerbumContext *ctx, Token literal_0);
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice2(struct VerbumContext *ctx, Token literal_0);
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice3(struct VerbumContext *ctx, Token literal_0);
struct storage_class_specifier *verbum_ast_new_storage_class_specifier_choice4(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_storage_class_specifier(struct VerbumContext *ctx, struct storage_class_specifier *d);
typedef enum type_specifierType {
	type_specifierType_0,
	type_specifierType_1,
	type_specifierType_2,
	type_specifierType_3,
	type_specifierType_4,
	type_specifierType_5,
	type_specifierType_6,
	type_specifierType_7,
	type_specifierType_8,
	type_specifierType_9,
	type_specifierType_10,
	type_specifierType_11,
} type_specifierType;
typedef struct type_specifier {

	type_specifierType tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
		struct {
			Token literal_0;
		} choice2;
		struct {
			Token literal_0;
		} choice3;
		struct {
			Token literal_0;
		} choice4;
		struct {
			Token literal_0;
		} choice5;
		struct {
			Token literal_0;
		} choice6;
		struct {
			Token literal_0;
		} choice7;
		struct {
			Token literal_0;
		} choice8;
		struct {
			struct struct_or_union_specifier *struct_or_union_specifier_0;
		} choice9;
		struct {
			struct enum_specifier *enum_specifier_0;
		} choice10;
		struct {
			struct typedef_name *typedef_name_0;
		} choice11;
	};
} type_specifier;
struct type_specifier *verbum_ast_new_type_specifier_choice0(struct VerbumContext *ctx, Token literal_0);
struct type_specifier *verbum_ast_new_type_specifier_choice1(struct VerbumContext *ctx, Token literal_0);
struct type_specifier *verbum_ast_new_type_specifier_choice2(struct VerbumContext *ctx, Token literal_0);
struct type_specifier *verbum_ast_new_type_specifier_choice3(struct VerbumContext *ctx, Token literal_0);
struct type_specifier *verbum_ast_new_type_specifier_choice4(struct VerbumContext *ctx, Token literal_0);
struct type_specifier *verbum_ast_new_type_specifier_choice5(struct VerbumContext *ctx, Token literal_0);
struct type_specifier *verbum_ast_new_type_specifier_choice6(struct VerbumContext *ctx, Token literal_0);
struct type_specifier *verbum_ast_new_type_specifier_choice7(struct VerbumContext *ctx, Token literal_0);
struct type_specifier *verbum_ast_new_type_specifier_choice8(struct VerbumContext *ctx, Token literal_0);
struct type_specifier *verbum_ast_new_type_specifier_choice9(struct VerbumContext *ctx, struct struct_or_union_specifier *struct_or_union_specifier_0);
struct type_specifier *verbum_ast_new_type_specifier_choice10(struct VerbumContext *ctx, struct enum_specifier *enum_specifier_0);
struct type_specifier *verbum_ast_new_type_specifier_choice11(struct VerbumContext *ctx, struct typedef_name *typedef_name_0);
void verbum_ast_delete_type_specifier(struct VerbumContext *ctx, struct type_specifier *d);
typedef enum struct_or_union_specifierType {
	struct_or_union_specifierType_0,
	struct_or_union_specifierType_1,
	struct_or_union_specifierType_2,
} struct_or_union_specifierType;
typedef struct struct_or_union_specifier {

	struct_or_union_specifierType tag;
	union {
		struct {
			struct struct_or_union *struct_or_union_0;
			Token IDENTIFIER_0;
			Token literal_0;
			struct struct_declaration *struct_declaration_0;
			struct struct_or_union_specifierRepetition0 *struct_or_union_specifierRepetition0_0;
			Token literal_1;

		} choice0;
		struct {
			struct struct_or_union *struct_or_union_0;
			Token literal_0;
			struct struct_declaration *struct_declaration_0;
			struct struct_or_union_specifierRepetition1 *struct_or_union_specifierRepetition1_0;
			Token literal_1;

		} choice1;
		struct {
			struct struct_or_union *struct_or_union_0;
			Token IDENTIFIER_0;
		} choice2;
	};
} struct_or_union_specifier;
struct struct_or_union_specifier *verbum_ast_new_struct_or_union_specifier_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct struct_or_union_specifierRepetition0 *struct_or_union_specifierRepetition0_0, struct struct_declaration *struct_declaration_0, struct struct_or_union *struct_or_union_0, Token IDENTIFIER_0);
struct struct_or_union_specifier *verbum_ast_new_struct_or_union_specifier_choice1(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition1 *struct_or_union_specifierRepetition1_0, Token literal_0, Token literal_1, struct struct_declaration *struct_declaration_0, struct struct_or_union *struct_or_union_0);
struct struct_or_union_specifier *verbum_ast_new_struct_or_union_specifier_choice2(struct VerbumContext *ctx, struct struct_or_union *struct_or_union_0, Token IDENTIFIER_0);
void verbum_ast_delete_struct_or_union_specifier(struct VerbumContext *ctx, struct struct_or_union_specifier *d);
typedef enum struct_or_unionType {
	struct_or_unionType_0,
	struct_or_unionType_1,
} struct_or_unionType;
typedef struct struct_or_union {

	struct_or_unionType tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
	};
} struct_or_union;
struct struct_or_union *verbum_ast_new_struct_or_union_choice0(struct VerbumContext *ctx, Token literal_0);
struct struct_or_union *verbum_ast_new_struct_or_union_choice1(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_struct_or_union(struct VerbumContext *ctx, struct struct_or_union *d);
typedef struct struct_declaration {
	struct struct_declarationRepetition0 *struct_declarationRepetition0_0;
	struct struct_declarator_list *struct_declarator_list_0;
} struct_declaration;

struct struct_declaration *verbum_ast_new_struct_declaration(struct VerbumContext *ctx, struct struct_declarationRepetition0 *struct_declarationRepetition0_0, struct struct_declarator_list *struct_declarator_list_0);
void verbum_ast_delete_struct_declaration(struct VerbumContext *ctx, struct struct_declaration *d);
typedef enum specifier_qualifierType {
	specifier_qualifierType_0,
	specifier_qualifierType_1,
} specifier_qualifierType;
typedef struct specifier_qualifier {

	specifier_qualifierType tag;
	union {
		struct {
			struct type_specifier *type_specifier_0;
		} choice0;
		struct {
			struct type_qualifier *type_qualifier_0;
		} choice1;
	};
} specifier_qualifier;
struct specifier_qualifier *verbum_ast_new_specifier_qualifier_choice0(struct VerbumContext *ctx, struct type_specifier *type_specifier_0);
struct specifier_qualifier *verbum_ast_new_specifier_qualifier_choice1(struct VerbumContext *ctx, struct type_qualifier *type_qualifier_0);
void verbum_ast_delete_specifier_qualifier(struct VerbumContext *ctx, struct specifier_qualifier *d);
typedef struct struct_declarator_list {
	struct struct_declarator *struct_declarator_0;
	struct struct_declarator_listRepetition0 *struct_declarator_listRepetition0_0;
} struct_declarator_list;

struct struct_declarator_list *verbum_ast_new_struct_declarator_list(struct VerbumContext *ctx, struct struct_declarator *struct_declarator_0, struct struct_declarator_listRepetition0 *struct_declarator_listRepetition0_0);
void verbum_ast_delete_struct_declarator_list(struct VerbumContext *ctx, struct struct_declarator_list *d);
typedef enum struct_declaratorType {
	struct_declaratorType_0,
	struct_declaratorType_1,
} struct_declaratorType;
typedef struct struct_declarator {

	struct_declaratorType tag;
	union {
		struct {
			struct declarator *declarator_0;
		} choice0;
		struct {
			struct struct_declaratorOptional0 *struct_declaratorOptional0_0;
			Token literal_0;
			struct constant_expression *constant_expression_0;
		} choice1;
	};
} struct_declarator;
struct struct_declarator *verbum_ast_new_struct_declarator_choice0(struct VerbumContext *ctx, struct declarator *declarator_0);
struct struct_declarator *verbum_ast_new_struct_declarator_choice1(struct VerbumContext *ctx, Token literal_0, struct struct_declaratorOptional0 *struct_declaratorOptional0_0, struct constant_expression *constant_expression_0);
void verbum_ast_delete_struct_declarator(struct VerbumContext *ctx, struct struct_declarator *d);
typedef struct declarator {
	struct declaratorOptional0 *declaratorOptional0_0;
	struct direct_declarator *direct_declarator_0;
} declarator;

struct declarator *verbum_ast_new_declarator(struct VerbumContext *ctx, struct direct_declarator *direct_declarator_0, struct declaratorOptional0 *declaratorOptional0_0);
void verbum_ast_delete_declarator(struct VerbumContext *ctx, struct declarator *d);
typedef struct pointer {
	Token literal_0;
	struct pointerRepetition0 *pointerRepetition0_0;
	struct pointerOptional0 *pointerOptional0_0;
} pointer;

struct pointer *verbum_ast_new_pointer(struct VerbumContext *ctx, Token literal_0, struct pointerOptional0 *pointerOptional0_0, struct pointerRepetition0 *pointerRepetition0_0);
void verbum_ast_delete_pointer(struct VerbumContext *ctx, struct pointer *d);
typedef enum type_qualifierType {
	type_qualifierType_0,
	type_qualifierType_1,
} type_qualifierType;
typedef struct type_qualifier {

	type_qualifierType tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
	};
} type_qualifier;
struct type_qualifier *verbum_ast_new_type_qualifier_choice0(struct VerbumContext *ctx, Token literal_0);
struct type_qualifier *verbum_ast_new_type_qualifier_choice1(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_type_qualifier(struct VerbumContext *ctx, struct type_qualifier *d);
typedef struct direct_declarator {
	struct direct_declaratorGroup0 *direct_declaratorGroup0_0;
	struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0;
} direct_declarator;

struct direct_declarator *verbum_ast_new_direct_declarator(struct VerbumContext *ctx, struct direct_declaratorGroup0 *direct_declaratorGroup0_0, struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0);
void verbum_ast_delete_direct_declarator(struct VerbumContext *ctx, struct direct_declarator *d);
typedef struct constant_expression {
	struct conditional_expression *conditional_expression_0;
} constant_expression;

struct constant_expression *verbum_ast_new_constant_expression(struct VerbumContext *ctx, struct conditional_expression *conditional_expression_0);
void verbum_ast_delete_constant_expression(struct VerbumContext *ctx, struct constant_expression *d);
typedef struct conditional_expression {
	struct logical_or_expression *logical_or_expression_0;
	struct conditional_expressionOptional0 *conditional_expressionOptional0_0;
} conditional_expression;

struct conditional_expression *verbum_ast_new_conditional_expression(struct VerbumContext *ctx, struct conditional_expressionOptional0 *conditional_expressionOptional0_0, struct logical_or_expression *logical_or_expression_0);
void verbum_ast_delete_conditional_expression(struct VerbumContext *ctx, struct conditional_expression *d);
typedef struct logical_or_expression {
	struct logical_and_expression *logical_and_expression_0;
	struct logical_or_expressionRepetition0 *logical_or_expressionRepetition0_0;
} logical_or_expression;

struct logical_or_expression *verbum_ast_new_logical_or_expression(struct VerbumContext *ctx, struct logical_and_expression *logical_and_expression_0, struct logical_or_expressionRepetition0 *logical_or_expressionRepetition0_0);
void verbum_ast_delete_logical_or_expression(struct VerbumContext *ctx, struct logical_or_expression *d);
typedef struct logical_and_expression {
	struct inclusive_or_expression *inclusive_or_expression_0;
	struct logical_and_expressionRepetition0 *logical_and_expressionRepetition0_0;
} logical_and_expression;

struct logical_and_expression *verbum_ast_new_logical_and_expression(struct VerbumContext *ctx, struct logical_and_expressionRepetition0 *logical_and_expressionRepetition0_0, struct inclusive_or_expression *inclusive_or_expression_0);
void verbum_ast_delete_logical_and_expression(struct VerbumContext *ctx, struct logical_and_expression *d);
typedef struct inclusive_or_expression {
	struct exclusive_or_expression *exclusive_or_expression_0;
	struct inclusive_or_expressionRepetition0 *inclusive_or_expressionRepetition0_0;
} inclusive_or_expression;

struct inclusive_or_expression *verbum_ast_new_inclusive_or_expression(struct VerbumContext *ctx, struct inclusive_or_expressionRepetition0 *inclusive_or_expressionRepetition0_0, struct exclusive_or_expression *exclusive_or_expression_0);
void verbum_ast_delete_inclusive_or_expression(struct VerbumContext *ctx, struct inclusive_or_expression *d);
typedef struct exclusive_or_expression {
	struct and_expression *and_expression_0;
	struct exclusive_or_expressionRepetition0 *exclusive_or_expressionRepetition0_0;
} exclusive_or_expression;

struct exclusive_or_expression *verbum_ast_new_exclusive_or_expression(struct VerbumContext *ctx, struct exclusive_or_expressionRepetition0 *exclusive_or_expressionRepetition0_0, struct and_expression *and_expression_0);
void verbum_ast_delete_exclusive_or_expression(struct VerbumContext *ctx, struct exclusive_or_expression *d);
typedef struct and_expression {
	struct equality_expression *equality_expression_0;
	struct and_expressionRepetition0 *and_expressionRepetition0_0;
} and_expression;

struct and_expression *verbum_ast_new_and_expression(struct VerbumContext *ctx, struct and_expressionRepetition0 *and_expressionRepetition0_0, struct equality_expression *equality_expression_0);
void verbum_ast_delete_and_expression(struct VerbumContext *ctx, struct and_expression *d);
typedef struct equality_expression {
	struct relational_expression *relational_expression_0;
	struct equality_expressionRepetition0 *equality_expressionRepetition0_0;
} equality_expression;

struct equality_expression *verbum_ast_new_equality_expression(struct VerbumContext *ctx, struct relational_expression *relational_expression_0, struct equality_expressionRepetition0 *equality_expressionRepetition0_0);
void verbum_ast_delete_equality_expression(struct VerbumContext *ctx, struct equality_expression *d);
typedef struct relational_expression {
	struct shift_expression *shift_expression_0;
	struct relational_expressionRepetition0 *relational_expressionRepetition0_0;
} relational_expression;

struct relational_expression *verbum_ast_new_relational_expression(struct VerbumContext *ctx, struct shift_expression *shift_expression_0, struct relational_expressionRepetition0 *relational_expressionRepetition0_0);
void verbum_ast_delete_relational_expression(struct VerbumContext *ctx, struct relational_expression *d);
typedef struct shift_expression {
	struct additive_expression *additive_expression_0;
	struct shift_expressionRepetition0 *shift_expressionRepetition0_0;
} shift_expression;

struct shift_expression *verbum_ast_new_shift_expression(struct VerbumContext *ctx, struct shift_expressionRepetition0 *shift_expressionRepetition0_0, struct additive_expression *additive_expression_0);
void verbum_ast_delete_shift_expression(struct VerbumContext *ctx, struct shift_expression *d);
typedef struct additive_expression {
	struct multiplicative_expression *multiplicative_expression_0;
	struct additive_expressionRepetition0 *additive_expressionRepetition0_0;
} additive_expression;

struct additive_expression *verbum_ast_new_additive_expression(struct VerbumContext *ctx, struct additive_expressionRepetition0 *additive_expressionRepetition0_0, struct multiplicative_expression *multiplicative_expression_0);
void verbum_ast_delete_additive_expression(struct VerbumContext *ctx, struct additive_expression *d);
typedef struct multiplicative_expression {
	struct cast_expression *cast_expression_0;
	struct multiplicative_expressionRepetition0 *multiplicative_expressionRepetition0_0;
} multiplicative_expression;

struct multiplicative_expression *verbum_ast_new_multiplicative_expression(struct VerbumContext *ctx, struct cast_expression *cast_expression_0, struct multiplicative_expressionRepetition0 *multiplicative_expressionRepetition0_0);
void verbum_ast_delete_multiplicative_expression(struct VerbumContext *ctx, struct multiplicative_expression *d);
typedef enum cast_expressionType {
	cast_expressionType_0,
	cast_expressionType_1,
} cast_expressionType;
typedef struct cast_expression {

	cast_expressionType tag;
	union {
		struct {
			struct unary_expression *unary_expression_0;
		} choice0;
		struct {
			Token literal_0;
			struct type_name *type_name_0;
			Token literal_1;

			struct cast_expression *cast_expression_0;
		} choice1;
	};
} cast_expression;
struct cast_expression *verbum_ast_new_cast_expression_choice0(struct VerbumContext *ctx, struct unary_expression *unary_expression_0);
struct cast_expression *verbum_ast_new_cast_expression_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct type_name *type_name_0, struct cast_expression *cast_expression_0);
void verbum_ast_delete_cast_expression(struct VerbumContext *ctx, struct cast_expression *d);
typedef enum unary_expressionType {
	unary_expressionType_0,
	unary_expressionType_1,
	unary_expressionType_2,
	unary_expressionType_3,
	unary_expressionType_4,
} unary_expressionType;
typedef struct unary_expression {

	unary_expressionType tag;
	union {
		struct {
			struct postfix_expression *postfix_expression_0;
		} choice0;
		struct {
			Token literal_0;
			struct unary_expression *unary_expression_0;
		} choice1;
		struct {
			Token literal_0;
			struct unary_expression *unary_expression_0;
		} choice2;
		struct {
			struct unary_operator *unary_operator_0;
			struct cast_expression *cast_expression_0;
		} choice3;
		struct {
			Token literal_0;
			struct unary_expressionGroup0 *unary_expressionGroup0_0;
		} choice4;
	};
} unary_expression;
struct unary_expression *verbum_ast_new_unary_expression_choice0(struct VerbumContext *ctx, struct postfix_expression *postfix_expression_0);
struct unary_expression *verbum_ast_new_unary_expression_choice1(struct VerbumContext *ctx, Token literal_0, struct unary_expression *unary_expression_0);
struct unary_expression *verbum_ast_new_unary_expression_choice2(struct VerbumContext *ctx, Token literal_0, struct unary_expression *unary_expression_0);
struct unary_expression *verbum_ast_new_unary_expression_choice3(struct VerbumContext *ctx, struct unary_operator *unary_operator_0, struct cast_expression *cast_expression_0);
struct unary_expression *verbum_ast_new_unary_expression_choice4(struct VerbumContext *ctx, Token literal_0, struct unary_expressionGroup0 *unary_expressionGroup0_0);
void verbum_ast_delete_unary_expression(struct VerbumContext *ctx, struct unary_expression *d);
typedef struct postfix_expression {
	struct primary_expression *primary_expression_0;
	struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0;
} postfix_expression;

struct postfix_expression *verbum_ast_new_postfix_expression(struct VerbumContext *ctx, struct primary_expression *primary_expression_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0);
void verbum_ast_delete_postfix_expression(struct VerbumContext *ctx, struct postfix_expression *d);
typedef enum primary_expressionType {
	primary_expressionType_0,
	primary_expressionType_1,
	primary_expressionType_2,
	primary_expressionType_3,
} primary_expressionType;
typedef struct primary_expression {

	primary_expressionType tag;
	union {
		struct {
			Token IDENTIFIER_0;
		} choice0;
		struct {
			struct constant *constant_0;
		} choice1;
		struct {
			Token STRING_0;
		} choice2;
		struct {
			Token literal_0;
			struct expression *expression_0;
			Token literal_1;

		} choice3;
	};
} primary_expression;
struct primary_expression *verbum_ast_new_primary_expression_choice0(struct VerbumContext *ctx, Token IDENTIFIER_0);
struct primary_expression *verbum_ast_new_primary_expression_choice1(struct VerbumContext *ctx, struct constant *constant_0);
struct primary_expression *verbum_ast_new_primary_expression_choice2(struct VerbumContext *ctx, Token STRING_0);
struct primary_expression *verbum_ast_new_primary_expression_choice3(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0);
void verbum_ast_delete_primary_expression(struct VerbumContext *ctx, struct primary_expression *d);
typedef enum constantType {
	constantType_0,
	constantType_1,
	constantType_2,
	constantType_3,
} constantType;
typedef struct constant {

	constantType tag;
	union {
		struct {
			Token INTEGER_CONSTANT_0;
		} choice0;
		struct {
			Token CHARACTER_CONSTANT_0;
		} choice1;
		struct {
			Token FLOATING_CONSTANT_0;
		} choice2;
		struct {
			Token ENUMERATION_CONSTANT_0;
		} choice3;
	};
} constant;
struct constant *verbum_ast_new_constant_choice0(struct VerbumContext *ctx, Token INTEGER_CONSTANT_0);
struct constant *verbum_ast_new_constant_choice1(struct VerbumContext *ctx, Token CHARACTER_CONSTANT_0);
struct constant *verbum_ast_new_constant_choice2(struct VerbumContext *ctx, Token FLOATING_CONSTANT_0);
struct constant *verbum_ast_new_constant_choice3(struct VerbumContext *ctx, Token ENUMERATION_CONSTANT_0);
void verbum_ast_delete_constant(struct VerbumContext *ctx, struct constant *d);
typedef struct expression {
	struct assignment_expression *assignment_expression_0;
	struct expressionRepetition0 *expressionRepetition0_0;
} expression;

struct expression *verbum_ast_new_expression(struct VerbumContext *ctx, struct assignment_expression *assignment_expression_0, struct expressionRepetition0 *expressionRepetition0_0);
void verbum_ast_delete_expression(struct VerbumContext *ctx, struct expression *d);
typedef enum assignment_expressionType {
	assignment_expressionType_0,
	assignment_expressionType_1,
} assignment_expressionType;
typedef struct assignment_expression {

	assignment_expressionType tag;
	union {
		struct {
			struct conditional_expression *conditional_expression_0;
		} choice0;
		struct {
			struct unary_expression *unary_expression_0;
			struct assignment_operator *assignment_operator_0;
			struct assignment_expression *assignment_expression_0;
		} choice1;
	};
} assignment_expression;
struct assignment_expression *verbum_ast_new_assignment_expression_choice0(struct VerbumContext *ctx, struct conditional_expression *conditional_expression_0);
struct assignment_expression *verbum_ast_new_assignment_expression_choice1(struct VerbumContext *ctx, struct assignment_expression *assignment_expression_0, struct assignment_operator *assignment_operator_0, struct unary_expression *unary_expression_0);
void verbum_ast_delete_assignment_expression(struct VerbumContext *ctx, struct assignment_expression *d);
typedef enum assignment_operatorType {
	assignment_operatorType_0,
	assignment_operatorType_1,
	assignment_operatorType_2,
	assignment_operatorType_3,
	assignment_operatorType_4,
	assignment_operatorType_5,
	assignment_operatorType_6,
	assignment_operatorType_7,
	assignment_operatorType_8,
	assignment_operatorType_9,
	assignment_operatorType_10,
} assignment_operatorType;
typedef struct assignment_operator {

	assignment_operatorType tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
		struct {
			Token literal_0;
		} choice2;
		struct {
			Token literal_0;
		} choice3;
		struct {
			Token literal_0;
		} choice4;
		struct {
			Token literal_0;
		} choice5;
		struct {
			Token literal_0;
		} choice6;
		struct {
			Token literal_0;
		} choice7;
		struct {
			Token literal_0;
		} choice8;
		struct {
			Token literal_0;
		} choice9;
		struct {
			Token literal_0;
		} choice10;
	};
} assignment_operator;
struct assignment_operator *verbum_ast_new_assignment_operator_choice0(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice1(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice2(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice3(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice4(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice5(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice6(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice7(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice8(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice9(struct VerbumContext *ctx, Token literal_0);
struct assignment_operator *verbum_ast_new_assignment_operator_choice10(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_assignment_operator(struct VerbumContext *ctx, struct assignment_operator *d);
typedef enum unary_operatorType {
	unary_operatorType_0,
	unary_operatorType_1,
	unary_operatorType_2,
	unary_operatorType_3,
	unary_operatorType_4,
	unary_operatorType_5,
} unary_operatorType;
typedef struct unary_operator {

	unary_operatorType tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
		struct {
			Token literal_0;
		} choice2;
		struct {
			Token literal_0;
		} choice3;
		struct {
			Token literal_0;
		} choice4;
		struct {
			Token literal_0;
		} choice5;
	};
} unary_operator;
struct unary_operator *verbum_ast_new_unary_operator_choice0(struct VerbumContext *ctx, Token literal_0);
struct unary_operator *verbum_ast_new_unary_operator_choice1(struct VerbumContext *ctx, Token literal_0);
struct unary_operator *verbum_ast_new_unary_operator_choice2(struct VerbumContext *ctx, Token literal_0);
struct unary_operator *verbum_ast_new_unary_operator_choice3(struct VerbumContext *ctx, Token literal_0);
struct unary_operator *verbum_ast_new_unary_operator_choice4(struct VerbumContext *ctx, Token literal_0);
struct unary_operator *verbum_ast_new_unary_operator_choice5(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_unary_operator(struct VerbumContext *ctx, struct unary_operator *d);
typedef struct type_name {
	struct type_nameRepetition0 *type_nameRepetition0_0;
	struct type_nameOptional0 *type_nameOptional0_0;
} type_name;

struct type_name *verbum_ast_new_type_name(struct VerbumContext *ctx, struct type_nameRepetition0 *type_nameRepetition0_0, struct type_nameOptional0 *type_nameOptional0_0);
void verbum_ast_delete_type_name(struct VerbumContext *ctx, struct type_name *d);
typedef struct parameter_type_list {
	struct parameter_list *parameter_list_0;
	struct parameter_type_listOptional0 *parameter_type_listOptional0_0;
} parameter_type_list;

struct parameter_type_list *verbum_ast_new_parameter_type_list(struct VerbumContext *ctx, struct parameter_list *parameter_list_0, struct parameter_type_listOptional0 *parameter_type_listOptional0_0);
void verbum_ast_delete_parameter_type_list(struct VerbumContext *ctx, struct parameter_type_list *d);
typedef struct parameter_list {
	struct parameter_declaration *parameter_declaration_0;
	struct parameter_listRepetition0 *parameter_listRepetition0_0;
} parameter_list;

struct parameter_list *verbum_ast_new_parameter_list(struct VerbumContext *ctx, struct parameter_listRepetition0 *parameter_listRepetition0_0, struct parameter_declaration *parameter_declaration_0);
void verbum_ast_delete_parameter_list(struct VerbumContext *ctx, struct parameter_list *d);
typedef struct parameter_declaration {
	struct declaration_specifier *declaration_specifier_0;
	struct parameter_declarationRepetition0 *parameter_declarationRepetition0_0;
	struct parameter_declarationOptional0 *parameter_declarationOptional0_0;
} parameter_declaration;

struct parameter_declaration *verbum_ast_new_parameter_declaration(struct VerbumContext *ctx, struct parameter_declarationRepetition0 *parameter_declarationRepetition0_0, struct declaration_specifier *declaration_specifier_0, struct parameter_declarationOptional0 *parameter_declarationOptional0_0);
void verbum_ast_delete_parameter_declaration(struct VerbumContext *ctx, struct parameter_declaration *d);
typedef enum abstract_declaratorType {
	abstract_declaratorType_0,
	abstract_declaratorType_1,
} abstract_declaratorType;
typedef struct abstract_declarator {

	abstract_declaratorType tag;
	union {
		struct {
			struct pointer *pointer_0;
			struct abstract_declaratorOptional0 *abstract_declaratorOptional0_0;
		} choice0;
		struct {
			struct direct_abstract_declarator *direct_abstract_declarator_0;
		} choice1;
	};
} abstract_declarator;
struct abstract_declarator *verbum_ast_new_abstract_declarator_choice0(struct VerbumContext *ctx, struct abstract_declaratorOptional0 *abstract_declaratorOptional0_0, struct pointer *pointer_0);
struct abstract_declarator *verbum_ast_new_abstract_declarator_choice1(struct VerbumContext *ctx, struct direct_abstract_declarator *direct_abstract_declarator_0);
void verbum_ast_delete_abstract_declarator(struct VerbumContext *ctx, struct abstract_declarator *d);
typedef enum direct_abstract_declaratorType {
	direct_abstract_declaratorType_0,
	direct_abstract_declaratorType_1,
	direct_abstract_declaratorType_2,
} direct_abstract_declaratorType;
typedef struct direct_abstract_declarator {

	direct_abstract_declaratorType tag;
	union {
		struct {
			Token literal_0;
			struct abstract_declarator *abstract_declarator_0;
			Token literal_1;

		} choice0;
		struct {
			struct direct_abstract_declaratorOptional0 *direct_abstract_declaratorOptional0_0;
			Token literal_0;
			struct direct_abstract_declaratorOptional1 *direct_abstract_declaratorOptional1_0;
			Token literal_1;

		} choice1;
		struct {
			struct direct_abstract_declaratorOptional2 *direct_abstract_declaratorOptional2_0;
			Token literal_0;
			struct direct_abstract_declaratorOptional3 *direct_abstract_declaratorOptional3_0;
			Token literal_1;

		} choice2;
	};
} direct_abstract_declarator;
struct direct_abstract_declarator *verbum_ast_new_direct_abstract_declarator_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct abstract_declarator *abstract_declarator_0);
struct direct_abstract_declarator *verbum_ast_new_direct_abstract_declarator_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct direct_abstract_declaratorOptional1 *direct_abstract_declaratorOptional1_0, struct direct_abstract_declaratorOptional0 *direct_abstract_declaratorOptional0_0);
struct direct_abstract_declarator *verbum_ast_new_direct_abstract_declarator_choice2(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct direct_abstract_declaratorOptional2 *direct_abstract_declaratorOptional2_0, struct direct_abstract_declaratorOptional3 *direct_abstract_declaratorOptional3_0);
void verbum_ast_delete_direct_abstract_declarator(struct VerbumContext *ctx, struct direct_abstract_declarator *d);
typedef enum enum_specifierType {
	enum_specifierType_0,
	enum_specifierType_1,
} enum_specifierType;
typedef struct enum_specifier {

	enum_specifierType tag;
	union {
		struct {
			Token literal_0;
			struct enum_specifierOptional0 *enum_specifierOptional0_0;
			Token literal_1;

			struct enumerator_list *enumerator_list_0;
			Token literal_2;

		} choice0;
		struct {
			Token literal_0;
			Token IDENTIFIER_0;
		} choice1;
	};
} enum_specifier;
struct enum_specifier *verbum_ast_new_enum_specifier_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, struct enumerator_list *enumerator_list_0, struct enum_specifierOptional0 *enum_specifierOptional0_0);
struct enum_specifier *verbum_ast_new_enum_specifier_choice1(struct VerbumContext *ctx, Token literal_0, Token IDENTIFIER_0);
void verbum_ast_delete_enum_specifier(struct VerbumContext *ctx, struct enum_specifier *d);
typedef struct enumerator_list {
	struct enumerator *enumerator_0;
	struct enumerator_listRepetition0 *enumerator_listRepetition0_0;
} enumerator_list;

struct enumerator_list *verbum_ast_new_enumerator_list(struct VerbumContext *ctx, struct enumerator *enumerator_0, struct enumerator_listRepetition0 *enumerator_listRepetition0_0);
void verbum_ast_delete_enumerator_list(struct VerbumContext *ctx, struct enumerator_list *d);
typedef struct enumerator {
	Token IDENTIFIER_0;
	struct enumeratorOptional0 *enumeratorOptional0_0;
} enumerator;

struct enumerator *verbum_ast_new_enumerator(struct VerbumContext *ctx, Token IDENTIFIER_0, struct enumeratorOptional0 *enumeratorOptional0_0);
void verbum_ast_delete_enumerator(struct VerbumContext *ctx, struct enumerator *d);
typedef struct typedef_name {
	Token IDENTIFIER_0;
} typedef_name;

struct typedef_name *verbum_ast_new_typedef_name(struct VerbumContext *ctx, Token IDENTIFIER_0);
void verbum_ast_delete_typedef_name(struct VerbumContext *ctx, struct typedef_name *d);
typedef struct declaration {
	struct declarationRepetition0 *declarationRepetition0_0;
	struct declarationRepetition1 *declarationRepetition1_0;
	Token literal_0;
} declaration;

struct declaration *verbum_ast_new_declaration(struct VerbumContext *ctx, Token literal_0, struct declarationRepetition1 *declarationRepetition1_0, struct declarationRepetition0 *declarationRepetition0_0);
void verbum_ast_delete_declaration(struct VerbumContext *ctx, struct declaration *d);
typedef struct init_declarator {
	struct declarator *declarator_0;
	struct init_declaratorOptional0 *init_declaratorOptional0_0;
} init_declarator;

struct init_declarator *verbum_ast_new_init_declarator(struct VerbumContext *ctx, struct init_declaratorOptional0 *init_declaratorOptional0_0, struct declarator *declarator_0);
void verbum_ast_delete_init_declarator(struct VerbumContext *ctx, struct init_declarator *d);
typedef enum initializerType {
	initializerType_0,
	initializerType_1,
} initializerType;
typedef struct initializer {

	initializerType tag;
	union {
		struct {
			struct assignment_expression *assignment_expression_0;
		} choice0;
		struct {
			Token literal_0;
			struct initializer_list *initializer_list_0;
			struct initializerOptional0 *initializerOptional0_0;
			Token literal_1;

		} choice1;
	};
} initializer;
struct initializer *verbum_ast_new_initializer_choice0(struct VerbumContext *ctx, struct assignment_expression *assignment_expression_0);
struct initializer *verbum_ast_new_initializer_choice1(struct VerbumContext *ctx, struct initializer_list *initializer_list_0, Token literal_0, Token literal_1, struct initializerOptional0 *initializerOptional0_0);
void verbum_ast_delete_initializer(struct VerbumContext *ctx, struct initializer *d);
typedef struct initializer_list {
	struct initializer *initializer_0;
	struct initializer_listRepetition0 *initializer_listRepetition0_0;
} initializer_list;

struct initializer_list *verbum_ast_new_initializer_list(struct VerbumContext *ctx, struct initializer *initializer_0, struct initializer_listRepetition0 *initializer_listRepetition0_0);
void verbum_ast_delete_initializer_list(struct VerbumContext *ctx, struct initializer_list *d);
typedef struct compound_statement {
	Token literal_0;
	struct compound_statementRepetition0 *compound_statementRepetition0_0;
	struct compound_statementRepetition1 *compound_statementRepetition1_0;
	Token literal_1;

} compound_statement;

struct compound_statement *verbum_ast_new_compound_statement(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct compound_statementRepetition0 *compound_statementRepetition0_0, struct compound_statementRepetition1 *compound_statementRepetition1_0);
void verbum_ast_delete_compound_statement(struct VerbumContext *ctx, struct compound_statement *d);
typedef enum statementType {
	statementType_0,
	statementType_1,
	statementType_2,
	statementType_3,
	statementType_4,
	statementType_5,
} statementType;
typedef struct statement {

	statementType tag;
	union {
		struct {
			struct labeled_statement *labeled_statement_0;
		} choice0;
		struct {
			struct expression_statement *expression_statement_0;
		} choice1;
		struct {
			struct compound_statement *compound_statement_0;
		} choice2;
		struct {
			struct selection_statement *selection_statement_0;
		} choice3;
		struct {
			struct iteration_statement *iteration_statement_0;
		} choice4;
		struct {
			struct jump_statement *jump_statement_0;
		} choice5;
	};
} statement;
struct statement *verbum_ast_new_statement_choice0(struct VerbumContext *ctx, struct labeled_statement *labeled_statement_0);
struct statement *verbum_ast_new_statement_choice1(struct VerbumContext *ctx, struct expression_statement *expression_statement_0);
struct statement *verbum_ast_new_statement_choice2(struct VerbumContext *ctx, struct compound_statement *compound_statement_0);
struct statement *verbum_ast_new_statement_choice3(struct VerbumContext *ctx, struct selection_statement *selection_statement_0);
struct statement *verbum_ast_new_statement_choice4(struct VerbumContext *ctx, struct iteration_statement *iteration_statement_0);
struct statement *verbum_ast_new_statement_choice5(struct VerbumContext *ctx, struct jump_statement *jump_statement_0);
void verbum_ast_delete_statement(struct VerbumContext *ctx, struct statement *d);
typedef enum labeled_statementType {
	labeled_statementType_0,
	labeled_statementType_1,
	labeled_statementType_2,
} labeled_statementType;
typedef struct labeled_statement {

	labeled_statementType tag;
	union {
		struct {
			Token IDENTIFIER_0;
			Token literal_0;
			struct statement *statement_0;
		} choice0;
		struct {
			Token literal_0;
			struct constant_expression *constant_expression_0;
			Token literal_1;

			struct statement *statement_0;
		} choice1;
		struct {
			Token literal_0;
			Token literal_1;

			struct statement *statement_0;
		} choice2;
	};
} labeled_statement;
struct labeled_statement *verbum_ast_new_labeled_statement_choice0(struct VerbumContext *ctx, Token literal_0, struct statement *statement_0, Token IDENTIFIER_0);
struct labeled_statement *verbum_ast_new_labeled_statement_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct statement *statement_0, struct constant_expression *constant_expression_0);
struct labeled_statement *verbum_ast_new_labeled_statement_choice2(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct statement *statement_0);
void verbum_ast_delete_labeled_statement(struct VerbumContext *ctx, struct labeled_statement *d);
typedef struct expression_statement {
	struct expression_statementOptional0 *expression_statementOptional0_0;
	Token literal_0;
} expression_statement;

struct expression_statement *verbum_ast_new_expression_statement(struct VerbumContext *ctx, Token literal_0, struct expression_statementOptional0 *expression_statementOptional0_0);
void verbum_ast_delete_expression_statement(struct VerbumContext *ctx, struct expression_statement *d);
typedef enum selection_statementType {
	selection_statementType_0,
	selection_statementType_1,
} selection_statementType;
typedef struct selection_statement {

	selection_statementType tag;
	union {
		struct {
			Token literal_0;
			Token literal_1;

			struct expression *expression_0;
			Token literal_2;

			struct statement *statement_0;
			struct selection_statementOptional0 *selection_statementOptional0_0;
		} choice0;
		struct {
			Token literal_0;
			Token literal_1;

			struct expression *expression_0;
			Token literal_2;

			struct statement *statement_0;
		} choice1;
	};
} selection_statement;
struct selection_statement *verbum_ast_new_selection_statement_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, struct expression *expression_0, struct selection_statementOptional0 *selection_statementOptional0_0, struct statement *statement_0);
struct selection_statement *verbum_ast_new_selection_statement_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, struct expression *expression_0, struct statement *statement_0);
void verbum_ast_delete_selection_statement(struct VerbumContext *ctx, struct selection_statement *d);
typedef enum iteration_statementType {
	iteration_statementType_0,
	iteration_statementType_1,
	iteration_statementType_2,
} iteration_statementType;
typedef struct iteration_statement {

	iteration_statementType tag;
	union {
		struct {
			Token literal_0;
			Token literal_1;

			struct expression *expression_0;
			Token literal_2;

			struct statement *statement_0;
		} choice0;
		struct {
			Token literal_0;
			struct statement *statement_0;
			Token literal_1;

			Token literal_2;

			struct expression *expression_0;
			Token literal_3;

			Token literal_4;

		} choice1;
		struct {
			Token literal_0;
			Token literal_1;

			struct iteration_statementOptional0 *iteration_statementOptional0_0;
			Token literal_2;

			struct iteration_statementOptional1 *iteration_statementOptional1_0;
			Token literal_3;

			struct iteration_statementOptional2 *iteration_statementOptional2_0;
			Token literal_4;

			struct statement *statement_0;
		} choice2;
	};
} iteration_statement;
struct iteration_statement *verbum_ast_new_iteration_statement_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, struct expression *expression_0, struct statement *statement_0);
struct iteration_statement *verbum_ast_new_iteration_statement_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, Token literal_3, Token literal_4, struct expression *expression_0, struct statement *statement_0);
struct iteration_statement *verbum_ast_new_iteration_statement_choice2(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token literal_2, Token literal_3, Token literal_4, struct iteration_statementOptional2 *iteration_statementOptional2_0, struct statement *statement_0, struct iteration_statementOptional0 *iteration_statementOptional0_0, struct iteration_statementOptional1 *iteration_statementOptional1_0);
void verbum_ast_delete_iteration_statement(struct VerbumContext *ctx, struct iteration_statement *d);
typedef enum jump_statementType {
	jump_statementType_0,
	jump_statementType_1,
	jump_statementType_2,
	jump_statementType_3,
} jump_statementType;
typedef struct jump_statement {

	jump_statementType tag;
	union {
		struct {
			Token literal_0;
			Token IDENTIFIER_0;
			Token literal_1;

		} choice0;
		struct {
			Token literal_0;
			Token literal_1;

		} choice1;
		struct {
			Token literal_0;
			Token literal_1;

		} choice2;
		struct {
			Token literal_0;
			struct jump_statementOptional0 *jump_statementOptional0_0;
			Token literal_1;

		} choice3;
	};
} jump_statement;
struct jump_statement *verbum_ast_new_jump_statement_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, Token IDENTIFIER_0);
struct jump_statement *verbum_ast_new_jump_statement_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1);
struct jump_statement *verbum_ast_new_jump_statement_choice2(struct VerbumContext *ctx, Token literal_0, Token literal_1);
struct jump_statement *verbum_ast_new_jump_statement_choice3(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct jump_statementOptional0 *jump_statementOptional0_0);
void verbum_ast_delete_jump_statement(struct VerbumContext *ctx, struct jump_statement *d);
typedef enum translation_unitRepetition0Type {
	translation_unitRepetition0Type_0,
	translation_unitRepetition0Type_1,
} translation_unitRepetition0Type;
typedef struct translation_unitRepetition0 {

	translation_unitRepetition0Type tag;
	union {
		struct {
			struct external_declaration *external_declaration_0;
			struct translation_unitRepetition0 *translation_unitRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} translation_unitRepetition0;
struct translation_unitRepetition0 *verbum_ast_new_translation_unitRepetition0_choice0(struct VerbumContext *ctx, struct translation_unitRepetition0 *translation_unitRepetition0_0, struct external_declaration *external_declaration_0);
struct translation_unitRepetition0 *verbum_ast_new_translation_unitRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_translation_unitRepetition0(struct VerbumContext *ctx, struct translation_unitRepetition0 *d);
typedef enum function_definitionRepetition0Type {
	function_definitionRepetition0Type_0,
	function_definitionRepetition0Type_1,
} function_definitionRepetition0Type;
typedef struct function_definitionRepetition0 {

	function_definitionRepetition0Type tag;
	union {
		struct {
			struct declaration_specifier *declaration_specifier_0;
			struct function_definitionRepetition0 *function_definitionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} function_definitionRepetition0;
struct function_definitionRepetition0 *verbum_ast_new_function_definitionRepetition0_choice0(struct VerbumContext *ctx, struct function_definitionRepetition0 *function_definitionRepetition0_0, struct declaration_specifier *declaration_specifier_0);
struct function_definitionRepetition0 *verbum_ast_new_function_definitionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_function_definitionRepetition0(struct VerbumContext *ctx, struct function_definitionRepetition0 *d);
typedef enum function_definitionRepetition1Type {
	function_definitionRepetition1Type_0,
	function_definitionRepetition1Type_1,
} function_definitionRepetition1Type;
typedef struct function_definitionRepetition1 {

	function_definitionRepetition1Type tag;
	union {
		struct {
			struct declaration *declaration_0;
			struct function_definitionRepetition1 *function_definitionRepetition1_0;
		} choice0;
		struct {
		} choice1;
	};
} function_definitionRepetition1;
struct function_definitionRepetition1 *verbum_ast_new_function_definitionRepetition1_choice0(struct VerbumContext *ctx, struct declaration *declaration_0, struct function_definitionRepetition1 *function_definitionRepetition1_0);
struct function_definitionRepetition1 *verbum_ast_new_function_definitionRepetition1_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_function_definitionRepetition1(struct VerbumContext *ctx, struct function_definitionRepetition1 *d);
typedef enum struct_or_union_specifierRepetition0Type {
	struct_or_union_specifierRepetition0Type_0,
	struct_or_union_specifierRepetition0Type_1,
} struct_or_union_specifierRepetition0Type;
typedef struct struct_or_union_specifierRepetition0 {

	struct_or_union_specifierRepetition0Type tag;
	union {
		struct {
			struct struct_declaration *struct_declaration_0;
			struct struct_or_union_specifierRepetition0 *struct_or_union_specifierRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} struct_or_union_specifierRepetition0;
struct struct_or_union_specifierRepetition0 *verbum_ast_new_struct_or_union_specifierRepetition0_choice0(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition0 *struct_or_union_specifierRepetition0_0, struct struct_declaration *struct_declaration_0);
struct struct_or_union_specifierRepetition0 *verbum_ast_new_struct_or_union_specifierRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_struct_or_union_specifierRepetition0(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition0 *d);
typedef enum struct_or_union_specifierRepetition1Type {
	struct_or_union_specifierRepetition1Type_0,
	struct_or_union_specifierRepetition1Type_1,
} struct_or_union_specifierRepetition1Type;
typedef struct struct_or_union_specifierRepetition1 {

	struct_or_union_specifierRepetition1Type tag;
	union {
		struct {
			struct struct_declaration *struct_declaration_0;
			struct struct_or_union_specifierRepetition1 *struct_or_union_specifierRepetition1_0;
		} choice0;
		struct {
		} choice1;
	};
} struct_or_union_specifierRepetition1;
struct struct_or_union_specifierRepetition1 *verbum_ast_new_struct_or_union_specifierRepetition1_choice0(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition1 *struct_or_union_specifierRepetition1_0, struct struct_declaration *struct_declaration_0);
struct struct_or_union_specifierRepetition1 *verbum_ast_new_struct_or_union_specifierRepetition1_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_struct_or_union_specifierRepetition1(struct VerbumContext *ctx, struct struct_or_union_specifierRepetition1 *d);
typedef enum struct_declarationRepetition0Type {
	struct_declarationRepetition0Type_0,
	struct_declarationRepetition0Type_1,
} struct_declarationRepetition0Type;
typedef struct struct_declarationRepetition0 {

	struct_declarationRepetition0Type tag;
	union {
		struct {
			struct specifier_qualifier *specifier_qualifier_0;
			struct struct_declarationRepetition0 *struct_declarationRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} struct_declarationRepetition0;
struct struct_declarationRepetition0 *verbum_ast_new_struct_declarationRepetition0_choice0(struct VerbumContext *ctx, struct struct_declarationRepetition0 *struct_declarationRepetition0_0, struct specifier_qualifier *specifier_qualifier_0);
struct struct_declarationRepetition0 *verbum_ast_new_struct_declarationRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_struct_declarationRepetition0(struct VerbumContext *ctx, struct struct_declarationRepetition0 *d);
typedef enum struct_declarator_listRepetition0Type {
	struct_declarator_listRepetition0Type_0,
	struct_declarator_listRepetition0Type_1,
} struct_declarator_listRepetition0Type;
typedef struct struct_declarator_listRepetition0 {

	struct_declarator_listRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct struct_declarator *struct_declarator_0;
			struct struct_declarator_listRepetition0 *struct_declarator_listRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} struct_declarator_listRepetition0;
struct struct_declarator_listRepetition0 *verbum_ast_new_struct_declarator_listRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct struct_declarator *struct_declarator_0, struct struct_declarator_listRepetition0 *struct_declarator_listRepetition0_0);
struct struct_declarator_listRepetition0 *verbum_ast_new_struct_declarator_listRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_struct_declarator_listRepetition0(struct VerbumContext *ctx, struct struct_declarator_listRepetition0 *d);
typedef enum struct_declaratorOptional0Type {
	struct_declaratorOptional0Type_0,
	struct_declaratorOptional0Type_1,
} struct_declaratorOptional0Type;
typedef struct struct_declaratorOptional0 {

	struct_declaratorOptional0Type tag;
	union {
		struct {
			struct declarator *declarator_0;
		} choice0;
		struct {
		} choice1;
	};
} struct_declaratorOptional0;
struct struct_declaratorOptional0 *verbum_ast_new_struct_declaratorOptional0_choice0(struct VerbumContext *ctx, struct declarator *declarator_0);
struct struct_declaratorOptional0 *verbum_ast_new_struct_declaratorOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_struct_declaratorOptional0(struct VerbumContext *ctx, struct struct_declaratorOptional0 *d);
typedef enum declaratorOptional0Type {
	declaratorOptional0Type_0,
	declaratorOptional0Type_1,
} declaratorOptional0Type;
typedef struct declaratorOptional0 {

	declaratorOptional0Type tag;
	union {
		struct {
			struct pointer *pointer_0;
		} choice0;
		struct {
		} choice1;
	};
} declaratorOptional0;
struct declaratorOptional0 *verbum_ast_new_declaratorOptional0_choice0(struct VerbumContext *ctx, struct pointer *pointer_0);
struct declaratorOptional0 *verbum_ast_new_declaratorOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_declaratorOptional0(struct VerbumContext *ctx, struct declaratorOptional0 *d);
typedef enum pointerRepetition0Type {
	pointerRepetition0Type_0,
	pointerRepetition0Type_1,
} pointerRepetition0Type;
typedef struct pointerRepetition0 {

	pointerRepetition0Type tag;
	union {
		struct {
			struct type_qualifier *type_qualifier_0;
			struct pointerRepetition0 *pointerRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} pointerRepetition0;
struct pointerRepetition0 *verbum_ast_new_pointerRepetition0_choice0(struct VerbumContext *ctx, struct type_qualifier *type_qualifier_0, struct pointerRepetition0 *pointerRepetition0_0);
struct pointerRepetition0 *verbum_ast_new_pointerRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_pointerRepetition0(struct VerbumContext *ctx, struct pointerRepetition0 *d);
typedef enum pointerOptional0Type {
	pointerOptional0Type_0,
	pointerOptional0Type_1,
} pointerOptional0Type;
typedef struct pointerOptional0 {

	pointerOptional0Type tag;
	union {
		struct {
			struct pointer *pointer_0;
		} choice0;
		struct {
		} choice1;
	};
} pointerOptional0;
struct pointerOptional0 *verbum_ast_new_pointerOptional0_choice0(struct VerbumContext *ctx, struct pointer *pointer_0);
struct pointerOptional0 *verbum_ast_new_pointerOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_pointerOptional0(struct VerbumContext *ctx, struct pointerOptional0 *d);
typedef enum direct_declaratorGroup0Type {
	direct_declaratorGroup0Type_0,
	direct_declaratorGroup0Type_1,
} direct_declaratorGroup0Type;
typedef struct direct_declaratorGroup0 {

	direct_declaratorGroup0Type tag;
	union {
		struct {
			Token IDENTIFIER_0;
		} choice0;
		struct {
			Token literal_0;
			struct declarator *declarator_0;
			Token literal_1;

		} choice1;
	};
} direct_declaratorGroup0;
struct direct_declaratorGroup0 *verbum_ast_new_direct_declaratorGroup0_choice0(struct VerbumContext *ctx, Token IDENTIFIER_0);
struct direct_declaratorGroup0 *verbum_ast_new_direct_declaratorGroup0_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct declarator *declarator_0);
void verbum_ast_delete_direct_declaratorGroup0(struct VerbumContext *ctx, struct direct_declaratorGroup0 *d);
typedef enum direct_declaratorOptional0Type {
	direct_declaratorOptional0Type_0,
	direct_declaratorOptional0Type_1,
} direct_declaratorOptional0Type;
typedef struct direct_declaratorOptional0 {

	direct_declaratorOptional0Type tag;
	union {
		struct {
			struct constant_expression *constant_expression_0;
		} choice0;
		struct {
		} choice1;
	};
} direct_declaratorOptional0;
struct direct_declaratorOptional0 *verbum_ast_new_direct_declaratorOptional0_choice0(struct VerbumContext *ctx, struct constant_expression *constant_expression_0);
struct direct_declaratorOptional0 *verbum_ast_new_direct_declaratorOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_direct_declaratorOptional0(struct VerbumContext *ctx, struct direct_declaratorOptional0 *d);
typedef enum direct_declaratorRepetition1Type {
	direct_declaratorRepetition1Type_0,
	direct_declaratorRepetition1Type_1,
} direct_declaratorRepetition1Type;
typedef struct direct_declaratorRepetition1 {

	direct_declaratorRepetition1Type tag;
	union {
		struct {
			Token IDENTIFIER_0;
			struct direct_declaratorRepetition1 *direct_declaratorRepetition1_0;
		} choice0;
		struct {
		} choice1;
	};
} direct_declaratorRepetition1;
struct direct_declaratorRepetition1 *verbum_ast_new_direct_declaratorRepetition1_choice0(struct VerbumContext *ctx, struct direct_declaratorRepetition1 *direct_declaratorRepetition1_0, Token IDENTIFIER_0);
struct direct_declaratorRepetition1 *verbum_ast_new_direct_declaratorRepetition1_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_direct_declaratorRepetition1(struct VerbumContext *ctx, struct direct_declaratorRepetition1 *d);
typedef enum direct_declaratorRepetition0Type {
	direct_declaratorRepetition0Type_0,
	direct_declaratorRepetition0Type_1,
	direct_declaratorRepetition0Type_2,
	direct_declaratorRepetition0Type_3,
} direct_declaratorRepetition0Type;
typedef struct direct_declaratorRepetition0 {

	direct_declaratorRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct direct_declaratorOptional0 *direct_declaratorOptional0_0;
			Token literal_1;

			struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0;
		} choice0;
		struct {
			Token literal_0;
			struct parameter_type_list *parameter_type_list_0;
			Token literal_1;

			struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0;
		} choice1;
		struct {
			Token literal_0;
			struct direct_declaratorRepetition1 *direct_declaratorRepetition1_0;
			Token literal_1;

			struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0;
		} choice2;
		struct {
		} choice3;
	};
} direct_declaratorRepetition0;
struct direct_declaratorRepetition0 *verbum_ast_new_direct_declaratorRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct direct_declaratorOptional0 *direct_declaratorOptional0_0, struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0);
struct direct_declaratorRepetition0 *verbum_ast_new_direct_declaratorRepetition0_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct parameter_type_list *parameter_type_list_0, struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0);
struct direct_declaratorRepetition0 *verbum_ast_new_direct_declaratorRepetition0_choice2(struct VerbumContext *ctx, struct direct_declaratorRepetition0 *direct_declaratorRepetition0_0, Token literal_0, Token literal_1, struct direct_declaratorRepetition1 *direct_declaratorRepetition1_0);
struct direct_declaratorRepetition0 *verbum_ast_new_direct_declaratorRepetition0_choice3(struct VerbumContext *ctx);
void verbum_ast_delete_direct_declaratorRepetition0(struct VerbumContext *ctx, struct direct_declaratorRepetition0 *d);
typedef enum conditional_expressionOptional0Type {
	conditional_expressionOptional0Type_0,
	conditional_expressionOptional0Type_1,
} conditional_expressionOptional0Type;
typedef struct conditional_expressionOptional0 {

	conditional_expressionOptional0Type tag;
	union {
		struct {
			Token literal_0;
			struct expression *expression_0;
			Token literal_1;

			struct conditional_expression *conditional_expression_0;
		} choice0;
		struct {
		} choice1;
	};
} conditional_expressionOptional0;
struct conditional_expressionOptional0 *verbum_ast_new_conditional_expressionOptional0_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0, struct conditional_expression *conditional_expression_0);
struct conditional_expressionOptional0 *verbum_ast_new_conditional_expressionOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_conditional_expressionOptional0(struct VerbumContext *ctx, struct conditional_expressionOptional0 *d);
typedef enum logical_or_expressionRepetition0Type {
	logical_or_expressionRepetition0Type_0,
	logical_or_expressionRepetition0Type_1,
} logical_or_expressionRepetition0Type;
typedef struct logical_or_expressionRepetition0 {

	logical_or_expressionRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct logical_and_expression *logical_and_expression_0;
			struct logical_or_expressionRepetition0 *logical_or_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} logical_or_expressionRepetition0;
struct logical_or_expressionRepetition0 *verbum_ast_new_logical_or_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct logical_and_expression *logical_and_expression_0, struct logical_or_expressionRepetition0 *logical_or_expressionRepetition0_0);
struct logical_or_expressionRepetition0 *verbum_ast_new_logical_or_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_logical_or_expressionRepetition0(struct VerbumContext *ctx, struct logical_or_expressionRepetition0 *d);
typedef enum logical_and_expressionRepetition0Type {
	logical_and_expressionRepetition0Type_0,
	logical_and_expressionRepetition0Type_1,
} logical_and_expressionRepetition0Type;
typedef struct logical_and_expressionRepetition0 {

	logical_and_expressionRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct inclusive_or_expression *inclusive_or_expression_0;
			struct logical_and_expressionRepetition0 *logical_and_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} logical_and_expressionRepetition0;
struct logical_and_expressionRepetition0 *verbum_ast_new_logical_and_expressionRepetition0_choice0(struct VerbumContext *ctx, struct logical_and_expressionRepetition0 *logical_and_expressionRepetition0_0, Token literal_0, struct inclusive_or_expression *inclusive_or_expression_0);
struct logical_and_expressionRepetition0 *verbum_ast_new_logical_and_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_logical_and_expressionRepetition0(struct VerbumContext *ctx, struct logical_and_expressionRepetition0 *d);
typedef enum inclusive_or_expressionRepetition0Type {
	inclusive_or_expressionRepetition0Type_0,
	inclusive_or_expressionRepetition0Type_1,
} inclusive_or_expressionRepetition0Type;
typedef struct inclusive_or_expressionRepetition0 {

	inclusive_or_expressionRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct exclusive_or_expression *exclusive_or_expression_0;
			struct inclusive_or_expressionRepetition0 *inclusive_or_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} inclusive_or_expressionRepetition0;
struct inclusive_or_expressionRepetition0 *verbum_ast_new_inclusive_or_expressionRepetition0_choice0(struct VerbumContext *ctx, struct inclusive_or_expressionRepetition0 *inclusive_or_expressionRepetition0_0, Token literal_0, struct exclusive_or_expression *exclusive_or_expression_0);
struct inclusive_or_expressionRepetition0 *verbum_ast_new_inclusive_or_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_inclusive_or_expressionRepetition0(struct VerbumContext *ctx, struct inclusive_or_expressionRepetition0 *d);
typedef enum exclusive_or_expressionRepetition0Type {
	exclusive_or_expressionRepetition0Type_0,
	exclusive_or_expressionRepetition0Type_1,
} exclusive_or_expressionRepetition0Type;
typedef struct exclusive_or_expressionRepetition0 {

	exclusive_or_expressionRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct and_expression *and_expression_0;
			struct exclusive_or_expressionRepetition0 *exclusive_or_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} exclusive_or_expressionRepetition0;
struct exclusive_or_expressionRepetition0 *verbum_ast_new_exclusive_or_expressionRepetition0_choice0(struct VerbumContext *ctx, struct exclusive_or_expressionRepetition0 *exclusive_or_expressionRepetition0_0, Token literal_0, struct and_expression *and_expression_0);
struct exclusive_or_expressionRepetition0 *verbum_ast_new_exclusive_or_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_exclusive_or_expressionRepetition0(struct VerbumContext *ctx, struct exclusive_or_expressionRepetition0 *d);
typedef enum and_expressionRepetition0Type {
	and_expressionRepetition0Type_0,
	and_expressionRepetition0Type_1,
} and_expressionRepetition0Type;
typedef struct and_expressionRepetition0 {

	and_expressionRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct equality_expression *equality_expression_0;
			struct and_expressionRepetition0 *and_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} and_expressionRepetition0;
struct and_expressionRepetition0 *verbum_ast_new_and_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct and_expressionRepetition0 *and_expressionRepetition0_0, struct equality_expression *equality_expression_0);
struct and_expressionRepetition0 *verbum_ast_new_and_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_and_expressionRepetition0(struct VerbumContext *ctx, struct and_expressionRepetition0 *d);
typedef enum equality_expressionGroup0Type {
	equality_expressionGroup0Type_0,
	equality_expressionGroup0Type_1,
} equality_expressionGroup0Type;
typedef struct equality_expressionGroup0 {

	equality_expressionGroup0Type tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
	};
} equality_expressionGroup0;
struct equality_expressionGroup0 *verbum_ast_new_equality_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0);
struct equality_expressionGroup0 *verbum_ast_new_equality_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_equality_expressionGroup0(struct VerbumContext *ctx, struct equality_expressionGroup0 *d);
typedef enum equality_expressionRepetition0Type {
	equality_expressionRepetition0Type_0,
	equality_expressionRepetition0Type_1,
} equality_expressionRepetition0Type;
typedef struct equality_expressionRepetition0 {

	equality_expressionRepetition0Type tag;
	union {
		struct {
			struct equality_expressionGroup0 *equality_expressionGroup0_0;
			struct relational_expression *relational_expression_0;
			struct equality_expressionRepetition0 *equality_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} equality_expressionRepetition0;
struct equality_expressionRepetition0 *verbum_ast_new_equality_expressionRepetition0_choice0(struct VerbumContext *ctx, struct relational_expression *relational_expression_0, struct equality_expressionGroup0 *equality_expressionGroup0_0, struct equality_expressionRepetition0 *equality_expressionRepetition0_0);
struct equality_expressionRepetition0 *verbum_ast_new_equality_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_equality_expressionRepetition0(struct VerbumContext *ctx, struct equality_expressionRepetition0 *d);
typedef enum relational_expressionGroup0Type {
	relational_expressionGroup0Type_0,
	relational_expressionGroup0Type_1,
	relational_expressionGroup0Type_2,
	relational_expressionGroup0Type_3,
} relational_expressionGroup0Type;
typedef struct relational_expressionGroup0 {

	relational_expressionGroup0Type tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
		struct {
			Token literal_0;
		} choice2;
		struct {
			Token literal_0;
		} choice3;
	};
} relational_expressionGroup0;
struct relational_expressionGroup0 *verbum_ast_new_relational_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0);
struct relational_expressionGroup0 *verbum_ast_new_relational_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0);
struct relational_expressionGroup0 *verbum_ast_new_relational_expressionGroup0_choice2(struct VerbumContext *ctx, Token literal_0);
struct relational_expressionGroup0 *verbum_ast_new_relational_expressionGroup0_choice3(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_relational_expressionGroup0(struct VerbumContext *ctx, struct relational_expressionGroup0 *d);
typedef enum relational_expressionRepetition0Type {
	relational_expressionRepetition0Type_0,
	relational_expressionRepetition0Type_1,
} relational_expressionRepetition0Type;
typedef struct relational_expressionRepetition0 {

	relational_expressionRepetition0Type tag;
	union {
		struct {
			struct relational_expressionGroup0 *relational_expressionGroup0_0;
			struct shift_expression *shift_expression_0;
			struct relational_expressionRepetition0 *relational_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} relational_expressionRepetition0;
struct relational_expressionRepetition0 *verbum_ast_new_relational_expressionRepetition0_choice0(struct VerbumContext *ctx, struct shift_expression *shift_expression_0, struct relational_expressionGroup0 *relational_expressionGroup0_0, struct relational_expressionRepetition0 *relational_expressionRepetition0_0);
struct relational_expressionRepetition0 *verbum_ast_new_relational_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_relational_expressionRepetition0(struct VerbumContext *ctx, struct relational_expressionRepetition0 *d);
typedef enum shift_expressionGroup0Type {
	shift_expressionGroup0Type_0,
	shift_expressionGroup0Type_1,
} shift_expressionGroup0Type;
typedef struct shift_expressionGroup0 {

	shift_expressionGroup0Type tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
	};
} shift_expressionGroup0;
struct shift_expressionGroup0 *verbum_ast_new_shift_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0);
struct shift_expressionGroup0 *verbum_ast_new_shift_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_shift_expressionGroup0(struct VerbumContext *ctx, struct shift_expressionGroup0 *d);
typedef enum shift_expressionRepetition0Type {
	shift_expressionRepetition0Type_0,
	shift_expressionRepetition0Type_1,
} shift_expressionRepetition0Type;
typedef struct shift_expressionRepetition0 {

	shift_expressionRepetition0Type tag;
	union {
		struct {
			struct shift_expressionGroup0 *shift_expressionGroup0_0;
			struct additive_expression *additive_expression_0;
			struct shift_expressionRepetition0 *shift_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} shift_expressionRepetition0;
struct shift_expressionRepetition0 *verbum_ast_new_shift_expressionRepetition0_choice0(struct VerbumContext *ctx, struct shift_expressionRepetition0 *shift_expressionRepetition0_0, struct shift_expressionGroup0 *shift_expressionGroup0_0, struct additive_expression *additive_expression_0);
struct shift_expressionRepetition0 *verbum_ast_new_shift_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_shift_expressionRepetition0(struct VerbumContext *ctx, struct shift_expressionRepetition0 *d);
typedef enum additive_expressionGroup0Type {
	additive_expressionGroup0Type_0,
	additive_expressionGroup0Type_1,
} additive_expressionGroup0Type;
typedef struct additive_expressionGroup0 {

	additive_expressionGroup0Type tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
	};
} additive_expressionGroup0;
struct additive_expressionGroup0 *verbum_ast_new_additive_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0);
struct additive_expressionGroup0 *verbum_ast_new_additive_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_additive_expressionGroup0(struct VerbumContext *ctx, struct additive_expressionGroup0 *d);
typedef enum additive_expressionRepetition0Type {
	additive_expressionRepetition0Type_0,
	additive_expressionRepetition0Type_1,
} additive_expressionRepetition0Type;
typedef struct additive_expressionRepetition0 {

	additive_expressionRepetition0Type tag;
	union {
		struct {
			struct additive_expressionGroup0 *additive_expressionGroup0_0;
			struct multiplicative_expression *multiplicative_expression_0;
			struct additive_expressionRepetition0 *additive_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} additive_expressionRepetition0;
struct additive_expressionRepetition0 *verbum_ast_new_additive_expressionRepetition0_choice0(struct VerbumContext *ctx, struct additive_expressionRepetition0 *additive_expressionRepetition0_0, struct additive_expressionGroup0 *additive_expressionGroup0_0, struct multiplicative_expression *multiplicative_expression_0);
struct additive_expressionRepetition0 *verbum_ast_new_additive_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_additive_expressionRepetition0(struct VerbumContext *ctx, struct additive_expressionRepetition0 *d);
typedef enum multiplicative_expressionGroup0Type {
	multiplicative_expressionGroup0Type_0,
	multiplicative_expressionGroup0Type_1,
	multiplicative_expressionGroup0Type_2,
} multiplicative_expressionGroup0Type;
typedef struct multiplicative_expressionGroup0 {

	multiplicative_expressionGroup0Type tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
			Token literal_0;
		} choice1;
		struct {
			Token literal_0;
		} choice2;
	};
} multiplicative_expressionGroup0;
struct multiplicative_expressionGroup0 *verbum_ast_new_multiplicative_expressionGroup0_choice0(struct VerbumContext *ctx, Token literal_0);
struct multiplicative_expressionGroup0 *verbum_ast_new_multiplicative_expressionGroup0_choice1(struct VerbumContext *ctx, Token literal_0);
struct multiplicative_expressionGroup0 *verbum_ast_new_multiplicative_expressionGroup0_choice2(struct VerbumContext *ctx, Token literal_0);
void verbum_ast_delete_multiplicative_expressionGroup0(struct VerbumContext *ctx, struct multiplicative_expressionGroup0 *d);
typedef enum multiplicative_expressionRepetition0Type {
	multiplicative_expressionRepetition0Type_0,
	multiplicative_expressionRepetition0Type_1,
} multiplicative_expressionRepetition0Type;
typedef struct multiplicative_expressionRepetition0 {

	multiplicative_expressionRepetition0Type tag;
	union {
		struct {
			struct multiplicative_expressionGroup0 *multiplicative_expressionGroup0_0;
			struct cast_expression *cast_expression_0;
			struct multiplicative_expressionRepetition0 *multiplicative_expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} multiplicative_expressionRepetition0;
struct multiplicative_expressionRepetition0 *verbum_ast_new_multiplicative_expressionRepetition0_choice0(struct VerbumContext *ctx, struct multiplicative_expressionGroup0 *multiplicative_expressionGroup0_0, struct cast_expression *cast_expression_0, struct multiplicative_expressionRepetition0 *multiplicative_expressionRepetition0_0);
struct multiplicative_expressionRepetition0 *verbum_ast_new_multiplicative_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_multiplicative_expressionRepetition0(struct VerbumContext *ctx, struct multiplicative_expressionRepetition0 *d);
typedef enum unary_expressionGroup0Type {
	unary_expressionGroup0Type_0,
	unary_expressionGroup0Type_1,
} unary_expressionGroup0Type;
typedef struct unary_expressionGroup0 {

	unary_expressionGroup0Type tag;
	union {
		struct {
			struct unary_expression *unary_expression_0;
		} choice0;
		struct {
			struct type_name *type_name_0;
		} choice1;
	};
} unary_expressionGroup0;
struct unary_expressionGroup0 *verbum_ast_new_unary_expressionGroup0_choice0(struct VerbumContext *ctx, struct unary_expression *unary_expression_0);
struct unary_expressionGroup0 *verbum_ast_new_unary_expressionGroup0_choice1(struct VerbumContext *ctx, struct type_name *type_name_0);
void verbum_ast_delete_unary_expressionGroup0(struct VerbumContext *ctx, struct unary_expressionGroup0 *d);
typedef enum postfix_expressionRepetition1Type {
	postfix_expressionRepetition1Type_0,
	postfix_expressionRepetition1Type_1,
} postfix_expressionRepetition1Type;
typedef struct postfix_expressionRepetition1 {

	postfix_expressionRepetition1Type tag;
	union {
		struct {
			struct assignment_expression *assignment_expression_0;
			struct postfix_expressionRepetition1 *postfix_expressionRepetition1_0;
		} choice0;
		struct {
		} choice1;
	};
} postfix_expressionRepetition1;
struct postfix_expressionRepetition1 *verbum_ast_new_postfix_expressionRepetition1_choice0(struct VerbumContext *ctx, struct assignment_expression *assignment_expression_0, struct postfix_expressionRepetition1 *postfix_expressionRepetition1_0);
struct postfix_expressionRepetition1 *verbum_ast_new_postfix_expressionRepetition1_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_postfix_expressionRepetition1(struct VerbumContext *ctx, struct postfix_expressionRepetition1 *d);
typedef enum postfix_expressionRepetition0Type {
	postfix_expressionRepetition0Type_0,
	postfix_expressionRepetition0Type_1,
	postfix_expressionRepetition0Type_2,
	postfix_expressionRepetition0Type_3,
	postfix_expressionRepetition0Type_4,
	postfix_expressionRepetition0Type_5,
	postfix_expressionRepetition0Type_6,
} postfix_expressionRepetition0Type;
typedef struct postfix_expressionRepetition0 {

	postfix_expressionRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct expression *expression_0;
			Token literal_1;

			struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0;
		} choice0;
		struct {
			Token literal_0;
			struct postfix_expressionRepetition1 *postfix_expressionRepetition1_0;
			Token literal_1;

			struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0;
		} choice1;
		struct {
			Token literal_0;
			Token IDENTIFIER_0;
			struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0;
		} choice2;
		struct {
			Token literal_0;
			Token IDENTIFIER_0;
			struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0;
		} choice3;
		struct {
			Token literal_0;
			struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0;
		} choice4;
		struct {
			Token literal_0;
			struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0;
		} choice5;
		struct {
		} choice6;
	};
} postfix_expressionRepetition0;
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct expression *expression_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0);
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice1(struct VerbumContext *ctx, Token literal_0, Token literal_1, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0, struct postfix_expressionRepetition1 *postfix_expressionRepetition1_0);
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice2(struct VerbumContext *ctx, Token literal_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0, Token IDENTIFIER_0);
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice3(struct VerbumContext *ctx, Token literal_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0, Token IDENTIFIER_0);
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice4(struct VerbumContext *ctx, Token literal_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0);
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice5(struct VerbumContext *ctx, Token literal_0, struct postfix_expressionRepetition0 *postfix_expressionRepetition0_0);
struct postfix_expressionRepetition0 *verbum_ast_new_postfix_expressionRepetition0_choice6(struct VerbumContext *ctx);
void verbum_ast_delete_postfix_expressionRepetition0(struct VerbumContext *ctx, struct postfix_expressionRepetition0 *d);
typedef enum expressionRepetition0Type {
	expressionRepetition0Type_0,
	expressionRepetition0Type_1,
} expressionRepetition0Type;
typedef struct expressionRepetition0 {

	expressionRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct assignment_expression *assignment_expression_0;
			struct expressionRepetition0 *expressionRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} expressionRepetition0;
struct expressionRepetition0 *verbum_ast_new_expressionRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct assignment_expression *assignment_expression_0, struct expressionRepetition0 *expressionRepetition0_0);
struct expressionRepetition0 *verbum_ast_new_expressionRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_expressionRepetition0(struct VerbumContext *ctx, struct expressionRepetition0 *d);
typedef enum type_nameRepetition0Type {
	type_nameRepetition0Type_0,
	type_nameRepetition0Type_1,
} type_nameRepetition0Type;
typedef struct type_nameRepetition0 {

	type_nameRepetition0Type tag;
	union {
		struct {
			struct specifier_qualifier *specifier_qualifier_0;
			struct type_nameRepetition0 *type_nameRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} type_nameRepetition0;
struct type_nameRepetition0 *verbum_ast_new_type_nameRepetition0_choice0(struct VerbumContext *ctx, struct type_nameRepetition0 *type_nameRepetition0_0, struct specifier_qualifier *specifier_qualifier_0);
struct type_nameRepetition0 *verbum_ast_new_type_nameRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_type_nameRepetition0(struct VerbumContext *ctx, struct type_nameRepetition0 *d);
typedef enum type_nameOptional0Type {
	type_nameOptional0Type_0,
	type_nameOptional0Type_1,
} type_nameOptional0Type;
typedef struct type_nameOptional0 {

	type_nameOptional0Type tag;
	union {
		struct {
			struct abstract_declarator *abstract_declarator_0;
		} choice0;
		struct {
		} choice1;
	};
} type_nameOptional0;
struct type_nameOptional0 *verbum_ast_new_type_nameOptional0_choice0(struct VerbumContext *ctx, struct abstract_declarator *abstract_declarator_0);
struct type_nameOptional0 *verbum_ast_new_type_nameOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_type_nameOptional0(struct VerbumContext *ctx, struct type_nameOptional0 *d);
typedef enum parameter_type_listOptional0Type {
	parameter_type_listOptional0Type_0,
	parameter_type_listOptional0Type_1,
} parameter_type_listOptional0Type;
typedef struct parameter_type_listOptional0 {

	parameter_type_listOptional0Type tag;
	union {
		struct {
			Token literal_0;
			Token literal_1;

		} choice0;
		struct {
		} choice1;
	};
} parameter_type_listOptional0;
struct parameter_type_listOptional0 *verbum_ast_new_parameter_type_listOptional0_choice0(struct VerbumContext *ctx, Token literal_0, Token literal_1);
struct parameter_type_listOptional0 *verbum_ast_new_parameter_type_listOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_parameter_type_listOptional0(struct VerbumContext *ctx, struct parameter_type_listOptional0 *d);
typedef enum parameter_listRepetition0Type {
	parameter_listRepetition0Type_0,
	parameter_listRepetition0Type_1,
} parameter_listRepetition0Type;
typedef struct parameter_listRepetition0 {

	parameter_listRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct parameter_declaration *parameter_declaration_0;
			struct parameter_listRepetition0 *parameter_listRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} parameter_listRepetition0;
struct parameter_listRepetition0 *verbum_ast_new_parameter_listRepetition0_choice0(struct VerbumContext *ctx, struct parameter_listRepetition0 *parameter_listRepetition0_0, struct parameter_declaration *parameter_declaration_0, Token literal_0);
struct parameter_listRepetition0 *verbum_ast_new_parameter_listRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_parameter_listRepetition0(struct VerbumContext *ctx, struct parameter_listRepetition0 *d);
typedef enum parameter_declarationRepetition0Type {
	parameter_declarationRepetition0Type_0,
	parameter_declarationRepetition0Type_1,
} parameter_declarationRepetition0Type;
typedef struct parameter_declarationRepetition0 {

	parameter_declarationRepetition0Type tag;
	union {
		struct {
			struct declaration_specifier *declaration_specifier_0;
			struct parameter_declarationRepetition0 *parameter_declarationRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} parameter_declarationRepetition0;
struct parameter_declarationRepetition0 *verbum_ast_new_parameter_declarationRepetition0_choice0(struct VerbumContext *ctx, struct parameter_declarationRepetition0 *parameter_declarationRepetition0_0, struct declaration_specifier *declaration_specifier_0);
struct parameter_declarationRepetition0 *verbum_ast_new_parameter_declarationRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_parameter_declarationRepetition0(struct VerbumContext *ctx, struct parameter_declarationRepetition0 *d);
typedef enum parameter_declarationOptional0Type {
	parameter_declarationOptional0Type_0,
	parameter_declarationOptional0Type_1,
	parameter_declarationOptional0Type_2,
} parameter_declarationOptional0Type;
typedef struct parameter_declarationOptional0 {

	parameter_declarationOptional0Type tag;
	union {
		struct {
			struct declarator *declarator_0;
		} choice0;
		struct {
			struct abstract_declarator *abstract_declarator_0;
		} choice1;
		struct {
		} choice2;
	};
} parameter_declarationOptional0;
struct parameter_declarationOptional0 *verbum_ast_new_parameter_declarationOptional0_choice0(struct VerbumContext *ctx, struct declarator *declarator_0);
struct parameter_declarationOptional0 *verbum_ast_new_parameter_declarationOptional0_choice1(struct VerbumContext *ctx, struct abstract_declarator *abstract_declarator_0);
struct parameter_declarationOptional0 *verbum_ast_new_parameter_declarationOptional0_choice2(struct VerbumContext *ctx);
void verbum_ast_delete_parameter_declarationOptional0(struct VerbumContext *ctx, struct parameter_declarationOptional0 *d);
typedef enum abstract_declaratorOptional0Type {
	abstract_declaratorOptional0Type_0,
	abstract_declaratorOptional0Type_1,
} abstract_declaratorOptional0Type;
typedef struct abstract_declaratorOptional0 {

	abstract_declaratorOptional0Type tag;
	union {
		struct {
			struct direct_abstract_declarator *direct_abstract_declarator_0;
		} choice0;
		struct {
		} choice1;
	};
} abstract_declaratorOptional0;
struct abstract_declaratorOptional0 *verbum_ast_new_abstract_declaratorOptional0_choice0(struct VerbumContext *ctx, struct direct_abstract_declarator *direct_abstract_declarator_0);
struct abstract_declaratorOptional0 *verbum_ast_new_abstract_declaratorOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_abstract_declaratorOptional0(struct VerbumContext *ctx, struct abstract_declaratorOptional0 *d);
typedef enum direct_abstract_declaratorOptional0Type {
	direct_abstract_declaratorOptional0Type_0,
	direct_abstract_declaratorOptional0Type_1,
} direct_abstract_declaratorOptional0Type;
typedef struct direct_abstract_declaratorOptional0 {

	direct_abstract_declaratorOptional0Type tag;
	union {
		struct {
			struct direct_abstract_declarator *direct_abstract_declarator_0;
		} choice0;
		struct {
		} choice1;
	};
} direct_abstract_declaratorOptional0;
struct direct_abstract_declaratorOptional0 *verbum_ast_new_direct_abstract_declaratorOptional0_choice0(struct VerbumContext *ctx, struct direct_abstract_declarator *direct_abstract_declarator_0);
struct direct_abstract_declaratorOptional0 *verbum_ast_new_direct_abstract_declaratorOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_direct_abstract_declaratorOptional0(struct VerbumContext *ctx, struct direct_abstract_declaratorOptional0 *d);
typedef enum direct_abstract_declaratorOptional1Type {
	direct_abstract_declaratorOptional1Type_0,
	direct_abstract_declaratorOptional1Type_1,
} direct_abstract_declaratorOptional1Type;
typedef struct direct_abstract_declaratorOptional1 {

	direct_abstract_declaratorOptional1Type tag;
	union {
		struct {
			struct constant_expression *constant_expression_0;
		} choice0;
		struct {
		} choice1;
	};
} direct_abstract_declaratorOptional1;
struct direct_abstract_declaratorOptional1 *verbum_ast_new_direct_abstract_declaratorOptional1_choice0(struct VerbumContext *ctx, struct constant_expression *constant_expression_0);
struct direct_abstract_declaratorOptional1 *verbum_ast_new_direct_abstract_declaratorOptional1_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_direct_abstract_declaratorOptional1(struct VerbumContext *ctx, struct direct_abstract_declaratorOptional1 *d);
typedef enum direct_abstract_declaratorOptional2Type {
	direct_abstract_declaratorOptional2Type_0,
	direct_abstract_declaratorOptional2Type_1,
} direct_abstract_declaratorOptional2Type;
typedef struct direct_abstract_declaratorOptional2 {

	direct_abstract_declaratorOptional2Type tag;
	union {
		struct {
			struct direct_abstract_declarator *direct_abstract_declarator_0;
		} choice0;
		struct {
		} choice1;
	};
} direct_abstract_declaratorOptional2;
struct direct_abstract_declaratorOptional2 *verbum_ast_new_direct_abstract_declaratorOptional2_choice0(struct VerbumContext *ctx, struct direct_abstract_declarator *direct_abstract_declarator_0);
struct direct_abstract_declaratorOptional2 *verbum_ast_new_direct_abstract_declaratorOptional2_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_direct_abstract_declaratorOptional2(struct VerbumContext *ctx, struct direct_abstract_declaratorOptional2 *d);
typedef enum direct_abstract_declaratorOptional3Type {
	direct_abstract_declaratorOptional3Type_0,
	direct_abstract_declaratorOptional3Type_1,
} direct_abstract_declaratorOptional3Type;
typedef struct direct_abstract_declaratorOptional3 {

	direct_abstract_declaratorOptional3Type tag;
	union {
		struct {
			struct parameter_type_list *parameter_type_list_0;
		} choice0;
		struct {
		} choice1;
	};
} direct_abstract_declaratorOptional3;
struct direct_abstract_declaratorOptional3 *verbum_ast_new_direct_abstract_declaratorOptional3_choice0(struct VerbumContext *ctx, struct parameter_type_list *parameter_type_list_0);
struct direct_abstract_declaratorOptional3 *verbum_ast_new_direct_abstract_declaratorOptional3_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_direct_abstract_declaratorOptional3(struct VerbumContext *ctx, struct direct_abstract_declaratorOptional3 *d);
typedef enum enum_specifierOptional0Type {
	enum_specifierOptional0Type_0,
	enum_specifierOptional0Type_1,
} enum_specifierOptional0Type;
typedef struct enum_specifierOptional0 {

	enum_specifierOptional0Type tag;
	union {
		struct {
			Token IDENTIFIER_0;
		} choice0;
		struct {
		} choice1;
	};
} enum_specifierOptional0;
struct enum_specifierOptional0 *verbum_ast_new_enum_specifierOptional0_choice0(struct VerbumContext *ctx, Token IDENTIFIER_0);
struct enum_specifierOptional0 *verbum_ast_new_enum_specifierOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_enum_specifierOptional0(struct VerbumContext *ctx, struct enum_specifierOptional0 *d);
typedef enum enumerator_listRepetition0Type {
	enumerator_listRepetition0Type_0,
	enumerator_listRepetition0Type_1,
} enumerator_listRepetition0Type;
typedef struct enumerator_listRepetition0 {

	enumerator_listRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct enumerator *enumerator_0;
			struct enumerator_listRepetition0 *enumerator_listRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} enumerator_listRepetition0;
struct enumerator_listRepetition0 *verbum_ast_new_enumerator_listRepetition0_choice0(struct VerbumContext *ctx, struct enumerator *enumerator_0, struct enumerator_listRepetition0 *enumerator_listRepetition0_0, Token literal_0);
struct enumerator_listRepetition0 *verbum_ast_new_enumerator_listRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_enumerator_listRepetition0(struct VerbumContext *ctx, struct enumerator_listRepetition0 *d);
typedef enum enumeratorOptional0Type {
	enumeratorOptional0Type_0,
	enumeratorOptional0Type_1,
} enumeratorOptional0Type;
typedef struct enumeratorOptional0 {

	enumeratorOptional0Type tag;
	union {
		struct {
			Token literal_0;
			struct constant_expression *constant_expression_0;
		} choice0;
		struct {
		} choice1;
	};
} enumeratorOptional0;
struct enumeratorOptional0 *verbum_ast_new_enumeratorOptional0_choice0(struct VerbumContext *ctx, Token literal_0, struct constant_expression *constant_expression_0);
struct enumeratorOptional0 *verbum_ast_new_enumeratorOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_enumeratorOptional0(struct VerbumContext *ctx, struct enumeratorOptional0 *d);
typedef enum declarationRepetition0Type {
	declarationRepetition0Type_0,
	declarationRepetition0Type_1,
} declarationRepetition0Type;
typedef struct declarationRepetition0 {

	declarationRepetition0Type tag;
	union {
		struct {
			struct declaration_specifier *declaration_specifier_0;
			struct declarationRepetition0 *declarationRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} declarationRepetition0;
struct declarationRepetition0 *verbum_ast_new_declarationRepetition0_choice0(struct VerbumContext *ctx, struct declaration_specifier *declaration_specifier_0, struct declarationRepetition0 *declarationRepetition0_0);
struct declarationRepetition0 *verbum_ast_new_declarationRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_declarationRepetition0(struct VerbumContext *ctx, struct declarationRepetition0 *d);
typedef enum declarationRepetition1Type {
	declarationRepetition1Type_0,
	declarationRepetition1Type_1,
} declarationRepetition1Type;
typedef struct declarationRepetition1 {

	declarationRepetition1Type tag;
	union {
		struct {
			struct init_declarator *init_declarator_0;
			struct declarationRepetition1 *declarationRepetition1_0;
		} choice0;
		struct {
		} choice1;
	};
} declarationRepetition1;
struct declarationRepetition1 *verbum_ast_new_declarationRepetition1_choice0(struct VerbumContext *ctx, struct declarationRepetition1 *declarationRepetition1_0, struct init_declarator *init_declarator_0);
struct declarationRepetition1 *verbum_ast_new_declarationRepetition1_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_declarationRepetition1(struct VerbumContext *ctx, struct declarationRepetition1 *d);
typedef enum init_declaratorOptional0Type {
	init_declaratorOptional0Type_0,
	init_declaratorOptional0Type_1,
} init_declaratorOptional0Type;
typedef struct init_declaratorOptional0 {

	init_declaratorOptional0Type tag;
	union {
		struct {
			Token literal_0;
			struct initializer *initializer_0;
		} choice0;
		struct {
		} choice1;
	};
} init_declaratorOptional0;
struct init_declaratorOptional0 *verbum_ast_new_init_declaratorOptional0_choice0(struct VerbumContext *ctx, Token literal_0, struct initializer *initializer_0);
struct init_declaratorOptional0 *verbum_ast_new_init_declaratorOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_init_declaratorOptional0(struct VerbumContext *ctx, struct init_declaratorOptional0 *d);
typedef enum initializerOptional0Type {
	initializerOptional0Type_0,
	initializerOptional0Type_1,
} initializerOptional0Type;
typedef struct initializerOptional0 {

	initializerOptional0Type tag;
	union {
		struct {
			Token literal_0;
		} choice0;
		struct {
		} choice1;
	};
} initializerOptional0;
struct initializerOptional0 *verbum_ast_new_initializerOptional0_choice0(struct VerbumContext *ctx, Token literal_0);
struct initializerOptional0 *verbum_ast_new_initializerOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_initializerOptional0(struct VerbumContext *ctx, struct initializerOptional0 *d);
typedef enum initializer_listRepetition0Type {
	initializer_listRepetition0Type_0,
	initializer_listRepetition0Type_1,
} initializer_listRepetition0Type;
typedef struct initializer_listRepetition0 {

	initializer_listRepetition0Type tag;
	union {
		struct {
			Token literal_0;
			struct initializer *initializer_0;
			struct initializer_listRepetition0 *initializer_listRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} initializer_listRepetition0;
struct initializer_listRepetition0 *verbum_ast_new_initializer_listRepetition0_choice0(struct VerbumContext *ctx, Token literal_0, struct initializer *initializer_0, struct initializer_listRepetition0 *initializer_listRepetition0_0);
struct initializer_listRepetition0 *verbum_ast_new_initializer_listRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_initializer_listRepetition0(struct VerbumContext *ctx, struct initializer_listRepetition0 *d);
typedef enum compound_statementRepetition0Type {
	compound_statementRepetition0Type_0,
	compound_statementRepetition0Type_1,
} compound_statementRepetition0Type;
typedef struct compound_statementRepetition0 {

	compound_statementRepetition0Type tag;
	union {
		struct {
			struct declaration *declaration_0;
			struct compound_statementRepetition0 *compound_statementRepetition0_0;
		} choice0;
		struct {
		} choice1;
	};
} compound_statementRepetition0;
struct compound_statementRepetition0 *verbum_ast_new_compound_statementRepetition0_choice0(struct VerbumContext *ctx, struct declaration *declaration_0, struct compound_statementRepetition0 *compound_statementRepetition0_0);
struct compound_statementRepetition0 *verbum_ast_new_compound_statementRepetition0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_compound_statementRepetition0(struct VerbumContext *ctx, struct compound_statementRepetition0 *d);
typedef enum compound_statementRepetition1Type {
	compound_statementRepetition1Type_0,
	compound_statementRepetition1Type_1,
} compound_statementRepetition1Type;
typedef struct compound_statementRepetition1 {

	compound_statementRepetition1Type tag;
	union {
		struct {
			struct statement *statement_0;
			struct compound_statementRepetition1 *compound_statementRepetition1_0;
		} choice0;
		struct {
		} choice1;
	};
} compound_statementRepetition1;
struct compound_statementRepetition1 *verbum_ast_new_compound_statementRepetition1_choice0(struct VerbumContext *ctx, struct statement *statement_0, struct compound_statementRepetition1 *compound_statementRepetition1_0);
struct compound_statementRepetition1 *verbum_ast_new_compound_statementRepetition1_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_compound_statementRepetition1(struct VerbumContext *ctx, struct compound_statementRepetition1 *d);
typedef enum expression_statementOptional0Type {
	expression_statementOptional0Type_0,
	expression_statementOptional0Type_1,
} expression_statementOptional0Type;
typedef struct expression_statementOptional0 {

	expression_statementOptional0Type tag;
	union {
		struct {
			struct expression *expression_0;
		} choice0;
		struct {
		} choice1;
	};
} expression_statementOptional0;
struct expression_statementOptional0 *verbum_ast_new_expression_statementOptional0_choice0(struct VerbumContext *ctx, struct expression *expression_0);
struct expression_statementOptional0 *verbum_ast_new_expression_statementOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_expression_statementOptional0(struct VerbumContext *ctx, struct expression_statementOptional0 *d);
typedef enum selection_statementOptional0Type {
	selection_statementOptional0Type_0,
	selection_statementOptional0Type_1,
} selection_statementOptional0Type;
typedef struct selection_statementOptional0 {

	selection_statementOptional0Type tag;
	union {
		struct {
			Token literal_0;
			struct statement *statement_0;
		} choice0;
		struct {
		} choice1;
	};
} selection_statementOptional0;
struct selection_statementOptional0 *verbum_ast_new_selection_statementOptional0_choice0(struct VerbumContext *ctx, Token literal_0, struct statement *statement_0);
struct selection_statementOptional0 *verbum_ast_new_selection_statementOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_selection_statementOptional0(struct VerbumContext *ctx, struct selection_statementOptional0 *d);
typedef enum iteration_statementOptional0Type {
	iteration_statementOptional0Type_0,
	iteration_statementOptional0Type_1,
} iteration_statementOptional0Type;
typedef struct iteration_statementOptional0 {

	iteration_statementOptional0Type tag;
	union {
		struct {
			struct expression *expression_0;
		} choice0;
		struct {
		} choice1;
	};
} iteration_statementOptional0;
struct iteration_statementOptional0 *verbum_ast_new_iteration_statementOptional0_choice0(struct VerbumContext *ctx, struct expression *expression_0);
struct iteration_statementOptional0 *verbum_ast_new_iteration_statementOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_iteration_statementOptional0(struct VerbumContext *ctx, struct iteration_statementOptional0 *d);
typedef enum iteration_statementOptional1Type {
	iteration_statementOptional1Type_0,
	iteration_statementOptional1Type_1,
} iteration_statementOptional1Type;
typedef struct iteration_statementOptional1 {

	iteration_statementOptional1Type tag;
	union {
		struct {
			struct expression *expression_0;
		} choice0;
		struct {
		} choice1;
	};
} iteration_statementOptional1;
struct iteration_statementOptional1 *verbum_ast_new_iteration_statementOptional1_choice0(struct VerbumContext *ctx, struct expression *expression_0);
struct iteration_statementOptional1 *verbum_ast_new_iteration_statementOptional1_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_iteration_statementOptional1(struct VerbumContext *ctx, struct iteration_statementOptional1 *d);
typedef enum iteration_statementOptional2Type {
	iteration_statementOptional2Type_0,
	iteration_statementOptional2Type_1,
} iteration_statementOptional2Type;
typedef struct iteration_statementOptional2 {

	iteration_statementOptional2Type tag;
	union {
		struct {
			struct expression *expression_0;
		} choice0;
		struct {
		} choice1;
	};
} iteration_statementOptional2;
struct iteration_statementOptional2 *verbum_ast_new_iteration_statementOptional2_choice0(struct VerbumContext *ctx, struct expression *expression_0);
struct iteration_statementOptional2 *verbum_ast_new_iteration_statementOptional2_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_iteration_statementOptional2(struct VerbumContext *ctx, struct iteration_statementOptional2 *d);
typedef enum jump_statementOptional0Type {
	jump_statementOptional0Type_0,
	jump_statementOptional0Type_1,
} jump_statementOptional0Type;
typedef struct jump_statementOptional0 {

	jump_statementOptional0Type tag;
	union {
		struct {
			struct expression *expression_0;
		} choice0;
		struct {
		} choice1;
	};
} jump_statementOptional0;
struct jump_statementOptional0 *verbum_ast_new_jump_statementOptional0_choice0(struct VerbumContext *ctx, struct expression *expression_0);
struct jump_statementOptional0 *verbum_ast_new_jump_statementOptional0_choice1(struct VerbumContext *ctx);
void verbum_ast_delete_jump_statementOptional0(struct VerbumContext *ctx, struct jump_statementOptional0 *d);
typedef translation_unit AST;

#endif
