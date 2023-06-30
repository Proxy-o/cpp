#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
    std::string name;
    Weapon *weapon;

    void attack();
    void setWeapon(Weapon &weapon);
    HumanB(std::string name);
    ~HumanB();
};
