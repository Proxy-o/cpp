/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:38:27 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/27 10:58:03 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

std::stack<int> RPN::_stack;

RPN::RPN()
{
}

RPN::RPN(RPN const& src)
{
    *this = src;
}

RPN& RPN::operator=(RPN const& rhs)
{
    if (this != &rhs)
    {
        this->_stack = rhs._stack;
    }
    return *this;
}

RPN::~RPN()
{
}
bool RPN::containsOnlySpaces(const std::string& str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!isspace(*it))
        {
            return false;
        }
    }
    return true;
}

void RPN::init_stack(std::string& str)
{
    // if the str contain only -+*/
    if (std::string("-+*/").find(str) != std::string::npos)
        throw InvalidExpressionException();
    std::string::reverse_iterator rit = str.rbegin();
    if (rit == str.rend() || containsOnlySpaces(str))
        throw InvalidExpressionException();
    for (; rit != str.rend(); rit++)
    {
        if (std::string("0123456789-+*/").find(*rit) != std::string::npos)
            _stack.push(*rit);
        else if (*rit != ' ')
            throw InvalidExpressionException();
    }
}

void RPN::print_stack()
{
    std::stack<int> tmp = _stack;
    while (!tmp.empty())
    {
        if (std::string("-+*/").find(tmp.top()) != std::string::npos)
            std::cout << static_cast<char>(tmp.top()) << std::endl;
        else
            std::cout << tmp.top() << std::endl;
        tmp.pop();
    }
}

void RPN::calculate()
{
    std::stack<int>& tmp = _stack;
    int a, b, result;
    std::stack<int> helper;
    while (tmp.empty() == false)
    {
        if (std::string("-+*/").find(tmp.top()) != std::string::npos && helper.size() < 2)
            throw InvalidExpressionException();
        else
            if (std::string("-+*/").find(tmp.top()) != std::string::npos && helper.size() >= 2)
            {
                if (tmp.top() == '-')
                {
                    a = helper.top();
                    helper.pop();
                    b = helper.top();
                    helper.pop();
                    result = b - a;
                    tmp.pop();
                    helper.push(result);
                }
                else if (tmp.top() == '+')
                {
                    a = helper.top();
                    helper.pop();
                    b = helper.top();
                    helper.pop();
                    result = a + b;
                    tmp.pop();
                    helper.push(result);
                }
                else if (tmp.top() == '*')
                {
                    a = helper.top();
                    helper.pop();
                    b = helper.top();
                    helper.pop();
                    result = a * b;
                    tmp.pop();
                    helper.push(result);
                }
                else if (tmp.top() == '/')
                {
                    a = helper.top();
                    helper.pop();
                    b = helper.top();
                    helper.pop();
                    if (a == 0)
                        throw ZeroDivisionException();
                    result = b / a;
                    tmp.pop();
                    helper.push(result);
                }
                else
                    throw InvalidExpressionException();
            }
            else if (tmp.empty() == false)
            {
                helper.push(tmp.top() - '0');
                tmp.pop();
            }
            else
                throw InvalidExpressionException();
    }
    std::cout << helper.top() << std::endl;
}

const char* RPN::InvalidExpressionException::what() const throw()
{
    return "Invalid Expression";
}

const char* RPN::ZeroDivisionException::what() const throw()
{
    return "Division by zero";
}