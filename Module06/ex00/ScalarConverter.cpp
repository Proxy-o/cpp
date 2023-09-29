/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:32:58 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 11:32:59 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

bool ScalarConverter::is_valid_int(std::string str)
{
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool ScalarConverter::is_valid_float(std::string str)
{
    size_t last_digit;
    size_t i;

    last_digit = str.length() - 1;
    if (str.at(last_digit) != 'f')
        return (false);
    if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
        return (true);
    if (str.at(0) == '+' || str.at(0) == '-')
        i = 1;
    else
        i = 0;
    for (; i < last_digit; i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
            return (false);
    }
    if (str.find('.') >= 16)
        return (false);
    return (true);
}

double ScalarConverter::is_valid_double(std::string str)
{
    size_t last_digit;
    size_t i;

    last_digit = str.length() - 1;
    if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
        return (true);
    if (str.at(0) == '+' || str.at(0) == '-')
        i = 1;
    else
        i = 0;
    for (; i < last_digit; i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '.')
            return (false);
    }
    if (str.find('.') >= 16)
        return (false);
    return (true);
}

int ScalarConverter::getType(std::string str)
{
    int type;
    type = INVALID;
    if (str.empty())
        type = INVALID;
    else if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
        type = CHAR;
    else if (is_valid_int(str) && str.length() < 16)
        type = INT;
    else if (is_valid_float(str))
        type = FLOAT;
    else if (is_valid_double(str))
        type = DOUBLE;
    return (type);
}

void ScalarConverter::to_char(std::string str)
{
    char c;

    c = str[0];
    PRINT("char: '" << c << "'");
    PRINT("int: " << static_cast<int>(c));
    PRINT("float: " << static_cast<float>(c) << ".0f");
    PRINT("double: " << static_cast<double>(c) << ".0");
}

bool ScalarConverter::overflow_int(std::string str)
{
    long int nbr;

    nbr = std::stol(str);

    if (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min())
    {
        ERROR("char: impossible");
        ERROR("int: impossible");
        PRINT("float: " << static_cast<float>(nbr) << ".0f");
        PRINT("double: " << static_cast<double>(nbr) << ".0");
        return (true);
    }
    return (false);
}
void ScalarConverter::to_int(std::string str)
{

    if (overflow_int(str))
        return;
    else
    {
        int nbr = std::stoi(str);

        if (nbr > std::numeric_limits<char>::max() || nbr < std::numeric_limits<char>::min())
        {
            ERROR("char: impossible");
        }
        else if (std::isprint(nbr))
        {
            PRINT("char: '" << static_cast<char>(nbr) << "'");
        }
        else
            ERROR("char: Non displayable");
        PRINT("int: " << nbr);
        PRINT("float: " << static_cast<float>(nbr) << ".0f");
        PRINT("double: " << static_cast<double>(nbr) << ".0");
    }
}

void ScalarConverter::to_float(std::string str)
{
    float nbr;

    nbr = std::stof(str);
    if (nbr > std::numeric_limits<char>::max() || nbr < std::numeric_limits<char>::min() || std::isnan(nbr) || std::isinf(nbr))
    {
        ERROR("char: impossible");
    }
    else if (std::isprint(nbr))
    {
        PRINT("char: '" << static_cast<char>(nbr) << "'");
    }
    else
        ERROR("char: Non displayable");
    if (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min() || std::isnan(nbr) || std::isinf(nbr))
    {
        ERROR("int: impossible");
    }
    else
        PRINT("int: " << static_cast<int>(nbr));
    // precision 1
    PRINT("float: " << std::fixed << std::setprecision(1) << nbr << "f");
    PRINT("double: " << std::fixed << std::setprecision(1) << static_cast<double>(nbr));
}

void ScalarConverter::to_double(std::string str)
{
    double nbr;

    nbr = std::stod(str);
    if (nbr > std::numeric_limits<char>::max() || nbr < std::numeric_limits<char>::min() || std::isnan(nbr) || std::isinf(nbr))
    {
        ERROR("char: impossible");
    }
    else if (std::isprint(nbr))
    {
        PRINT("char: '" << static_cast<char>(nbr) << "'");
    }
    else
        ERROR("char: Non displayable");
    if (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min() || std::isnan(nbr) || std::isinf(nbr))
    {
        ERROR("int: impossible");
    }
    else
        PRINT("int: " << static_cast<int>(nbr));
    if (nbr > std::numeric_limits<float>::max() || nbr < std::numeric_limits<float>::min())
    {
        ERROR("float: impossible");
    }
    else
        PRINT("float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f");
    PRINT("double: " << std::fixed << std::setprecision(1) << nbr);
}

void ScalarConverter::convert(std::string str)
{
    int type;

    type = ScalarConverter::getType(str);
    switch (type)
    {
    case CHAR:
        to_char(str);
        break;
    case INT:
        to_int(str);
        break;
    case FLOAT:
        to_float(str);
        break;
    case DOUBLE:
        to_double(str);
        break;
    default:
        ERROR("char: impossible");
        ERROR("int: impossible");
        ERROR("float: impossible");
        ERROR("double: impossible");
        break;
    }
}