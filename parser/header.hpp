#ifndef header_hpp
#define header_hpp
#include <string>

enum TokenType{
    T_VARIABLE = 0;
    T_CONTROL_FLOW = 1;
    T_INT = 2;
    T_SIMICOLOUMN = 3;
    T_LBRACKET = 4;
    T_RBRACKET = 5;
    T_LCURLYBRACKET = 6;
    T_RCURLYBRACKET = 7;
};

union TokenValue{
    double numberValue;
    std::string *wordValue;
};


// This is a global variable used to move the
// attribute value from the lexer back to the
// main program.
// By convention it is called yylval, as that is
// the name that will be automatially generated
// by Bison (see next lab).
extern TokenValue yylval;
extern int LineNum;
extern int ColNum;
extern std::string SourceFile;

// This is the lexer function defined by flex. Each
// time it is called, a token type value will be
// returned.
extern int yylex();

#endif
