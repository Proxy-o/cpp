/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:10:12 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/06 18:10:12 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();
    Point(Point const &to_copy);
    Point(float const x, float const y);
    ~Point();

    float getX() const;
    float getY() const;
    void setX(float const x);
    void setY(float const y);

    Point &operator=(Point const &right_side);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif