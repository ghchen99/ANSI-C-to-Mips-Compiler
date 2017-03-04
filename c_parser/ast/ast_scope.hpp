#ifndef ast_scope_hpp
#define ast_scope_hpp

class Scope
    : public Program
{
private:
    const Program *scope1;
public:
    Scope(const Program *_scope1)
        :scope1(_scope1)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        std::cout << "<Scope>" << std::endl;
        scope1 -> print();
        std::cout << "</Scope>" << std::endl;
    }

    ~Scope(){
        delete scope1;
    }

};

class Scope
    : public Program
{
private:
    const Program *scope1;
    const Program *scope2;
public:
    Scope(const Program *_scope1,const Program *scope2)
        :scope1(_scope1)
        ,scope2(_scope2)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        std::cout << "<Scope>" << std::endl;
        scope1 -> print();
        scope2 -> print();
        std::cout << "</Scope>" << std::endl;
    }

    ~Scope(){
        delete scope1;
        delete scope2;
    }

};

class EmptyScope
    : public Program
{
public:
    EmptyScope()
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        std::cout << "<Scope>" << std::endl;
        std::cout << "</Scope>" << std::endl;
    }

    ~EmptyScope(){
    }

};

#endif
