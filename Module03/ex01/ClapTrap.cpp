/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:28:42 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/08 10:36:07 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << " ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << " copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap::~ClapTrap()
{
    std::cout << " ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    std::cout << " assignation operator called" << std::endl;
    if (this != &clapTrap)
    {
        this->_name = clapTrap._name;
        this->_hitPoints = clapTrap._hitPoints;
        this->_energyPoints = clapTrap._energyPoints;
        this->_attackDamage = clapTrap._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(std::string const &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << " ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (this->_energyPoints <= 0)
        std::cout << " ClapTrap " << this->_name << "  has no energy points!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << " ClapTrap " << this->_name << "  has no hit points!" << std::endl;
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    std::cout << " ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << " ClapTrap " << this->_name << "  repaired by " << amount << " points!" << std::endl;
        _energyPoints--;
    }
    else if (this->_energyPoints <= 0)
        std::cout << " ClapTrap " << this->_name << "  has no energy points!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << " ClapTrap " << this->_name << "  has no hit points!" << std::endl;
    return;
}
