#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default_name"), _grade(150)
{
    std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name)
{

    std::cout << "constructor with parameter called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &to_copy) : _name(to_copy._name), _grade(to_copy._grade)
{
    std::cout << "copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &right_side)
{
    if (this != &right_side)
        this->_grade = right_side._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "distructor called" << std::endl;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}
std::string Bureaucrat::getName() const
{
    return this->_name;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Error: The grade is too high. Grades must be between 1 and 150.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Error: The grade is too low. Grades must be between 1 and 150.");
}

void Bureaucrat::incrementGrade()
{

    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "incrementing Grade" << std::endl;
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "decrementing Grade" << std::endl;
    this->_grade += 1;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return out;
}
std::ostream &operator<<(std::ostream &out, Bureaucrat *b)
{
    out << b->getName() << ", bureaucrat grade " << b->getGrade() << std::endl;
    return out;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << "  couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
