template <class DataType>
struct Node
{
    DataType data;
    Node *next;
};

template <class DataType>
void splitByParity(Node<DataType> *&head, Node<DataType> *&even, Node<DataType> *&odd)
{
    if (!head)
        return;

    even = nullptr;
    odd = nullptr;

    Node<DataType> *evenTail = nullptr;
    Node<DataType> *oddTail = nullptr;
    Node<DataType> *it = head;

    while (it)
    {
        Node<DataType> *next = it->next;
        it->next = nullptr;

        if (it->data % 2 == 0)
        {
            if (!even)
            {
                even = it;
                evenTail = it;
            }
            else
            {
                evenTail->next = it;
                evenTail = it;
            }
        }
        else
        {
            if (!odd)
            {
                odd = it;
                oddTail = it;
            }
            else
            {
                oddTail->next = it;
                oddTail = it;
            }
        }

        it = next;
    }

    head = nullptr;
}