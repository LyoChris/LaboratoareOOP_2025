#pragma once
#include <iostream> 

template<typename T>
class Vector {
private:
    T* data;
    int capacity;
    int size;

    void resize();

public:
    Vector();
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    void insert(int index, const T& element);
    void remove(int index);
    void sort(int (*cmp)(T, T));
    void sort();
    T& operator[](int index);
    void print() const;
    int get_size() const;
};