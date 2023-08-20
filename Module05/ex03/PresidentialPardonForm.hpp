#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "iostream"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
    PresidentialPardonForm();

public:
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &to_copy);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &right_side);
    void execute(Bureaucrat const &executor) const;
};

#endif