#include "vector.h"

template<typename T>
Vector<T>::Vector() : capacity(4), size(0) {
    data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector& other) : capacity(other.capacity), size(other.size) {
    data = new T[capacity];
    for (int i = 0; i < size; ++i)
        data[i] = other.data[i];
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept : data(other.data), capacity(other.capacity), size(other.size) {
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template<typename T>
void Vector<T>::resize() {
    capacity *= 2;
    T* new_data = new T[capacity];
    for (int i = 0; i < size; ++i)
        new_data[i] = data[i];
    delete[] data;
    data = new_data;
}

template<typename T>
void Vector<T>::insert(int index, const T& element) {
    if (index < 0 || index > size) return;

    if (size == capacity)
        resize();

    for (int i = size; i > index; --i)
        data[i] = data[i - 1];

    data[index] = element;
    ++size;
}

template<typename T>
void Vector<T>::remove(int index) {
    if (index < 0 || index >= size) return;

    for (int i = index; i < size - 1; ++i)
        data[i] = data[i + 1];

    --size;
}

template<typename T>
void Vector<T>::sort(int (*cmp)(T, T)) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (cmp(data[j], data[j + 1]) > 0) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void Vector<T>::sort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (data[j + 1] < data[j]) {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

template<typename T>
T& Vector<T>::operator[](int index) {
    return data[index];
}

template<typename T>
void Vector<T>::print() const {
    for (int i = 0; i < size; ++i)
        std::cout << data[i] << " ";
    std::cout << "\n";
}

template<typename T>
int Vector<T>::get_size() const {
    return size;
}
