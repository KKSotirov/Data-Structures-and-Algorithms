struct Node
{
    int value;
    Node *next;
};

void moveMinToFront(Node *&head)
{
    if (!head)
        return;

    Node *itMin = head;
    Node *itMinPrev = nullptr;
    for (Node *it = head; it && it->next; it = it->next)
    {

        if (it->next->value < itMin->value)
        {
            itMinPrev = it;
            itMin = it->next;
        }
    }

    // Handle edge case (itMinPrev is still nullptr and touching its ->Value ptr we suffer an agonising death)
    if (itMin == head)
        return;

    // Now we "Skip" itMinValue Node
    itMinPrev->next = itMin->next;

    // Now we "Insert" itMinValue Node before head
    itMin->next = head;
    head = itMin;
}
