#ifndef ast_declaration_hpp
#define ast_declaration_hpp

class declaration
    : public Program
{
private:
    const Program *declaration1;
public:
    declaration(const Program *_declaration1)
        :declaration1(_declaration1)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        std::cout << "<Variable id=\"" ;
        declaration1 -> print();
        std::cout << "\" />" << std::endl;
    }

    ~declaration(){
        delete declaration1;
    }

};

class deco_list
    : public Program
{
private:
    const Program *declaration1;
    const Program *declaration2;
public:
    deco_list(const Program *_declaration1,const Program *_declaration2)
        :declaration1(_declaration1),
         declaration2(_declaration2)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        declaration1 -> print();
        declaration2 -> print();
    }

    ~deco_list(){
        delete declaration1;
        delete declaration2;
    }

};
#endif
