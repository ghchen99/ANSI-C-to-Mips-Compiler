%option noyywrap

%{
/* Now in a section of C that will be embedded
   into the auto-generated code. Flex will not
   try to interpret code surrounded by %{ ... %} */

/* Bring in our declarations for token types and
   the yylval variable. */

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <iostream>
#include "c_lexer.hpp"
void count();

/* End the embedded code section. */
%}


%%

[A-Za-z]([A-Za-z]|[0-9])*	{count();std::string s(yytext);yylval.wordValue = new std::string();*yylval.wordValue = s;return Identifier;}

[\n] {LineNum += 1; ColNum = 0;}
[ \t\v\n\f]		{}
. {}


%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++){
if (yytext[i] == '\t'){
			ColNum += 8 - (ColNum % 8);
    }else{
			ColNum++;
    }
  }
}
