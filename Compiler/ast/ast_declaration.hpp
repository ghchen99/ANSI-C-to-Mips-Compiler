#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include <cmath>

class declaration
    : public Program
{
private:
    const std::string id;
    const Program *Deco1;
public:
    declaration(const std::string &_id, const Program *_Deco1)
        : id(_id)
        , Deco1(_Deco1)
    {}


    virtual void print() const override
    {
    }

    virtual void globalvariable() const {
        std::cout << "in decalration" << '\n';
        Deco1 -> globalvariable();
    }

    ~declaration(){

    }

};




class Init_deco_list2
    : public Program
{
private:
    const Program *Deco1;
    const Program *Deco2;
public:
    Init_deco_list2(const Program *_Deco1, const Program *_Deco2)
        :Deco1(_Deco1)
        ,Deco2(_Deco2)
    {}


    virtual void print() const override
    {
    }

    virtual void globalvariable() const {
       std::cout << ".global\t";
       Deco1 -> print();
       std::cout << '\n';

       std::cout << ".type\t";
       Deco1 -> print();
       std::cout << ",  @object" << '\n';

       std::cout << ".size\t";
       Deco1 -> print();
       std::cout << ",  4" << '\n';

       Deco1 -> print();
       std::cout << ":" << '\n';

       std::cout << ".word\t";
       Deco2 -> globalvariable();
       std::cout << '\n';
    }

    ~Init_deco_list2(){

    }

};

class Init_deco_list1
    : public Program
{
private:
    const Program *Deco1;
public:
    Init_deco_list1(const Program *_Deco1)
        :Deco1(_Deco1)
    {}


    virtual void print() const override
    {
    }

    virtual void globalvariable() const {
       std::cout << ".global\t";
       Deco1 -> print();
       std::cout << '\n';

       std::cout << ".type\t";
       Deco1 -> print();
       std::cout << ",  @object" << '\n';

       std::cout << ".size\t";
       Deco1 -> print();
       std::cout << ",  4" << '\n';

       Deco1 -> print();
       std::cout << ":" << '\n';

       std::cout << ".space\t4" << std::endl;
    }

    ~Init_deco_list1(){

    }

};

#endif
