#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
    return;
}

Cat::~Cat()
{
    std::cout << "Cat distructor called" << std::endl;
    return;
}

Cat::Cat(const Cat &src) : Animal()
{
    std::cout << "Cat copy Constructor called" << std::endl;
    *this = src;
    return;
}

Cat &Cat::operator=(const Cat &right_side)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    this->type = right_side.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "the vois of Cat" << std::endl;
    return;
}