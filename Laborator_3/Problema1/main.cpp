#include <iostream>
#include "Math.h"

int main() {
    // Testing integer addition
    std::cout << "Add(5, 3) = " << Math::Add(5, 3) << std::endl;
    std::cout << "Add(5, 3, 2) = " << Math::Add(5, 3, 2) << std::endl;

    // Testing double addition
    std::cout << "Add(5.5, 3.3) = " << Math::Add(5.5, 3.3) << std::endl;
    std::cout << "Add(5.5, 3.3, 2.2) = " << Math::Add(5.5, 3.3, 2.2) << std::endl;

    // Testing integer multiplication
    std::cout << "Mul(5, 3) = " << Math::Mul(5, 3) << std::endl;
    std::cout << "Mul(5, 3, 2) = " << Math::Mul(5, 3, 2) << std::endl;

    // Testing double multiplication
    std::cout << "Mul(5.5, 3.3) = " << Math::Mul(5.5, 3.3) << std::endl;
    std::cout << "Mul(5.5, 3.3, 2.2) = " << Math::Mul(5.5, 3.3, 2.2) << std::endl;

    // Testing variadic addition
    std::cout << "Add(4, 1, 2, 3, 4) = " << Math::Add(4, 1, 2, 3, 4) << std::endl;

    // Testing string addition
    const char* str1 = "Hello, ";
    const char* str2 = "World!";
    char* result = Math::Add(str1, str2);

    if (result) {
        std::cout << "Add(\"Hello, \", \"World!\") = " << result << std::endl;
        delete[] result; // Free allocated memory
    }
    else {
        std::cout << "String concatenation failed (nullptr detected)." << std::endl;
    }

    return 0;
}