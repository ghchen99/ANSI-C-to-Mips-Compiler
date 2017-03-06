/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 1 "src/parser.y" /* yacc.c:1909  */

  #include "header.hpp"

  #include <cassert>

  extern const Program *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 58 "src/parser.tab.hpp" /* yacc.c:1909  */

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
    T_ELSE = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "src/parser.y" /* yacc.c:1909  */

  const Program *prog;
  std::string *string;
  double number;

#line 134 "src/parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
