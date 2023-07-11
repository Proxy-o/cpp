#ifndef MATERIALSOURCE_HPP
#define MATERIALSOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria	*_materia[4];
    int			_count;
public:
    MateriaSource();
    MateriaSource(const MateriaSource &copy);
    virtual ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &copy);

    virtual void learnMateria(AMateria *m);
    virtual AMateria *createMateria(std::string const &type);
};

#endif
