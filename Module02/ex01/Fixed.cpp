#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = to_copy;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &right_side)
{
    std::cout << "Copy assignment operator called" << std::endl;
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
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value)
{
    this->_fixed_point_value = roundf(float_value * (1 << this->_fractional_bits));
    std::cout << "Float constructor called" << std::endl;
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