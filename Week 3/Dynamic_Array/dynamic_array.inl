#include <cstddef>
#include <stdexcept>
#include <utility>
#include <cassert>
#include "dynamic_array.hpp"

template <typename T>
void DynamicArray<T>::swap(DynamicArray &copy) noexcept
{
    std::swap(this->data, copy.data);
    std::swap(this->size, copy.size);
    std::swap(this->capacity, copy.capacity);
}

template <typename T>
void DynamicArray<T>::resize()
{
    std::size_t newCapacity = capacity * 2;
    T *copy = new T[newCapacity];

    try
    {
        for (std::size_t i = 0; i < size; i++)
            copy[i] = data[i];
    }
    catch (...)
    {
        delete[] copy;
        throw;
    }

    delete[] data;
    data = copy;
    capacity = newCapacity;
}

template <typename T>
DynamicArray<T>::DynamicArray() : size(0), capacity(2)
{
    data = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &other) : size(other.size), capacity(other.capacity)
{
    data = new T[capacity];

    try
    {
        for (std::size_t i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    catch (...)
    {
        delete[] data;
        throw;
    }
}

template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray &other)
{
    if (this != &other)
    {
        DynamicArray copy(other);
        this->swap(copy);
    }

    return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

template <typename T>
void DynamicArray<T>::push_back(const T &value)
{
    if (size >= capacity)
        resize();

    data[size] = value;
    size++;
}

template <typename T>
void DynamicArray<T>::pop_back()
{
    if (size == 0)
        throw std::out_of_range("Array is empty");
    size--;
}

template <typename T>
void DynamicArray<T>::insert(std::size_t index, const T &value)
{
    if (index > size)
        throw std::out_of_range("Invalid index!");

    if (size >= capacity)
        resize();

    for (std::size_t i = size; i > index; i--)
        data[i] = data[i - 1];

    data[index] = value;
    size++;
}

template <typename T>
void DynamicArray<T>::erase(std::size_t index)
{
    if (index >= size)
        throw std::out_of_range("Invalid index!");

    for (std::size_t i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    size--;
}

template <typename T>
void DynamicArray<T>::clear()
{
    size = 0;
}

template <typename T>
T &DynamicArray<T>::operator[](const std::size_t index)
{
    assert(index < size);
    return data[index];
}

template <typename T>
const T &DynamicArray<T>::operator[](const std::size_t index) const
{
    assert(index < size);
    return data[index];
}

template <typename T>
T &DynamicArray<T>::at(const std::size_t index)
{
    if (index >= size)
        throw std::out_of_range("Invalid index!");

    return data[index];
}

template <typename T>
const T &DynamicArray<T>::at(const std::size_t index) const
{
    if (index >= size)
        throw std::out_of_range("Invalid index!");

    return data[index];
}
