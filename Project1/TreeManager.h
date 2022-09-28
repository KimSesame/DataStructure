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

    void print() const { std::cout << bst; }
    void search(std::string target) const;
};

#include "TreeManager.hpp"