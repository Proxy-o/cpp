#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie;

	zombie = newZombie("Zombie1");
	zombie->announce();
	delete zombie;
	randomChump("Zombie2");
	return (0);
}