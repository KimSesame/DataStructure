#pragma once

#include "Database_BST_Node.h"

class Stack
{
    friend class TreeManager;

private:
    Database_BST_Node *top;

public:
    Stack() : top(nullptr) {}

    bool is_empty() const { return top == nullptr; }
    void push(Database_BST_Node* p_node);
    Database_BST_Node *pop();
};

#include "Stack.hpp"