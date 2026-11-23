template <class DataType>
struct Node
{
    DataType data;

    Node *next;
    Node *prev;
};

template <class DataType>
void moveToFront(Node<DataType> *&head, Node<DataType> *&tail, Node<DataType> *&node)
{
    if (!head || head == node)
        return;

    node->prev ? (node->prev->next = node->next) : (head = node->next);
    node->next ? (node->next->prev = node->prev) : (tail = node->prev);

    node->next = head;
    head->prev = node;
    node->prev = nullptr;
    head = node;
}