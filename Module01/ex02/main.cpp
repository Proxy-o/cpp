#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "str adress : " << &str << std::endl;
    std::cout << "adress held by stringPTR : " << stringPTR << std::endl;
    std::cout << "adress held by stringREF : " << &stringREF << std::endl;

    std::cout << "\nstr value: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}
