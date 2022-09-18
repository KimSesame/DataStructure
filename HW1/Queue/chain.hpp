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
ChainNode<T> *Chain<T>::Search(const T &data) const
{
    ChainNode<T> *cur_node = head;

    while (cur_node->data != data)
        cur_node = cur_node->next;

    return cur_node;
}

template <typename T>
void Chain<T>::Append(const T &data)
{
    ChainNode<T> *new_node = new ChainNode(data);

    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
        return;
    }

    tail->next = new_node;
    tail = new_node;
}

template <typename T>
void Chain<T>::Delete(const T &data)
{
    ChainNode<T> *del_node = Search(data);
    ChainNode<T> *cur_node = head;

    if (del_node == nullptr)
        return;

    if (del_node == head)
    {
        head = head->next;
        delete del_node;
        return;
    }

    while (cur_node->next == del_node)
        cur_node = cur_node->next;

    cur_node->next = cur_node->next->next;
    delete del_node;
}