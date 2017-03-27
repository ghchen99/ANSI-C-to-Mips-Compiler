#ifndef ast_init_declartor_hpp
#define ast_init_declartor_hpp

class init_declartor
    : public Program
{
private:
    const Program *init_declartor0;
    const Program *init_declartor1;
public:
    init_declartor(const Program *_init_declartor0, const Program *_init_declartor1)
        : init_declartor0(_init_declartor0)
        , init_declartor1(_init_declartor1)
    {}


    virtual void print() const override
    {
        init_declartor0 -> print();
    }

    ~init_declartor(){
    }

};

class init_deco_list
    : public Program
{
private:
    const Program *init_deco_list0;
    const Program *init_deco_list1;
public:
    init_deco_list(const Program *_init_deco_list0, const Program *_init_deco_list1)
        : init_deco_list0(_init_deco_list0)
        , init_deco_list1(_init_deco_list1)
    {}


    virtual void print() const override
    {
        init_deco_list0 -> print();
        init_deco_list1 -> print();
    }

    ~init_deco_list(){
    }

};




#endif
