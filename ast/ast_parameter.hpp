#ifndef ast_parameter_hpp
#define ast_parameter_hpp

class ParameterDeclare
    : public Program
{
private:
    const std::string id1;
    const Program *Program_call1;
public:
    ParameterDeclare(const std::string _id1,const Program *_Program_call1)
        : id1(_id1)
        , Program_call1(_Program_call1)
    {}


    virtual void print(ALL *ptr) const override
    {
        if(ptr->parameterId < 8){
            int p = ptr->parameterId;
            int tmp = ptr->getIndex();
            //std::cout << "sw\t$zero,\t" << tmp << "($sp)" << '\n';
            std::cout << "sw\t$"<< p <<",\t" << tmp << "($sp)" << '\n';
            std::string s = Program_call1 -> getId();
            ptr->map.insert ( std::pair<std::string,int>(s,tmp));
            ptr->increIndex();
            ptr->parameterId++;
        }else{
            int tmp = ptr->getIndex();
            //std::cout << "#index in declareation is " << tmp << '\n';
            //std::cout << "#initialise a variable" << '\n';
            std::cout << "sw\t$zero,\t" << tmp << "($sp)" << '\n';
            std::string s = Program_call1 -> getId();
            //std::cout << "#add the stack index variable " << s << " to the map" << '\n';
            ptr->map.insert ( std::pair<std::string,int>(s,tmp));
            //std::cout << "#increment index, now is " << tmp <<" and increment by 4" << '\n';
            ptr->increIndex();
        }
    }

    virtual void countstack(ALL *ptr) const override{
        Program_call1 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 4;
    }

    ~ParameterDeclare(){
    }


};


class ParameterDeclareMore
    : public Program
{
private:
    const Program *Program_call1;
    const Program *Program_call2;
public:
    ParameterDeclareMore(const Program *_Program_call1,const Program *_Program_call2)
        : Program_call1(_Program_call1)
        , Program_call2(_Program_call2)
    {}


    virtual void print(ALL *ptr) const override
    {
        if(ptr->parameterId < 8){
            int p = ptr->parameterId;
            int tmp = ptr->getIndex();
            //std::cout << "sw\t$zero,\t" << tmp << "($sp)" << '\n';
            std::cout << "sw\t$"<< p <<",\t" << tmp << "($sp)" << '\n';
            std::string s = Program_call1 -> getId();
            ptr->map.insert ( std::pair<std::string,int>(s,tmp));
            ptr->increIndex();
            ptr->parameterId++;
        }else{
            int tmp = ptr->getIndex();
            //std::cout << "#index in declareation is " << tmp << '\n';
            //std::cout << "#initialise a variable" << '\n';
            std::cout << "sw\t$zero,\t" << tmp << "($sp)" << '\n';
            std::string s = Program_call1 -> getId();
            //std::cout << "#add the stack index variable " << s << " to the map" << '\n';
            ptr->map.insert ( std::pair<std::string,int>(s,tmp));
            //std::cout << "#increment index, now is " << tmp <<" and increment by 4" << '\n';
            ptr->increIndex();
        }

        Program_call2 ->  print(ptr);
    }

    virtual void countstack(ALL *ptr) const override{
        Program_call1 -> countstack(ptr);
        Program_call2 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 8;
    }

    ~ParameterDeclareMore(){
    }


};

#endif
