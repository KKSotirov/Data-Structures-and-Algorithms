#pragma once
#include <cstddef>

template <typename T>
class LinkedStack
{
private:
    struct Node
    {
        T data;
        Node *next;
    };

    Node *tos;
    std::size_t count;

    void swap(LinkedStack &other) noexcept;
    void copyFrom(const LinkedStack<T> &other);

public:
    LinkedStack();
    LinkedStack(const LinkedStack &other);
    LinkedStack &operator=(LinkedStack other);
    ~LinkedStack();

    void push(const T &value);
    void pop();

    T &top();
    const T &top() const;

    bool empty() const;
    std::size_t size() const;
    void clear();
};

#include "linked_stack.inl"