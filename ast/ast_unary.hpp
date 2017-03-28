#ifndef ast_unary_hpp
#define ast_unary_hpp

class UnaryIncrement
    : public Program
{
private:
    const Program *scope0;
public:
    UnaryIncrement(const Program *_scope0)
        :scope0(_scope0)
    {}


    virtual void print(ALL *ptr) const override
    {
    }

    virtual void returnprint(ALL *ptr) const override{
        scope0 -> returnprint(ptr);
        std::string s = scope0 -> getId();
        int tmp = ptr->map[s];
        std::cout << "lw\t$t0,\t" << tmp << "($sp)" << '\n';
        std::cout << "addiu\t$t0,$t0,1" << '\n';
    }

    virtual void declarationPrint(ALL *ptr) const override{
        scope0 -> declarationPrint(ptr);
        std::string s = scope0 -> getId();
        int tmp = ptr->map[s];
        std::cout << "lw\t$t1,\t" << tmp << "($sp)" << '\n';
        std::cout << "addiu\t$t1,$t1,1" << '\n';
    }

    ~UnaryIncrement(){
    }

    virtual void countstack(ALL *ptr) const override{
        scope0 ->  countstack(ptr);
        ptr->stacksize = ptr->stacksize + 4;
    }

};

class UnaryDecrement
    : public Program
{
private:
    const Program *scope0;
public:
    UnaryDecrement(const Program *_scope0)
        :scope0(_scope0)
    {}


    virtual void print(ALL *ptr) const override
    {
    }

    virtual void returnprint(ALL *ptr) const override{
        scope0 -> returnprint(ptr);
        std::string s = scope0 -> getId();
        int tmp = ptr->map[s];
        std::cout << "lw\t$t0,\t" << tmp << "($sp)" << '\n';
        std::cout << "addi\t$t0,$t0,-1" << '\n';
    }

    virtual void declarationPrint(ALL *ptr) const override{
        scope0 -> declarationPrint(ptr);
        std::string s = scope0 -> getId();
        int tmp = ptr->map[s];
        std::cout << "lw\t$t1,\t" << tmp << "($sp)" << '\n';
        std::cout << "addi\t$t1,$t1,-1" << '\n';
    }

    ~UnaryDecrement(){
    }

    virtual void countstack(ALL *ptr) const override{
        scope0 ->  countstack(ptr);
        ptr->stacksize = ptr->stacksize + 4;
    }

};

#endif
