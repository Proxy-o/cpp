#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "the WrongAnimal default constructor called" << std::endl;
    return;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "the WrongAnimal distructor called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "copy Constructor called" << std::endl;
    *this = src;
    return;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &right_side)
{

    std::cout << "Copy assignment operator called" << std::endl;
    this->type = right_side.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "the vois of WrongAnimal" << std::endl;
    return;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::setType(std::string type)
{
    this->type = type;
    return;
}