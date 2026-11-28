struct Node
{
    int value;
    Node *next;
};

void add(Node *node, Node *&head)
{
    if (!head)
    {
        head = node;
        return;
    }

    head->next = node;
    head = head->next;
}

Node *sortX(Node *head, const int x)
{
    if (!head)
        return nullptr;

    Node sentinel{0, nullptr};
    Node *beforeX = &sentinel;
    Node *afterX = nullptr;
    Node *afterXStart = nullptr;

    for (Node *it = head; it; it = it->next)
    {
        if (it->value >= x)
        {
            if (!afterX)
                afterXStart = it;
            add(it, afterX);
        }
        else
            add(it, beforeX);
    }
    add(nullptr, afterX);

    beforeX->next = afterXStart;
    return sentinel.next;
}
