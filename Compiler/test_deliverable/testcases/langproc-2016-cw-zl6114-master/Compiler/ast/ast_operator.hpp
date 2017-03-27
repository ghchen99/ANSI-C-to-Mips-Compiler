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

    virtual void countstack(ALL *ptr) const override{
        left -> countstack(ptr);
        right -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 16;
    }

    virtual void declarationPrint(ALL *ptr) const override{
        //std::cout << "int Initializer declarationPrint" << '\n';
        std::string base = "yyLabEL" ;
        std::string labelbase = "L" ;
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
        }else if (opcode == "<<"){
            //when to use logical shift and when to use arithmatic
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "sllv\t$t1,\t$t0,\t$t1" << '\n';
        }else if (opcode == ">>"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "slav\t$t1,\t$t0,\t$t1" << '\n';
        }else if (opcode == "=="){
            //when to use logical shift and when to use arithmatic
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "xor\t$t1,\t$t0,\t$t1" << '\n';
            std::cout << "sltu\t$t1,\t$t1,\t1" << '\n';
        }else if (opcode == "!="){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "xor\t$t1,\t$t0,\t$t1" << '\n';
            std::cout << "sltu\t$t1,\t$zero,\t$t1" << '\n';
        }else if (opcode == ">"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "slt\t$t1,\t$t1,\t$t0" << '\n';
        }else if (opcode == ">="){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "slt\t$t1,\t$t0,\t$t1" << '\n';
            std::cout << "xori\t$t1,\t$t1,\t1" << '\n';
        }else if (opcode == "<"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "slt\t$t1,\t$t0,\t$t1" << '\n';
        }else if (opcode == "<="){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "slt\t$t1,\t$t1,\t$t0" << '\n';
            std::cout << "xori\t$t1,\t$t1,\t1" << '\n';
        }else if (opcode == "&"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "and\t$t1,\t$t0,\t$t1" << '\n';
        }else if (opcode == "^"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "xor\t$t1,\t$t0,\t$t1" << '\n';
        }else if (opcode == "|"){
            std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
            std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
            std::cout << "or\t$t1,\t$t0,\t$t1" << '\n';
        }//else if (opcode == "&&"){
        //     std::cout << "lw\t$t0,\t" << ptr->numberMap[s1] << "($sp)" <<'\n';
        //     std::cout << "lw\t$t1,\t" << ptr->numberMap[s2] << "($sp)" <<'\n';
        //     std::string s1 = ptr->makeName(labelbase);
        // }
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


class left_shift_operator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">>"; }
public:
    left_shift_operator(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};


class right_shift_opearator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">>"; }
public:
    right_shift_opearator(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

class double_equal
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "=="; }
public:
    double_equal(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

class not_equal
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "!="; }
public:
    not_equal(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

class Greater
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">"; }
public:
    Greater(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

class GreaterEqual
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return ">="; }
public:
    GreaterEqual(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

class Less
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "<"; }
public:
    Less(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

class LessEqual
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "<="; }
public:
    LessEqual(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

class And
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "&"; }
public:
    And(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};


class ExclusiveOr
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "^"; }
public:
    ExclusiveOr(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

class Or
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "|"; }
public:
    Or(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

class andand
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "&&"; }
public:
    andand(const Program *_left, const Program *_right)
        : Operator(_left, _right)
    {}

    virtual void print(ALL *ptr) const override{};


};

#endif
