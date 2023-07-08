/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:34:36 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/08 11:01:02 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << " ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << " ScavTrap name constructor called & the name is : " << name << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    std::cout << " ScavTrap Copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap::~ScavTrap()
{
    std::cout << " ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    std::cout << " ScavTrap Assignation operator called" << std::endl;
    this->_name = scavTrap._name;
    this->_hitPoints = scavTrap._hitPoints;
    this->_energyPoints = scavTrap._energyPoints;
    this->_attackDamage = scavTrap._attackDamage;
    return *this;
}

void ScavTrap::attack(std::string const &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
        std::cout << " ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    else if (this->_energyPoints <= 0)
        std::cout << " ScavTrap " << this->_name << "  has no energy points!" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << " ScavTrap " << this->_name << "  has no hit points!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}
