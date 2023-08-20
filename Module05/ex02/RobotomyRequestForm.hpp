#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "iostream"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
    RobotomyRequestForm();

public:
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &to_copy);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &right_side);
    void execute(Bureaucrat const &executor) const;
};

#endif