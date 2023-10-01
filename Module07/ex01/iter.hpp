/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:22:53 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/01 15:56:07 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define PRINT(x) std::cout << x << std::endl;

template <typename T>

void iter(T *array, int length, void (*func)(T a))
{

    if (!array)
        return;
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    };
}

template <typename T>
void print(T a)
{
    std::cout << a << std::endl;
}