/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:06:04 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/02 11:32:27 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
    T *_pointer;
    unsigned int _n;

public:
    Array(void);
    Array(unsigned int n);
    ~Array(void);
    Array(Array<T> &to_copy);
    Array<T> &operator=(const Array<T> &rhd);
    T &operator[](unsigned int index);
    unsigned int size(void) const;

    class IndexOutOfBoundsException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> const &array);
#include "Array.tpp"