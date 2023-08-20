#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "------------test 1----------" << std::endl;

    try
    {
        Bureaucrat b("othmane", 10);
        ShrubberyCreationForm f("form1");
        b.signForm(f);
        b.executeForm(f);
        std::cout << f;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }

    std::cout << "------------test 2----------" << std::endl;

    try
    {
        Bureaucrat b2("othmane", 10);
        RobotomyRequestForm f2("form2");
        b2.signForm(f2);
        b2.executeForm(f2);
        b2.executeForm(f2);
        b2.executeForm(f2);
        b2.executeForm(f2);
        b2.executeForm(f2);
        std::cout << f2;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------test 3----------" << std::endl;

    try
    {
        Bureaucrat b3("othmane", 1);
        PresidentialPardonForm f3("form3");
        b3.signForm(f3);
        b3.executeForm(f3);
        std::cout
            << f3;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
