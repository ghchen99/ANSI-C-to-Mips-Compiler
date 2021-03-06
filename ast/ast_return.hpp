#ifndef ast_return_hpp
#define ast_return_hpp

class ReturnZero
    : public Program
{
public:
    ReturnZero()
    {}


    virtual void print(ALL *ptr) const override
    {
        std::cout << "move\t$2,\t$0";
        std::cout << '\n';
        //std::cout << "$yyEnDlaBel:\t";
        std::cout << "\n\n#stacksize is" << ptr->stacksize << '\n';
        std::cout << "lw\t$31,\t" << (ptr->stacksize - 4) << "($sp)" << '\n';
        std::cout << "addiu\t$sp,\t$sp,\t" << ptr->stacksize;
        std::cout << '\n';
        std::cout << "j\t$ra" << '\n';
        std::cout << "nop" << '\n';
        std::cout << "#finishing a function" << '\n';
        std::cout << "\n\n";
    }

    virtual void countstack(ALL *ptr) const override{
    }

    ~ReturnZero(){
    }

};


class Return
    : public Program
{
private:
        const Program *Program_call1;
public:
    Return(const Program *_Program_call1)
        :Program_call1(_Program_call1)
    {}


    virtual void print(ALL *ptr) const override
    {
        Program_call1 ->  returnprint(ptr);

        //std::cout << "return the calculation into register t0" << '\n';
        std::cout << "move\t$2,\t$t0";
        std::cout << '\n';
        //std::cout << "$yyEnDlaBel:\t";
        std::cout << "\n\n#stacksize is" << ptr->stacksize << '\n';
        std::cout << "lw\t$31,\t" << (ptr->stacksize - 4) << "($sp)" << '\n';
        std::cout << "addiu\t$sp,\t$sp,\t" << ptr->stacksize;
        std::cout << '\n';
        std::cout << "j\t$ra" << '\n';
        std::cout << "nop" << '\n';
        std::cout << "#finishing a function" << '\n';
        std::cout << "\n\n";
    }

    virtual void countstack(ALL *ptr) const override{
        Program_call1 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 4;
    }


    ~Return(){
        delete Program_call1;
    }

};

#endif
