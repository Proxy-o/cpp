/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:48:36 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/27 11:49:00 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_vctr;
std::vector<std::vector<int> > PmergeMe::_vctrOfVctr;
std::vector<int> PmergeMe::_sorted;
struct timeval PmergeMe::_vTimeStart;
struct timeval PmergeMe::_vTimeEnd;

// deques
std::deque<int> PmergeMe::_deq;
std::deque<std::deque<int> > PmergeMe::_deqOfDeq;
std::deque<int> PmergeMe::_sorted_deq;
struct timeval PmergeMe::_deqTimeStart;
struct timeval PmergeMe::_deqTimeEnd;


const char* PmergeMe::BadInputException::what() const throw()
{
    return "Bad input";
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const& src)
{
    *this = src;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs)
{
    if (this != &rhs)
    {
        this->_vctr = rhs._vctr;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::init_vector(char** str, int& size)
{
    if (size < 2)
        throw BadInputException();
    for (int i = 1; i < size; i++)
    {
        std::string tmp = str[i];
        if (tmp.find_first_not_of("0123456789") != std::string::npos)
            throw BadInputException();
        int tmpInt = std::stod(tmp);
        const int MAX_INT = std::numeric_limits<int>::max();
        if (tmpInt < 0 || tmpInt > MAX_INT)
            throw BadInputException();
        PmergeMe::_vctr.push_back(tmpInt);
    }
    if (PmergeMe::_vctr.size() < 2)
        throw BadInputException();
}

void PmergeMe::init_vectorOfVector()
{
    bool second = false;
    std::vector<int> tmp;
    for (size_t i = 0; i < PmergeMe::_vctr.size(); i++)
    {

        if (second)
        {
            tmp.push_back(PmergeMe::_vctr[i]);
            std::sort(tmp.begin(), tmp.end());
            PmergeMe::_vctrOfVctr.push_back(tmp);
            tmp.clear();
            second = false;
        }
        else {
            tmp.push_back(PmergeMe::_vctr[i]);
            second = true;
        }
    }
    if (_vctr.size() % 2 != 0)
    {
        tmp.insert(tmp.begin(), -1);
        PmergeMe::_vctrOfVctr.push_back(tmp);
    }
}


void PmergeMe::sort_vectorOfVector()
{
    for (size_t i = 0; i < PmergeMe::_vctrOfVctr.size() - 1;i++)
    {
        for (size_t j = i + 1; j < PmergeMe::_vctrOfVctr.size();j++)
        {
            if (PmergeMe::_vctrOfVctr[i][1] > PmergeMe::_vctrOfVctr[j][1])
                PmergeMe::_vctrOfVctr[i].swap(PmergeMe::_vctrOfVctr[j]);
        }
    }
}

void PmergeMe::print_vector(std::vector<int> vctr)
{
    for (size_t i = 0; i < vctr.size(); i++)
    {
        std::cout << vctr[i];
        if (i < vctr.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::fill_sorted()
{
    std::vector<int> tmp;
    for (size_t i = 0; i < PmergeMe::_vctrOfVctr.size(); i++)
    {
        tmp.push_back(PmergeMe::_vctrOfVctr[i][0]);
        PmergeMe::_sorted.push_back(PmergeMe::_vctrOfVctr[i][1]);
    }
    for (size_t i = 0; i < tmp.size(); i++)
    {
        std::vector<int>::iterator sorted = std::lower_bound(PmergeMe::_sorted.begin(), PmergeMe::_sorted.end(), tmp[i]);
        PmergeMe::_sorted.insert(sorted, tmp[i]);
    }
    if (PmergeMe::_sorted[0] == -1)
        PmergeMe::_sorted.erase(PmergeMe::_sorted.begin());
}



void PmergeMe::vector_merge(char** argv, int argc)
{
    gettimeofday(&PmergeMe::_vTimeStart, NULL);
    PmergeMe::init_vector(argv, argc);
    PmergeMe::init_vectorOfVector();
    PmergeMe::sort_vectorOfVector();
    PmergeMe::fill_sorted();
    gettimeofday(&PmergeMe::_vTimeEnd, NULL);
    double	vClock;
    vClock = (PmergeMe::_vTimeEnd.tv_sec - PmergeMe::_vTimeStart.tv_sec) * (double)1000000;
    double usec = ((PmergeMe::_vTimeEnd.tv_usec - _vTimeStart.tv_usec));
    vClock = (vClock + usec);

    std::cout << "\033[1;32mVECTOR ==> Before: \033[0m";
    PmergeMe::print_vector(PmergeMe::_vctr);
    std::cout << "\033[1;32mVECTOR ==> After : \033[0m";
    PmergeMe::print_vector(PmergeMe::_sorted);

    std::cout << "\033[1;32mVECTOR ==> Time : " << vClock << " microseconds\033[0m" << std::endl;
}


// deques

void PmergeMe::init_deque(char** str, int& size)
{
    if (size < 2)
        throw BadInputException();
    for (int i = 1; i < size; i++)
    {
        std::string tmp = str[i];
        if (tmp.find_first_not_of("0123456789") != std::string::npos)
            throw BadInputException();
        int tmpInt = std::stod(tmp);
        const int MAX_INT = std::numeric_limits<int>::max();
        if (tmpInt < 0 || tmpInt > MAX_INT)
            throw BadInputException();
        PmergeMe::_deq.push_back(tmpInt);
    }
    if (PmergeMe::_deq.size() < 2)
        throw BadInputException();
}

void PmergeMe::init_dequeOfDeque()
{
    bool second = false;
    std::deque<int> tmp;
    for (size_t i = 0; i < PmergeMe::_deq.size(); i++)
    {

        if (second)
        {
            tmp.push_back(PmergeMe::_deq[i]);
            std::sort(tmp.begin(), tmp.end());
            PmergeMe::_deqOfDeq.push_back(tmp);
            tmp.clear();
            second = false;
        }
        else {
            tmp.push_back(PmergeMe::_deq[i]);
            second = true;
        }
    }
    if (_deq.size() % 2 != 0)
    {
        tmp.insert(tmp.begin(), -1);
        PmergeMe::_deqOfDeq.push_back(tmp);
    }
}

void PmergeMe::sort_dequeOfDeque()
{
    for (size_t i = 0; i < PmergeMe::_deqOfDeq.size() - 1;i++)
    {
        for (size_t j = i + 1; j < PmergeMe::_deqOfDeq.size();j++)
        {
            if (PmergeMe::_deqOfDeq[i][1] > PmergeMe::_deqOfDeq[j][1])
                PmergeMe::_deqOfDeq[i].swap(PmergeMe::_deqOfDeq[j]);
        }
    }
}

void PmergeMe::print_deque(std::deque<int> deq)
{
    for (size_t i = 0; i < deq.size(); i++)
    {
        std::cout << deq[i];
        if (i < deq.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::fill_sorted_deque()
{
    std::deque<int> tmp;
    for (size_t i = 0; i < PmergeMe::_deqOfDeq.size(); i++)
    {
        tmp.push_back(PmergeMe::_deqOfDeq[i][0]);
        PmergeMe::_sorted_deq.push_back(PmergeMe::_deqOfDeq[i][1]);
    }
    for (size_t i = 0; i < tmp.size(); i++)
    {
        std::deque<int>::iterator sorted = std::lower_bound(PmergeMe::_sorted_deq.begin(), PmergeMe::_sorted_deq.end(), tmp[i]);
        PmergeMe::_sorted_deq.insert(sorted, tmp[i]);
    }
    if (PmergeMe::_sorted_deq[0] == -1)
        PmergeMe::_sorted_deq.erase(PmergeMe::_sorted_deq.begin());
}

void PmergeMe::deque_merge(char** argv, int argc)
{
    gettimeofday(&PmergeMe::_deqTimeStart, NULL);
    PmergeMe::init_deque(argv, argc);
    PmergeMe::init_dequeOfDeque();
    PmergeMe::sort_dequeOfDeque();
    PmergeMe::fill_sorted_deque();
    gettimeofday(&PmergeMe::_deqTimeEnd, NULL);
    double	deqClock;
    deqClock = (PmergeMe::_deqTimeEnd.tv_sec - PmergeMe::_deqTimeStart.tv_sec) * (double)1000000;
    double usec = ((PmergeMe::_deqTimeEnd.tv_usec - _deqTimeStart.tv_usec));
    deqClock = (deqClock + usec);

    std::cout << "\033[1;31mDEQUE ==> Before: \033[0m";
    PmergeMe::print_deque(PmergeMe::_deq);
    std::cout << "\033[1;31mDEQUE ==> After : \033[0m";
    PmergeMe::print_deque(PmergeMe::_sorted_deq);

    std::cout << "\033[1;31mDEQUE ==> Time : " << deqClock << " microseconds\033[0m" << std::endl;
}