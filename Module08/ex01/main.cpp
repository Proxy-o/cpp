/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:56:09 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/20 10:55:46 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    // try
    // {
    //     Span sp = Span(5);
    //     sp.addNumber(6);
    //     sp.addNumber(3);
    //     sp.addNumber(17);
    //     sp.addNumber(9);
    //     sp.addNumber(11);
    //     std::cout << sp.shortestSpan() << std::endl;
    //     std::cout << sp.longestSpan() << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // exmple 2
    try
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        Span sp = Span(1000);
        sp.fillWithRandomNumbers(1000);
        sp.removeDuplicates();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}