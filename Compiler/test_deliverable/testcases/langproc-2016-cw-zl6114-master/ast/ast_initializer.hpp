#ifndef ast_initializer_hpp
#define ast_initializer_hpp

class Initializer
    : public Program
{
private:
    const Program *Program_call1;
public:
    Initializer(const Program *_Program_call1)
        : Program_call1(_Program_call1)
    {}


    virtual void print(ALL *ptr) const override
    {
        //std::cout << "in Initializer" << '\n';
        Program_call1 -> print(ptr);
    }

    virtual void globalvariable(ALL *ptr) const override{
        //std::cout << "in Initializer" << '\n';
        Program_call1 -> globalvariable(ptr);
    }

    virtual void declarationPrint(ALL *ptr) const override{
        //std::cout << "int Initializer declarationPrint" << '\n';
        Program_call1 -> declarationPrint(ptr);
    }

    virtual void countstack(ALL *ptr) const override{
        Program_call1 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 4;
    }


    ~Initializer(){
        delete Program_call1;
    }

};

#endif
