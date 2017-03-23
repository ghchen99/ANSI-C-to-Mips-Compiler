#ifndef ast_function_hpp
#define ast_function_hpp

class FunctionDeclare
    : public Program
{
private:
    const Program *Program_call1;
    const Program *Program_call2;
public:
    FunctionDeclare(const Program *_Program_call1, const Program *_Program_call2)
        : Program_call1(_Program_call1)
        , Program_call2(_Program_call2)
    {}


    virtual void print(ALL *ptr) const override
    {
        //std::cout << "index in the function is  " << ptr->getIndex() << '\n';
        ptr->increIndex();
        //std::cout << "index in the function is  " << ptr->getIndex() << '\n';

        std::cout << "\n\n";
        std::cout << "#start declaring a function" << '\n';

        std::cout << ".global\t";
        Program_call1 -> print(ptr);
        std::cout << '\n';

        std::cout << ".ent\t";
        Program_call1 -> print(ptr);
        std::cout << '\n';

        std::cout << ".type\t";
        Program_call1 -> print(ptr);
        std::cout << ",  @function" << '\n';

        std::cout << "#finishing declaring a function" << '\n';
        std::cout << "\n";
        std::cout << "#start a function" << '\n';

        Program_call1 -> print(ptr);
        std::cout << ":" << '\n';

        std::cout << "addiu\t$sp,\t$sp,\t-10000";
        std::cout << '\n';

        // stack = 0;
        Program_call2 -> print(ptr);

        std::cout << "addiu\t$sp,\t$sp,\t+10000";
        std::cout << '\n';
        std::cout << "j\t$ra" << '\n';
        std::cout << "nop" << '\n';
        std::cout << "#finishing a function" << '\n';
        std::cout << "\n\n";
    }

    ~FunctionDeclare(){
        delete Program_call1;
        delete Program_call2;
    }

};

#endif
