/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:58:03 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/20 12:39:38 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack() : std::stack<T, C>()
{
}
template <typename T, typename C>
MutantStack<T, C>::MutantStack(MutantStack const &to_copy) : std::stack<T, C>(to_copy)
{
}

template <typename T, typename C>
MutantStack<T, C> &MutantStack<T, C>::operator=(MutantStack const &rhd)
{
    if (*this != rhd)
        std::stack<T>::operator=(rhd);
    return *this;
}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack()
{
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin()
{
    return this->c.begin();
}
template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end()
{
    return this->c.end();
}
