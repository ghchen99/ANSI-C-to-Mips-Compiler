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


    virtual void print() const override
    {
        //std::cout << "in Initializer" << '\n';
        Program_call1 -> print();
    }

    virtual void globalvariable() const{
        //std::cout << "in Initializer" << '\n';
        Program_call1 -> globalvariable();
    }


    ~Initializer(){
        delete Program_call1;
    }

};

#endif
