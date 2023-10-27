/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:40:18 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/27 09:55:29 by otait-ta         ###   ########.fr       */
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

BitcoinExchange::BitcoinExchange(BitcoinExchange const& src)
{
    *this = src;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
    (void)rhs;
    return *this;
}

bool BitcoinExchange::is_valid_date(std::string& dateStr)
{
    std::tm date;
    std::istringstream dateStream(dateStr);
    char dash;
    // if date is contain somthing else than numbers and dashes
    if (dateStr.find_first_not_of("0123456789- ") != std::string::npos)
        return false;
    if (dateStream >> date.tm_year >> dash >> date.tm_mon >> dash >> date.tm_mday)
    {
        date.tm_mon--;
        date.tm_hour = 0;
        date.tm_min = 0;
        date.tm_sec = 0;
        date.tm_isdst = -1;

        if (date.tm_mon >= 0 && date.tm_mon <= 11 && date.tm_mday >= 1 && date.tm_mday <= 31)
        {
            if (date.tm_year < 2009 || (date.tm_year == 2009 && date.tm_mon <= 0 && date.tm_mday < 2))
                return false;
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
        std::cout << it->first << " " << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
}

int BitcoinExchange::read_data()
{
    std::ifstream db(DATA_BASE);
    std::string line;
    if (!db.is_open())
    {
        std::cerr << "DB Error: could not open file" << std::endl;
        return 1;
    }
    std::getline(db, line);
    while (std::getline(db, line))
    {
        std::string date = line.substr(0, line.find(','));
        std::string rate = line.substr(line.find(',') + 1);
        if (date.empty() || rate.empty())
        {
            std::cerr << "DB Error: invalid line  format" << line << std::endl;
            continue;
        }
        if (!is_valid_date(date))
        {
            std::cerr << "DB Error: invalid date : " << line << std::endl;
            continue;
        }
        if (rate.empty() || rate.find_first_not_of("0123456789.") != std::string::npos)
        {
            std::cerr << "DB Error: invalid value : " << rate << std::endl;
            continue;
        }
        double rateDouble = std::stof(rate);
        if (rateDouble < 0)
        {
            std::cerr << "DB Error: invalid rate : " << rateDouble << std::endl;
            continue;
        }
        BitcoinExchange::_rates.insert(std::pair<std::string, double>(date, rateDouble));
    }
    db.close();
    return 0;
}

bool BitcoinExchange::check_format(std::string& line)
{
    if (line.find('|') == std::string::npos)
    {
        std::cerr << "Error: bad input = > " << line << std::endl;
        return false;
    }
    if (line.find('|') != line.rfind('|'))
    {
        std::cerr << "Error: bad input = > " << line << std::endl;
        return false;
    }
    if (line.find('|') == line.length() - 1)
    {
        std::cerr << "Error: bad input = > " << line << std::endl;
        return false;
    }
    if (line.find('|') == 0)
    {
        std::cerr << "Error: bad input = > " << line << std::endl;
        return false;
    }
    if (line.at(line.find('|') - 1) != ' ' || line.at(line.find('|') + 1) != ' ')
    {
        std::cerr << "Error: bad input = > " << line << std::endl;
        return false;
    }
    std::string date = line.substr(0, line.find('|'));
    if (!is_valid_date(date))
    {
        std::cerr << "Error: invalid date : " << date << std::endl;
        return false;
    }
    std::string value = line.substr(line.find('|') + 1);
    if (value.empty())
    {
        std::cerr << "Error: bad input = > " << line << std::endl;
        return false;
    }
    return true;
}

double BitcoinExchange::closet_rate(std::string& date)
{
    std::map<std::string, double>::const_iterator it = BitcoinExchange::_rates.lower_bound(date);
    if (it->first == date || it == BitcoinExchange::_rates.begin())
        return it->second;
    it--;
    return it->second;
}

void BitcoinExchange::exchange(std::string& file)
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
            continue;
        }
        std::string date = line.substr(0, line.find('|'));
        // remove spaces from start of  date
        date.erase(0, date.find_first_not_of(' '));
        if (date.at(date.length() - 2) == ' ')
        {
            std::cerr << "Error: bad input = > " << line << std::endl;
            continue;
        }

        std::string value = line.substr(line.find('|') + 2);
        if (value.empty() || value.find_first_not_of("0123456789.") != std::string::npos ||
            value.find("..") != std::string::npos || value.find('.') != value.rfind('.'))
        {
            std::cerr << "Error: bad input : " << line << std::endl;
            continue;
        }

        double valueDouble = std::stof(value);
        if (valueDouble < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (valueDouble > 1000)
        {
            std::cerr << "Error: too large number." << std::endl;
            continue;
        }
        double exchangeRate = closet_rate(date);
        std::cout << date << " => " << valueDouble << " = " << std::fixed << std::setprecision(2) << valueDouble * exchangeRate << std::endl;
    }
}