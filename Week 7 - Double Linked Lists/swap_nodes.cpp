#include <stdexcept>
#include <utility>

struct Node
{
    int value;

    Node *prev;
    Node *next;
};

void swapHelper(Node *&head, Node *&tail, Node *first, Node *secondPrev, Node *secondNext)
{

    first->next = secondNext;
    first->prev = secondPrev;

    // Head
    if (secondPrev)
        secondPrev->next = first;
    else
        head = first;

    // Tail
    if (secondNext)
        secondNext->prev = first;
    else
        tail = first;
}

void swapConsecutiveHelper(Node *&head, Node *&tail, Node *first, Node *second, Node *firstPrev, Node *secondNext)
{

    // Head
    if (firstPrev)
        firstPrev->next = second;
    else
        head = second;

    // Tail
    if (secondNext)
        secondNext->prev = first;
    else
        tail = first;

    first->next = secondNext;
    first->prev = second;

    second->prev = firstPrev;
    second->next = first;
}

void swapTwoNodes(Node *&head, Node *&tail, Node *first, Node *second)
{
    if (!first || !second || first == second)
        return;

    Node *firstPrev = first->prev;
    Node *firstNext = first->next;
    Node *secondPrev = second->prev;
    Node *secondNext = second->next;

    // Consecutive Nodes
    if (firstNext == second)
    {
        swapConsecutiveHelper(head, tail, first, second, firstPrev, secondNext);
        return;
    }
    if (secondNext == first)
    {
        swapConsecutiveHelper(head, tail, second, first, secondPrev, firstNext);
        return;
    }

    // Base case
    swapHelper(head, tail, first, secondPrev, secondNext);
    swapHelper(head, tail, second, firstPrev, firstNext);
}