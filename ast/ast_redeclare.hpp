#ifndef ast_redeclare_hpp
#define ast_redeclare_hpp


class declaration_call
    : public Program
{
private:
    const Program *Program_call1;
public:
    declaration_call(const Program *_Program_call1)
        : Program_call1(_Program_call1)
    {}


    virtual void print(ALL *ptr) const override
    {
        Program_call1 -> declarationPrint(ptr);
    }

    ~declaration_call(){
        delete Program_call1;
    }
    virtual void countstack(ALL *ptr) const override{
        Program_call1 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 4;
    }


};


class ReDeclare
    : public Program
{
private:
    const Program *Program_call1;
    const std::string id1;
    const Program *Program_call2;
public:
    ReDeclare(const Program *_Program_call1,const std::string _id1,const Program *_Program_call2)
        : Program_call1(_Program_call1)
        , id1(_id1)
        , Program_call2(_Program_call2)
    {}


    virtual void print(ALL *ptr) const override
    {
    }

    virtual void declarationPrint(ALL *ptr) const override
    {
        //std::cout << "in ReDeclare" << '\n';
        if (id1 == "="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                Program_call2 -> declarationPrint(ptr);
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                Program_call2 -> declarationPrint(ptr);
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == "+="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "add\t$t1,\t$t3,\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "add\t$t1,\t$t3,\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == "-="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "sub\t$t1,\t$t3,\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "sub\t$t1,\t$t3,\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == "*="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "mult\t$t1,\t$t3" << '\n';
                std::cout << "mflo\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "mult\t$t1,\t$t3" << '\n';
                std::cout << "mflo\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == "/="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "div\t$zero,\t$t3,\t$t1" << '\n';
                std::cout << "mflo\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "div\t$zero,\t$t3,\t$t1" << '\n';
                std::cout << "mflo\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == "%="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "div\t$zero,\t$t3,\t$t1" << '\n';
                std::cout << "mfhi\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "div\t$zero,\t$t3,\t$t1" << '\n';
                std::cout << "mfhi\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == "<<="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "sllv\t$t1,\t$t3,\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "sllv\t$t1,\t$t3,\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == ">>="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "slav\t$t1,\t$t3,\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "slav\t$t1,\t$t3,\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == "&="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "and\t$t1,\t$t3,\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "and\t$t1,\t$t3,\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == "^="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "xor\t$t1,\t$t3,\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "xor\t$t1,\t$t3,\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }else if(id1 == "|="){
            std::string s = Program_call1 -> getId();
            int tmp = ptr->map[s];
            if(tmp == -1){
                int index = ptr->getIndex();
                std::cout << "lui\t$t1,\t%hi("<< s <<")" << '\n';
                std::cout << "lw\t$t1,\t%lo("<< s <<")($t1)" << '\n';
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "or\t$t1,\t$t3,\t$t1" << '\n';
                ptr->map[s] = index;
                //ptr->map.insert ( std::pair<std::string,int>(s,index));
                ptr->increIndex();
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }else{
                Program_call1 -> declarationPrint(ptr);
                std::cout << "move\t$t3,\t$t1" << '\n';
                Program_call2 -> declarationPrint(ptr);
                std::cout << "or\t$t1,\t$t3,\t$t1" << '\n';
                std::cout << "sw\t$t1,\t" << ptr->map[s] << "($sp)" << '\n';
            }
        }
    }

    virtual void countstack(ALL *ptr) const override{
        Program_call1 -> countstack(ptr);
        Program_call2 -> countstack(ptr);
        ptr->stacksize = ptr->stacksize + 8;
    }

    ~ReDeclare(){
        delete Program_call1;
        delete Program_call2;
    }


};

#endif
