#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    PRINT("Default constructor called");
}

ScalarConverter::~ScalarConverter(void)
{
    PRINT("Destructor called");
}

ScalarConverter::ScalarConverter(ScalarConverter const &toCopy)
{
    PRINT("Copy constructor called");
    *this = toCopy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &right_side)
{
    PRINT("Assignment operator called");
    if (this != &right_side)
    {
        // nothing to do here
    }
    return (*this);
}

int ScalarConverter::getType(std::string str) const
{
    int type;
    if (str.empty())
        type = 0;
    else if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
        type = 1;

    return (type);
}

void ScalarConverter::convert(std::string str)
{
    int type;

    type = ScalarConverter::getType(str);
}