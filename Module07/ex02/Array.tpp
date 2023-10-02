/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:26:57 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/02 14:28:10 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Array.hpp"

template <typename T>
const char *Array<T>::IndexOutOfBoundsException::what(void) const throw()
{
    return ("Index out of bounds");
}

template <typename T>
Array<T>::Array() : _pointer(NULL), _n(0)
{
}
template <typename T>
Array<T>::Array(unsigned int n) : _n(n)
{
    if (n == 0)
        this->_pointer = NULL;
    else
        this->_pointer = new T[n];
}

template <typename T>
Array<T>::Array(Array<T> &to_copy)
{
    if (to_copy._n == 0 || to_copy._pointer == NULL)
    {
        this->_n = 0;
        this->_pointer = NULL;
    }
    else
    {
        this->_n = to_copy._n;
        this->_pointer = new T[to_copy._n];
        for (unsigned int i = 0; i < to_copy._n; i++)
        {
            this->_pointer[i] = to_copy._pointer[i];
        }
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhd)
{
    if (this == &rhd)
        return *this;
    if (this->_pointer)
        delete[] this->_pointer;
    this->_pointer = new T[rhd._n];
    for (unsigned int i = 0; i < rhd._n; i++)
    {
        this->_pointer[i] = rhd._pointer[i];
    }
    this->_n = rhd._n;
    return *this;
}
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= this->_n)
    {
        throw Array<T>::IndexOutOfBoundsException();
    }

    return this->_pointer[index];
}

template <typename T>
Array<T>::~Array()
{
    if (this->_pointer)
        delete[] this->_pointer;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return (this->_n);
}

template <typename T>
std::ostream &operator<<(std::ostream &o, Array<T> &array)
{
    if (array.size() == 0)
        return o << "array is mepty";
    for (unsigned i = 0; i < array.size(); i++)
    {
        o << "T[" << i << "] = " << array[i] << " ";
    }
    return o;
}
