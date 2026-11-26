#include <stdexcept>
#include <utility>
#include "dll.hpp"

void DoubleLinkedList::swap(DoubleLinkedList &other) noexcept
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);
}

void DoubleLinkedList::free()
{
    for (auto it = head; it;)
    {
        Node *tmp = it;
        it = it->next;
        delete tmp;
    }
    head = tail = nullptr;
}

void DoubleLinkedList::copyFrom(const DoubleLinkedList &other)
{

    for (Node *it = other.head; it; it = it->next)
    {
        pushBack(it->value);
    }
}

DoubleLinkedList::DoubleLinkedList() = default;
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &other)
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

// Key functionalities
void DoubleLinkedList::pushBack(const int val)
{
    Node *newNode = new Node(val, tail, nullptr);
    if (tail)
        tail->next = newNode;
    else
        head = newNode;

    tail = newNode;
}

void DoubleLinkedList::popBack()
{
    if (!tail)
        throw std::out_of_range("Empty list!");

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node *tmp = tail;
    tail->prev->next = nullptr;
    tail = tail->prev;
    tmp->prev = nullptr;
    delete tmp;
}

void DoubleLinkedList::pushFront(const int val)
{
    Node *newNode = new Node(val, nullptr, head);
    if (head)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
}

void DoubleLinkedList::popFront()
{
    if (!head)
        throw std::out_of_range("Empty list!");

    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
        return;
    }

    Node *tmp = head;
    head->next->prev = nullptr;
    head = head->next;
    tmp->next = nullptr;
    delete tmp;
}

void DoubleLinkedList::insertFirst(const int val)
{
    pushFront(val);
}

void DoubleLinkedList::removeFirst()
{
    popFront();
}

void DoubleLinkedList::insertAfter(Node *&pos, const int val)
{
    if (!pos)
    {
        // empty dll
        throw std::invalid_argument("Invalid position!");
    }

    if (pos == tail)
    {
        pushBack(val);
        return;
    }

    Node *newNode = new Node(val, pos, pos->next);
    pos->next->prev = newNode;
    pos->next = newNode;
}

void DoubleLinkedList::removeAfter(Node *&pos)
{

    // No next
    if (!pos || pos == tail)
        return;

    // Next is tail
    if (pos->next == tail)
    {
        popBack();
        return;
    }

    // Base case
    Node *tmp = pos->next;
    pos->next = tmp->next;
    tmp->next->prev = pos;
    tmp->next = tmp->prev = nullptr;
    delete tmp;
}

void DoubleLinkedList::insertBefore(Node *&pos, const int val)
{
    // Empty/ 1 element dll
    if (!pos)
        throw std::invalid_argument("Invalid position!");

    if (pos == head)
    {
        pushFront(val);
        return;
    }

    // Base case
    Node *newNode = new Node(val, pos->prev, pos);
    pos->prev->next = newNode;
    pos->prev = newNode;
}

void DoubleLinkedList::removeBefore(Node *&pos)
{
    // Nothing to be removed
    if (!pos || pos == head)
        return;

    if (pos->prev == head)
    {
        popFront();
        return;
    }

    // Base case
    Node *tmp = pos->prev;
    tmp->prev->next = pos;
    pos->prev = tmp->prev;
    delete tmp;
}
