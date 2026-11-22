template <class DataType>
struct Node
{
    DataType data;
    Node *next;
};

template <class DataType>
void reverseList(Node<DataType> *&head)
{
    if (!head)
        return;

    Node<DataType> *itReverse = nullptr;
    Node<DataType> *it = head;

    while (it)
    {
        Node<DataType> *next = it->next;

        it->next = itReverse;
        itReverse = it;
        it = next;
    }

    head = itReverse;
}
