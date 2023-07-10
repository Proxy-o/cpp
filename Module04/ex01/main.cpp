#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const int anim_numb = 4;
    Animal *animals[anim_numb];
    int i;

    std::cout << "Filling first half with dogs, second half with cats :" << std::endl;
    for (i = 0; i < (anim_numb / 2); i++)
        animals[i] = new Dog();
    for (i = anim_numb / 2; i < anim_numb; i++)
        animals[i] = new Cat();

    std::cout << "====== TYPES =====" << std::endl;
    for (i = 0; i < anim_numb; i++)
        std::cout << animals[i]->getType() << std::endl;

    std::cout << "====     SOUNDS =====" << std::endl;
    for (i = 0; i < anim_numb; i++)
        animals[i]->makeSound();
    for (i = 0; i < anim_numb; i++)
    {
        if (animals[i])
            delete animals[i];
    }
}