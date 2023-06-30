#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
    return;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (this->weapon == NULL || this->weapon->getType() == "")
        std::cout << this->name << " has no weapon" << std::endl;
    else
        std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
    return;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
    return;
}