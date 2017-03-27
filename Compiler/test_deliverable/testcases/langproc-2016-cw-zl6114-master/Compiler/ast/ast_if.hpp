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

    virtual void countstack(ALL *ptr) const override{
        scope0 -> countstack(ptr);
        scope1 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 12;
    }


    virtual void print(ALL *ptr) const override
    {
        std::string labelbase = "L" ;
        std::string s1 = ptr->makeName(labelbase);
        std::string s2 = ptr->makeName(labelbase);
        scope0 -> declarationPrint(ptr);
        std::cout << "addiu\t$t2,\t$zero,\t1" << '\n';
        std::cout << "beq\t$t1,\t$t2,\t" << s1 << '\n';
        std::cout << "nop" << '\n';
        std::cout << "b\t" << s2 << '\n';
        std::cout << "nop" << '\n';
        std::cout << s1 << ":" << '\n';
        scope1 -> print(ptr);
        // std::cout << "b\t" << "$yyEnDlaBel" << '\n';
        // std::cout << "nop" << '\n';
        std::cout << s2 << ":" << '\n';
        //std::cout << "in declaration path" << '\n';
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

    virtual void countstack(ALL *ptr) const override{
        scope0 -> countstack(ptr);
        scope1 -> countstack(ptr);
        scope2 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 12;
    }


    virtual void print(ALL *ptr) const override
    {
        std::string labelbase = "L" ;
        std::string s1 = ptr->makeName(labelbase);
        std::string s2 = ptr->makeName(labelbase);
        scope0 -> declarationPrint(ptr);
        std::cout << "addiu\t$t2,\t$zero,\t1" << '\n';
        std::cout << "beq\t$t1,\t$t2,\t" << s1 << '\n';
        std::cout << "nop" << '\n';
        scope2 -> print(ptr);
        // std::cout << "b\t" << "$yyEnDlaBel" << '\n';
        // std::cout << "nop" << '\n';
        std::cout << "b\t" << s2 << '\n';
        std::cout << "nop" << '\n';
        std::cout << s1 << ":" << '\n';
        scope1 -> print(ptr);
        std::cout << s2 << ":" << '\n';
    }

    ~IfElse(){
        delete scope1;
        delete scope2;
    }

};

#endif
