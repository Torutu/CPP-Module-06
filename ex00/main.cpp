#include "ScalarConverter.hpp"

/*
| **Cast Type**          | **Usage**                                                        | **When to Use**                                                                                         | **Example**                                     |
| ---------------------- | ---------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- | ----------------------------------------------- |
| **C-style cast**       | Basic cast with the syntax `(T)value`                            | Use cautiously; most permissive. Avoid when possible due to lack of control over conversions.           | `int i = (int)3.14;`                            |
| **`static_cast`**      | For safe, explicit conversions between related types.            | Convert between numeric types, base/derived classes, etc.                                               | `int i = static_cast<int>(3.14);`               |
| **`dynamic_cast`**     | For downcasting in polymorphic class hierarchies.                | When working with polymorphic classes, for safe downcasting.                                            | `Derived* d = dynamic_cast<Derived*>(basePtr);` |
| **`const_cast`**       | To add or remove the `const` qualifier from pointers/references. | To modify `const` objects or add `const` to non-const types.                                            | `int* ptr = const_cast<int*>(&x);`              |
| **`reinterpret_cast`** | Low-level cast to reinterpret the bit pattern of a value.        | When you need to re-interpret the bit pattern of an object, e.g., cast between unrelated pointer types. | `char* ptr = reinterpret_cast<char*>(&d);`      |

*/

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
