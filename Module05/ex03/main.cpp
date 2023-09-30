#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat b("othmane", 1);
        Intern i;
        AForm *f;
        f = i.makeForm("robotomy request", "home");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
