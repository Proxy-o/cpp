/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:16:00 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/20 10:53:07 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _filled(0)
{
}

Span::Span(unsigned int n) : _n(n), _filled(0)
{
    this->_v.reserve(n);
}

Span::Span(Span const &src)
{
    *this = src;
}

Span::~Span()
{
}

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
        this->_n = rhs._n;
    return *this;
}

void Span::addNumber(int nbr)
{
    if (this->_filled >= this->_n)
        throw CantAddMoreNumbersException();
    std::vector<int>::iterator position = std::lower_bound(this->_v.begin(), this->_v.end(), nbr);
    this->_v.insert(position, nbr);
    this->_filled++;
}

void Span::fillWithRandomNumbers(unsigned int n)
{
    if (n > this->_n)
        throw CantAddMoreNumbersException();
    for (unsigned int i = 0; i < n; ++i)
    {
        this->_v.push_back(std::rand() % 1000);
    }
    std::sort(this->_v.begin(), this->_v.end());
    this->_filled = n;
}

void Span::printVector()
{
    for (unsigned int i = 0; i < this->_filled; i++)
    {
        std::cout << this->_v[i] << " ";
    }
    std::cout << std::endl;
}

void Span::removeDuplicates()
{
    std::vector<int>::iterator it;
    it = std::unique(this->_v.begin(), this->_v.end());
    this->_v.resize(std::distance(this->_v.begin(), it));
    this->_filled = this->_v.size();
}

int Span::shortestSpan()
{
    if (this->_filled < 2)
        throw NoEnoughNumbersException();
    int shortest = this->_v[1] - this->_v[0];
    for (unsigned int i = 2; i < this->_filled; i++)
    {
        if (this->_v[i] - this->_v[i - 1] < shortest)
            shortest = this->_v[i] - this->_v[i - 1];
    }
    return shortest;
}

int Span::longestSpan()
{
    if (this->_filled < 2)
        throw NoEnoughNumbersException();
    return this->_v[this->_filled - 1] - this->_v[0];
}

const char *Span::CantAddMoreNumbersException::what() const throw()
{
    return "Can't add more numbers !!";
}

const char *Span::NoEnoughNumbersException::what() const throw()
{
    return "No enough numbers in the container !!";
}