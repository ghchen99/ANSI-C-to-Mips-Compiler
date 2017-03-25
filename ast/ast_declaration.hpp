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


    virtual void print(ALL *ptr) const override
    {
        Deco1 -> print(ptr);
    }

    virtual void globalvariable(ALL *ptr) const {
        //std::cout << "in decalration" << '\n';
        Deco1 -> globalvariable(ptr);
    }

    virtual void countstack(ALL *ptr) const override{
        Deco1 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 8;
    }

    ~declaration(){

    }

};

class Init_deco_list
    : public Program
{
private:
    const Program *Deco1;
    const Program *Deco2;
public:
    Init_deco_list(const Program *_Deco1, const Program *_Deco2)
        :Deco1(_Deco1)
        ,Deco2(_Deco2)
    {}


    virtual void print(ALL *ptr) const override
    {
    }

    virtual void globalvariable(ALL *ptr) const {
        Deco1 -> globalvariable(ptr);
        Deco2 -> globalvariable(ptr);
    }

    virtual void countstack(ALL *ptr) const override{
        Deco1 -> countstack(ptr);
        Deco1 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 8;
    }

    ~Init_deco_list(){

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

    virtual void countstack(ALL *ptr) const override{
        Deco1 -> countstack(ptr);
        Deco2 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 8;
    }


    virtual void print(ALL *ptr) const override
    {
        int tmp = ptr->getIndex();
        //std::cout << "#index in declareation is " << tmp << '\n';
        //std::cout << "#initialise a variable" << '\n';
        std::cout << "sw\t$zero,\t" << tmp << "($sp)" << '\n';
        std::string s = Deco1 -> getId();
        //std::cout << "#add the stack index variable " << s << " to the map" << '\n';
        ptr->map.insert ( std::pair<std::string,int>(s,tmp));
        //std::cout << "#increment index, now is " << tmp <<" and increment by 4" << '\n';
        ptr->increIndex();

        Deco2 -> declarationPrint(ptr);

        std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
    }

    virtual void globalvariable(ALL *ptr) const {
       std::cout << ".global\t";
       Deco1 -> print(ptr);
       std::cout << '\n';

       std::cout << ".type\t";
       Deco1 -> print(ptr);
       std::cout << ",  @object" << '\n';

       std::cout << ".size\t";
       Deco1 -> print(ptr);
       std::cout << ",  4" << '\n';

       Deco1 -> print(ptr);
       std::cout << ":" << '\n';

       std::cout << ".word\t";
       Deco2 -> globalvariable(ptr);
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

    virtual void countstack(ALL *ptr) const override{
        Deco1 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 8;
    }

    virtual void print(ALL *ptr) const override
    {
        int tmp = ptr->getIndex();
        //std::cout << "#index in declareation is " << tmp << '\n';
        //std::cout << "#initialise a variable" << '\n';
        std::cout << "sw\t$zero,\t" << tmp << "($sp)" << '\n';
        std::string s = Deco1 -> getId();
        //std::cout << "#add the stack index variable " << s << " to the map" << '\n';
        ptr->map.insert ( std::pair<std::string,int>(s,tmp));
        //std::cout << "#increment index, now is " << tmp <<" and increment by 4" << '\n';
        ptr->increIndex();
    }

    virtual void globalvariable(ALL *ptr) const {
       std::cout << ".global\t";
       Deco1 -> print(ptr);
       std::cout << '\n';

       std::cout << ".type\t";
       Deco1 -> print(ptr);
       std::cout << ",  @object" << '\n';

       std::cout << ".size\t";
       Deco1 -> print(ptr);
       std::cout << ",  4" << '\n';

       Deco1 -> print(ptr);
       std::cout << ":" << '\n';

       std::cout << ".space\t4" << std::endl;
    }

    ~Init_deco_list1(){

    }

};

#endif
