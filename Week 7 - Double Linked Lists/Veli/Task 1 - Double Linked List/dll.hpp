#pragma once;
struct Node
{
    int value;
    Node *prev;
    Node *next;

    Node() : value(0), prev(nullptr), next(nullptr) {}
    Node(int x) : value(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node *prev, Node *next)
        : value(x), prev(prev), next(next) {}
};

class DoubleLinkedList
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;

    void swap(DoubleLinkedList &other) noexcept;
    void free();
    void copyFrom(const DoubleLinkedList &other);

public:
    DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList &other);
    DoubleLinkedList &operator=(const DoubleLinkedList &other);
    ~DoubleLinkedList();

    // Key functionalities
    void pushBack(const int val);
    void popBack();

    void pushFront(const int val);
    void popFront();

    void insertFirst(const int val);
    void removeFirst();

    void insertAfter(Node *&pos, const int val);
    void removeAfter(Node *&pos);

    void insertBefore(Node *&pos, const int val);
    void removeBefore(Node *&pos);
};

#include "dll.inl";