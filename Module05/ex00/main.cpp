#include "Bureaucrat.hpp"

int main()
{
    std::cout << "------------test 1----------" << std::endl;
    Bureaucrat a("othmane", 149);
    try
    {
        std::cout << a;
        a.decrementGrade();
        a.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // return 0;
    std::cout << "------------test 2----------" << std::endl;
    try
    {
        Bureaucrat b("said", 2);
        std::cout << b;
        b.incrementGrade();
        b.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------test 2----------" << std::endl;
    try
    {
        Bureaucrat b("name3", 156);
        std::cout << b;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
