#ifndef ast_postfix_hpp
#define ast_postfix_hpp

class PostFixFunction
    : public Program
{
private:
    const Program *scope0;
public:
    PostFixFunction(const Program *_scope0)
        :scope0(_scope0)
    {}


    virtual void print(ALL *ptr) const override
    {
    }

    virtual void returnprint(ALL *ptr) const override{
        std::string s = scope0 -> getId();
        int tmp = ptr->map[s];
        if(tmp == -3){
            std::cout << ".cprestore	16" << '\n';
            std::cout << "lui\t$28,\t%hi(__gnu_local_gp)" << '\n';
            std::cout << "addiu\t$28,\t$28,\t%lo(__gnu_local_gp)" << '\n';
            std::cout << "lw\t$t5,\t%call16(" << s << ")($28)" << '\n';
        }else if(tmp == -2){
            std::cout << "lw\t$t5,\t%got(" << s << ")($28)" << '\n';
            std::cout << "nop" << '\n';
            std::cout << "move\t$25,\t$t5" << '\n';
            std::cout << "jalr\t$25" << '\n';
            std::cout << "nop" << '\n';
        }
    }

    virtual void declarationPrint(ALL *ptr) const override{
        std::string s = scope0 -> getId();
        int tmp = ptr->map[s];
        if(tmp == -3){
            std::cout << ".cprestore	16" << '\n';
            std::cout << "lui\t$28,\t%hi(__gnu_local_gp)" << '\n';
            std::cout << "addiu\t$28,\t$28,\t%lo(__gnu_local_gp)" << '\n';
            std::cout << "lw\t$t5,\t%call16(" << s << ")($28)" << '\n';
        }else if(tmp == -2){
            std::cout << "lw\t$t5,\t%got(" << s << ")($28)" << '\n';
            std::cout << "nop" << '\n';
            std::cout << "move\t$25,\t$t5" << '\n';
            std::cout << "jalr\t$25" << '\n';
            std::cout << "nop" << '\n';
        }
        std::cout << "move\t$t1,\t$2" << '\n';
    }

    ~PostFixFunction(){
    }

    virtual void countstack(ALL *ptr) const override{
        scope0 ->  countstack(ptr);
        ptr->stacksize = ptr->stacksize + 4;
    }

};

class PostFixFunctionParam
    : public Program
{
private:
    const Program *scope0;
    const Program *scope1;
public:
    PostFixFunctionParam(const Program *_scope0,const Program *_scope1)
        :scope0(_scope0)
        ,scope1(_scope1)
    {}


    virtual void print(ALL *ptr) const override
    {
    }

    virtual void returnprint(ALL *ptr) const override{
        std::string s = scope0 -> getId();
        int tmp = ptr->map[s];
        scope1 -> parameterPrint(ptr);
        if(tmp == -3){
            std::cout << ".cprestore	16" << '\n';
            std::cout << "lui\t$28,\t%hi(__gnu_local_gp)" << '\n';
            std::cout << "addiu\t$28,\t$28,\t%lo(__gnu_local_gp)" << '\n';
            std::cout << "lw\t$t5,\t%call16(" << s << ")($28)" << '\n';
        }else if(tmp == -2){
            std::cout << "lw\t$t5,\t%got(" << s << ")($28)" << '\n';
            std::cout << "nop" << '\n';
            std::cout << "move\t$25,\t$t5" << '\n';
            std::cout << "jalr\t$25" << '\n';
            std::cout << "nop" << '\n';
        }
    }

    virtual void declarationPrint(ALL *ptr) const override{
        std::string s = scope0 -> getId();
        int tmp = ptr->map[s];
        if(tmp == -3){
            std::cout << ".cprestore	16" << '\n';
            std::cout << "lui\t$28,\t%hi(__gnu_local_gp)" << '\n';
            std::cout << "addiu\t$28,\t$28,\t%lo(__gnu_local_gp)" << '\n';
            std::cout << "lw\t$t5,\t%call16(" << s << ")($28)" << '\n';
        }else if(tmp == -2){
            std::cout << "lw\t$t5,\t%got(" << s << ")($28)" << '\n';
            std::cout << "nop" << '\n';
            std::cout << "move\t$25,\t$t5" << '\n';
            std::cout << "jalr\t$25" << '\n';
            std::cout << "nop" << '\n';
        }
        std::cout << "move\t$t1,\t$2" << '\n';
    }

    ~PostFixFunctionParam(){
    }

    virtual void countstack(ALL *ptr) const override{
        scope0 ->  countstack(ptr);
        scope1 ->  countstack(ptr);
        ptr->stacksize = ptr->stacksize + 4;
    }

};

#endif
