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

    virtual void globalvariable(ALL *ptr){
        left -> globalvariable(ptr);
        std::cout << "+";
        right -> globalvariable(ptr);
    }

    virtual void print(ALL *ptr) const override
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

    virtual void globalvariable(ALL *ptr){
        left -> print(ptr);
        std::cout << "-";
        right -> print(ptr);
    }

    virtual void print(ALL *ptr) const override
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
