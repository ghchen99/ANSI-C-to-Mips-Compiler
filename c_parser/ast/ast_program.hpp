#ifndef ast_program_hpp
#define ast_program_hpp

#include <string>
#include <iostream>
#include <map>


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
        std::cout << "\t<Variable id=\"" << id;
        std::cout << "\" />" << std::endl;
    }

	~Variable(){
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
        std::cout << "<Scope>" ;
        Variable -> print();
        std::cout << "</Scope>" << std::endl;
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
        std::cout << "\" />" << std::endl;
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
        std::cout << "\" />" << std::endl;
        Parameter -> print();
        Scope -> print();
    }

	~Function(){
	}

};



#endif
