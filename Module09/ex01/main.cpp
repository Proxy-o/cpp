/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:35:44 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/24 11:15:49 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usaage : ./RPN ' 8 9 * 9 - 9 - 9 - 4 - 1 + '" << std::endl;
    }
    else
    {
        std::string str = av[1];
        try
        {

            RPN::init_stack(str);
            // RPN::print_stack();
            RPN::calculate();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}