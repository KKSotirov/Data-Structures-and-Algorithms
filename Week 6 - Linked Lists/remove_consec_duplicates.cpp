struct Node
{
    int value;
    Node *next;
};

void removeDuplicates(Node *head)
{
    if (!head)
        return;

    Node *itRabit = head;
    Node *itTurtle = nullptr;
    while (itRabit)
    {
        // Init itTurtle
        if (!itTurtle)
        {
            itTurtle = itRabit;
            itRabit = itRabit->next;
            continue;
        }

        // Same Consecutive nodes -> we cut
        if (itRabit->value == itTurtle->value)
        {
            Node *tmp = itRabit;
            itRabit = itRabit->next;
            tmp->next = nullptr;
            delete tmp;
        }

        // Different -> we it further
        else
        {
            itTurtle->next = itRabit;
            itTurtle = itRabit;
            itRabit = itRabit->next;
        }
    }
    itTurtle ? itTurtle->next = itRabit : itTurtle = nullptr;
}