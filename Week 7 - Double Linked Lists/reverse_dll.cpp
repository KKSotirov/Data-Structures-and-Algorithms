#include <stdexcept>
#include <utility>

struct Node
{
    int value;

    Node *prev;
    Node *next;
};

// Solution 1
void reverseDll(Node *&head, Node *&tail)
{
    // No if(!head) and if(head==tail) because we have a pseudo if in our for loop

    Node *tmp;
    for (Node *it = tail; it; it = tmp)
    {
        tmp = it->prev;
        it->prev = it->next;
        it->next = tmp;
    }
    std::swap(head, tail);
}

// Solution 2
void reverseDll2(Node *&head, Node *&tail)
{
    for (Node *it = head; it; it = it->prev)
    {
        std::swap(it->prev, it->next);
        // Tricky because in for loop we iterate with it = it->prev!!! We do so because at line 31 we swap prev and next, so the it=it->prev is really it=it->ORIGINAL next (beforet the swap)
    }
    std::swap(head, tail);
}
