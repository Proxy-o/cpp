#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
   Animal *animal = new Dog();
   Animal *animal2 = new Cat();

   animal->makeSound();
   animal2->makeSound();
   delete animal;
   delete animal2;
   return (0);
}