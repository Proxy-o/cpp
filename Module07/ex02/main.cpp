/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:05:32 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/02 14:35:02 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "Array.hpp"
void f()
{
    system("leaks result");
}
int main()
{
    atexit(f);
    // test exmeple from subject
    Array<int> numbers(5);
    for (unsigned int i = 0; i < 5; i++)
    {
        numbers[i] = i;
    }
    Array<int> numbers2(numbers);
    Array<int> numbers3;
    numbers3 = numbers2;
    std::cout << numbers3 << std::endl;
    std::cout << numbers2 << std::endl;
    std::cout << numbers << std::endl;
    // test with strings
    Array<std::string> strings(5);
    strings[0] = "hello";
    strings[1] = "world";
    strings[2] = "this";
    strings[3] = "is";
    strings[4] = "a test";
    Array<std::string> strings2(strings);
    Array<std::string> strings3;
    strings3 = strings2;
    strings[2] = "its changed";
    std::cout << strings3 << std::endl;
    std::cout << strings2 << std::endl;
    std::cout << strings << std::endl;
    // test try catch
    try
    {
        std::cout << strings[5] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 1;
}