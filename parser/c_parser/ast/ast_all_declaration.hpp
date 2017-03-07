#ifndef ast_all_declaration_hpp
#define ast_all_declaration_hpp

class all_declaration
    : public Program
{
private:
    const Program *declaration;
public:
    all_declaration(const Program *_declaration)
        :declaration(_declaration)
    {}


    virtual void print() const override
    {
        declaration -> print();
    }

    ~all_declaration(){
    }

};

#endif
