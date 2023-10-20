/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:29:02 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/20 12:47:36 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(MutantStack const &to_copy);
    MutantStack &operator=(MutantStack const &rhd);
    ~MutantStack();
    typedef typename std::deque<T>::iterator iterator;
    iterator begin();
    iterator end();
};
#include "MutantStack.tpp"