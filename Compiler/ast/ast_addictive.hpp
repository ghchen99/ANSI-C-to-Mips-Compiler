#ifndef ast_addictive_hpp
#define ast_addictive_hpp


class add_expression
    : public Program
{
private:
    const Program *left;
    const Program *right;
public:
    add_expression(const Program *_left, const Program *_right)
        : left(_left)
        , right(_right)
    {}

    virtual void globalvariable(){
        left -> globalvariable();
        std::cout << "+";
        right -> globalvariable();
    }

    virtual void print() const override
    {
        std::cout << "in add" << '\n';
    }

    virtual ~add_expression()
    {
        delete left;
        delete right;
    }


};

class minus_expression
    : public Program
{
private:
    const Program *left;
    const Program *right;
public:
    minus_expression(const Program *_left, const Program *_right)
        : left(_left)
        , right(_right)
    {}

    virtual void globalvariable(){
        left -> print();
        std::cout << "-";
        right -> print();
    }

    virtual void print() const override
    {
        std::cout << "in sub" << '\n';
    }

    virtual ~minus_expression()
    {
        delete left;
        delete right;
    }


};

#endif
