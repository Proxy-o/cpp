#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
public:
    Harl();
    ~Harl();
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void complain(std::string level);
};

typedef void (Harl::*t_fptr)(void);

#endif // HARL_HPP