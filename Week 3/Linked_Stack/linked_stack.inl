#include <cstddef>
#include <stdexcept>
#include "linked_stack.hpp"
#include <utility>

template <typename T>
void LinkedStack<T>::swap(LinkedStack &other) noexcept
{
    std::swap(topNode, other.topNode);
    std::swap(count, other.count);
}

template <typename T>
LinkedStack<T>::LinkedStack() : topNode(nullptr), count(0) {}

// ChatGpt constructor ~~> need to remember it!
template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack &other)
    : topNode(nullptr), count(0)
{
    if (other.topNode == nullptr)
        return;

    try
    {
        topNode = new Node{other.topNode->data, nullptr};
        count++;

        Node *current = topNode;
        Node *otherCurrent = other.topNode->next;

        while (otherCurrent != nullptr)
        {
            current->next = new Node{otherCurrent->data, nullptr};

            current = current->next;
            otherCurrent = otherCurrent->next;
            count++;
        }
    }
    catch (...)
    {
        clear();
        throw;
    }
}

template <typename T>
LinkedStack<T> &LinkedStack<T>::operator=(LinkedStack other)
{
    if (this != &other)
        this->swap(other);

    return *this;
}

template <typename T>
void LinkedStack<T>::push(const T &value)
{
    Node *newNode = new Node{value, topNode};
    topnode = newNode;
    count++;
}

template <typename T>
void LinkedStack<T>::pop()
{
    if (topNode == NULL)
    {
        std::cout << "Stack underflow \n";
        return -1;
    }

    Node *temp = topNode;
    topNode = topNode.next;

    delete temp;
    count--;
}

template <typename T>
T &LinkedStack<T>::top()
{
    return topNode.data;
}

template <typename T>
const T &LinkedStack<T>::top() const
{
    return topNode.data;
}

template <typename T>
bool LinkedStack<T>::empty() const
{
    return (topNode == NULL);
}

template <typename T>
std::size_t LinkedStack<T>::size() const
{
    return count;
}

template <typename T>
void LinkedStack<T>::clear()
{
    while (count != 0)
        pop();
}
