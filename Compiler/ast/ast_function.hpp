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


    virtual void print() const override
    {
        std::cout << ".global\t";
        Program_call1 -> print();
        std::cout << '\n';

        std::cout << ".ent\t";
        Program_call1 -> print();
        std::cout << '\n';

        std::cout << ".type\t";
        Program_call1 -> print();
        std::cout << ",  @function" << '\n';

        Program_call1 -> print();
        std::cout << ":" << '\n';
        Program_call2 -> print();
    }

    ~FunctionDeclare(){
        delete Program_call1;
        delete Program_call2;
    }

};

#endif
