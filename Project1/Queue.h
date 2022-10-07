#pragma once

#include "Database_BST_Node.h"

class Queue
{
    friend class TreeManager;

private:
    Database_BST_Node *front;
    Database_BST_Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool is_empty() const { return front == nullptr; }
    void enqueue(Database_BST_Node *p_node);
    Database_BST_Node *dequeue();
};

#include "Queue.hpp"