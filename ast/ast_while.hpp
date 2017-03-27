#ifndef ast_while_hpp
#define ast_while_hpp


class While
    : public Program
{
private:
    const Program *scope0;
    const Program *scope1;
public:
    While(const Program *_scope0, const Program *_scope1)
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
        std::string s3 = ptr->makeName(labelbase);

        std::cout << s1 << ":" << '\n';
        scope0 -> declarationPrint(ptr);
        std::cout << "addiu\t$t2,\t$zero,\t1" << '\n';
        std::cout << "bne\t$t1,\t$t2,\t" << s3 << '\n';
        std::cout << "nop" << '\n';

        std::cout << s2 << ":" << '\n';
        scope1 -> print(ptr);
        std::cout << "b\t" << s1 << '\n';


        std::cout << s3 << ":" << '\n';

        // std::cout << "b\t" << "$yyEnDlaBel" << '\n';
        // std::cout << "nop" << '\n';
        //std::cout << "in declaration path" << '\n';
    }

    ~While(){
        delete scope1;
    }

};

class DoWhile
    : public Program
{
private:
    const Program *scope0;
    const Program *scope1;
public:
    DoWhile(const Program *_scope0, const Program *_scope1)
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

        std::cout << s1 << ":" << '\n';
        scope0 -> print(ptr);


        scope1 -> declarationPrint(ptr);
        std::cout << "addiu\t$t2,\t$zero,\t1" << '\n';
        std::cout << "beq\t$t1,\t$t2,\t" << s1 << '\n';
        std::cout << "nop" << '\n';
    }

    ~DoWhile(){
        delete scope1;
    }

};


class ForLoop
    : public Program
{
private:
    const Program *scope0;
    const Program *scope1;
    const Program *scope2;
    const Program *scope3;

public:
    ForLoop(const Program *_scope0, const Program *_scope1, const Program *_scope2, const Program *_scope3)
        :scope0(_scope0)
        ,scope1(_scope1)
        ,scope2(_scope2)
        ,scope3(_scope3)
    {}

    virtual void countstack(ALL *ptr) const override{
        scope0 -> countstack(ptr);
        scope1 -> countstack(ptr);
                scope2 -> countstack(ptr);
                        scope3 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 12;
    }


    virtual void print(ALL *ptr) const override
    {
        std::string labelbase = "L" ;
        std::string s1 = ptr->makeName(labelbase);
        std::string s2 = ptr->makeName(labelbase);
        std::string s3 = ptr->makeName(labelbase);

        scope0 -> print(ptr);

        std::cout << s1 << ":" << '\n';
        scope1 -> print(ptr);
        std::cout << "addiu\t$t2,\t$zero,\t1" << '\n';
        std::cout << "bne\t$t1,\t$t2,\t" << s3 << '\n';
        std::cout << "nop" << '\n';

        std::cout << s2 << ":" << '\n';
        scope2 -> declarationPrint(ptr);
        scope3 -> print(ptr);
        std::cout << "b\t" << s1 << '\n';


        std::cout << s3 << ":" << '\n';

    }

    ~ForLoop(){
        delete scope1;
    }

};


class ForLoopNoIncre
    : public Program
{
private:
    const Program *scope0;
    const Program *scope1;
    const Program *scope3;

public:
    ForLoopNoIncre(const Program *_scope0, const Program *_scope1, const Program *_scope3)
        :scope0(_scope0)
        ,scope1(_scope1)
        ,scope3(_scope3)
    {}

    virtual void countstack(ALL *ptr) const override{
        scope0 -> countstack(ptr);
        scope1 -> countstack(ptr);
        scope3 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 12;
    }


    virtual void print(ALL *ptr) const override
    {
        std::string labelbase = "L" ;
        std::string s1 = ptr->makeName(labelbase);
        std::string s2 = ptr->makeName(labelbase);
        std::string s3 = ptr->makeName(labelbase);

        scope0 -> print(ptr);

        std::cout << s1 << ":" << '\n';
        scope1 -> print(ptr);
        std::cout << "addiu\t$t2,\t$zero,\t1" << '\n';
        std::cout << "bne\t$t1,\t$t2,\t" << s3 << '\n';
        std::cout << "nop" << '\n';

        std::cout << s2 << ":" << '\n';
        scope3 -> print(ptr);
        std::cout << "b\t" << s1 << '\n';


        std::cout << s3 << ":" << '\n';

    }

    ~ForLoopNoIncre(){
        delete scope1;
    }

};

#endif
