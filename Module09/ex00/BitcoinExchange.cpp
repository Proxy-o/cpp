/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:40:18 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/22 17:11:12 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>

std::map<std::string, double> BitcoinExchange::_rates;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    (void)rhs;
    return *this;
}

bool BitcoinExchange::is_valid_date(std::string &dateStr)
{
    std::tm date = {};
    std::istringstream dateStream(dateStr);
    char dash;

    if (dateStream >> date.tm_year >> dash >> date.tm_mon >> dash >> date.tm_mday)
    {
        date.tm_year -= 1900;
        date.tm_mon--;
        date.tm_hour = 0;
        date.tm_min = 0;
        date.tm_sec = 0;
        date.tm_isdst = -1;

        if (date.tm_mon >= 0 && date.tm_mon <= 11 && date.tm_mday >= 1 && date.tm_mday <= 31)
        {
            if (date.tm_mon == 1)
            {
                if ((date.tm_year % 4 == 0 && date.tm_year % 100 != 0) || (date.tm_year % 400 == 0))
                {
                    return date.tm_mday <= 29;
                }
                else
                {
                    return date.tm_mday <= 28;
                }
            }
            else if (date.tm_mon == 3 || date.tm_mon == 5 || date.tm_mon == 8 || date.tm_mon == 10)
            {
                return date.tm_mday <= 30;
            }
            return true;
        }
    }

    return false;
}

void BitcoinExchange::print_rates()
{
    for (std::map<std::string, double>::iterator it = BitcoinExchange::_rates.begin(); it != BitcoinExchange::_rates.end(); ++it)
    {
        // presesion to 2 decimal places
        std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
}

int BitcoinExchange::read_inpute()
{
    std::ifstream db(DATA_BASE);
    std::string line;
    if (!db.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }
    std::getline(db, line);
    while (std::getline(db, line))
    {
        std::string date = line.substr(0, line.find(','));
        std::string rate = line.substr(line.find(',') + 1);
        if (date.empty() || rate.empty())
        {
            std::cerr << "Error: invalid file format" << std::endl;
            db.close();
            return 1;
        }
        if (!is_valid_date(date))
        {
            std::cerr << "Error: invalid date : " << date << std::endl;
            db.close();
            return 1;
        }
        double rateDouble = std::stof(rate);
        if (rateDouble < 0)
        {
            std::cerr << "Error: invalid rate : " << rateDouble << std::endl;
            db.close();
            return 1;
        }
        BitcoinExchange::_rates.insert(std::pair<std::string, double>(date, rateDouble));
    }
    db.close();
    return 0;
}

bool BitcoinExchange::check_format(std::string &line)
{
    // check if it is in thes format "date | value"
    if (line.find('|') == std::string::npos)
    {
        std::cerr << "Error: invalid file format" << std::endl;
        return false;
    }
    if (line.find('|') != line.rfind('|'))
    {
        std::cerr << "Error: invalid file format" << std::endl;
        return false;
    }
    if (line.at(line.find('|') - 1) != ' ' || line.at(line.find('|') + 1) != ' ')
    {
        std::cerr << "Error: invalid file format" << std::endl;
        return false;
    }
    std::string date = line.substr(0, line.find('|'));
    if (is_valid_date(date))
    {
        std::cerr << "Error: invalid date : " << date << std::endl;
        return false;
    }
    std::string value = line.substr(line.find('|') + 1);
    if (value.empty())
    {
        std::cerr << "Error: invalid file format" << std::endl;
        return false;
    }
    return true;
}

double BitcoinExchange::closet_rate(std::string &date)
{
    std::map<std::string, double>::const_iterator it = BitcoinExchange::_rates.lower_bound(date);
    if (it == BitcoinExchange::_rates.end())
    {
        std::cerr << "Error: invalid date : " << date << std::endl;
        return 0;
    }
    if (it->first == date || it == BitcoinExchange::_rates.begin())
        return it->second;
    it--;
    return it->second;
}

void BitcoinExchange::exchange(std::string &file)
{
    std::ifstream infile(file);
    if (!infile.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
    std::string line;
    std::getline(infile, line);
    if (line != "date | value")
    {
        std::cerr << "Error: invalid file format" << std::endl;
        infile.close();
        return;
    }
    while (std::getline(infile, line))
    {
        if (!check_format(line))
        {
            infile.close();
            return;
        }
        std::string date = line.substr(0, line.find('|'));
        std::string value = line.substr(line.find('|') + 1);
        double valueDouble = std::stof(value);
        if (valueDouble < 0)
        {
            std::cerr << "Error: invalid value : " << valueDouble << std::endl;
            infile.close();
            return;
        }
        double exchangeRate = closet_rate(date);
        std::cout << date << " => " << valueDouble << " = " << std::fixed << std::setprecision(2) << valueDouble * exchangeRate << std::endl;
    }
}