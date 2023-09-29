/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:15:27 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 15:07:49 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base *generate(void)
{
    int random = 0;

    random = std::rand() % 3 + 1;
    if (random == 1)
        return new A;
    else if (random == 2)
        return new B;
    else
        return new C;
}
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        PRINT("the actual tye of p is : A")
    else if (dynamic_cast<B *>(p))
        PRINT("the actual tye of p is : B")
    else if (dynamic_cast<C *>(p))
        PRINT("the actual tye of p is : C")
    else
        PRINT("the actual tye of p is : unknown");
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        PRINT("the actual tye of p is : A");
        (void)a;
    }
    catch (const std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            PRINT("the actual tye of p is : B");
            (void)b;
        }
        catch (const std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                PRINT("the actual tye of p is : C");
                (void)c;
            }
            catch (const std::exception &e)
            {
                ERROR("the actual tye of p is : unknown");
            }
        }
    }
}

int main()
{
    std::srand(std::time(0));
    for (int i = 0; i < 10; i++)
    {
        PRINT("---------------");
        Base *base = generate();
        Base &baseRef = *base;
        identify(base);
        identify(baseRef);
        delete base;
        PRINT("---------------");
    }
}