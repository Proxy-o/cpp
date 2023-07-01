#include "Harl.hpp"

Harl::Harl()
{
    return;
}
Harl::~Harl()
{
    return;
}
void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    return;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for\
 years whereas you started working here since last month."
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int i = -1;
    bool is_there = false;

    t_fptr functs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"debug", "info", "warning", "error"};

    while (++i < 4 && !is_there)
    {
        if (level.compare(levels[i]) == 0)
        {
            is_there = true;
            break;
        }
    }
    if (is_there)
        (this->*functs[i])();
    else
        std::cerr << "Wrong level name !" << std::endl;
}