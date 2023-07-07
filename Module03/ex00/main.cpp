/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:28:24 by otait-ta          #+#    #+#             */
/*   Updated: 2023/07/07 16:28:28 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("clapTrap");
    ClapTrap clapTrap2(clapTrap);
    ClapTrap clapTrap3;
    clapTrap3 = clapTrap2;
    clapTrap.attack("target");
    clapTrap.takeDamage(9);
    clapTrap.attack("target");
    clapTrap.beRepaired(10);
    return (0);
}