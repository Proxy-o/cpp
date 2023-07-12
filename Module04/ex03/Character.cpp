#include "Character.hpp"

Character::Character() : _name("default_name"), _count(0)
{
    std::cout << "Character default constructor called" << std::endl;
    return;
}

Character::Character(std::string const &name) : _name(name), _count(0)
{
    std::cout << "Character parameter constructor called" << std::endl;
    return;
}

Character::Character(Character const &src)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = src;
    return;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < this->_count; i++)
        delete this->_inventory[i];
    return;
}

Character &Character::operator=(Character const &right_side)
{
    std::cout << "Character assignation operator called" << std::endl;
    if (this != &right_side)
    {
        this->_name = right_side._name;
        for (int i = 0; i < this->_count; i++)
        {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
        for (int i = 0; i < right_side._count; i++)
        {
            this->_inventory[i] = right_side._inventory[i]->clone();
        }
        this->_count = right_side._count;
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
        std::cout << "Materia " << m->getType() << " equipped" << std::endl;
    if (this->_count < 4)
    {
        this->_inventory[this->_count] = m;
        this->_count++;
    }
    else
        std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if ( idx < this->_count && idx >= 0 )
    {
        for (int i = idx; i < this->_count - 1; i++)
        {
            this->_inventory[i] = this->_inventory[i + 1];
        }
        this->_inventory[this->_count - 1] = NULL;
        this->_count--;
    }
    return;
}

void Character::use(int idx, ICharacter &target)
{
    if ( idx < this->_count && idx >= 0 )
    {
        this->_inventory[idx]->use(target);
    }
    return;
}

