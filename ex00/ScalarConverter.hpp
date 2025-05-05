#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>

class ScalarConverter {
public:

    ScalarConverter(); // Prevent instantiation
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    static void convert(const std::string &literal);    
};

#endif
