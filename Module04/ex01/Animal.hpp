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

     void makeSound() const;
    std::string getType() const;
    void setType(std::string type);
};

#endif
