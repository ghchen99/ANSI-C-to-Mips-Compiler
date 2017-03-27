#ifndef ast_toplevel_hpp
#define ast_toplevel_hpp

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <map>

//Register t0 is the register used to put the return value in.
//Register t1 is the register used to put the calculated value after int x = ? or x  = ?

// ########  #######  ########     ##       ######## ##     ## ######## ##
//    ##    ##     ## ##     ##    ##       ##       ##     ## ##       ##
//    ##    ##     ## ##     ##    ##       ##       ##     ## ##       ##
//    ##    ##     ## ########     ##       ######   ##     ## ######   ##
//    ##    ##     ## ##           ##       ##        ##   ##  ##       ##
//    ##    ##     ## ##           ##       ##         ## ##   ##       ##
//    ##     #######  ##           ######## ########    ###    ######## ########

//mutable int index;
class ALL
{
    using bindingsMap = std::map<std::string,double>;
protected:
    mutable int index;
public:
    mutable int stacksize = 0;
    mutable int parameterId = 4;
    mutable bindingsMap map;
    mutable bindingsMap numberMap;
    ALL(int _index = 0)
        :index(_index)
    {}

    int getIndex() const{
        return index;
    }

    void increIndex() const{
        index  = index + 4;
    }

    mutable int makeNameUnq=0;

    std::string makeName(std::string base) const
    {
        return "_"+base+"_"+std::to_string(makeNameUnq++);
    }

};


class Program
    :public ALL
{
public:
    virtual ~Program()
    {
    }

    Program(){ }

    virtual void print(ALL *ptr) const =0;

    virtual void globalvariable(ALL *ptr) const {}

    virtual void returnprint(ALL *ptr) const{}

    virtual void parameterPrint(ALL *ptr) const{}

    virtual const std::string getId() const{
        return 0;
    }

    virtual void declarationPrint(ALL *ptr) const {}

    virtual void countstack(ALL *ptr) const =0;


};

class Program_call
    : public Program
{
private:
    const Program *Program_call1;
    const Program *Program_call2;
public:
    Program_call(const Program *_Program_call1, const Program *_Program_call2)
        : Program_call1(_Program_call1)
        , Program_call2(_Program_call2)
    {}


    virtual void print(ALL *ptr) const override
    {
        Program_call1 -> print(ptr);
        Program_call2 -> print(ptr);
    }

    virtual void countstack(ALL *ptr) const override{
        Program_call1 -> countstack(ptr);
        Program_call2 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 4;
    }

    ~Program_call(){
        delete Program_call1;
        delete Program_call2;
    }


};

class Empty
	: public Program
{
public:
	Empty()
	{
	}

    virtual void print(ALL *ptr) const override
    {
    }

	~Empty(){
	}

    virtual void countstack(ALL *ptr) const override{
    }
};

class EmptyString
	: public Program
{
private:
    const std::string id1;
    const std::string id2;
public:
	EmptyString (std::string &_id1, const std::string &_id2)
        : id1(_id1)
        , id2(_id2)
	{
	}

    virtual void print(ALL *ptr) const override
    {
    }

	~EmptyString(){
	}

    virtual void countstack(ALL *ptr) const override{
    }
};

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

    virtual void print(ALL *ptr) const override
    {
        //std::cout << "int vari" << '\n';
        std::cout<<id;
    }

    virtual void returnprint(ALL *ptr) const override{
        int tmp = ptr->map[id];
//         lui	$2,%hi(x)
// lw	$2,%lo(x)($2)

        if(tmp == -1){
            std::cout << "lui\t$t0,\t%hi("<< id <<")" << '\n';
            std::cout << "lw\t$t0,\t%lo("<< id <<")($t0)" << '\n';
        }else{
            //std::cout << ptr->map[id] << '\n';
            std::cout << "lw\t$t0,\t" << ptr->map[id] << "($sp)" << '\n';
        }
    }

    virtual void declarationPrint(ALL *ptr) const override{
        int tmp = ptr->map[id];
        if(tmp == -1){
            std::cout << "lui\t$t1,\t%hi("<< id <<")" << '\n';
            std::cout << "lw\t$t1,\t%lo("<< id <<")($t1)" << '\n';
        }else{
            std::cout << "lw\t$t1,\t" << ptr->map[id] << "($sp)" << '\n';
        }
    }

    ~Variable(){
    }

    virtual void countstack(ALL *ptr) const override{
        ptr->stacksize = ptr->stacksize + 4;
    }

};

class Number
    : public Program
{
private:
    int value;
public:
    Number(int _value)
        : value(_value)
    {}

    virtual void print(ALL *ptr) const override
    {
        std::cout << value;
    }

    virtual void globalvariable(ALL *ptr) const {
        std::cout << value;
    }

    virtual void returnprint(ALL *ptr) const override{
        //std::cout << ptr->map[id] << '\n';
        if (value > 65535){
            std::cout << "li\t$t0,\t" << value << '\n';
        }else if((value < 65535) && (value >= 0)){
            std::cout << "addiu\t$t0,\t$zero,\t" << value << '\n';
        }else if(value < 0){
            std::cout << "li\t$t0,\t" << value << '\n';
        }
    }


    virtual void declarationPrint(ALL *ptr) const override{
            std::cout << "li\t$t1,\t" << value << '\n';
    }

    virtual void countstack(ALL *ptr) const override{
        ptr->stacksize = ptr->stacksize + 4;
    }

};
#endif
