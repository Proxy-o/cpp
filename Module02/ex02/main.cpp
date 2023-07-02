#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(1));
    std::cout << (a++ < a) << std::endl;
    std::cout << Fixed::min(a * 100, b) << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}