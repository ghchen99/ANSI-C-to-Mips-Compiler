#ifndef ast_if_hpp
#define ast_if_hpp

class If
    : public Program
{
private:
    const Program *scope0;
    const Program *scope1;
public:
    If(const Program *_scope0, const Program *_scope1)
        :scope0(_scope0)
        ,scope1(_scope1)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        std::cout << "<Scope>" << std::endl;
        scope1 -> print();
        std::cout << "</Scope>" << std::endl;
    }

    ~If(){
        delete scope1;
    }

};

class IfElse
    : public Program
{
private:
    const Program *scope0;
    const Program *scope1;
    const Program *scope2;
public:
    IfElse(const Program *_scope0,const Program *_scope1,const Program *_scope2)
        :scope0(_scope0)
        ,scope1(_scope1)
        ,scope2(_scope2)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        std::cout << "<Scope>" << std::endl;
        scope1 -> print();
        std::cout << "</Scope>" << std::endl;
        std::cout << "<Scope>" << std::endl;
        scope2 -> print();
        std::cout << "</Scope>" << std::endl;
    }

    ~IfElse(){
        delete scope1;
        delete scope2;
    }

};

#endif
