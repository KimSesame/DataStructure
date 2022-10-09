#pragma once

#include "Database_BST.h"
#include "Stack.h"
#include "Queue.h"

class TreeManager
{
    friend class Manager;

private:
    Database_BST bst;
    Stack stack;
    Queue queue;
    std::string img_route;  // selected route

public:
    TreeManager() {}
    ~TreeManager() {}

    void print() const;
    void search(std::string target);
    void select(Database_BST_Node* start, int unique);
    
    void set_queue();
    bool string_search(std::string str, std::string target);
};

#include "TreeManager.hpp"