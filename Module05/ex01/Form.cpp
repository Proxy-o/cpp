#include "Form.hpp"

Form::Form() : _name("default_name"), _is_signed(false), _grade_to_signe(150), _grade_to_exec(150)
{
    std::cout << "default constructor" << std::endl;
}

Form::Form(const std::string &name, int grade_to_signe, int grade_to_exec) : _name(name), _is_signed(false)
{
    std::cout << " constructor with params" << std::endl;
    if (grade_to_exec > 150 || grade_to_signe > 150)
        throw(Form::GradeTooLowException());
    else if (grade_to_exec < 1 || grade_to_signe < 1)
        throw(Form::GradeTooHighException());
    else
    {
        this->_grade_to_exec = grade_to_exec;
        this->_grade_to_signe = grade_to_signe;
    }
    return;
}

Form::Form(const Form &to_copy)
{
    std::cout << " copy constructor" << std::endl;
    if (this != &to_copy)
        *this = to_copy;
}

Form &Form::operator=(const Form &rs)
{
    if (this == &rs)
        return *this;
    this->_grade_to_exec = rs._grade_to_exec;
    this->_grade_to_signe = rs._grade_to_signe;
    this->_is_signed = rs._is_signed;
    return (*this);
}

Form::~Form()
{
    std::cout << "destructor" << std::endl;
    return;
}
std::string Form::getName() const
{
    return this->_name;
}

bool Form::get_is_signed() const
{
    return this->_is_signed;
}

int Form::get_grade_to_signe() const
{
    return this->_grade_to_signe;
}

int Form::get_grade_to_exec() const
{
    return this->_grade_to_exec;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Error: The grade is too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Error: The grade is too low.");
}

std::ostream &operator<<(std::ostream &out, Form &form)
{
    out << "name : " << form.getName() << std::endl;
    out << "is signed  : ";
    if (form.get_is_signed())
        out << "true " << std::endl;
    else
        out << "false " << std::endl;

    out << "grade required to signe : " << form.get_grade_to_signe() << std::endl;
    out << "grade required to execute : " << form.get_grade_to_exec() << std::endl;
    return (out);
}
std::ostream &operator<<(std::ostream &out, Form *form)
{
    out << "name : " << form->getName() << std::endl;
    out << "is signed  : " << form->get_is_signed() << std::endl;
    out << "grade required to signe : " << form->get_grade_to_signe() << std::endl;
    out << "grade required to execute : " << form->get_grade_to_exec() << std::endl;
    return (out);
}

void Form::beSigned(Bureaucrat &brcrt)

{
    if (brcrt.getGrade() > this->get_grade_to_signe())
        throw(Form::GradeTooLowException());
    else
        this->_is_signed = 1;
    return;
}
