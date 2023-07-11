#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Animal";
    std::cout << "the Animal default constructor called" << std::endl;
    return;
}

Animal::~Animal()
{
    std::cout << "the Animal distructor called" << std::endl;
    return;
}

Animal::Animal(const Animal &src)
{
    std::cout << "copy Constructor called" << std::endl;
    *this = src;
    return;
}

Animal &Animal::operator=(const Animal &right_side)
{

    std::cout << "Copy assignment operator called" << std::endl;
    this->type = right_side.type;
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::setType(std::string type)
{
    this->type = type;
    return;
}