/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:08:17 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/08 11:41:38 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = fragTrap;
    return;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
    return;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    this->_name = fragTrap._name;
    this->_hitPoints = fragTrap._hitPoints;
    this->_energyPoints = fragTrap._energyPoints;
    this->_attackDamage = fragTrap._attackDamage;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
        std::cout << "FragTrap " << this->_name << " says: High five, even though he only has two fingers!" << std::endl;
    else if (this->_energyPoints <= 0)
        std::cout << "FragTrap " << this->_name << "  has no energy points to High Five" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << "FragTrap " << this->_name << "  has no hit points to High Five" << std::endl;
    return;
}
