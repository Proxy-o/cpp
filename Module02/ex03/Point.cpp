/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:10:07 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/06 18:10:08 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(Point const &to_copy) : _x(to_copy.getX()), _y(to_copy.getY()) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::~Point() {}

float Point::getX() const
{
    Fixed const &x = this->_x;
    return x.toFloat();
}

float Point::getY() const
{
    Fixed const &y = this->_y;
    return y.toFloat();
}

Point &Point::operator=(Point const &right_side)
{
    if (this != &right_side)
    {
        (Fixed) this->_x = right_side.getX();
        (Fixed) this->_y = right_side.getY();
    }
    return *this;
}
