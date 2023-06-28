#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies;

	zombies = zombieHorde(5, "rick");
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}