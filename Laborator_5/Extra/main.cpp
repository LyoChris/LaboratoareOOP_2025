#include "Complex.h"

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - 2;
    Complex c5 = 2 * c1;

	std::cout << "c1: " << c1 << "\n";
	std::cout << "c2: " << c2 << "\n";
    std::cout << "c3: " << c3 << "\n";
    std::cout << "c4: " << c4 << "\n";
    std::cout << "c5: " << c5 << "\n";

    c1++;
    std::cout << "After c1++: " << c1 << "\n";
    ++c1;
    std::cout << "After ++c1: " << c1 << "\n";

    c2--;
    std::cout << "After c2--: " << c2 << "\n";
    --c2;
    std::cout << "After --c2: " << c2 << "\n";

    c1();

    return 0;
}