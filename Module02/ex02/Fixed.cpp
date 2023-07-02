#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point_value(0)
{
    return;
}

Fixed::Fixed(const Fixed &to_copy)
{
    *this = to_copy;
    return;
}

Fixed::~Fixed(void)
{
    return;
}

Fixed &Fixed::operator=(const Fixed &right_side)
{
    if (this != &right_side)
        this->_fixed_point_value = right_side.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixed_point_value = raw;
}

// ex01

Fixed::Fixed(const int int_value)
{
    this->_fixed_point_value = int_value * (1 << this->_fractional_bits);
}

Fixed::Fixed(const float float_value)
{
    this->_fixed_point_value = roundf(float_value * (1 << this->_fractional_bits));
}

float Fixed::toFloat(void) const
{
    float result;

    result = static_cast<float>((this->_fixed_point_value)) / (1 << this->_fractional_bits);
    return result;
}

int Fixed::toInt(void) const
{
    int result;

    result = this->_fixed_point_value / (1 << this->_fractional_bits);
    return result;
}

std::ostream &operator<<(std::ostream &o, Fixed const &right_side)
{
    o << right_side.toFloat();
    return o;
}

// ex02

bool Fixed::operator>(const Fixed &right_side) const
{
    return this->_fixed_point_value > right_side.getRawBits();
}

bool Fixed::operator<(const Fixed &right_side) const
{
    return this->_fixed_point_value < right_side.getRawBits();
}

bool Fixed::operator>=(const Fixed &right_side) const
{
    return this->_fixed_point_value >= right_side.getRawBits();
}

bool Fixed::operator<=(const Fixed &right_side) const
{
    return this->_fixed_point_value <= right_side.getRawBits();
}

bool Fixed::operator==(const Fixed &right_side) const
{
    return this->_fixed_point_value == right_side.getRawBits();
}

bool Fixed::operator!=(const Fixed &right_side) const
{
    return this->_fixed_point_value != right_side.getRawBits();
}

Fixed Fixed::operator+(const Fixed &right_side) const
{
    Fixed result;

    result.setRawBits(this->_fixed_point_value + right_side.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &right_side) const
{
    Fixed result;

    result.setRawBits(this->_fixed_point_value - right_side.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &right_side) const
{
    Fixed result;

    result.setRawBits((this->_fixed_point_value * right_side.getRawBits()) >> this->_fractional_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &right_side) const
{
    Fixed result;

    result.setRawBits((this->_fixed_point_value << this->_fractional_bits) / right_side.getRawBits());
    return result;
}

Fixed &Fixed::operator++(void)
{
    this->_fixed_point_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed result(*this);

    this->_fixed_point_value++;
    return result;
}

Fixed &Fixed::operator--(void)
{
    this->_fixed_point_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed result(*this);

    this->_fixed_point_value--;
    return result;
}

Fixed &Fixed::min(Fixed &left_side, Fixed &right_side)
{
    if (left_side < right_side)
        return left_side;
    return right_side;
}

const Fixed &Fixed::min(const Fixed &left_side, const Fixed &right_side)
{
    if (left_side < right_side)
        return left_side;
    return right_side;
}

Fixed &Fixed::max(Fixed &left_side, Fixed &right_side)
{
    if (left_side > right_side)
        return left_side;
    return right_side;
}

const Fixed &Fixed::max(const Fixed &left_side, const Fixed &right_side)
{
    if (left_side > right_side)
        return left_side;
    return right_side;
}
