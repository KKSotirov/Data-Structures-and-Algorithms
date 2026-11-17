#pragma once

template <class T>
class LinkedQueue
{
private:
    struct Node
    {
        T data;
        Node *next;
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    size_t size = 0;

    void swap(LinkedQueue &other) noexcept;
    void copyFrom(const LinkedQueue &other);
    void free();

public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue &other);
    LinkedQueue &operator=(const LinkedQueue &other);
    ~LinkedQueue();

    void enqueue(const T &el);
    void dequeue();

    T &front();
    const T &front() const;

    bool empty() const;
    std::size_t count() const;
    void clear();
};

#include "linked_queue.inl"