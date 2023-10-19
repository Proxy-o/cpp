#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(19);
    c.push_back(4551);
    c.push_back(14);
    c.push_back(9);
    c.push_back(79);
    c.push_back(0);

    std::vector<int>::iterator a = easyfind(c, 8);
    if (a == c.end())
        std::cout << "did not found it " << std::endl;
    else
        std::cout << *a << std::endl;
}
