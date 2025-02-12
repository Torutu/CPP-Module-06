#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

// Function declarations
Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generation

    // Generate a random object
    Base* randomObject = generate();

    std::cout << "Identifying from pointer: ";
    identify(randomObject);

    std::cout << "Identifying from reference: ";
    identify(*randomObject);

    delete randomObject; // Clean up
    return 0;
}
