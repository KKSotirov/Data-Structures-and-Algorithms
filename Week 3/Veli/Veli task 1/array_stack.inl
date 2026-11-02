#include <cstddef>
#include "array_stack.hpp"

template <typename T>
void ArrayStack<T>::push(const T &value)
{
    data.push_back(value);
}

template <typename T>
void ArrayStack<T>::pop()
{
    data.pop_back();
}

template <typename T>
T &ArrayStack<T>::top()
{
    if (data.empty())
        throw std::out_of_range("Stack is empty!");

    return data[data.getSize() - 1];
}

template <typename T>
const T &ArrayStack<T>::top() const
{
    if (data.empty())
        throw std::out_of_range("Stack is empty!");

    return data[data.getSize() - 1];
}

template <typename T>
bool ArrayStack<T>::empty() const
{
    return (data.empty());
}

template <typename T>
std::size_t ArrayStack<T>::size() const
{
    return data.getSize();
}