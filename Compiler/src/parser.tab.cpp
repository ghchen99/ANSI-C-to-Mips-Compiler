/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y" /* yacc.c:355  */

  #include "header.hpp"

  #include <cassert>

  extern const Program *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 111 "src/parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_FOR = 258,
    T_IF = 259,
    T_INT = 260,
    T_RETURN = 261,
    T_WHILE = 262,
    T_NUMBER = 263,
    T_VARIABLE = 264,
    T_ELLIPSIS = 265,
    T_RIGHT_ASSIGN = 266,
    T_LEFT_ASSIGN = 267,
    T_ADD_ASSIGN = 268,
    T_SUB_ASSIGN = 269,
    T_MUL_ASSIGN = 270,
    T_DIV_ASSIGN = 271,
    T_MOD_ASSIGN = 272,
    T_AND_ASSIGN = 273,
    T_XOR_ASSIGN = 274,
    T_OR_ASSIGN = 275,
    T_RIGHT_OP = 276,
    T_LEFT_OP = 277,
    T_INC_OP = 278,
    T_DEC_OP = 279,
    T_PTR_OP = 280,
    T_AND_OP = 281,
    T_OR_OP = 282,
    T_LE_OP = 283,
    T_GE_OP = 284,
    T_EQ_OP = 285,
    T_NE_OP = 286,
    T_INEXCLUS_OR = 287,
    T_EXCLUS_OR = 288,
    T_SIMICOLOUMN = 289,
    T_LCURLYBRACKET = 290,
    T_RCURLYBRACKET = 291,
    T_COMMA = 292,
    T_COLOUMN = 293,
    T_EQUAL = 294,
    T_LBRACKET = 295,
    T_RBRACKET = 296,
    T_LSQUAREBRACKET = 297,
    T_RSQUAREBRACKET = 298,
    T_DOT = 299,
    T_AMPERSAND = 300,
    T_EXCLAMATION = 301,
    T_TILDE = 302,
    T_MINUS = 303,
    T_PLUS = 304,
    T_STAR = 305,
    T_DIVIDE = 306,
    T_MOD = 307,
    T_QUESTIONMARK = 308,
    T_GOTO = 309,
    T_BREAK = 310,
    T_CONTINUE = 311,
    T_DO = 312,
    T_SIZEOF = 313,
    T_CONST = 314,
    T_VOLATILE = 315,
    T_VOID = 316,
    T_CHAR = 317,
    T_LONG = 318,
    T_SIGNED = 319,
    T_UNSIGNED = 320,
    T_FLOAT = 321,
    T_DOUBLE = 322,
    T_STRUCT = 323,
    T_UNION = 324,
    T_TYPEDEF = 325,
    T_AUTO = 326,
    T_REGISTER = 327,
    T_EXTERN = 328,
    T_STATIC = 329,
    T_ELSE = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "src/parser.y" /* yacc.c:355  */

  const Program *prog;
  std::string *string;
  double number;

#line 205 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 222 "src/parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   235

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      78,     2,    77,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    67,    68,    70,    71,    73,    74,    76,
      78,    80,    81,    83,    84,    86,    88,    90,    96,    97,
      98,   100,   101,   102,   103,   105,   107,   108,   109,   110,
     111,   113,   114,   115,   117,   118,   119,   120,   121,   122,
     124,   125,   127,   128,   129,   130,   132,   133,   135,   136,
     138,   139,   140,   141,   142,   144,   145,   147,   148,   149,
     150,   152,   153,   155,   156,   158,   159,   161,   162,   164,
     165,   167,   168,   170,   171,   173,   174,   176,   177,   179,
     180,   182,   183,   184,   186,   187,   188,   189,   190,   192,
     193,   194,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_FOR", "T_IF", "T_INT", "T_RETURN",
  "T_WHILE", "T_NUMBER", "T_VARIABLE", "T_ELLIPSIS", "T_RIGHT_ASSIGN",
  "T_LEFT_ASSIGN", "T_ADD_ASSIGN", "T_SUB_ASSIGN", "T_MUL_ASSIGN",
  "T_DIV_ASSIGN", "T_MOD_ASSIGN", "T_AND_ASSIGN", "T_XOR_ASSIGN",
  "T_OR_ASSIGN", "T_RIGHT_OP", "T_LEFT_OP", "T_INC_OP", "T_DEC_OP",
  "T_PTR_OP", "T_AND_OP", "T_OR_OP", "T_LE_OP", "T_GE_OP", "T_EQ_OP",
  "T_NE_OP", "T_INEXCLUS_OR", "T_EXCLUS_OR", "T_SIMICOLOUMN",
  "T_LCURLYBRACKET", "T_RCURLYBRACKET", "T_COMMA", "T_COLOUMN", "T_EQUAL",
  "T_LBRACKET", "T_RBRACKET", "T_LSQUAREBRACKET", "T_RSQUAREBRACKET",
  "T_DOT", "T_AMPERSAND", "T_EXCLAMATION", "T_TILDE", "T_MINUS", "T_PLUS",
  "T_STAR", "T_DIVIDE", "T_MOD", "T_QUESTIONMARK", "T_GOTO", "T_BREAK",
  "T_CONTINUE", "T_DO", "T_SIZEOF", "T_CONST", "T_VOLATILE", "T_VOID",
  "T_CHAR", "T_LONG", "T_SIGNED", "T_UNSIGNED", "T_FLOAT", "T_DOUBLE",
  "T_STRUCT", "T_UNION", "T_TYPEDEF", "T_AUTO", "T_REGISTER", "T_EXTERN",
  "T_STATIC", "\"then\"", "T_ELSE", "'>'", "'<'", "$accept", "ROOT",
  "PROGRAM", "ALL_DECLEARARION", "DECLARATION", "DECLARATION_SPECIFIERS",
  "TYPE_SPECIFIER", "INIT_DECLARATOR_LIST", "INIT_DECLARATOR",
  "DECLARATOR", "DIRECT_DECLARATOR", "INITIALIZER", "ADDITIVE_EXPRESSION",
  "MULTIPLICATIVE_EXPRESSION", "UNARY_EXPRESSION", "POSTFIX_EXPRESSION",
  "PRIMARY_EXPRESSION", "FUNCTION", "PARAM_DECLARATION_LIST",
  "COMPOUND_STATEMENT", "DECLARATION_LIST", "STATEMENT_LIST", "STATEMENT",
  "IF_STATEMENT", "ITERATION_STATEMENT", "JUMP_STATEMENT",
  "EXPRESSION_STATEMENT", "EXPRESSION", "ASSIGNMENT_EXPRESSION",
  "CONDITIONAL_EXPRESSION", "LOGICAL_OR_EXPRESSION",
  "LOGICAL_AND_EXPRESSION", "INCLUSIVE_OR_EXPRESSION",
  "EXCLUSIVE_OR_EXPRESSION", "AND_EXPRESSION", "EQUALITY_EXPRESSION",
  "RELATIONAL_EXPRESSION", "SHIFT_EXPRESSION", "ASSIGNMENT_OPERATOR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,    62,    60
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,  -116,  -116,    44,     9,  -116,  -116,    50,  -116,    42,
    -116,  -116,  -116,  -116,  -116,   104,  -116,   -14,    10,  -116,
      54,    33,    12,    45,    54,    47,  -116,    79,  -116,  -116,
      33,  -116,   -28,   120,   164,    51,  -116,  -116,  -116,    48,
     163,    96,   106,   100,   166,   -16,   177,   167,   121,    62,
    -116,   136,    45,    53,  -116,    33,    33,    33,    33,    33,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,    33,  -116,  -116,    40,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,  -116,
    -116,   170,   145,   151,    38,   153,  -116,  -116,   160,  -116,
      50,  -116,   117,   108,  -116,  -116,  -116,  -116,  -116,   112,
     203,  -116,    33,  -116,   120,  -116,   120,  -116,  -116,  -116,
    -116,  -116,    58,   169,    96,    96,   106,   100,   166,   -16,
     -16,   177,   177,   177,   177,   -28,   -28,  -116,  -116,    49,
      33,  -116,   113,    33,   209,  -116,  -116,   152,  -116,  -116,
    -116,  -116,  -116,  -116,    33,    49,    63,  -116,    90,   180,
    -116,  -116,    14,   160,   160,    33,   160,    92,   146,  -116,
      99,  -116,   160,   160,   187,  -116,  -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    16,     0,     2,     3,     5,     0,     9,     0,
      15,     6,     1,     4,     7,     0,    11,    13,     0,     8,
       0,     0,     0,     0,     0,     0,    12,    13,    32,    31,
       0,    14,    89,    18,    21,    25,    26,    17,    67,    69,
      71,    73,    75,    77,    79,    81,    84,     0,     0,     0,
      35,    40,     0,     0,    65,     0,     0,     0,     0,     0,
      99,    98,    96,    97,    93,    94,    95,   100,   101,   102,
      92,     0,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      34,     0,     0,     0,     0,     0,    63,    42,     0,    46,
       0,    50,     0,     0,    48,    53,    54,    51,    52,     0,
       0,    37,     0,    33,    20,    21,    19,    22,    23,    24,
      68,    27,     0,     0,    74,    72,    76,    78,    80,    82,
      83,    87,    88,    85,    86,    91,    90,    39,    36,     0,
       0,    61,     0,     0,     0,    43,    47,     0,    44,    49,
      64,    41,    66,    28,     0,     0,     0,    62,     0,     0,
      45,    70,     0,     0,     0,     0,     0,     0,    55,    57,
       0,    59,     0,     0,     0,    60,    56,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,   219,   -46,     1,  -116,   150,   205,   130,
    -116,  -116,   123,   157,   -49,  -116,  -116,  -116,   -18,    -4,
    -116,   124,   -87,  -116,  -116,  -116,  -115,   -30,   -19,    73,
    -116,  -116,   138,   154,   149,   155,   137,    23,  -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    24,     8,    15,    16,    27,
      10,    31,    32,    33,    34,    35,    36,    11,    25,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    54,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,     7,    37,    99,    48,     7,   115,   115,   117,   118,
     119,   144,    83,    84,     1,     1,   149,     1,     2,    50,
      55,    56,    28,    29,   155,    21,    22,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     162,    28,    29,    90,    12,   123,    28,    29,   111,     2,
     100,    23,   120,    47,    30,   166,   146,    28,    29,     2,
     149,    85,    86,     2,   142,    92,    93,     1,    94,    95,
      28,    29,   141,    30,    72,    73,   168,   169,    30,   171,
      49,   121,    18,    96,    14,   175,   176,   138,    52,    30,
     112,    74,   151,   152,   113,    20,    96,    49,    97,   153,
     112,    75,    30,   100,   163,   115,   131,   132,   133,   134,
     156,    92,    93,   158,    94,    95,    28,    29,    21,    98,
      92,    93,     1,    94,    95,    28,    29,   112,    78,   112,
       9,   164,   167,   172,     9,   170,   112,    17,    19,    79,
     174,    20,    96,    49,   148,    80,   150,   157,    30,   112,
     112,    96,    49,   145,    51,    92,    93,    30,    94,    95,
      28,    29,    91,    92,    93,    98,    94,    95,    28,    29,
      57,    58,    59,   110,    98,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,   139,    96,    49,   160,    76,
      77,   140,    30,   143,    96,    49,    81,    82,    87,    88,
      30,    89,    49,    70,   137,    49,   112,   154,     1,    98,
     135,   136,   114,   116,   124,   125,   159,    98,   129,   130,
     165,   177,   173,    13,   122,    26,   147,   161,   127,     0,
       0,     0,   126,     0,     0,   128
};

static const yytype_int16 yycheck[] =
{
      30,     0,    21,    49,    22,     4,    55,    56,    57,    58,
      59,    98,    28,    29,     5,     5,   103,     5,     9,    23,
      48,    49,     8,     9,   139,    39,    40,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     155,     8,     9,    47,     0,    75,     8,     9,    52,     9,
      49,    41,    71,    41,    40,    41,   102,     8,     9,     9,
     147,    77,    78,     9,    94,     3,     4,     5,     6,     7,
       8,     9,    34,    40,    23,    24,   163,   164,    40,   166,
      35,    41,    40,    34,    34,   172,   173,    91,    41,    40,
      37,    40,   110,   112,    41,    37,    34,    35,    36,    41,
      37,    53,    40,   102,    41,   154,    83,    84,    85,    86,
     140,     3,     4,   143,     6,     7,     8,     9,    39,    57,
       3,     4,     5,     6,     7,     8,     9,    37,    32,    37,
       0,    41,   162,    41,     4,   165,    37,     7,    34,    33,
      41,    37,    34,    35,    36,    45,    34,    34,    40,    37,
      37,    34,    35,    36,    24,     3,     4,    40,     6,     7,
       8,     9,    41,     3,     4,    57,     6,     7,     8,     9,
      50,    51,    52,    37,    57,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    40,    34,    35,    36,    26,
      27,    40,    40,    40,    34,    35,    30,    31,    21,    22,
      40,    34,    35,    39,    34,    35,    37,    38,     5,    57,
      87,    88,    55,    56,    76,    77,     7,    57,    81,    82,
      40,    34,    76,     4,    74,    20,   102,   154,    79,    -1,
      -1,    -1,    78,    -1,    -1,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     9,    80,    81,    82,    83,    84,    85,    88,
      89,    96,     0,    82,    34,    86,    87,    88,    40,    34,
      37,    39,    40,    41,    84,    97,    87,    88,     8,     9,
      40,    90,    91,    92,    93,    94,    95,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    41,    97,    35,
      98,    88,    41,   106,   107,    48,    49,    50,    51,    52,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      39,   117,    23,    24,    40,    53,    26,    27,    32,    33,
      45,    30,    31,    28,    29,    77,    78,    21,    22,    34,
      98,    41,     3,     4,     6,     7,    34,    36,    57,    83,
      84,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      37,    98,    37,    41,    92,    93,    92,    93,    93,    93,
     107,    41,    86,   106,   111,   111,   112,   113,   114,   115,
     115,   116,   116,   116,   116,    91,    91,    34,    98,    40,
      40,    34,   106,    40,   101,    36,    83,   100,    36,   101,
      34,    97,   107,    41,    38,   105,   106,    34,   106,     7,
      36,   108,   105,    41,    41,    40,    41,   106,   101,   101,
     106,   101,    41,    76,    41,   101,   101,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    82,    82,    83,    83,    84,
      85,    86,    86,    87,    87,    88,    89,    90,    91,    91,
      91,    92,    92,    92,    92,    93,    94,    94,    94,    94,
      94,    95,    95,    95,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   101,   101,   102,   102,   103,   103,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   114,   115,   115,   115,   115,   115,   116,
     116,   116,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     3,     4,     2,
       2,     1,     1,     3,     5,     4,     6,     5,     5,     6,
       2,     4,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     5,     7,     5,     7,     6,
       7,     2,     3,     1,     2,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 65 "src/parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].prog); }
#line 1460 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1466 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Program_call((yyvsp[-1].prog),(yyvsp[0].prog));}
#line 1472 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new GlobalVariable((yyvsp[0].prog)); }
#line 1478 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 71 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1484 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 73 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Empty();}
#line 1490 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 74 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new declaration(*(yyvsp[-2].string),(yyvsp[-1].prog)); }
#line 1496 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 76 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1502 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 78 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = new std::string("int"); }
#line 1508 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 80 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1514 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Init_deco_list((yyvsp[-2].prog),(yyvsp[0].prog)); }
#line 1520 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 83 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Init_deco_list1((yyvsp[0].prog));}
#line 1526 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 84 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Init_deco_list2((yyvsp[-2].prog),(yyvsp[0].prog)); }
#line 1532 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 86 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1538 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 88 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Variable(*(yyvsp[0].string)); }
#line 1544 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 90 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Initializer((yyvsp[0].prog));}
#line 1550 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 96 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1556 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 97 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new AddOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1562 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) =  new SubOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1568 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1574 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 101 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new MulOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1580 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 102 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new DivOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1586 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 103 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new ModOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1592 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 105 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1598 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 107 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1604 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 108 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new PostFixFunction((yyvsp[-2].prog)); }
#line 1610 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 109 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new PostFixFunctionParam((yyvsp[-3].prog),(yyvsp[-1].prog));}
#line 1616 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 110 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new PostFixIncrement((yyvsp[-1].prog)); }
#line 1622 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 111 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new PostFixDecrement((yyvsp[-1].prog)); }
#line 1628 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 113 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Variable(*(yyvsp[0].string)); }
#line 1634 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 114 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Number((yyvsp[0].number));}
#line 1640 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 115 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[-1].prog);}
#line 1646 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 117 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new FunctionDeclare((yyvsp[-3].prog),(yyvsp[0].prog));}
#line 1652 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 118 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new FunctionDeclare((yyvsp[-3].prog),(yyvsp[0].prog));}
#line 1658 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 119 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new FunctionDeclareParam((yyvsp[-4].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1664 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 120 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new FunctionDeclareParam((yyvsp[-4].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1670 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 121 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new FunctionDeclareNoCompound((yyvsp[-3].prog));}
#line 1676 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 122 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new FunctionDeclareNoCompound((yyvsp[-4].prog));}
#line 1682 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 124 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new ParameterDeclare(*(yyvsp[-1].string),(yyvsp[0].prog));}
#line 1688 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 125 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new ParameterDeclareMore((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1694 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 127 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Empty();}
#line 1700 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 128 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = (yyvsp[-1].prog);}
#line 1706 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 129 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = (yyvsp[-1].prog);}
#line 1712 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 130 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Program_call((yyvsp[-2].prog),(yyvsp[-1].prog));}
#line 1718 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 132 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1724 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 133 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Program_call((yyvsp[-1].prog),(yyvsp[0].prog)); }
#line 1730 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 135 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1736 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 136 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Program_call((yyvsp[-1].prog),(yyvsp[0].prog)); }
#line 1742 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 138 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1748 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 139 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1754 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 140 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1760 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 141 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1766 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 142 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1772 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 144 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new If((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1778 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 145 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new IfElse((yyvsp[-4].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1784 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 147 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new While((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1790 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 148 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new DoWhile((yyvsp[-5].prog),(yyvsp[-2].prog));}
#line 1796 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 149 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new ForLoopNoIncre((yyvsp[-3].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1802 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 150 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new ForLoop((yyvsp[-4].prog),(yyvsp[-3].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1808 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 152 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new ReturnZero();}
#line 1814 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 153 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Return((yyvsp[-1].prog));}
#line 1820 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 155 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Empty();}
#line 1826 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 156 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new declaration_call((yyvsp[-1].prog)); }
#line 1832 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 158 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1838 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 159 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Program_call((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1844 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 161 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1850 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 162 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog)  = new ReDeclare((yyvsp[-2].prog),*(yyvsp[-1].string),(yyvsp[0].prog)); }
#line 1856 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 164 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1862 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 165 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new ConditionExpr((yyvsp[-4].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1868 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 167 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1874 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 168 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new OroR((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1880 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 170 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1886 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 171 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new andand((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1892 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 173 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1898 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 174 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Or((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1904 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 176 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1910 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 177 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new ExclusiveOr((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1916 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1922 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 180 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new And((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1928 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1934 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 183 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new double_equal((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1940 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 184 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new not_equal((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1946 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1952 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 187 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Greater((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1958 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 188 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Less((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1964 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new LessEqual((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1970 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 190 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new GreaterEqual((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1976 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1982 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) =  new left_shift_operator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1988 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new right_shift_opearator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1994 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 196 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("=");}
#line 2000 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 197 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("*=");}
#line 2006 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 198 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("/=");}
#line 2012 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 199 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("%=");}
#line 2018 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 200 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("+=");}
#line 2024 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 201 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("-=");}
#line 2030 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 202 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("<<=");}
#line 2036 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 203 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string(">>=");}
#line 2042 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 204 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("&=");}
#line 2048 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 205 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("^=");}
#line 2054 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 206 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("|=");}
#line 2060 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2064 "src/parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 208 "src/parser.y" /* yacc.c:1906  */

const Program *g_root; // Definition of variable (to match declaration earlier)
const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
