#ifndef ast_redeclare_hpp
#define ast_redeclare_hpp

class ReDeclare
    : public Program
{
private:
    const Program *Program_call1;
    const std::string id1;
    const Program *Program_call2;
public:
    ReDeclare(const Program *_Program_call1,const std::string _id1,const Program *_Program_call2)
        : Program_call1(_Program_call1)
        , id1(_id1)
        , Program_call2(_Program_call2)
    {}


    virtual void print(ALL *ptr) const override
    {
        Program_call1 -> declarationPrint(ptr);
        Program_call2 -> declarationPrint(ptr);
        std::string s = Program_call1 -> getId();
        std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
        //store back to $t0
    }

    ~ReDeclare(){
        delete Program_call1;
        delete Program_call2;
    }


};

#endif
