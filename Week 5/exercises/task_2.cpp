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
}

template <class T>
std::size_t countNodes(const Node<T> *head)
{
    const Node<T> *iter = head;
    size_t count = 0;
    while (iter)
    {
        count++;
        iter = iter->next;
    }
    return count;
}

template <class T>
void printEverySecond(const Node<T> *head)
{
    const Node<T> *iter = head;
    size_t index = 1;
    while (iter)
    {
        if (index % 2 == 0)
            std::cout << iter->data << " ";
        index++;
        iter = iter->next;
    }
}

int main()
{
    Node<int> n6{60, nullptr};
    Node<int> n5{50, &n6};
    Node<int> n4{40, &n5};
    Node<int> n3{30, &n4};
    Node<int> n2{20, &n3};
    Node<int> n1{10, &n2};

    Node<int> *head = &n1;

    std::cout << "Elements: ";
    print(head);

    std::cout << "\nCount: ";
    std::cout << countNodes(head);

    std::cout << "\nEvery second element: ";
    printEverySecond(head);

    return 0;
}