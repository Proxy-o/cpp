/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:41:25 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/24 17:22:02 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    try
    {

        PmergeMe::vector_merge(argv, argc);
        PmergeMe::deque_merge(argv, argc);

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
