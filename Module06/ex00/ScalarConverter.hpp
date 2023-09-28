#pragma once

#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

#define PRINT(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;

class ScalarConverter
{
private:
    ScalarConverter(void);
    ~ScalarConverter(void);
    ScalarConverter(ScalarConverter const &toCopy);
    ScalarConverter &operator=(ScalarConverter const &right_side);
    static int getType(const std::string str);
    static bool is_valid_int(std::string str);
    static bool is_valid_float(std::string str);
    static double is_valid_double(std::string str);
    static void to_char(const std::string str);
    static void to_int(const std::string str);
    static void to_float(const std::string str);
    static void to_double(const std::string str);
    static bool overflow_int(std::string str);

public:
    static void convert(const std::string str);
};

enum e_type
{
    INVALID,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
};