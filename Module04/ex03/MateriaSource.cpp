#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    _count = 0;
    for (int i = 0; i < 4; i++)
    {
        _materia[i] = NULL;
    }
    return;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    *this = copy;
    return;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] != NULL)
        {
            delete _materia[i];
        }
    }
    return;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materia[i] != NULL)
            {
                delete _materia[i];
                _materia[i] = NULL;
            }
        }
        _count = copy._count;
        for (int i = 0; i < 4; i++)
        {
            if (copy._materia[i] != NULL)
            {
                _materia[i] = copy._materia[i]->clone();
            }
           
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (_count < 4)
    {
        _materia[_count] = m;
        _count++;
    }
    else
    {
        std::cout << "There is no more space for new materia in MateriaSource" << std::endl;
    }
    return;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] != NULL && _materia[i]->getType() == type)
        {
            return _materia[i]->clone();
        }
    }
    std::cout << "Materia " << type << " not found" << std::endl;
    return NULL;
}

