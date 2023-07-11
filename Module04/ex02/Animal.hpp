#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &src);
    Animal &operator=(const Animal &right_side);

    virtual void makeSound() = 0;
    std::string getType() const;
    void setType(std::string type);
};

#endif
