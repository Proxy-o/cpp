#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "";
    return;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
    return;
}

Brain::Brain(const Brain &src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
    return;
}

Brain &Brain::operator=(const Brain &right_side)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &right_side)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = right_side.ideas[i];
    }
    return (*this);
}

void Brain::printIdeas() const
{
    for (int i = 0; i < 100; i++)
        std::cout << this->ideas[i] << std::endl;
    return;
}

std::string Brain::getIdea(int index) const
{
    return (this->ideas[index]);
}

void Brain::setIdea(int index, std::string new_idea)
{
    this->ideas[index] = new_idea;
    return;
}