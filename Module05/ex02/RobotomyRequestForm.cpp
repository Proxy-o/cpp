#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy) : AForm(to_copy), _target(to_copy._target)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &right_side)
{
    this->_target = right_side._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    try
    {
        this->check_requirements(executor);
        static int i;
        if (i % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully " << std::endl;
        else
            std::cout << "the robotomy failed" << std::endl;
        i++;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
