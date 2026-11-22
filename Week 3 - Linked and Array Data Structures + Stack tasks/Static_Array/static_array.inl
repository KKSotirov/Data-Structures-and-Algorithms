
template <typename T, std::size_t N>
StaticArray<T, N>::StaticArray() : data{} {}

template <typename T, std::size_t N>
T &StaticArray<T, N>::operator[](std::size_t index)
{
    assert(index < N);
    return data[index];
}

template <typename T, std::size_t N>
const T &StaticArray<T, N>::operator[](const std::size_t index) const
{
    assert(index < N);
    return data[index];
}

template <typename T, std::size_t N>
T &StaticArray<T, N>::at(const std::size_t index)
{
    if (index >= N)
        throw std::out_of_range("Invalid index!");

    return data[index];
}

template <typename T, std::size_t N>
const T &StaticArray<T, N>::at(const std::size_t index) const
{
    if (index >= N)
        throw std::out_of_range("Invalid index!");

    return data[index];
}

template <typename T, std::size_t N>
bool StaticArray<T, N>::empty() const
{
    return N == 0;
}

template <typename T, std::size_t N>
std::size_t StaticArray<T, N>::size() const
{
    return N;
}

template <typename T, std::size_t N>
void StaticArray<T, N>::fill(const T &value)
{
    for (std::size_t i = 0; i < N; i++)
        data[i] = value;
}

#include "static_array.hpp"