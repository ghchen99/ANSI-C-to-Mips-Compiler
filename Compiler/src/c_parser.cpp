#include "header.hpp"

int main()
{
    //stack = 0;
    //std::vector<std::string> v;
    const Program *ast=parseAST();
    ast->print();

    std::cout << "#finishing" << '\n';
    std::cout<<std::endl;


    return 0;
}
