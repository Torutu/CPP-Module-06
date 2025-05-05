#include "Serializer.hpp"
#include <iostream>
#include <stdexcept> // for std::runtime_error

int main() {
    try {
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
        if (!deserializedPtr)
            throw std::runtime_error("Deserialization returned null pointer!");

        std::cout << "Deserialized Data address: " << deserializedPtr << std::endl;
        std::cout << "Deserialized Data value: " << deserializedPtr->value << std::endl;
        std::cout << "Deserialized Data text: " << deserializedPtr->text << std::endl;

        if (deserializedPtr == &data)
            std::cout << "Deserialization successful!" << std::endl;
        else
            throw std::runtime_error("Pointer mismatch after deserialization!");

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
 