#include "ast.hpp"

int main()
{
    const Program *ast=parseAST();

    std::cout<<std::endl;

    return 0;
}
