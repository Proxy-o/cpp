#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;
class Intern
{

public:
    Intern();
    Intern(const Intern &to_copy);
    ~Intern();
    Intern &operator=(const Intern &right_side);

    AForm *makeForm(std::string name, std::string taget);
    class FormNotValideException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

#endif