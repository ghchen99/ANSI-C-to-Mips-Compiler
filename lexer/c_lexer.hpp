#ifndef histogram_hpp
#define histogram_hpp
#include <string>

enum TokenType{
    None   = 0,
    Keyword = 1,
    Identifier = 2,
    Operator = 3,
    Constant = 4,
    StringLiteral = 5,
    Invalid = 6
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

// This is the lexer function defined by flex. Each
// time it is called, a token type value will be
// returned.
extern int yylex();

#endif
