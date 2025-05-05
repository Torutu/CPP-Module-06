#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <stdexcept>

class ScalarConverter {
public:

    ScalarConverter(); // Prevent instantiation
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

    static void convert(const std::string &literal);    
};



// Custom exception class for invalid conversion
class ConversionException : public std::exception {
public:
    ConversionException(const std::string& message) : msg(message) {}
    
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};


#endif
