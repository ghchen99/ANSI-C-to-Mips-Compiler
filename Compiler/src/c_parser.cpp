#include "header.hpp"

int main()
{

    //std::vector<std::string> v;
    const Program *ast=parseAST();
    ast->print();
    std::cout<<std::endl;

    return 0;
}
