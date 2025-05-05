#include "Serializer.hpp"

/*
unitptr_t is an unsigned integer type
it is an integer type that can hold an address
it can allow you to safely convert pointer to int and back to pointer
*/

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
