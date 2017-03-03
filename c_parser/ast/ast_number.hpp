#ifndef ast_number_hpp
#define ast_number_hpp

class Number
    : public Program
{
private:
    double value;
public:
    Number(double _value)
        : value(_value)
    {}

    virtual void print() const override
    {
    }

};

#endif
