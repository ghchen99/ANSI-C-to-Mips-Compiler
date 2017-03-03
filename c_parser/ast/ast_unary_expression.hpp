#ifndef ast_unary_expression_hpp
#define ast_unary_expression_hpp

class unary_expression
	: public Program
{
private:
    //const std::string id;
    const Program *unary_expression0;
public:
    unary_expression(
            // const std::string &_id,
             const Program *_unary_expression0)
        : //id(_id),
          unary_expression0(_unary_expression0)
    {}

    virtual void print() const override
    {
		// std::cout << "in unary_expression" << '\n';
        // unary_expression0 -> print();
    }

	~unary_expression(){
	}

};

#endif
