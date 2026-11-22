
#include <iostream>

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
bool hasAtleastOneElement(const Node<T> *head)
{
    return (head);
}

template <class T>
bool hasAtleastTwoElements(const Node<T> *head)
{
    return hasAtleastOneElement(head) && (head->next);
}

template <class T>
bool hasAtLeastThreeElements(const Node<T> *head)
{
    return hasAtleastTwoElements(head) && ((head->next)->next);
}

template <class T>
bool hasExactlyOneElement(const Node<T> *head)
{
    return hasAtleastOneElement(head) && (!head->next);
}

template <class T>
bool hasExactlyTwoElements(const Node<T> *head)
{
    return hasAtleastTwoElements(head) && (!(head->next)->next);
}

template <class T>
bool hasExactlyThreeElements(const Node<T> *head)
{
    return hasAtLeastThreeElements(head) && (!head->next->next->next);
}