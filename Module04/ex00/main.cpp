#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *animal = new Animal();
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    std::cout << "====== TYPES =====" << std::endl;
    std::cout << animal->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << "====     SOUNDS =====" << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    cat->makeSound();

    std::cout << "== == TYPES AGAIN AFTER CHANGING ANIMAL TYPE == == =" << std::endl;
    animal->setType("human");
    std::cout << animal->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << "== == SOUNDS AGAIN AFTER CHANGING ANIMAL TYPE == == =" << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    delete animal;
    delete dog;
    delete cat;

    // WRONG ANIMAL
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const WrongAnimal *i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    return 0;
}