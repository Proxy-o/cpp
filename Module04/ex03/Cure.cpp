#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
    std::cout << "Cure default constructor called" << std::endl;
    return;
}

Cure::Cure(Cure const & src)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
    return;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
    return;
}

Cure & Cure::operator=(Cure const & right_side)
{
    std::cout << "Cure assignation operator called" << std::endl;
    if (this != &right_side)
        this->_type = right_side._type;
    return *this;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
    return;
}

