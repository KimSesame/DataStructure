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

public:
    TreeManager() {}
    ~TreeManager() {}

    void print() const { std::cout << bst; }
    void search(std::string target);
    
    void set_queue();
    bool string_search(std::string str, std::string target);

    // test
    void print_queue();
};

#include "TreeManager.hpp"