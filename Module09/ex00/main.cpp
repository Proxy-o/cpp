/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:04:10 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/23 10:53:54 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            std::cout << "Usage: ./btc [file]" << std::endl;
            return 1;
        }
        std::string file = argv[1];
        if (BitcoinExchange::read_data())
            return 1;
        // BitcoinExchange::print_rates();
        BitcoinExchange::exchange(file);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}