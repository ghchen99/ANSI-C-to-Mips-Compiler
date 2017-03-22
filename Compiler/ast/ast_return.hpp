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
        Program_call1 ->  returnprint();
        std::cout << "return the calculation into register t0" << '\n';
        std::cout << "move\t$2,\t$t0";
        std::cout << '\n';
    }


    ~Return(){
        delete Program_call1;
    }

};

#endif
