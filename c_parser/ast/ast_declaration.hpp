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
        std::cout << "in declaration path" << '\n';
        std::cout << "<Variable id=\"" ;
        declaration1 -> print();
        std::cout << "\" />" << std::endl;
    }

    ~declaration(){
    }

};

#endif
