template <typename T>
void swap(DynamicArray<T> &copy) noexcept
{
    std::swap(this->data, copy.data);
    std::swap(this->size, copy.size);
    std::swap(this->capacity, copy.capacity);
}

template <typename T>
void DynamicArray<T>::resize()
{
    try
    {
        T copy = new T[size * 2];
        for (size_t i = 0; i < size; i++)
            copy[i] = data[i];
    }
    catch (...)
    {
        delete[] copy;
        throw;
    }

    capacity *= 2;
    delete[] data;
    data = copy;
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
    for (size_t i = 0; i < count; i++)
        data[i] = other.data[i];
}

template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray &other)
{
    if (this != other)
    {
        DynamicArray copy(other);
        this->swap(other);
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

    data[count] = value;
    count++;
}

#include "dynamic_array.hpp"