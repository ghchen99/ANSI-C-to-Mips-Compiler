#ifndef ast_vairable_hpp
#define ast_vairable_hpp

class Variable
    : public Program
{
private:
    const std::string id;
public:
    Variable(const std::string &_id)
        : id(_id)
    {}

    const std::string getId() const
    { return id; }

    virtual void print() const override
    {
        //std::cout << "int vari" << '\n';
        std::cout<<id;
    }

    ~Variable(){
    }

};

#endif
