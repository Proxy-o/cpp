#include "AMateria.hpp"

AMateria::AMateria() : _type("default_type")
{
    std::cout << "AMateria default constructor called" << std::endl;
    return;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria parameter constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
    return;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
    return;
}

AMateria & AMateria::operator=(AMateria const & right_side)
{
    std::cout << "AMateria assignation operator called" << std::endl;
    if (this != &right_side)
        this->_type = right_side._type;
    return *this;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* default use on " << target.getName() << " *" << std::endl;
    return;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

