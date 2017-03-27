#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>

class Expression
{
public:
    virtual ~Expression()
    {}

    virtual void print() const =0;

};


#endif
