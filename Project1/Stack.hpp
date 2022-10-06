#include "Stack.h"

void Stack::push(Database_BST_Node* p_node)
{
    p_node->link = top;
    top = p_node;
}

Database_BST_Node* Stack::pop()
{
    if(top == nullptr)
        return nullptr;

    Database_BST_Node* del_node = top;
    top = del_node->link;
    
    return del_node;
}