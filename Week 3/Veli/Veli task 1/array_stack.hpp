#pragma once
#include "dynamic_array.hpp"
#include <cstddef>

template <typename T>
class ArrayStack
{
private:
    DynamicArray<T> data;

public:
    void push(const T &value);
    void pop();

    T &top();
    const T &top() const;

    bool empty() const;
    std::size_t size() const;
};

#include "array_stack.inl"
