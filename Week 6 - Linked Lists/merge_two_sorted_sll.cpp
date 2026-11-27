struct Node
{
    int value;
    Node *next;
};

Node *mergeSortedSll(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    Node *head = (head1->value > head2->value) ? head2 : head1;
    Node *newIt;

    while (head1 && head2)
    {
        if (head1->value > head2->value)
        {
            newIt->next = head2;
            head2 = head2->next;
        }
        else
        {
            newIt->next = head1;
            head1 = head1->next;
        }
        newIt = newIt->next;
    }
    newIt->next = head1 ? head1 : head2;
    return head;
}
// SENTINEL

Node *mergeSortedSll2(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    Node sentinel{0, nullptr};
    Node *newIt = &sentinel;

    while (head1 && head2)
    {
        if (head1->value > head2->value)
        {
            newIt->next = head2;
            head2 = head2->next;
        }
        else
        {
            newIt->next = head1;
            head1 = head1->next;
        }
        newIt = newIt->next;
    }

    newIt->next = head1 ? head1 : head2;
    return sentinel.next;
}