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
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

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
      98,   100,   101,   102,   103,   105,   106,   107,   109,   110,
     111,   112,   113,   115,   116,   117,   119,   120,   121,   122,
     123,   124,   126,   127,   129,   130,   131,   132,   134,   135,
     137,   138,   140,   141,   142,   143,   144,   146,   147,   149,
     150,   151,   152,   154,   155,   157,   158,   160,   161,   163,
     164,   166,   167,   169,   170,   172,   173,   175,   176,   178,
     179,   181,   182,   184,   185,   186,   188,   189,   190,   191,
     192,   194,   195,   196,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208
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

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,  -136,  -136,    10,    40,  -136,  -136,     7,  -136,    -1,
    -136,  -136,  -136,  -136,  -136,    45,  -136,    87,     1,  -136,
       6,    90,     2,    33,     6,    69,  -136,    41,  -136,  -136,
      90,    90,    90,  -136,    39,   -25,   248,    -2,  -136,  -136,
    -136,    -5,   105,    86,   100,    78,   126,     0,   114,   127,
     106,    67,  -136,   123,    33,  -136,  -136,     9,  -136,    90,
      90,    90,    90,    90,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,    90,  -136,  -136,     3,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,  -136,  -136,   129,   134,   139,   206,   151,
    -136,  -136,   201,  -136,     7,  -136,   135,   142,  -136,  -136,
    -136,  -136,  -136,    60,   190,  -136,    90,  -136,   -25,  -136,
     -25,  -136,  -136,  -136,  -136,  -136,    48,   130,    86,    86,
     100,    78,   126,     0,     0,   114,   114,   114,   114,    39,
      39,  -136,  -136,   214,    90,  -136,    88,    90,   189,  -136,
    -136,   177,  -136,  -136,  -136,  -136,  -136,  -136,    90,   214,
      59,  -136,    68,   157,  -136,  -136,    -4,   201,   201,    90,
     201,    79,   122,  -136,    80,  -136,   201,   201,   168,  -136,
    -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    16,     0,     2,     3,     5,     0,     9,     0,
      15,     6,     1,     4,     7,     0,    11,    13,     0,     8,
       0,     0,     0,     0,     0,     0,    12,    13,    34,    33,
       0,     0,     0,    14,    91,    18,    21,    25,    28,    17,
      69,    71,    73,    75,    77,    79,    81,    83,    86,     0,
       0,     0,    37,    42,     0,    27,    26,     0,    67,     0,
       0,     0,     0,     0,   101,   100,    98,    99,    95,    96,
      97,   102,   103,   104,    94,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    36,     0,     0,     0,     0,     0,
      65,    44,     0,    48,     0,    52,     0,     0,    50,    55,
      56,    53,    54,     0,     0,    39,     0,    35,    20,    21,
      19,    22,    23,    24,    70,    29,     0,     0,    76,    74,
      78,    80,    82,    84,    85,    89,    90,    87,    88,    93,
      92,    41,    38,     0,     0,    63,     0,     0,     0,    45,
      49,     0,    46,    51,    66,    43,    68,    30,     0,     0,
       0,    64,     0,     0,    47,    72,     0,     0,     0,     0,
       0,     0,    57,    59,     0,    61,     0,     0,     0,    62,
      58,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   199,   -37,    13,  -136,   138,   186,   104,
    -136,  -136,    81,   128,   -29,  -136,  -136,  -136,   -19,   -14,
    -136,   112,   -84,  -136,  -136,  -136,  -135,   -32,   -10,    61,
    -136,  -136,   109,   144,   137,   143,   108,    65,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    24,     8,    15,    16,    27,
      10,    33,    34,    35,    36,    37,    38,    11,    25,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    58,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    55,    56,    50,    28,    29,     1,     1,   159,    52,
      12,    39,     2,     7,   103,     2,     2,     7,   148,    30,
      31,    76,    77,   153,   166,    61,    62,    63,    87,    88,
     119,   119,   121,   122,   123,    94,    32,   170,    78,    18,
     115,    14,    23,    49,   125,     1,   116,   127,    79,     2,
     117,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   104,   124,   146,   153,    51,   150,
      96,    97,     1,    98,    99,    28,    29,    89,    90,    19,
      21,   142,    20,   172,   173,    20,   175,    59,    60,   157,
      30,    31,   179,   180,   154,   155,   116,   116,    28,    29,
     167,   100,    51,   101,     9,   116,   156,    32,     9,   168,
      54,    17,   160,    30,    31,   162,   116,   116,    82,   104,
     176,   178,   161,    84,   102,   116,    21,    22,    53,   119,
      32,    80,    81,    83,   171,    91,    92,   174,    96,    97,
       1,    98,    99,    28,    29,    96,    97,    95,    98,    99,
      28,    29,   135,   136,   137,   138,    85,    86,    30,    31,
     114,    93,    51,   141,    51,    30,    31,   116,   158,   100,
      51,   149,   139,   140,   143,    32,   100,    51,   152,   144,
      96,    97,    32,    98,    99,    28,    29,   118,   120,   128,
     129,   147,   102,   133,   134,     1,   163,   169,   177,   102,
      30,    31,   181,    13,    96,    97,    26,    98,    99,    28,
      29,   100,    51,   164,    28,    29,   126,    32,   151,   165,
     131,     0,    28,    29,    30,    31,   130,   132,     0,    30,
      31,     0,     0,     0,   102,   100,    51,    30,    31,     0,
     145,    32,     0,     0,     0,     0,    32,     0,   100,     0,
       0,     0,     0,     0,    32,     0,     0,     0,   102,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74
};

static const yytype_int16 yycheck[] =
{
      32,    30,    31,    22,     8,     9,     5,     5,   143,    23,
       0,    21,     9,     0,    51,     9,     9,     4,   102,    23,
      24,    23,    24,   107,   159,    50,    51,    52,    28,    29,
      59,    60,    61,    62,    63,    49,    40,    41,    40,    40,
      54,    34,    41,    41,    41,     5,    37,    79,    53,     9,
      41,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    51,    75,    98,   151,    35,   106,
       3,     4,     5,     6,     7,     8,     9,    77,    78,    34,
      39,    95,    37,   167,   168,    37,   170,    48,    49,    41,
      23,    24,   176,   177,    34,   114,    37,    37,     8,     9,
      41,    34,    35,    36,     0,    37,   116,    40,     4,    41,
      41,     7,   144,    23,    24,   147,    37,    37,    32,   106,
      41,    41,    34,    45,    57,    37,    39,    40,    24,   158,
      40,    26,    27,    33,   166,    21,    22,   169,     3,     4,
       5,     6,     7,     8,     9,     3,     4,    41,     6,     7,
       8,     9,    87,    88,    89,    90,    30,    31,    23,    24,
      37,    34,    35,    34,    35,    23,    24,    37,    38,    34,
      35,    36,    91,    92,    40,    40,    34,    35,    36,    40,
       3,     4,    40,     6,     7,     8,     9,    59,    60,    80,
      81,    40,    57,    85,    86,     5,     7,    40,    76,    57,
      23,    24,    34,     4,     3,     4,    20,     6,     7,     8,
       9,    34,    35,    36,     8,     9,    78,    40,   106,   158,
      83,    -1,     8,     9,    23,    24,    82,    84,    -1,    23,
      24,    -1,    -1,    -1,    57,    34,    35,    23,    24,    -1,
      34,    40,    -1,    -1,    -1,    -1,    40,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    57,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     9,    80,    81,    82,    83,    84,    85,    88,
      89,    96,     0,    82,    34,    86,    87,    88,    40,    34,
      37,    39,    40,    41,    84,    97,    87,    88,     8,     9,
      23,    24,    40,    90,    91,    92,    93,    94,    95,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    41,
      97,    35,    98,    88,    41,    93,    93,   106,   107,    48,
      49,    50,    51,    52,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    39,   117,    23,    24,    40,    53,
      26,    27,    32,    33,    45,    30,    31,    28,    29,    77,
      78,    21,    22,    34,    98,    41,     3,     4,     6,     7,
      34,    36,    57,    83,    84,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    37,    98,    37,    41,    92,    93,
      92,    93,    93,    93,   107,    41,    86,   106,   111,   111,
     112,   113,   114,   115,   115,   116,   116,   116,   116,    91,
      91,    34,    98,    40,    40,    34,   106,    40,   101,    36,
      83,   100,    36,   101,    34,    97,   107,    41,    38,   105,
     106,    34,   106,     7,    36,   108,   105,    41,    41,    40,
      41,   106,   101,   101,   106,   101,    41,    76,    41,   101,
     101,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    82,    82,    83,    83,    84,
      85,    86,    86,    87,    87,    88,    89,    90,    91,    91,
      91,    92,    92,    92,    92,    93,    93,    93,    94,    94,
      94,    94,    94,    95,    95,    95,    96,    96,    96,    96,
      96,    96,    97,    97,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   101,   101,   102,   102,   103,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   114,   114,   114,   115,   115,   115,   115,
     115,   116,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     1,     3,
       4,     2,     2,     1,     1,     3,     5,     4,     6,     5,
       5,     6,     2,     4,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     5,     7,     5,
       7,     6,     7,     2,     3,     1,     2,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 1473 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1479 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Program_call((yyvsp[-1].prog),(yyvsp[0].prog));}
#line 1485 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new GlobalVariable((yyvsp[0].prog)); }
#line 1491 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 71 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1497 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 73 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Empty();}
#line 1503 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 74 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new declaration(*(yyvsp[-2].string),(yyvsp[-1].prog)); }
#line 1509 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 76 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 1515 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 78 "src/parser.y" /* yacc.c:1646  */
    { (yyval.string) = new std::string("int"); }
#line 1521 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 80 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1527 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Init_deco_list((yyvsp[-2].prog),(yyvsp[0].prog)); }
#line 1533 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 83 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Init_deco_list1((yyvsp[0].prog));}
#line 1539 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 84 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Init_deco_list2((yyvsp[-2].prog),(yyvsp[0].prog)); }
#line 1545 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 86 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1551 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 88 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Variable(*(yyvsp[0].string)); }
#line 1557 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 90 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Initializer((yyvsp[0].prog));}
#line 1563 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 96 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1569 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 97 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new AddOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1575 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) =  new SubOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1581 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1587 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 101 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new MulOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1593 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 102 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new DivOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1599 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 103 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new ModOperator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1605 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 105 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1611 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 106 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new UnaryDecrement((yyvsp[0].prog));}
#line 1617 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 107 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new UnaryIncrement((yyvsp[0].prog));}
#line 1623 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 109 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1629 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 110 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new PostFixFunction((yyvsp[-2].prog)); }
#line 1635 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 111 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new PostFixFunctionParam((yyvsp[-3].prog),(yyvsp[-1].prog));}
#line 1641 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 112 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new PostFixIncrement((yyvsp[-1].prog)); }
#line 1647 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 113 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new PostFixDecrement((yyvsp[-1].prog)); }
#line 1653 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 115 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Variable(*(yyvsp[0].string)); }
#line 1659 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 116 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Number((yyvsp[0].number));}
#line 1665 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 117 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[-1].prog);}
#line 1671 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 119 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new FunctionDeclare((yyvsp[-3].prog),(yyvsp[0].prog));}
#line 1677 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 120 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new FunctionDeclare((yyvsp[-3].prog),(yyvsp[0].prog));}
#line 1683 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 121 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new FunctionDeclareParam((yyvsp[-4].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1689 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 122 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new FunctionDeclareParam((yyvsp[-4].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1695 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 123 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new FunctionDeclareNoCompound((yyvsp[-3].prog));}
#line 1701 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 124 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new FunctionDeclareNoCompound((yyvsp[-4].prog));}
#line 1707 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 126 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new ParameterDeclare(*(yyvsp[-1].string),(yyvsp[0].prog));}
#line 1713 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 127 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new ParameterDeclareMore((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1719 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 129 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Empty();}
#line 1725 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 130 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = (yyvsp[-1].prog);}
#line 1731 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 131 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = (yyvsp[-1].prog);}
#line 1737 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 132 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Program_call((yyvsp[-2].prog),(yyvsp[-1].prog));}
#line 1743 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 134 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1749 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Program_call((yyvsp[-1].prog),(yyvsp[0].prog)); }
#line 1755 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 137 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1761 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 138 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Program_call((yyvsp[-1].prog),(yyvsp[0].prog)); }
#line 1767 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 140 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1773 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 141 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1779 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 142 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1785 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 143 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1791 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 144 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1797 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 146 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new If((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1803 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 147 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new IfElse((yyvsp[-4].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1809 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 149 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new While((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1815 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 150 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new DoWhile((yyvsp[-5].prog),(yyvsp[-2].prog));}
#line 1821 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 151 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new ForLoopNoIncre((yyvsp[-3].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1827 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 152 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new ForLoop((yyvsp[-4].prog),(yyvsp[-3].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1833 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 154 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new ReturnZero();}
#line 1839 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 155 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Return((yyvsp[-1].prog));}
#line 1845 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 157 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Empty();}
#line 1851 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 158 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new declaration_call((yyvsp[-1].prog)); }
#line 1857 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 160 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog); }
#line 1863 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 161 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new Program_call((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1869 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 163 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1875 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 164 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog)  = new ReDeclare((yyvsp[-2].prog),*(yyvsp[-1].string),(yyvsp[0].prog)); }
#line 1881 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 166 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1887 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 167 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new ConditionExpr((yyvsp[-4].prog),(yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1893 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 169 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1899 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 170 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new OroR((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1905 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 172 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1911 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 173 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new andand((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1917 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 175 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1923 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 176 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Or((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1929 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 178 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1935 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 179 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new ExclusiveOr((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1941 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 181 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1947 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 182 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new And((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1953 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 184 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1959 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 185 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new double_equal((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1965 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 186 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new not_equal((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1971 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 188 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 1977 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 189 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Greater((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1983 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 190 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new Less((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1989 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new LessEqual((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 1995 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 192 "src/parser.y" /* yacc.c:1646  */
    {(yyval.prog) = new GreaterEqual((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 2001 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = (yyvsp[0].prog);}
#line 2007 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) =  new left_shift_operator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 2013 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.prog) = new right_shift_opearator((yyvsp[-2].prog),(yyvsp[0].prog));}
#line 2019 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 198 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("=");}
#line 2025 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 199 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("*=");}
#line 2031 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 200 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("/=");}
#line 2037 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 201 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("%=");}
#line 2043 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 202 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("+=");}
#line 2049 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 203 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("-=");}
#line 2055 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 204 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("<<=");}
#line 2061 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 205 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string(">>=");}
#line 2067 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 206 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("&=");}
#line 2073 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 207 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("^=");}
#line 2079 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 208 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = new std::string("|=");}
#line 2085 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2089 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 210 "src/parser.y" /* yacc.c:1906  */

const Program *g_root; // Definition of variable (to match declaration earlier)
const Program *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
