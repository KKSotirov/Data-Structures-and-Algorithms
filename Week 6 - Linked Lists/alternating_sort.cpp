struct Node
{
    int value;
    Node *next;
};

void add(Node *el, Node *&currIt, Node *&currHalfStart, int &currHalfLen)
{
    if (!currIt)
        currIt = currHalfStart = el;

    else
    {
        currIt->next = el;
        currIt = el;
    }

    currHalfLen++;
}

void alternatingSort(Node *&head)
{
    if (!head)
        return;

    Node *halfOneIt = nullptr;
    Node *halfOneStart = nullptr;
    int halfOneLen = 0;

    Node *halfTwoIt = nullptr;
    Node *halfTwoStart = nullptr;
    int halfTwoLen = 0;

    while (head)
    {
        if (halfOneLen <= halfTwoLen)
            add(head, halfOneIt, halfOneStart, halfOneLen);
        else
            add(head, halfTwoIt, halfTwoStart, halfTwoLen);

        head = head->next;
    }
    halfTwoIt ? halfTwoIt->next = nullptr : halfTwoIt = nullptr;
    halfOneIt ? halfOneIt->next = halfTwoIt : halfOneIt = nullptr;

    head = halfOneStart;
}