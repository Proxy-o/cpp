#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;
class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const int grade);
    Bureaucrat(const Bureaucrat &to_copy);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &right_side);
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    void signForm(Form &form);
};
std::ostream &operator<<(std::ostream &out, Bureaucrat &b);
std::ostream &operator<<(std::ostream &out, Bureaucrat *b);

#endif