#include <iostream>
#include <cstddef>

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
void print(const Node<T> *head)
{
    const Node<T> *iter = head;

    while (iter)
    {
        std::cout << iter->data << " ";
        iter = iter->next;
    }

    std::cout << "\n";
}

template <class T>
void swapFirstTwo(Node<T> *&head)
{
    if ((head) && (head->next))
        throw std::underflow_error("Queue underflow!");
    Node<T> *tmp = head->next;
    head->next = head->next->next;
    tmp->next = head;
    head = tmp;
}

template <class T>
void moveFirstToLast(Node<T> *&head, Node<T> *&tail)
{
    if (!head || head == tail)
        return;

    // [1] ~~> [2] ~~> [3] ~~> [7]
    // [2] ~~> [3] ~~> [7] ~~> [1]
    Node<T> *tmp = head;
    head = head->next;
    tmp->next = nullptr;
    tail->next = tmp;
    tail = tail->next;
}

int main()
{
    Node<int> n5{50, nullptr};
    Node<int> n4{40, &n5};
    Node<int> n3{30, &n4};
    Node<int> n2{20, &n3};
    Node<int> n1{10, &n2};

    Node<int> *head = &n1;
    Node<int> *tail = &n5;

    std::cout << "Initial: ";
    print(head);

    swapFirstTwo(head);

    std::cout << "After swap: ";
    print(head);

    moveFirstToLast(head, tail);

    std::cout << "After rotation: ";
    print(head);

    return 0;
}