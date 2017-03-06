#ifndef ast_declaration_specifiers_hpp
#define ast_declaration_specifiers_hpp

class declaration_specifiers
    : public Program
{
private:
    const Program *declaration_specifiers0;
    const Program *declaration_specifiers1;
public:
    declaration_specifiers(const Program *_declaration_specifiers0, const Program *_declaration_specifiers1)
        : declaration_specifiers0(_declaration_specifiers0)
        , declaration_specifiers1(_declaration_specifiers1)
    {}


    virtual void print() const override
    {
        std::cout << "in declaration specifier path" << '\n';
        std::cout << "<Variable id=\"" ;
        declaration_specifiers0 -> print();
        std::cout << "\" />" << std::endl;
    }

    ~declaration_specifiers(){
    }

};

#endif
