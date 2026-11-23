template <class DataType>
struct Node
{
    DataType data;

    Node *prev;
    Node *next;
};

template <class DataType>
void moveAfter(Node<DataType> *&head, Node<DataType> *&tail, Node<DataType> *node, Node<DataType> *position)
{
    if (!head || head == tail)
        return;

    if (node == position || position->next == node)
        return;

    node->prev ? (node->prev->next = node->next) : head = node->next;
    node->next ? (node->next->prev = node->prev) : tail = node->prev;

    // position->next ? (position->next->prev = node) : tail = node;
    // position->next ? (node->next = position->next) : tail = node;
    node->next = position->next;
    node->prev = position;

    position->next ? (position->next->prev = node) : (tail = node);

    position->next = node;
    node->prev = position;
}