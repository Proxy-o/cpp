/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:44:59 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/24 17:19:49 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>

class PmergeMe
{
private:
    static std::vector<int> _vctr;
    static std::vector<int> _sorted;
    static std::vector<std::vector<int> > _vctrOfVctr;
    static struct timeval					_vTimeStart;
    static struct timeval					_vTimeEnd;

    // deques
    static std::deque<int> _deq;
    static std::deque<int> _sorted_deq;
    static std::deque<std::deque<int> > _deqOfDeq;
    static struct timeval					_deqTimeStart;
    static struct timeval					_deqTimeEnd;

    PmergeMe();
    PmergeMe(PmergeMe const& src);
    PmergeMe& operator=(PmergeMe const& rhs);
    ~PmergeMe();

public:

    static void init_vector(char** str, int& size);
    static void init_vectorOfVector();
    static void print_vector(std::vector<int> vctr);
    static void sort_vectorOfVector();
    static void fill_sorted();
    static void vector_merge(char** argv, int argc);

    // deques
    static void init_deque(char** str, int& size);
    static void init_dequeOfDeque();
    static void print_deque(std::deque<int> deq);
    static void sort_dequeOfDeque();
    static void fill_sorted_deque();
    static void deque_merge(char** argv, int argc);

    class BadInputException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};