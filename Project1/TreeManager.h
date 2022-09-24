#pragma once

#include "Database_BST.h"

class TreeManager
{
    friend class Manager;

private:
    Database_BST bst;

public:
    TreeManager() {}
    ~TreeManager() {}

    void print() const { std::cout << bst; }   // test
};

#include "TreeManager.hpp"