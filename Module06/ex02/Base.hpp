/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:08:21 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 14:59:40 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define PRINT(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;

class Base
{
public:
    virtual ~Base(void);
};
