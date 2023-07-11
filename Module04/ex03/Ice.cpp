#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
    return;
}

Ice::Ice(Ice const & src)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = src;
    return;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
    return;
}

Ice & Ice::operator=(Ice const & right_side)
{
    std::cout << "Ice assignation operator called" << std::endl;
    if (this != &right_side)
        this->_type = right_side._type;
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return;
}

