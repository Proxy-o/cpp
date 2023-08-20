#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    // std::cout << "------------test 1----------" << std::endl;

    // try
    // {
    //     Bureaucrat b("othmane", 10);
    //     ShrubberyCreationForm f("form1");
    //     b.signForm(f);
    //     f.apply_execute(b);
    //     std::cout << f;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what();
    // }

    std::cout << "------------test 2----------" << std::endl;

    try
    {
        Bureaucrat b2("othmane", 500);
        RobotomyRequestForm f2("form2");
        b2.signForm(f2);
        f2.apply_execute(b2);
        f2.apply_execute(b2);
        f2.apply_execute(b2);
        f2.apply_execute(b2);
        std::cout << f2;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
