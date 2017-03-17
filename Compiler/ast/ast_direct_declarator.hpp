#ifndef ast_direct_declarator_hpp
#define ast_direct_declarator_hpp
class direct_declarator1
    : public Program
{
private:
    const Program *declaration1;
    const Program *declaration2;
public:
    direct_declarator1(const Program *_declaration1,const Program *_declaration2)
        :declaration1(_declaration1),
         declaration2(_declaration2)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        declaration1 -> print();
        declaration2 -> print();
    }

    ~direct_declarator1(){
        delete declaration1;
        delete declaration2;
    }

};

class direct_declarator2
    : public Program
{
private:
    const Program *declaration2;
public:
    direct_declarator2(const Program *_declaration2)
        :declaration2(_declaration2)
    {}


    virtual void print() const override
    {
        declaration2 -> print();
    }

    ~direct_declarator2(){
        delete declaration2;
    }

};

#endif
