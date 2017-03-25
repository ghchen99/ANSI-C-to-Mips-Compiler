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

    virtual void countstack(ALL *ptr) const override{
        Program_call1 -> countstack(ptr);
        Program_call2 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 64;
    }


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

        std::cout << "addiu\t$sp,\t$sp,\t-" << ptr->stacksize;
        std::cout << '\n';

        // stack = 0;
        Program_call2 -> print(ptr);

        std::cout << ".end\t" ;
        Program_call1 -> print(ptr);
        std::cout << '\n';
    }

    ~FunctionDeclare(){
        delete Program_call1;
        delete Program_call2;
    }

};


class FunctionDeclareParam
	: public Program
{
private:
    const Program *Program_call1;
    const Program *Program_call2;
    const Program *Program_call3;
public:
    FunctionDeclareParam(const Program *_Program_call1,
                         const Program *_Program_call2,
                         const Program *_Program_call3)
        : Program_call1(_Program_call1)
        , Program_call2(_Program_call2)
        , Program_call3(_Program_call3)
    {}

        virtual void countstack(ALL *ptr) const override{
            Program_call1 -> countstack(ptr);
            Program_call2 -> countstack(ptr);
            Program_call3 -> countstack(ptr);
            ptr->stacksize = ptr->stacksize + 128;
        }


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

            std::cout << "addiu\t$sp,\t$sp,\t-" << ptr->stacksize;
            std::cout << '\n';

            // stack = 0;
            std::cout << "#printing out ParameterDeclare" << '\n';
            Program_call2 -> print(ptr);

            Program_call3 -> print(ptr);

            std::cout << "\n\n#stacksize is" << ptr->stacksize << '\n';
            std::cout << "addiu\t$sp,\t$sp,\t" << ptr->stacksize;
            std::cout << '\n';
            std::cout << "j\t$ra" << '\n';
            std::cout << "nop" << '\n';
            std::cout << "#finishing a function" << '\n';
            std::cout << "\n\n";
        }

	~FunctionDeclareParam(){
	}

};

#endif
