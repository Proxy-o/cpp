#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _fixed_point_value;
    static const int _fractional_bits = 8;

public:
    Fixed(void);
    Fixed(const Fixed &to_copy);
    ~Fixed(void);
    Fixed &operator=(const Fixed &right_side);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    // ex01
    Fixed(const int int_value);
    Fixed(const float float_value);
    float toFloat(void) const;
    int toInt(void) const;
};
std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif