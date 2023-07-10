#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{

private:
    std::string ideas[100];

public:
    Brain();
    ~Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &right_side);

    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);
    void printIdeas() const;
};

#endif