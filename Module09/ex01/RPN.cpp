/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:38:27 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/23 19:59:26 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

std::stack<int> RPN::_stack;

RPN::RPN()
{
}

RPN::RPN(RPN const &src)
{
    *this = src;
}

RPN &RPN::operator=(RPN const &rhs)
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

void RPN::init_stack(std::string &str)
{
    std::string::reverse_iterator rit = str.rbegin();
    for (; rit != str.rend(); rit++)
    {
        if (std::string("0123456789").find(*rit) != std::string::npos)
            _stack.push(*rit - '0');
        else if (std::string("-+*/").find(*rit) != std::string::npos)
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
    std::stack<int> &tmp = _stack;
    int a, b, result;
    std::stack<int> helper;
    while (tmp.empty() == false)
    {
        if (std::string("-+*/").find(tmp.top()) != std::string::npos)
        {
            if (tmp.top() == '-' && helper.size() >= 2)
            {
                a = helper.top();
                helper.pop();
                b = helper.top();
                helper.pop();
                result = b - a;
                tmp.pop();
                helper.push(result);
            }
            else if (tmp.top() == '+' && helper.size() >= 2)
            {
                a = helper.top();
                helper.pop();
                b = helper.top();
                helper.pop();
                result = a + b;
                tmp.pop();
                helper.push(result);
            }
            else if (tmp.top() == '*' && helper.size() >= 2)
            {
                a = helper.top();
                helper.pop();
                b = helper.top();
                helper.pop();
                result = a * b;
                tmp.pop();
                helper.push(result);
            }
            else if (tmp.top() == '/' && helper.size() >= 2)
            {
                a = helper.top();
                helper.pop();
                b = helper.top();
                helper.pop();
                result = b / a;
                tmp.pop();
                helper.push(result);
            }
        }
        else
        {
            helper.push(tmp.top());
            if (tmp.empty() == false)
                tmp.pop();
        }
    }

    std::cout << helper.top() << std::endl;
}

const char *RPN::InvalidExpressionException::what() const throw()
{
    return "Invalid Expression";
}