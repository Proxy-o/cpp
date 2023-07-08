/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:28:24 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/08 11:44:48 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("himeroune");
    ScavTrap scavTrap2("himeroune2");
    scavTrap.attack("target1");
    scavTrap.guardGate();
    scavTrap2.attack("target2");
    scavTrap2.guardGate();

    return 0;
}