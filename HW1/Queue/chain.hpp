#include "Chain.h"

template <typename T>
ChainNode<T>::ChainNode(const T data, ChainNode<T> *next)
{
    this->data = data;
    this->next = next;
}

template <typename T>
Chain<T>::Chain()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
Chain<T>::~Chain()
{
    ChainNode<T> *next = nullptr;

    while (head)
    {
        next = head->next;
        cout << "Delete: " << head->data << endl;
        delete head;
        head = next;
    }
}

template <typename T>
bool Chain<T>::IsEmpty(void) const
{
    return head == nullptr;
}

template <typename T>
void Chain<T>::Print(void) const
{
    ChainNode<T> *cur_node = head;

    cout << "Print: ";
    while (cur_node)
    {
        cout << cur_node->data << " ";
        cur_node = cur_node->next;
    }
    cout << endl;
}

template <typename T>
void Chain<T>::StackPush(const T &data)
{
    head = new ChainNode<T>(data, head);
    cout << "StackPush: " << data << endl;
}

template <typename T>
void Chain<T>::StackPop(void)
{
    ChainNode<T> *top = head;

    if (IsEmpty())
        cout << "StackPop: EMPTY!" << endl;
    else
    {
        cout << "StackPop: " << top->data << endl;
        head = top->next;
        delete top;
    }
}

template <class T>
void Chain<T>::QueuePush(const T &data)
{
    if (IsEmpty())
        head = tail = new ChainNode<T>(data);
    else
        tail = tail->next = new ChainNode<T>(data);
    cout << "QueuePush: " << data << endl;
}

template <class T>
void Chain<T>::QueuePop()
{
    ChainNode<T> *front = head;

    if (IsEmpty())
        cout << "QueuePop: EMPTY!" << endl;
    else
    {
        cout << "QueuePop: " << front->data << endl;
        head = front->next;
        delete front;
    }
}