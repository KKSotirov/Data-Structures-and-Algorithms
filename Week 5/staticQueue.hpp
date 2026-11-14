#pragma once
// #include <stdexcept>
// #include <utility>

template <class T>
class StaticQueue
{
private:
    T *data;
    size_t head;
    size_t tail;
    size_t cap;

    void copyFrom(const StaticQueue &other);
    void swap(StaticQueue &other) noexcept;

public:
    StaticQueue(const size_t newCap);
    StaticQueue(const StaticQueue &other);
    StaticQueue &operator=(const StaticQueue &other);
    ~StaticQueue();

    void enqueue(const T &el);
    void dequeue();

    bool isFull() const;
    bool isEmpty() const;

    T &first();
    const T &first() const;

    size_t count() const;
};
