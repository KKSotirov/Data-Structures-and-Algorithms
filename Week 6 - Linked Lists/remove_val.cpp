struct Node
{
    int value;
    Node *next;
};

void cut(Node *&head, Node *&itR)
{
    if (!itR)
        return;

    if (itR == head)
        head = head->next;

    Node *tmp = itR;
    itR = itR->next;
    tmp->next = nullptr;
    delete tmp;
}

void removeAll(Node *&head, int val)
{
    if (!head)
        return;

    Node *itTurtle = nullptr;
    Node *itRabit = head;
    while (itRabit)
    {
        if (itRabit->value == val)
            cut(head, itRabit);
        else
        {
            itTurtle ? itTurtle->next = itRabit : itTurtle = itRabit;
            itTurtle = itRabit;
            itRabit = itRabit->next;
        }
    }
    itTurtle ? itTurtle->next = itRabit : itTurtle = nullptr;

    return;
}