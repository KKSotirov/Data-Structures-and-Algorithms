#include <utility>
#include <stdexcept>
#include "queue_using_2stacks.hpp"

template <class DataType>
void PseudoQueue<DataType>::move()
{
    // moves all elements from stack1 to stack2, thus reversing their order and achieving pseudo FIFO

    while (!in.empty())
    {
        out.push(in.top());
        in.pop();
    }
}

template <class DataType>
void PseudoQueue<DataType>::swap(PseudoQueue &other) noexcept
{
    using std::swap;

    swap(in, other.in);
    swap(out, other.out);
}

template <class DataType>
void PseudoQueue<DataType>::free()
{
    while (!in.empty())
        in.pop();

    while (!out.empty())
        out.pop();
}

template <class DataType>
PseudoQueue<DataType>::PseudoQueue() = default;

template <class DataType>
PseudoQueue<DataType>::PseudoQueue(const PseudoQueue &other) : in(other.in), out(other.out) {}

template <class DataType>
PseudoQueue<DataType> &PseudoQueue<DataType>::operator=(const PseudoQueue &other)
{
    if (this != &other)
    {
        PseudoQueue copy(other);
        this->swap(copy);
    }
    return *this;
}

template <class DataType>
PseudoQueue<DataType>::~PseudoQueue()
{
    free();
}

// Key functionalities
template <class DataType>
void PseudoQueue<DataType>::enqueue(const DataType &data)
{
    in.push(data);
}

template <class DataType>
void PseudoQueue<DataType>::dequeue()
{
    if (empty())
        throw std::underflow_error("Queue underflow!");

    if (out.empty())
        move();
    out.pop();
}

template <class DataType>
bool PseudoQueue<DataType>::empty() const
{
    return (in.empty()) && (out.empty());
}

template <class DataType>
DataType &PseudoQueue<DataType>::front()
{
    if (empty())
        throw std::underflow_error("Queue underflow!");

    if (out.empty())
        move();
    return out.top();
}

template <class DataType>
void PseudoQueue<DataType>::clear()
{
    free();
}