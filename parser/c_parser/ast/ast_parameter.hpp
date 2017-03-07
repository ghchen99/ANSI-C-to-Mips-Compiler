#ifndef ast_parameter_hpp
#define ast_parameter_hpp


class param_list
    : public Program
{
private:
    const Program *declaration1;
    const Program *declaration2;
public:
    param_list(const Program *_declaration1,const Program *_declaration2)
        :declaration1(_declaration1),
         declaration2(_declaration2)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        declaration1 -> print();
        declaration2 -> print();
    }

    ~param_list(){
        delete declaration1;
        delete declaration2;
    }

};


class parameter
    : public Program
{
private:
    const Program *parameter1;
public:
    parameter(const Program *_parameter1)
        :parameter1(_parameter1)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        std::cout << "<Parameter id=\"" ;
        parameter1 -> print();
        std::cout << "\" />" << std::endl;
    }

    ~parameter(){
        delete parameter1;
    }

};

class MutiplyParameter
    : public Program
{
private:
    const Program *parameter1;
    const Program *parameter2;
public:
    MutiplyParameter(const Program *_parameter1,const Program *_parameter2)
        :parameter1(_parameter1),
        parameter2(_parameter2)
    {}


    virtual void print() const override
    {
        //std::cout << "in declaration path" << '\n';
        std::cout << "<Parameter id=\"" ;
        parameter1 -> print();
        std::cout << "\" />" << std::endl;
        parameter2 -> print();
    }

    ~MutiplyParameter(){
        delete parameter1;
        delete parameter2;
    }

};

#endif
