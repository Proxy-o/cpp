/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:01:18 by otait-ta          #+#    #+#             */
/*   Updated: 2023/09/29 13:15:05 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data *data = new Data;
    data->randomString = "a random string";
    data->randomInt = 41;
    PRINT("before serialization");
    PRINT(data);
    PRINT(data->randomString);
    PRINT(data->randomInt);
    PRINT("---------------");
    uintptr_t raw = Serializer::serialize(data);
    Data *data2 = Serializer::deserialize(raw);
    PRINT("after deserialization");
    PRINT(data2);
    PRINT(data2->randomString);
    PRINT(data2->randomInt);
    return 0;
}