#include "AForm.hpp"

AForm::AForm() : _name("default_name"), _is_signed(false), _grade_to_signe(150), _grade_to_exec(150)
{
    std::cout << "default constructor" << std::endl;
}

AForm::AForm(const std::string &name, int grade_to_signe, int grade_to_exec) : _name(name), _is_signed(false)
{
    std::cout << " constructor with params" << std::endl;
    if (grade_to_exec > 150 || grade_to_signe > 150)
        throw(AForm::GradeTooLowException());
    else if (grade_to_exec < 1 || grade_to_signe < 1)
        throw(AForm::GradeTooHighException());
    else
    {
        this->_grade_to_exec = grade_to_exec;
        this->_grade_to_signe = grade_to_signe;
    }
    return;
}

AForm::AForm(const AForm &to_copy)
{
    std::cout << " copy constructor" << std::endl;
    if (this != &to_copy)
        *this = to_copy;
}

AForm &AForm::operator=(const AForm &rs)
{
    if (this == &rs)
        return *this;
    this->_grade_to_exec = rs._grade_to_exec;
    this->_grade_to_signe = rs._grade_to_signe;
    this->_is_signed = rs._is_signed;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "destructor" << std::endl;
    return;
}
std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::get_is_signed() const
{
    return this->_is_signed;
}

int AForm::get_grade_to_signe() const
{
    return this->_grade_to_signe;
}

int AForm::get_grade_to_exec() const
{
    return this->_grade_to_exec;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Error: The grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Error: The grade is too low.");
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Error: The Form not signed");
}

std::ostream &operator<<(std::ostream &out, AForm &AForm)
{
    out << "name : " << AForm.getName() << std::endl;
    out << "is signed  : ";
    if (AForm.get_is_signed())
        out << "true " << std::endl;
    else
        out << "false " << std::endl;
    out << "grade required to signe : " << AForm.get_grade_to_signe() << std::endl;
    out << "grade required to execute : " << AForm.get_grade_to_exec() << std::endl;
    return (out);
}
std::ostream &operator<<(std::ostream &out, AForm *AForm)
{
    out << "name : " << AForm->getName() << std::endl;
    out << "is signed  : " << AForm->get_is_signed() << std::endl;
    out << "grade required to signe : " << AForm->get_grade_to_signe() << std::endl;
    out << "grade required to execute : " << AForm->get_grade_to_exec() << std::endl;
    return (out);
}

void AForm::beSigned(Bureaucrat &brcrt)

{
    if (brcrt.getGrade() > this->get_grade_to_signe())
        throw(AForm::GradeTooLowException());
    else
        this->_is_signed = 1;
    return;
}

void AForm::check_requirements(Bureaucrat const &executor) const
{
    if (this->get_is_signed() == false)
        throw(AForm::FormNotSignedException());
    else if (executor.getGrade() > this->get_grade_to_exec())
        throw(AForm::GradeTooLowException());
}