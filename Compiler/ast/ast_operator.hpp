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

    virtual void globalvariable(ALL *ptr) const
    {
        std::cout<<"( ";
        left->globalvariable(ptr);
        std::cout<<" ";
        std::cout<<getOpcode();
        std::cout<<" ";
        right->globalvariable(ptr);
        std::cout<<" )";
    }

    virtual void declarationPrint(ALL *ptr) const override{
        //std::cout << "int Initializer declarationPrint" << '\n';
        std::string base = "yyLabEL" ;
        std::string s1 = ptr->makeName(base);
        getLeft() -> declarationPrint(ptr);
        std::cout << "sw\t$t1,\t" << ptr->getIndex() << "($sp)" <<'\n';
        ptr->numberMap.insert ( std::pair<std::string,int>(s1,ptr->getIndex()));
        ptr->increIndex();

        std::string s2 = ptr->makeName(base);
        getRight() -> declarationPrint(ptr);
        std::cout << "sw\t$t1,\t" << ptr->getIndex() << "($sp)" <<'\n';
        ptr->numberMap.insert ( std::pair<std::string,int>(s2,ptr->getIndex()));
        ptr->increIndex();

        std::string opcode = getOpcode();
        if (opcode == "+"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "add\t$t1,\t$t0,\t$t1" << '\n';
        }else if (opcode == "-"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "sub\t$t1,\t$t0,\t$t1" << '\n';
        }else if (opcode == "*"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "mult\t$t1,\t$t0" << '\n';
            std::cout << "mflo\t$t1" << '\n';
        }else if (opcode == "%"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "div\t$t1,\t$t0" << '\n';
            std::cout << "mfhi\t$t1" << '\n';
        }else if (opcode == "/"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "div\t$t1,\t$t0" << '\n';
            std::cout << "mflo\t$t1" << '\n';
        }
    }

    virtual void returnprint(ALL *ptr) const override{
        //std::cout << "int Initializer declarationPrint" << '\n';
        std::string base = "yyLabEL" ;
        std::string s1 = ptr->makeName(base);
        getLeft() -> declarationPrint(ptr);
        std::cout << "sw\t$t1,\t" << ptr->getIndex() << "($sp)" <<'\n';
        ptr->numberMap.insert ( std::pair<std::string,int>(s1,ptr->getIndex()));
        ptr->increIndex();

        std::string s2 = ptr->makeName(base);
        getRight() -> declarationPrint(ptr);
        std::cout << "sw\t$t1,\t" << ptr->getIndex() << "($sp)" <<'\n';
        ptr->numberMap.insert ( std::pair<std::string,int>(s2,ptr->getIndex()));
        ptr->increIndex();

        std::string opcode = getOpcode();
        if (opcode == "+"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "add\t$t1,\t$t0,\t$t1" << '\n';
        }else if (opcode == "-"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "sub\t$t1,\t$t0,\t$t1" << '\n';
        }else if (opcode == "*"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "mult\t$t1,\t$t0" << '\n';
            std::cout << "mflo\t$t1" << '\n';
        }else if (opcode == "%"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "div\t$t1,\t$t0" << '\n';
            std::cout << "mfhi\t$t1" << '\n';
        }else if (opcode == "/"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "div\t$t1,\t$t0" << '\n';
            std::cout << "mflo\t$t1" << '\n';
        }

        std::cout << "move\t$t0,\t$t1" << '\n';
    }

    virtual void print(ALL *ptr) const override{};
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

    virtual void print(ALL *ptr) const override{};


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

    virtual void print(ALL *ptr) const override{};
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

    virtual void print(ALL *ptr) const override{};
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

    virtual void print(ALL *ptr) const override{};

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

    virtual void print(ALL *ptr) const override{};

};

#endif
