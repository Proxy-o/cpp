#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "iostream"

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &to_copy);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &right_side);
    void apply_execute(Bureaucrat const &executor) const;
};

#endif