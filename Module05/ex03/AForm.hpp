#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string _name;
    bool _is_signed;
    int _grade_to_signe;
    int _grade_to_exec;

public:
    AForm();
    AForm(const std::string &name, int grade_to_signe, int grade_to_exec);
    AForm(const AForm &to_copy);
    virtual ~AForm();
    AForm &operator=(const AForm &right_side);
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
    class FormNotSignedException : public std::exception
    {
        virtual const char *what() const throw();
    };

    void beSigned(Bureaucrat &bureaucrat);

    void check_requirements(Bureaucrat const &executor) const;
    virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm &f);
std::ostream &operator<<(std::ostream &o, AForm *f);

#endif