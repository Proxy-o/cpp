#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool _is_signed;
    int _grade_to_signe;
    int _grade_to_exec;

public:
    Form();
    Form(const std::string &name, int grade_to_signe, int grade_to_exec);
    Form(const Form &to_copy);
    ~Form();
    Form &operator=(const Form &right_side);
    std::string getName() const;
    bool get_is_signed() const;
    int get_grade_to_signe() const;
    int get_grade_to_exec() const;

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

    void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &o, Form &f);
std::ostream &operator<<(std::ostream &o, Form *f);

#endif