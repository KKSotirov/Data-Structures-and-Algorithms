#pragma once
#include <cstddef>
#include <cassert>
#include <stdexcept>

template <typename T, std::size_t N>
class StaticArray
{
private:
    T data[N > 0 ? N : 1];

public:
    StaticArray();

    T &operator[](std::size_t index);
    const T &operator[](const size_t index) const;

    T &at(const std::size_t index);
    const T &at(const std::size_t index) const;

    bool empty() const;
    std::size_t size() const;

    void fill(const T &value);
};

#include "static_array.inl"
