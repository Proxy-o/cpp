/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:26:12 by otait-ta          #+#    #+#             */
/*   Updated: 2023/10/20 13:53:26 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "new top: " << mstack.top() << std::endl;
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(100);
    mstack.push(13);
    mstack.push(37);
    mstack.push(-9);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "stack: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);
    std::cout << "top: " << s.top() << std::endl;
    std::cout << "size: " << s.size() << std::endl;

    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    return 0;
}