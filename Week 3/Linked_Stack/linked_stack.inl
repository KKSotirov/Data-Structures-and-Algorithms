#include <cstddef>
#include <stdexcept>
#include "linked_stack.hpp"
#include <utility>

template <typename T>
void LinkedStack<T>::swap(LinkedStack &other) noexcept
{
    std::swap(tos, other.tos);
    std::swap(count, other.count);
}

template <typename T>
void LinkedStack<T>::copyFrom(const LinkedStack &other)
{
    tos = nullptr;
    if (other.isEmpty())
        return;

    Node *iterOther = other.tos;

    try
    {
        tos = new Node(iterOther->data);
        Node *iterThis = tos;
        do
        {
            iterOther = iterOther->next;
            if (iterOther)
            {
                iterThis->next = new Node(iterOther->data);
                iterThis = iterThis->next;
                count++;
            }
        } while (iterOther);
    }
    catch (...)
    {
        while (tos != nullptr)
        {
            Node *temp = tos;
            tos = tos->next;
            delete temp;
        }
        count = 0;
        throw;
    }
}

template <typename T>
LinkedStack<T>::LinkedStack() : tos(nullptr), count(0) {}

// ChatGpt constructor ~~> need to remember it!
template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack &other)
    : tos(nullptr), count(0)
{
    if (other.tos == nullptr)
        return;
    copyFrom(other);
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
    Node *newNode = new Node{value, tos};
    tos = newNode;
    count++;
}

template <typename T>
void LinkedStack<T>::pop()
{
    if (tos == NULL)
    {
        std::cout << "Stack underflow \n";
        return -1;
    }

    Node *temp = tos;
    tos = tos.next;

    delete temp;
    count--;
}

template <typename T>
T &LinkedStack<T>::top()
{
    return tos.data;
}

template <typename T>
const T &LinkedStack<T>::top() const
{
    return tos.data;
}

template <typename T>
bool LinkedStack<T>::empty() const
{
    return (tos == NULL);
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
