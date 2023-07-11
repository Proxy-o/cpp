#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
    return;
}

Dog::~Dog()
{
    std::cout << "Dog distructor called" << std::endl;
    delete this->brain;
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
    this->brain = new Brain(*right_side.brain);
    return *this;
}

void Dog::makeSound()  
{
    std::cout << "the vois of Dog" << std::endl;
    return;
}