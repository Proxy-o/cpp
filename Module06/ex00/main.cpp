/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:32:38 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 11:32:40 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    ScalarConverter::convert(argv[1]);

    return 0;
}
