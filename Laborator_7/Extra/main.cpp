#include "vector.cpp"


int compare_ints(int x, int y) {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    Vector<int> v;

    v.insert(0, 10);
    v.insert(1, 5);
    v.insert(2, 20);
    v.insert(1, 15); // [10, 15, 5, 20]

    std::cout << "After insertions: ";
    v.print();

    std::cout << "Element at index 2: " << v[2] << "\n";

    v.remove(1); // remove 15
    std::cout << "After removal: ";
    v.print();

    v.sort(compare_ints);
    std::cout << "After sort with compare_ints: ";
    v.print();

    v.insert(0, 7);
    std::cout << "Before sort (operator<): ";
    v.print();

    v.sort();
    std::cout << "After sort with operator<: ";
    v.print();

    Vector<int> copy = v;
    std::cout << "Copied vector: ";
    copy.print();

    Vector<int> moved = std::move(v);
    std::cout << "Moved vector: ";
    moved.print();

    std::cout << "Original vector after move: ";
    v.print();

    return 0;
}