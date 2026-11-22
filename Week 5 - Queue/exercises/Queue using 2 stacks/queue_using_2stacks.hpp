#pragma once
#include <stack>

template <class DataType>
class PseudoQueue
{
private:
    std::stack<DataType> in;
    std::stack<DataType> out;

    void move();
    void swap(PseudoQueue &other) noexcept;
    void free();

public:
    PseudoQueue();
    PseudoQueue(const PseudoQueue &other);
    PseudoQueue &operator=(const PseudoQueue &other);
    ~PseudoQueue();

    // Key functionalities:
    void enqueue(const DataType &data);
    void dequeue();
    bool empty() const;
    DataType &front();
    // No const front() , because move() is required and move changes in and out
    void clear();
};

#include "queue_using_2stacks.inl"