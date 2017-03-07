#ifndef ast_postfix_hpp
#define ast_postfix_hpp

class PostFix
    : public Program
{
private:
    const Program *scope1;
public:
    PostFix(const Program *_scope1)
        :scope1(_scope1)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        scope1 -> print();
    }

    ~PostFix(){
        delete scope1;
    }

};

#endif
