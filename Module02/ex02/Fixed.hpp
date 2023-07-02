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

    // ex02
    bool operator>(const Fixed &right_side) const;
    bool operator<(const Fixed &right_side) const;
    bool operator>=(const Fixed &right_side) const;
    bool operator<=(const Fixed &right_side) const;
    bool operator==(const Fixed &right_side) const;
    bool operator!=(const Fixed &right_side) const;

    Fixed operator+(const Fixed &right_side) const;
    Fixed operator-(const Fixed &right_side) const;
    Fixed operator*(const Fixed &right_side) const;
    Fixed operator/(const Fixed &right_side) const;

    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};
std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif