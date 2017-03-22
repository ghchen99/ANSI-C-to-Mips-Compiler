#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>

class Operator
    : public Program
{
private:
    const Program *left;
    const Program *right;
protected:
    Operator(const Program *_left, const Program *_right)
        : left(_left)
        , right(_right)
    {}
public:

    virtual ~Operator()
    {
        delete left;
        delete right;
    }

    virtual const char *getOpcode() const =0;

    const Program *getLeft() const
    { return left; }

    const Program *getRight() const
    { return right; }

    virtual void globalvariable() const
    {
        std::cout<<"( ";
        left->globalvariable();
        std::cout<<" ";
        std::cout<<getOpcode();
        std::cout<<" ";
        right->globalvariable();
        std::cout<<" )";
    }

    virtual void print() const override{};
};

class AddOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "+"; }
public:
    AddOperator(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print() const override{};
};

class SubOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "-"; }
public:
    SubOperator(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print() const override{};
};

class MulOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "*"; }
public:
    MulOperator(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print() const override{};
};

class DivOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "/"; }
public:
    DivOperator(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print() const override{};

};

class ModOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "%"; }
public:
    ModOperator(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print() const override{};

};

#endif
