#include "ScalarConverter.hpp"



ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
    return *this;
}

//PseudoLiteral is a string that represent a special floating-point value that isn't a regular number
/*
| Literal | Meaning                   | Type it belongs to |
| ------- | ------------------------- | ------------------ |
| `nan`   | Not a Number              | `double`           |
| `nanf`  | Not a Number (float)      | `float`            |
| `+inf`  | Positive infinity         | `double`           |
| `-inf`  | Negative infinity         | `double`           |
| `+inff` | Positive infinity (float) | `float`            |
| `-inff` | Negative infinity (float) | `float`            |
*/
static bool isPseudoLiteral(const std::string& s) {
    return (s == "-inff" || s == "+inff" || s == "nanf" ||
            s == "-inf" || s == "+inf" || s == "nan");
}

static bool isFloatPseudoLiteral(const std::string& s) {
    return (s == "-inff" || s == "+inff" || s == "nanf");
}

static void printFloat(double value) {
    float f = static_cast<float>(value);
    if (std::isnan(f) || std::isinf(f) || f != static_cast<int>(f))
        std::cout << "float: " << f << "f\n";
    else
        std::cout << "float: " << f << ".0f\n";
}

static void printDouble(double value) {
    if (std::isnan(value) || std::isinf(value) || value != static_cast<int>(value))
        std::cout << "double: " << value << "\n";
    else
        std::cout << "double: " << value << ".0\n";
}

void ScalarConverter::convert(const std::string& literal) {
    char charVal;
    int intVal;
    float floatVal;
    double doubleVal;

    try {
        // Check if it's a pseudo literal
        if (isPseudoLiteral(literal)) {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";

            if (isFloatPseudoLiteral(literal)) {
                std::cout << "float: " << literal << "\n";
                std::cout << "double: " << literal.substr(0, literal.length() - 1) << "\n";
            } else {
                std::cout << "float: " << literal << "f\n";
                std::cout << "double: " << literal << "\n";
            }
            return;
        }

        char* endPtr = NULL;
        errno = 0;
        doubleVal = std::strtod(literal.c_str(), &endPtr);

        // Check if it's a single displayable char
        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            charVal = literal[0];
            intVal = static_cast<int>(charVal);
            floatVal = static_cast<float>(charVal);
            doubleVal = static_cast<double>(charVal);

            std::cout << "char: '" << charVal << "'\n";
            std::cout << "int: " << intVal << "\n";
            printFloat(doubleVal);
            printDouble(doubleVal);
            return;
        }

        // Conversion failed if nothing consumed
        if ((*endPtr && *endPtr != 'f') || (endPtr[0] && endPtr[1])) {
            throw ConversionException("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible");
        }

        intVal = static_cast<int>(doubleVal);
        floatVal = static_cast<float>(doubleVal);
        charVal = static_cast<char>(intVal);

        // Print char
        if (intVal >= 0 && intVal <= 127) {
            if (std::isprint(charVal))
                std::cout << "char: '" << charVal << "'\n";
            else
                std::cout << "char: Non displayable\n";
        } else {
            std::cout << "char: impossible\n";
        }

        // Print int
        if (doubleVal >= static_cast<double>(std::numeric_limits<int>::min()) &&
            doubleVal <= static_cast<double>(std::numeric_limits<int>::max())) {
            std::cout << "int: " << intVal << "\n";
        } else {
            std::cout << "int: impossible\n";
        }
    
        // Print float and double
        printFloat(doubleVal);
        printDouble(doubleVal);

    } catch (const ConversionException& e) {
        std::cout << e.what() << "\n";
    } catch (const std::exception& e) {
        // Catch any other standard exceptions
        std::cout << "Error: " << e.what() << "\n";
    }
}
