#pragma once

#include <iostream>

#define PRINT(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;

class ScalarConverter
{
private:
    ScalarConverter(void);
    ~ScalarConverter(void);
    ScalarConverter(ScalarConverter const &toCopy);
    ScalarConverter &operator=(ScalarConverter const &right_side);
    int getType(const std::string str) const;

public:
    static void convert(const std::string str);
};