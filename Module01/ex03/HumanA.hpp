#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
public:
    std::string name;
    Weapon &weapon;

    void attack();
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
};
