#ifndef ast_globalvariable_hpp
#define ast_globalvariable_hpp

class GlobalVariable
    : public Program
{
private:
    const Program *Program_call1;
public:
    GlobalVariable(const Program *_Program_call1)
        : Program_call1(_Program_call1)
    {}


    virtual void print(ALL *ptr) const override
    {
        std::cout << "\n\n";
        std::cout << "#start declaring a globalvariable" << '\n';
        //std::cout << "in globalvariable" << '\n';
        Program_call1 -> globalvariable(ptr);
        std::cout << "#finished declaring a globalvariable" << '\n';
        std::cout << "\n\n";
    }

    virtual void countstack(ALL *ptr) const override{
    }


    ~GlobalVariable(){
        delete Program_call1;
    }

};

#endif
