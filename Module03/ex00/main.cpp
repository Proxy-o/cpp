#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("clapTrap");
    ClapTrap clapTrap2(clapTrap);
    ClapTrap clapTrap3;
    clapTrap3 = clapTrap2;
    clapTrap.attack("target");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(10);
    return (0);
}