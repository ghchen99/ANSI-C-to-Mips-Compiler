#include "header.hpp"

int main()
{
    //std::map<std::string,double> map;
    //int x = 0;
    //stack = 0;
    //std::vector<std::string> v;
    ALL *ptr = new ALL();

    const Program *ast=parseAST();

    ast -> countstack(ptr);

    ast -> print(ptr);
    std::cout << "#finishing" << '\n';
    std::cout<<std::endl;

    return 0;
}
