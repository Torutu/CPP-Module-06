#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Generates a random instance of A, B, or C
Base* generate(void) {
    int choice = std::rand() % 3; // Generates 0, 1, or 2

    switch (choice) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return NULL; // Should never happen
}

// Identifies object type from pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identifies object type from reference (cannot use a pointer directly)
void identify(Base& p) {
    identify(&p); // Calls the pointer version to avoid extra casting logic
}
