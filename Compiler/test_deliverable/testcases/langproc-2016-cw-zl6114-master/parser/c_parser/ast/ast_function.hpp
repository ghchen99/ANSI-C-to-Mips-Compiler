#ifndef ast_function_hpp
#define ast_function_hpp

class Function
	: public Program
{
private:
    const Program *FunctionId;
    const Program *Parameter;
    const Program *Scope;
public:
    Function(const Program *_FunctionId,
             const Program *_Parameter,
             const Program *_Scope)
        : FunctionId(_FunctionId),
          Parameter(_Parameter),
          Scope(_Scope)
    {}

    virtual void print() const override
    {
        std::cout << "<Function id=\"";
        FunctionId -> print();
        std::cout << "\">" << "\n";
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
    const Program *FunctionId;
    const Program *Scope;
public:
    FunctionNoParam(const Program *_FunctionId,
             const Program *_Scope)
        : FunctionId(_FunctionId),
          Scope(_Scope)
    {}

    virtual void print() const override
    {
        std::cout << "<Function id=\"";
        FunctionId -> print();
        std::cout << "\">" << "\n";
        Scope -> print();
        std::cout << "</Function>" << '\n';
    }

	~FunctionNoParam(){
	}

};

#endif
