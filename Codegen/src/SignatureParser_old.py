from parsimonious.grammar import Grammar

# GRAMMAR = Grammar(
#     """
#     identifier                          = identifier_nondigit / identifier identifier_nondigit / identifier digit
#     identifier_nondigit                 = nondigit
#     nondigit                            = ~"[A-Z a-z]|_"
#     digit                               = ~"[0-9]"
#     declarator                          = ptr_declarator / noptr_declarator parameters_and_qualifiers trailing_return_type
#     ptr_declarator                      = noptr_declarator / ptr_operator ptr_declarator
#     noptr_declarator                    = declarator_id attribute_specifier_seq? / noptr_declarator parameters_and_qualifiers / "(" ptr_declarator ")"
#     parameters_and_qualifiers           = "(" parameter_declaration_clause ")" attribute_specifier_seq? cv_qualifier_seq?
#     trailing_return_type                = "->" trailing_type_specifier_seq abstract_declarator?
#     ptr_operator                        = "*" attribute_specifier_seq? cv_qualifier_seq? / "&" attribute_specifier_seq? / "&&" attribute_specifier_seq? / nested_name_specifier "*" attribute_specifier_seq? cv_qualifier_seq?
#     cv_qualifier_seq                    = cv_qualifier cv_qualifier_seq?
#     cv_qualifier                        = "const" / "volatile"
#     ref_qualifier                       = "&" / "&&"
#     declarator_id                       = "..."? id_expression / nested_name_specifier? class_name
#     abstract_declarator                 = ptr_abstract_declarator / noptr_abstract_declarator? parameters_and_qualifiers / trailing_return_type
#     ptr_abstract_declarator             = noptr_abstract_declarator / ptr_operator ptr_abstract_declarator?
#     noptr_abstract_declarator           = noptr_abstract_declarator? parameters_and_qualifiers / noptr_abstract_declarator? "[" constant_expression? "]"  attribute_specifier_seq? / "(" ptr_abstract_declarator ")"
#     abstract_pack_declarator            = noptr_abstract_pack_declarator / ptr_operator abstract_pack_declarator
#     noptr_abstract_pack_declarator      = noptr_abstract_pack_declarator parameters_and_qualifiers / noptr_abstract_pack_declarator "[" constant_expression? "]" attribute_specifier_seq? / "..."
#     parameter_declaration_clause        = parameter_declaration_list? "..."? / parameter_declaration_list "," "..."
#     parameter_declaration_list          = parameter_declaration / parameter_declaration_list "," parameter_declaration
#     parameter_declaration               = attribute_specifier_seq? decl_specifier_seq declarator / attribute_specifier_seq? decl_specifier_seq declarator "=" initializer_clause / attribute_specifier_seq? decl_specifier_seq abstract_declarator? / attribute_specifier_seq? decl_specifier_seq abstract_declarator? "=" initializer_clause
#     function_definition                 = attribute_specifier_seq? decl_specifier_seq? declarator virt_specifier_seq? function_body
#     function_body                       = ""?
#     initializer                         = ""?
#     brace_or_equal_initializer          = ""?
#     initializer_clause                  = ""?

#     class_name                          = identifier / simple_template_id
#     class_head                          = class_key attribute_specifier_seq? / class_head_name class_virt_specifier? base_clause? / class_key attribute_specifier_seq? base_clause?
#     class_head_name                     = nested_name_specifier? class_name
#     class_virt_specifier                = "final"
#     class_key                           = "class" / "struct" / "union"
#     """)

GRAMMAR = Grammar(
    r"""
    start                   = function_definition
    function_definition     = access_modifier? return_type ptr_cdecl? full_function_name function_arg_list function_modifier?
    return_type             = full_type_name
    access_modifier         = "public:" / "private:" / "protected:"
    ptr_cdecl               = ("__ptr64" / "__cdecl")+
    full_function_name      = (full_namespace function_name) / function_name
    function_arg_list       = "(" function_arguments? ")"
    function_modifier       = "const"
    full_type_name          = (class_key? ((full_namespace "::" type_name) / type_name) pointer_or_ref_chars* "__ptr64"?)
    full_namespace          = (namespace "::" full_namespace) / (namespace "::")
    namespace               = full_type_name
    function_name           = identifier
    function_arguments      = (full_type_name "," function_arguments) / full_type_name
    type_name               = (identifier "<" template_args_list ">") / identifier
    template_args_list      = (template_argument "," template_args_list) / template_argument
    template_argument       = (class_key? full_type_name) / literal_int
    identifier              = nondigit ~"[A-Za-z0-9_]*"
    class_key               = "class" / "struct" / "union"
    literal_int             = ~"[0-9]+"
    nondigit                = ~"[A-Za-z_]"
    pointer_or_ref_chars    = "*" / "&" / "&&" / "const"



    # namespace                           = identifier "::"
    # type_name_with_modifiers            = type_name_flat "const"?
    # type_name_flat                      = basic_type / identifier
    # basic_type                          = "int" / "float" / "double"
    # type                                = (type pointer_and_ref_chars) / basic_type / full_class_name

    # class_template_args_wrapper         = "<" class_template_args? ">"
    # class_template_args                 = class_template_args "," literal_int / class_template_args "," class_with_key / class_with_key / literal_int
    # full_class_name                     = complete_namespace "::" class_name
    # complete_namespace                  = (complete_namespace identifier "::") / identifier "::"
    # class_with_key                      = class_key full_class_name
    # literal                             = literal_int
    # class_identifier                    = "class"
    # digit                               = ~"[0-9]"
    """)

class SignatureParser:
    def __init__(self):
        pass

    