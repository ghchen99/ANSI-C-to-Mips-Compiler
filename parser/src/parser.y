%code requires{
  #include "header.hpp"

  #include <cassert>

  extern const Program *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Program *prog;
  std::string *string;
  double number;
}

%token T_FOR T_IF T_INT T_RETURN T_WHILE
%token T_NUMBER T_VARIABLE
%token T_ELLIPSIS T_RIGHT_ASSIGN T_LEFT_ASSIGN T_ADD_ASSIGN
%token T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN
%token T_AND_ASSIGN T_XOR_ASSIGN T_OR_ASSIGN T_RIGHT_OP T_LEFT_OP
%token T_INC_OP T_DEC_OP T_PTR_OP T_AND_OP T_OR_OP T_LE_OP T_GE_OP
%token T_EQ_OP T_NE_OP T_INEXCLUS_OR T_EXCLUS_OR
%token T_SIMICOLOUMN T_LCURLYBRACKET T_RCURLYBRACKET T_COMMA T_COLOUMN
%token T_EQUAL T_LBRACKET T_RBRACKET T_LSQUAREBRACKET T_RSQUAREBRACKET
%token T_DOT T_AMPERSAND T_EXCLAMATION T_TILDE
%token T_MINUS T_PLUS T_STAR T_DIVIDE T_MOD T_QUESTIONMARK
%token T_GOTO T_BREAK T_CONTINUE T_DO T_SIZEOF T_CONST T_VOLATILE
%token T_VOID T_CHAR T_LONG T_SIGNED T_UNSIGNED T_FLOAT T_DOUBLE T_STRUCT T_UNION
%token T_TYPEDEF T_AUTO T_REGISTER T_EXTERN T_STATIC

// Precedences go increasing, so "then" < "else".
%nonassoc "then"
%nonassoc T_ELSE

%type <prog> PROGRAM ALL_DECLEARARION DECLARATION DIRECT_DECLARATOR DECLARATOR
%type <prog> INIT_DECLARATOR INIT_DECLARATOR_LIST INITIALIZER ASSIGNMENT_EXPRESSION
%type <prog> UNARY_EXPRESSION POSTFIX_EXPRESSION PRIMARY_EXPRESSION RE_DECLARATION
%type <prog> FUNCTION COMPOUND_STATEMENT PARAM_DECLARATION_LIST
%type <prog> STATEMENT STATEMENT_LIST IF_STATEMENT EXPRESSION DECLARATION_LIST
%type <prog> JUMP_STATEMENT ITERATION_STATEMENT EXPRESSION_STATEMENT
%type <prog> EQUALITY_EXPRESSION RELATIONAL_EXPRESSION SHIFT_EXPRESSION ADDITIVE_EXPRESSION MULTIPLICATIVE_EXPRESSION
%type <prog> CONDITIONAL_EXPRESSION LOGICAL_OR_EXPRESSION POINTER
%type <prog> LOGICAL_AND_EXPRESSION INCLUSIVE_OR_EXPRESSION EXCLUSIVE_OR_EXPRESSION AND_EXPRESSION
%type <string> T_INT T_VARIABLE TYPE_SPECIFIER DECLARATION_SPECIFIERS OPERATOR
%type <string> ASSIGNMENT_OPERATOR TYPE_QUALIFIER struct_or_union STRUCT_UNION STORAGE_CLASS_SPECIFIER
%type <number> T_NUMBER

%start ROOT



%%

ROOT : PROGRAM { g_root = $1; }

PROGRAM: ALL_DECLEARARION { $$ = $1;}
       | PROGRAM ALL_DECLEARARION { $$ = new Program_call($1,$2);}

ALL_DECLEARARION : DECLARATION { $$ = $1;}
                 | FUNCTION { $$ = $1; }

FUNCTION : DECLARATION_SPECIFIERS DECLARATOR T_LBRACKET PARAM_DECLARATION_LIST T_RBRACKET COMPOUND_STATEMENT
            { $$ = new Function($2,$4,$6);}
         | DECLARATION_SPECIFIERS DECLARATOR T_LBRACKET T_RBRACKET COMPOUND_STATEMENT
            { $$ = new FunctionNoParam($2,$5);}
         | DECLARATOR T_LBRACKET PARAM_DECLARATION_LIST T_RBRACKET COMPOUND_STATEMENT { $$ = new Function($1,$3,$5);}
         | DECLARATOR T_LBRACKET T_RBRACKET COMPOUND_STATEMENT {$$ = new FunctionNoParam($1,$4);}

COMPOUND_STATEMENT : T_LCURLYBRACKET T_RCURLYBRACKET {$$ = new EmptyScope();}
                   | T_LCURLYBRACKET DECLARATION_LIST T_RCURLYBRACKET {$$ = new Scope($2);}
                   | T_LCURLYBRACKET STATEMENT_LIST T_RCURLYBRACKET {$$ = new Scope($2);}
                   | T_LCURLYBRACKET DECLARATION_LIST STATEMENT_LIST T_RCURLYBRACKET {$$ = new DoubleScope($2,$3);}

STATEMENT_LIST : STATEMENT { $$ = $1; }
               | STATEMENT_LIST STATEMENT { $$ = new Program_call($1,$2); }

STATEMENT : COMPOUND_STATEMENT { $$ = $1;}
          | IF_STATEMENT { $$ = $1;}
          | JUMP_STATEMENT { $$ = $1;}
          | ITERATION_STATEMENT { $$ = $1;}

ITERATION_STATEMENT : T_WHILE T_LBRACKET EXPRESSION T_RBRACKET STATEMENT {$$ = new Scope($5);}
                    //| T_WHILE T_LBRACKET EXPRESSION T_RBRACKET T_LCURLYBRACKET EXPRESSION T_SIMICOLOUMN T_RCURLYBRACKET {$$ = new Scope($6);}
                    | T_DO STATEMENT T_WHILE T_LBRACKET EXPRESSION T_RBRACKET T_SIMICOLOUMN {$$ = new Scope($2);}
                    | T_FOR T_LBRACKET EXPRESSION_STATEMENT EXPRESSION_STATEMENT T_RBRACKET STATEMENT {$$ = new Scope($6);}
                    | T_FOR T_LBRACKET EXPRESSION_STATEMENT EXPRESSION_STATEMENT EXPRESSION T_RBRACKET STATEMENT {$$ = new Scope($7);}

EXPRESSION_STATEMENT : T_SIMICOLOUMN { $$ = new Empty();}
                     | EXPRESSION T_SIMICOLOUMN { $$ = $1;}

IF_STATEMENT : T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT { $$ = new If($3,$5);}   %prec "then" //https://www.gnu.org/software/bison/manual/html_node/Precedence-Decl.html
             | T_IF T_LBRACKET EXPRESSION T_RBRACKET STATEMENT T_ELSE STATEMENT
             {$$ = new IfElse($3,$5,$7);}
             /*| T_IF T_LBRACKET EXPRESSION T_RBRACKET T_LCURLYBRACKET DECLARATION_LIST JUMP_STATEMENT T_RCURLYBRACKET T_ELSE STATEMENT
             {$$ = new IfElse($3,$6,$10);}*/

JUMP_STATEMENT : T_RETURN T_SIMICOLOUMN { $$ = new Empty();}
               | T_RETURN EXPRESSION T_SIMICOLOUMN { $$ = new Empty();}
               | T_GOTO T_VARIABLE T_SIMICOLOUMN { $$ = new Empty();}
               | T_BREAK T_SIMICOLOUMN { $$ = new Empty();}
               | T_CONTINUE T_SIMICOLOUMN { $$ = new Empty();}

EXPRESSION : INITIALIZER { $$ = $1;}
           | T_LBRACKET ASSIGNMENT_EXPRESSION T_RBRACKET { $$ = $2;}
           | T_ELLIPSIS { $$ = new Empty();}
          // | PRIMARY_EXPRESSION ASSIGNMENT_OPERATOR INITIALIZER { $$ = $3;}

/*EXPRESSION_OPERATOR : T_EQ_OP {$$ = new std::string("==");}
                    | T_NE_OP {$$ = new std::string("!=");}
                    | T_GE_OP {$$ = new std::string(">=");}
                    | T_LE_OP {$$ = new std::string("<=");}
                    | T_OR_OP {$$ = new std::string("||");}
                    | T_AND_OP {$$ = new std::string("&&");}*/


DECLARATION_LIST : DECLARATION { $$ = $1; }
                 | DECLARATION_LIST DECLARATION { $$ = new Program_call($1,$2); }

PARAM_DECLARATION_LIST : DECLARATION_SPECIFIERS DECLARATOR { $$ = new parameter($2); }
                       | DECLARATION_SPECIFIERS DECLARATOR T_COMMA PARAM_DECLARATION_LIST
                        { $$ = new MutiplyParameter($2,$4); }
                       | DECLARATION_SPECIFIERS { $$ = new Empty();}

/*MULTI_DECLARATION : DECLARATION { $$ = $1;}
                  | MULTI_DECLARATION DECLARATION { $$ = new Program_call($1,$2);}*/

DECLARATION : DECLARATION_SPECIFIERS T_SIMICOLOUMN { $$ = new Empty();}
            | DECLARATION_SPECIFIERS INIT_DECLARATOR_LIST T_SIMICOLOUMN { $$ = new declaration($2);}
            | RE_DECLARATION { $$ = $1;}

RE_DECLARATION :  INIT_DECLARATOR_LIST T_SIMICOLOUMN { $$ = new Empty();}

DECLARATION_SPECIFIERS : TYPE_SPECIFIER { $$ = $1;}
                       | TYPE_SPECIFIER DECLARATION_SPECIFIERS { $$ = $1;}
                       | STORAGE_CLASS_SPECIFIER { $$ = $1;}
                       | STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIERS { $$ = $1;}

STORAGE_CLASS_SPECIFIER : T_TYPEDEF { $$ = new std::string("typedef");}
                        | T_EXTERN { $$ = new std::string("extern");}
                        | T_STATIC { $$ = new std::string("static");}
                        | T_AUTO { $$ = new std::string("auto");}
                        | T_REGISTER { $$ = new std::string("register");}

INIT_DECLARATOR_LIST : INIT_DECLARATOR { $$ = $1;}
                     //| INIT_DECLARATOR T_COMMA INIT_DECLARATOR_LIST

INIT_DECLARATOR : DECLARATOR { $$ = $1; }
                | DECLARATOR ASSIGNMENT_OPERATOR INITIALIZER { $$ = new init_declartor($1,$3); }
                //| LOGICAL_OR_EXPRESSION { $$ = $1;}
                | T_INC_OP INITIALIZER { $$ = $2;}
                | T_DEC_OP INITIALIZER { $$ = $2;}
                | DIRECT_DECLARATOR T_INC_OP { $$ =$1;}
                | DIRECT_DECLARATOR T_DEC_OP { $$ = $1;}
                | DIRECT_DECLARATOR T_LSQUAREBRACKET EXPRESSION T_RSQUAREBRACKET  { $$ = $1;}
                | DIRECT_DECLARATOR T_LSQUAREBRACKET EXPRESSION T_RSQUAREBRACKET STATEMENT  { $$ = $1;}
                | DIRECT_DECLARATOR T_LSQUAREBRACKET EXPRESSION T_RSQUAREBRACKET T_LSQUAREBRACKET EXPRESSION T_RSQUAREBRACKET { $$ = $1;}
            //  | DIRECT_DECLARATOR T_LBRACKET T_RBRACKET  { $$ = $1;}
                | DIRECT_DECLARATOR T_DOT T_VARIABLE { $$ = $1;}
                | DIRECT_DECLARATOR T_PTR_OP T_VARIABLE { $$ = $1;}

DECLARATOR : POINTER DIRECT_DECLARATOR { $$ = $2;}
           | DIRECT_DECLARATOR {$$ = $1;}

POINTER : T_STAR { $$ = new Empty();}
        | T_STAR POINTER { $$ = $2;}
        | T_STAR TYPE_QUALIFIER { $$ = new Empty();}
        | T_STAR TYPE_QUALIFIER POINTER { $$ = $3;}

TYPE_QUALIFIER : T_CONST { $$ = new std::string("const"); }
               | T_VOLATILE { $$ = new std::string("volatile"); }

DIRECT_DECLARATOR : T_VARIABLE { $$ = new Variable(*$1);}

TYPE_SPECIFIER : T_INT { $$ = new std::string("int"); }
               | T_VOID { $$ = new std::string("void"); }
               | T_CHAR { $$ = new std::string("char"); }
               | T_LONG { $$ = new std::string("long"); }
               | T_FLOAT { $$ = new std::string("float"); }
               | T_DOUBLE { $$ = new std::string("double"); }
               | T_SIGNED { $$ = new std::string("signed"); }
               | T_UNSIGNED { $$ = new std::string("unsigned"); }
               | STRUCT_UNION { $$ = $1 ; }
               //| ENUM

STRUCT_UNION : struct_or_union T_VARIABLE T_LCURLYBRACKET DECLARATION_LIST T_RCURLYBRACKET { $$ = $1;}
             | struct_or_union T_LCURLYBRACKET DECLARATION_LIST T_RCURLYBRACKET { $$ = $1;}
             | struct_or_union T_VARIABLE { $$ = $1;}

struct_or_union	: T_STRUCT { $$ = new std::string("struct"); }
               	| T_UNION  { $$ = new std::string("union"); }

INITIALIZER : ASSIGNMENT_EXPRESSION { $$ = $1;}
            //| T_LCURLYBRACKET INIT_DECLARATOR_LIST T_RCURLYBRACKET
            //| T_LCURLYBRACKET INIT_DECLARATOR_LIST T_COMMA T_RCURLYBRACKET

ASSIGNMENT_EXPRESSION : CONDITIONAL_EXPRESSION { $$ = $1;}
                      | UNARY_EXPRESSION ASSIGNMENT_OPERATOR ASSIGNMENT_EXPRESSION { new Program_call($1,$3);}

CONDITIONAL_EXPRESSION : LOGICAL_OR_EXPRESSION { $$ = $1;}
                       | LOGICAL_OR_EXPRESSION T_QUESTIONMARK EXPRESSION T_COLOUMN CONDITIONAL_EXPRESSION { $$ = new Empty();}

LOGICAL_OR_EXPRESSION : LOGICAL_AND_EXPRESSION { $$ = $1;}
                      | LOGICAL_AND_EXPRESSION T_OR_OP INCLUSIVE_OR_EXPRESSION { new Program_call($1,$3);}

LOGICAL_AND_EXPRESSION : INCLUSIVE_OR_EXPRESSION { $$ = $1;}
                       | LOGICAL_AND_EXPRESSION T_AND_OP INCLUSIVE_OR_EXPRESSION { new Program_call($1,$3);}

INCLUSIVE_OR_EXPRESSION : EXCLUSIVE_OR_EXPRESSION { $$ = $1;}
                        | INCLUSIVE_OR_EXPRESSION T_INEXCLUS_OR EXCLUSIVE_OR_EXPRESSION { new Program_call($1,$3);}

EXCLUSIVE_OR_EXPRESSION : AND_EXPRESSION { $$ = $1;}
                        | EXCLUSIVE_OR_EXPRESSION T_EXCLUS_OR AND_EXPRESSION { new Program_call($1,$3);}

AND_EXPRESSION : EQUALITY_EXPRESSION { $$ = $1;}
               | AND_EXPRESSION T_AMPERSAND EQUALITY_EXPRESSION { new Program_call($1,$3);}

EQUALITY_EXPRESSION : RELATIONAL_EXPRESSION { $$ = $1;}
                    | EQUALITY_EXPRESSION T_EQ_OP RELATIONAL_EXPRESSION { new Program_call($1,$3);}
                    | EQUALITY_EXPRESSION T_NE_OP RELATIONAL_EXPRESSION { new Program_call($1,$3);}

RELATIONAL_EXPRESSION : SHIFT_EXPRESSION { $$ = $1;}
                      | RELATIONAL_EXPRESSION '>' SHIFT_EXPRESSION { new Program_call($1,$3);}
                      | RELATIONAL_EXPRESSION '<' SHIFT_EXPRESSION { new Program_call($1,$3);}
                      | RELATIONAL_EXPRESSION T_LE_OP SHIFT_EXPRESSION { new Program_call($1,$3);}
                      | RELATIONAL_EXPRESSION T_GE_OP SHIFT_EXPRESSION { new Program_call($1,$3);}

SHIFT_EXPRESSION : ADDITIVE_EXPRESSION { $$ = $1;}
                 | SHIFT_EXPRESSION T_LEFT_OP ADDITIVE_EXPRESSION { new Program_call($1,$3);}
                 | SHIFT_EXPRESSION T_RIGHT_OP ADDITIVE_EXPRESSION { new Program_call($1,$3);}

ADDITIVE_EXPRESSION : MULTIPLICATIVE_EXPRESSION { $$ = $1;}
                    | ADDITIVE_EXPRESSION T_PLUS MULTIPLICATIVE_EXPRESSION { new Program_call($1,$3);}
                    | ADDITIVE_EXPRESSION T_MINUS MULTIPLICATIVE_EXPRESSION { new Program_call($1,$3);}

MULTIPLICATIVE_EXPRESSION : UNARY_EXPRESSION { $$ = $1;}
                          | MULTIPLICATIVE_EXPRESSION T_STAR UNARY_EXPRESSION { new Program_call($1,$3);}
                          | MULTIPLICATIVE_EXPRESSION T_DIVIDE UNARY_EXPRESSION { new Program_call($1,$3);}
                          | MULTIPLICATIVE_EXPRESSION T_MOD UNARY_EXPRESSION { new Program_call($1,$3);}

UNARY_EXPRESSION : POSTFIX_EXPRESSION { $$ = $1; }
                 | OPERATOR UNARY_EXPRESSION { $$ = new unary_expression($2);}
                 | T_INC_OP UNARY_EXPRESSION { $$ = new unary_expression($2);}
                 | T_DEC_OP UNARY_EXPRESSION { $$ = new unary_expression($2);}
                 | T_SIZEOF UNARY_EXPRESSION { $$ = $2; }
                 /*| T_SIZEOF T_LBRACKET TYPE_NAME T_RBRACKET
type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
specifier_qualifier_list
    	: type_specifier specifier_qualifier_list
    	| type_specifier
    	| type_qualifier specifier_qualifier_list
    	| type_qualifier
type_qualifier
        : CONST
        | VOLATILE*/

OPERATOR : T_MINUS {$$ = new std::string("-");}
         | T_PLUS  {$$ = new std::string("+");}
         | T_STAR  {$$ = new std::string("*");}
         | T_DIVIDE  {$$ = new std::string("/");}
         | T_MOD  {$$ = new std::string("%%");}
         | T_EQUAL {$$ = new std::string("=");}

ASSIGNMENT_OPERATOR : T_EQUAL {$$ = new std::string("=");}
                    | T_MUL_ASSIGN {$$ = new std::string("*=");}
                    | T_DIV_ASSIGN {$$ = new std::string("/=");}
                    | T_MOD_ASSIGN {$$ = new std::string("%%=");}
                    | T_ADD_ASSIGN {$$ = new std::string("+=");}
                    | T_SUB_ASSIGN {$$ = new std::string("-=");}
                    | T_LEFT_ASSIGN {$$ = new std::string("<<=");}
                    | T_RIGHT_ASSIGN {$$ = new std::string(">>=");}
                    | T_AND_ASSIGN {$$ = new std::string("&=");}
                    | T_XOR_ASSIGN {$$ = new std::string("^=");}
                    | T_OR_ASSIGN {$$ = new std::string("|=");}

/*CAST_EXPRESSION : UNARY_EXPRESSION { $$ = $1;}*/

POSTFIX_EXPRESSION : PRIMARY_EXPRESSION { $$ = $1; }
                   | POSTFIX_EXPRESSION T_LSQUAREBRACKET EXPRESSION T_RSQUAREBRACKET  { $$ = new PostFix($1); }
                   | POSTFIX_EXPRESSION T_LBRACKET T_RBRACKET  { $$ = new PostFix($1); }
                   | POSTFIX_EXPRESSION T_DOT T_VARIABLE  { $$ = new PostFix($1); }
                   | POSTFIX_EXPRESSION T_PTR_OP T_VARIABLE  { $$ = new PostFix($1); }
                   | POSTFIX_EXPRESSION T_INC_OP  { $$ = new PostFix($1); }
                   | POSTFIX_EXPRESSION T_DEC_OP { $$ = new PostFix($1); }


PRIMARY_EXPRESSION :  T_VARIABLE { $$ = new Variable(*$1); }
                   |  T_NUMBER { $$ = new Number($1);}
                //   |  T_LBRACKET EXPRESSION T_RBRACKET { $$ = $2;}




%%
const Program *g_root; // Definition of variable (to match declaration earlier)
const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
