#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "default constructor called" << std::endl;
}

Intern::Intern(const Intern &to_copy)
{
    (void)to_copy;
    std::cout << "copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &right_side)
{
    (void)right_side;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "distructor called" << std::endl;
}

const char *Intern::FormNotValideException::what() const throw()
{
    return ("Error: Form not valide.");
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string forms_name[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *forms[] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};

    int i = 0;
    for (; i < 3; i++)
    {
        if (forms_name[i] != name)
            delete forms[i];
        else
            break;
    }
    if (i == 3)
        throw FormNotValideException();
    return (forms[i]);
}