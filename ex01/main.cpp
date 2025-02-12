#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.value = 42;
    data.text = "Hello, World!";

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Original Data value: " << data.value << std::endl;
    std::cout << "Original Data text: " << data.text << std::endl;

    // Serialization
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    // Deserialization
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserializedPtr << std::endl;
    std::cout << "Deserialized Data value: " << deserializedPtr->value << std::endl;
    std::cout << "Deserialized Data text: " << deserializedPtr->text << std::endl;

    // Check if the pointers match
    if (deserializedPtr == &data)
        std::cout << "Deserialization successful!" << std::endl;
    else
        std::cout << "Deserialization failed!" << std::endl;

    return 0;
}
