#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
    return;
}

Dog::~Dog()
{
    std::cout << "Dog distructor called" << std::endl;
    return;
}

Dog::Dog(const Dog &src) : Animal()
{
    std::cout << "Dog copy Constructor called" << std::endl;
    *this = src;
    return;
}

Dog &Dog::operator=(const Dog &right_side)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    this->type = right_side.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "the vois of Dog" << std::endl;
    return;
}