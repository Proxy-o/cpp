#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(Ice const & src);
        ~Ice();
        Ice & operator=(Ice const & right_side);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif