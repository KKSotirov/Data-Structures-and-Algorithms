#pragma once
#include <cstddef>

template <typename T>
class DynamicArray
{
private:
    T *data;
    std::size_t size;
    std::size_t capacity;

public:
    DynamicArray();
    DynamicArray(const DynamicArray &other);
    DynamicArray &operator=(const DynamicArray &other); // copy and swap
    ~DynamicArray();

    void push_back(const T &value);
    void pop_back();

    void insert(std::size_t index, const T &value);
    void erase(std::size_t index);
    void clear();

    T &operator[](const std::size_t index);
    const T &operator[](const std::size_t index) const;

    T &at(const std::size_t index);
    const T &at(const std::size_t index) const;
};

#include "dynamic_array.inl"