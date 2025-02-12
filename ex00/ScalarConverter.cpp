#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    char charVal;
    int intVal;
    float floatVal;
    double doubleVal;
    bool isChar = false, isInt = false, isFloat = false, isDouble = false;

    // Handle pseudo-literals first
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "\n";
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << "\n";
        return;
    }
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return;
    }

    // Detect char type
    if (literal.length() == 1 && !isdigit(literal[0])) {
        charVal = literal[0];
        intVal = static_cast<int>(charVal);
        floatVal = static_cast<float>(charVal);
        doubleVal = static_cast<double>(charVal);
        isChar = true;
    } else {
        // Try to parse it as int, float, or double
        try {
            intVal = std::stoi(literal);
            isInt = true;
        } catch (...) {}

        try {
            floatVal = std::stof(literal);
            isFloat = true;
        } catch (...) {}

        try {
            doubleVal = std::stod(literal);
            isDouble = true;
        } catch (...) {}
    }

    // Printing results
    if (isChar) {
        std::cout << "char: " << (isprint(charVal) ? std::string(1, charVal) : "Non displayable") << "\n";
        std::cout << "int: " << intVal << "\n";
        std::cout << "float: " << floatVal << "f\n";
        std::cout << "double: " << doubleVal << "\n";
        return;
    }

    if (isInt || isFloat || isDouble) {
        if (isInt) {
            if (intVal >= std::numeric_limits<char>::min() && intVal <= std::numeric_limits<char>::max()) {
                std::cout << "char: " << (isprint(intVal) ? std::string(1, static_cast<char>(intVal)) : "Non displayable") << "\n";
            } else {
                std::cout << "char: impossible\n";
            }
            std::cout << "int: " << intVal << "\n";
        } else {
            std::cout << "int: impossible\n";
            std::cout << "char: impossible\n";
        }

        if (isFloat) {
            std::cout << "float: " << floatVal << "f\n";
        } else {
            std::cout << "float: impossible\n";
        }

        if (isDouble) {
            std::cout << "double: " << doubleVal << "\n";
        } else {
            std::cout << "double: impossible\n";
        }
        return;
    }

    // If nothing matched
    std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}
