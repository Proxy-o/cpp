#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
    return;
}

Cat::~Cat()
{
    std::cout << "Cat distructor called" << std::endl;
    delete this->brain;
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
    this->brain = new Brain(*right_side.brain);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "the vois of Cat" << std::endl;
    return;
}