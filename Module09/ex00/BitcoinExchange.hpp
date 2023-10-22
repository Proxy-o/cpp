/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:23:45 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/22 20:12:52 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>

#define DATA_BASE "./data.csv"

class BitcoinExchange
{
private:
    static std::map<std::string, double> _rates;

    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &rhs);

public:
    /**
     * @brief Reads input from the file and stores it in a map.
     *
     * @return int The status of the operation. 0 if success, 1 if failure.
     **/
    static int read_data();
    static void print_rates();
    static bool is_valid_date(std::string &date);
    static void exchange(std::string &file);
    static bool check_format(std::string &line);
    static double closet_rate(std::string &date);
};
