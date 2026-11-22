#include <stdexcept>
#include <cassert>
#include <utility>
#include "staticQueue.hpp"

template <class T>
void StaticQueue<T>::copyFrom(const StaticQueue &other)
{
    data = new T[other.count + 1];
    try
    {
        for (size_t i = 0; i < other.count(); i++)
        {
            data[i] = other.data[i];
        }
    }
    catch (...)
    {
        delete[] data;
        throw;
    }

    head = other.head;
    tail = other.tail;
}

template <class T>
void StaticQueue<T>::swap(StaticQueue &other) noexcept
{
    std::swap(this->data, other.data);
    std::swap(this->head, other.head);
    std::swap(this->tail, other.tail);
}

template <class T>
StaticQueue<T>::StaticQueue(const size_t newCap) : head(0), tail(0), data(new T[newCap + 1])
{
}

template <class T>
StaticQueue<T>::StaticQueue(const StaticQueue &other)
{
    this->copyFrom(other);
}

template <class T>
StaticQueue<T> &StaticQueue<T>::operator=(const StaticQueue &other)
{
    if (this != &other)
    {
        StaticQueue copy(other);
        this->swap(copy);
    }
    return *this;
}

template <class T>
StaticQueue<T>::~StaticQueue()
{
    delete[] data;
    data = nullptr;
    head = 0;
    tail = 0;
}

template <class T>
void StaticQueue<T>::enqueue(const T &el)
{
    if (isFull())
        throw std::overflow_error("Queue is already full!");

    data[tail] = el;
    tail = (tail + 1) % this->count();
}

template <class T>
void StaticQueue<T>::dequeue()
{
    if (isEmpty())
        throw std::underflow_error("Queue is empty!");

    // delete data[head] ?
    head = (head + 1) % (cap + 1);
}

template <class T>
bool StaticQueue<T>::isFull() const
{
    return (tail + 1) % (cap + 1) == head;
}

template <class T>
bool StaticQueue<T>::isEmpty() const
{
    return (head == tail);
}

template <class T>
T &StaticQueue<T>::first()
{
    return data[head];
}

template <class T>
const T &StaticQueue<T>::first() const
{
    return data[head];
}

template <class T>
size_t StaticQueue<T>::count() const
{
    return (tail + cap + 1 - head) % (cap + 1);
}