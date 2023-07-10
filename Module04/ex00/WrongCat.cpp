#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
    return;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat distructor called" << std::endl;
    return;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
    std::cout << "WrongCat copy Constructor called" << std::endl;
    *this = src;
    return;
}

WrongCat &WrongCat::operator=(const WrongCat &right_side)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    this->type = right_side.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "the vois of WrongCat" << std::endl;
    return;
}