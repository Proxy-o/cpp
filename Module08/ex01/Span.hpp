/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:10:01 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/20 10:07:54 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
class Span
{
private:
    std::vector<int> _v;
    unsigned int _n;
    unsigned int _filled;

public:
    Span();
    Span(unsigned int n);
    Span(Span const &src);
    ~Span();
    Span &operator=(Span const &rhs);

    void addNumber(int nbr);
    int shortestSpan();
    int longestSpan();
    void fillWithRandomNumbers(unsigned int n);
    void printVector();
    void removeDuplicates();

    class CantAddMoreNumbersException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class NoEnoughNumbersException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};
