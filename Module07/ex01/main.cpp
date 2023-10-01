/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:22:57 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/01 16:01:53 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void toUpper(char c)
{
    if (c >= 'a' && c <= 'z')
        PRINT((char)(c - 32));
}

int main()
{

    PRINT("TESTING WITH INT ARRAY")
    int intArray[5] = {1, 2, 3, 4, 5};
    iter(intArray, 5, print);

    PRINT("TESTING WITH CHAR ARRAY")
    char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
    iter(charArray, 5, toUpper);

    PRINT("TESTING WITH STRING ARRAY")
    std::string stringArray[5] = {"one", "two", "three", "four", "five"};
    iter(stringArray, 5, print);
}
