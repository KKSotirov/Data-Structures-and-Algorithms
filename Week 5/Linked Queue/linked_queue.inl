#include <stdexcept>
#include <utility>
#include "linked_queue.hpp"

template <class T>
void LinkedQueue<T>::swap(LinkedQueue &other) noexcept
{
    using std::swap;
    swap(head, other.head);
    swap(tail, other.tail);
    swap(size, other.size);
}

template <class T>
void LinkedQueue<T>::copyFrom(const LinkedQueue &other)
{
    const Node *iter = other.head;
    while (iter != nullptr)
    {
        this->enqueue(iter->data);
        iter = iter->next;
    }
}

template <class T>
void LinkedQueue<T>::free()
{
    while (!empty())
        dequeue();
}

template <class T>
LinkedQueue<T>::LinkedQueue() = default;

template <class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue &other)
{
    try
    {
        copyFrom(other);
    }
    catch (...)
    {
        free();
        throw;
    }
}

template <class T>
LinkedQueue<T> &LinkedQueue<T>::operator=(const LinkedQueue &other)
{
    if (this != &other)
    {
        LinkedQueue copy(other);
        this->swap(copy);
    }
    return *this;
}

template <class T>
LinkedQueue<T>::~LinkedQueue()
{
    free();
}

template <class T>
void LinkedQueue<T>::enqueue(const T &el)
{
    Node *newNode = new Node{el, nullptr};
    if (empty())
    {
        // empty queue
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Not empty queue
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <class T>
void LinkedQueue<T>::dequeue()
{
    if (empty())
        throw std::underflow_error("Stack is already empty!");

    Node *tmp = head;
    head = head->next;
    delete tmp;
    size--;
    if (size == 0)
        tail = head;
}

template <class T>
T &LinkedQueue<T>::front()
{
    if (empty())
        throw std::underflow_error("Empty Queue!");

    return head->data;
}

template <class T>
const T &LinkedQueue<T>::front() const
{
    if (empty())
        throw std::underflow_error("Empty Queue!");

    return head->data;
}

template <class T>
bool LinkedQueue<T>::empty() const
{
    return head == nullptr;
}

template <class T>
std::size_t LinkedQueue<T>::count() const
{
    return size;
}

template <class T>
void LinkedQueue<T>::clear()
{
    free();
}