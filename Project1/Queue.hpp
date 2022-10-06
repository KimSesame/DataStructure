#include "Queue.h"

void Queue::enqueue(Database_BST_Node* p_node)
{
    if (front == nullptr)
    {
        front = p_node;
        rear = p_node;
    }
    else
    {
        rear->link = p_node;
        rear = p_node;
    }
    return;
}

Database_BST_Node *Queue::dequeue()
{
    Database_BST_Node *del_node = front;
    if (front == rear)
    {
        front = nullptr;
        rear = nullptr;
    }
    else
        front = del_node->link;
    
    return del_node;
}