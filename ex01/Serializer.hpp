#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint> // For uintptr_t
#include "Data.hpp"

class Serializer {
private:
    Serializer(); // Private constructor to prevent instantiation
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
