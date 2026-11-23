template <class DataType>
struct Node
{
    DataType data;
    Node *prev;
    Node *next;
};

template <class DataType>
void insert(Node<DataType> *&curr, Node<DataType> *&element)
{
    Node<DataType> *ogNext = curr->next;
    curr->next = element;
    element->prev = curr;

    element->next = ogNext;
    ogNext->prev = element;
}
