struct Node
{
    int value;
    Node *next;
};

void splitInHalves(Node *head, Node *&first, Node *&second)
{
    if (!head)
    {
        first = second = nullptr;
        return;
    }

    Node *rabit = head->next;
    Node *turtle = head;
    while (rabit && rabit->next)
    {
        rabit = rabit->next->next;
        turtle = turtle->next;
    }

    turtle ? second = turtle->next : second = nullptr;
    turtle ? turtle->next = nullptr : first = nullptr;
    first = head;
}

// CODE BELOW IS AI-GENERATED IN ORDER TO ILLUSTRATE HOW THE ALGORITHM WORKS

#include <iostream>

void printList(Node *head)
{
    for (Node *it = head; it; it = it->next)
        std::cout << it->value << " -> ";

    std::cout << "nullptr\n";
    std::cout << "\n";
}

void freeList(Node *head)
{
    while (head)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main()
{
    for (int n = 0; n <= 7; n++)
    {
        Node *head = nullptr;

        // Create the original list
        for (int i = n; i >= 1; i--)
            head = new Node{i, head};

        Node *first = nullptr;
        Node *second = nullptr;

        std::cout << "\n--- TEST: " << n << " nodes ---\n";

        std::cout << "Original: ";
        printList(head);

        splitInHalves(head, first, second);

        std::cout << "First:    ";
        printList(first);

        std::cout << "Second:   ";
        printList(second);

        freeList(first);
        freeList(second);
    }

    return 0;
}