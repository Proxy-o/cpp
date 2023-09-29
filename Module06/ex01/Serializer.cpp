/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:40:11 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 13:01:06 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
    PRINT("Default constructor called");
    return;
}

Serializer::Serializer(Serializer const &src)
{
    PRINT("Copy constructor called");
    *this = src;
    return;
}

Serializer::~Serializer(void)
{
    PRINT("Destructor called");
    return;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
    PRINT("Assignment operator called");
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
