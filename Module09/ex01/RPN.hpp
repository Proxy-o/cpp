/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:33:06 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/24 11:30:33 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stack>

class RPN
{
private:
    static std::stack<int> _stack;
    RPN();
    RPN(RPN const &src);
    RPN &operator=(RPN const &rhs);
    ~RPN();

public:
    static void init_stack(std::string &str);
    static void print_stack();
    static void calculate();
    static bool containsOnlySpaces(const std::string &str);

    class InvalidExpressionException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class ZeroDivisionException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};
