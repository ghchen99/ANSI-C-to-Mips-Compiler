#ifndef ast_program_hpp
#define ast_program_hpp

#include <string>
#include <iostream>
#include <map>


// ########  #######  ########     ##       ######## ##     ## ######## ##
//    ##    ##     ## ##     ##    ##       ##       ##     ## ##       ##
//    ##    ##     ## ##     ##    ##       ##       ##     ## ##       ##
//    ##    ##     ## ########     ##       ######   ##     ## ######   ##
//    ##    ##     ## ##           ##       ##        ##   ##  ##       ##
//    ##    ##     ## ##           ##       ##         ## ##   ##       ##
//    ##     #######  ##           ######## ########    ###    ######## ########

class Program
{
public:
    virtual ~Program()
    {
    }

    Program(){
    }

    virtual void print() const =0;

};

class Variable
	: public Program
{
private:
        std::string type;
    	std::string id;
public:
	Variable(const std::string &_type,const std::string &_id)
		: type(_type), id(_id)
	{
	}

    virtual void print() const override
    {
        std::cout << "<Variable id=\"" << id;
        std::cout << "\" />" << std::endl;
    }

	~Variable(){
	}
};

class MultipleVariable
	: public Program
{
private:
    const Program *Variable1;
    const Program *Variable2;
public:
    MultipleVariable(const Program *_Variable1,const Program *_Variable2)
        : Variable1(_Variable1),
          Variable2(_Variable2)
    {}

    virtual void print() const override
    {
        Variable1 -> print();
        Variable2 -> print();
    }

	~MultipleVariable(){
	}
};


class Scope
	: public Program
{
private:
    const Program *Variable;
public:
    Scope(const Program *_Variable)
        : Variable(_Variable)
    {}

    virtual void print() const override
    {
        std::cout << "<Scope>\n" ;
        Variable -> print();
        std::cout << "</Scope>" << "\n";
    }

	~Scope(){
	}
};

class Parameter
	: public Program
{
private:
     const std::string type;
     const std::string id;
public:
	Parameter(const std::string &_type,const std::string &_id)
		: type(_type), id(_id)
	{
	}

    virtual void print() const override
    {
        std::cout << "<Parameter id=\"" << id;
        std::cout << "\" />" << "\n";
    }

	~Parameter(){
	}
};

class Empty
	: public Program
{
public:
	Empty()
	{
	}

    virtual void print() const override
    {
    }

	~Empty(){
	}
};

class Function
	: public Program
{
private:
    const std::string type;
    const std::string id;
    const Program *Parameter;
    const Program *Scope;
public:
    Function(const std::string _type,
             const std::string _id,
             const Program *_Parameter,
             const Program *_Scope)
        : type(_type),
          id(_id),
          Parameter(_Parameter),
          Scope(_Scope)
    {}

    virtual void print() const override
    {
        std::cout << "<Function id=\"" << id;
        std::cout << "\" />" << "\n";
        Parameter -> print();
        Scope -> print();
        std::cout << "</Function>" << '\n';
    }

	~Function(){
	}

};

class FunctionNoParam
	: public Program
{
private:
    const std::string type;
    const std::string id;
    const Program *Scope;
public:
    FunctionNoParam(const std::string _type,
             const std::string _id,
             const Program *_Scope)
        : type(_type),
          id(_id),
          Scope(_Scope)
    {}

    virtual void print() const override
    {
        std::cout << "<Function id=\"" << id;
        std::cout << "\" />" << "\n";
        Scope -> print();
        std::cout << "</Function>" << '\n';
    }

	~FunctionNoParam(){
	}

};



#endif
