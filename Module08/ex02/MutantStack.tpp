/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:58:03 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/20 12:47:13 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}
template <typename T>
MutantStack<T>::MutantStack(MutantStack const &to_copy) : std::stack<T>(to_copy)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhd)
{
    if (*this != rhd)
        std::stack<T>::operator=(rhd);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}
