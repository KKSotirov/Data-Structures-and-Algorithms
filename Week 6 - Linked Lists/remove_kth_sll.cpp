struct Node
{
    int value;
    Node *next;
};

bool setDistance(Node *&rabit, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (!rabit)
            return false;

        rabit = rabit->next;
    }

    return true;
}

void cut(Node *&pos)
{
    Node *tmp = pos;
    pos = pos->next;
    delete tmp;
    return;
}

void removeKth(Node *&head, int k)
{
    if (!head || k <= 0)
        return;

    Node *rabit = head;
    Node *turtle = head;

    // Our rabit did not take a single step ~~> invalid k
    if (!setDistance(rabit, k))
        return;

    // Our Rabit has walked off to after the last element, meaning k = listSize ~~> The user wants to cut off the head
    if (!rabit)
    {
        cut(head);
        return;
    }

    // We walk our rabit and turtle, while rabit is not the last, in order to set our turtle one pos behind k-th
    while (rabit->next)
    {
        rabit = rabit->next;
        turtle = turtle->next;
    }

    // Now turtle is just before the kth position! ~~> We cut
    if (turtle)
        cut(turtle->next);
}