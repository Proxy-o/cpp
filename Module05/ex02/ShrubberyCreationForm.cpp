#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &to_copy) : AForm(to_copy), _target(to_copy._target)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &right_side)
{
    this->_target = right_side._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    try
    {
        this->check_requirements(executor);
        std::string name = this->_target + "_shrubbery";
        std::ofstream file(name.c_str());
        file << "                  /\\\n";
        file << "                 //\\\\\n";
        file << "                ///\\\\\\\n";
        file << "               ////\\\\\\\\\n";
        file << "              /////\\\\\\\\\\\n";
        file << "             //////\\\\\\\\\\\\\n";
        file << "            ///////\\\\\\\\\\\\\\\n";
        file << "           ////////\\\\\\\\\\\\\\\\\n";
        file << "          /////////\\\\\\\\\\\\\\\\\\\n";
        file << "         //////////\\\\\\\\\\\\\\\\\\\\\n";
        file << "               |||\n";
        file << "               |||\n";
        file << "               |||\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}
