/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:32:30 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 13:14:49 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"

#define PRINT(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;

class Serializer
{
private:
    Serializer(void);
    Serializer(Serializer const &src);
    Serializer &operator=(Serializer const &rhs);
    ~Serializer(void);

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};