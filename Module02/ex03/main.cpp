/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:09:59 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/06 18:09:59 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{

    std::cout << "Test 1: " << std::endl;
    std::cout << "Point a(0, 0), b(0, 4), c(4, 0), point(0, 0)" << std::endl;
    Point a(0, 0), b(0, 4), c(4, 0), point(0, 0);
    std::cout << "bsp(a, b, c, point) = " << bsp(a, b, c, point) << std::endl;

    std::cout << "Test 2: " << std::endl;
    std::cout << "Point a(0, 0), b(0, 4), c(4, 0), point(1, 1)" << std::endl;
    Point a1(0, 0), b1(0, 4), c1(4, 0), point1(1, 1);
    std::cout << "bsp(a, b, c, point) = " << bsp(a1, b1, c1, point1) << std::endl;

    std::cout << "Test 3: " << std::endl;
    std::cout << "Point a(0, 0), b(0, 4), c(4, 0), point(4, 4)" << std::endl;
    Point a2(0, 0), b2(0, 4), c2(4, 0), point2(4, 4);
    std::cout << "bsp(a, b, c, point) = " << bsp(a2, b2, c2, point2) << std::endl;

    return 0;
}