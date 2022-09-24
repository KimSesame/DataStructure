#pragma once

#include "Database_BST_Node.h"
#include <iostream>

#define BST_MAX 300
class Database_BST
{
    friend class TreeManager;
    friend class Manager;

private:
    Database_BST_Node *root;
    int size;

public:
    Database_BST() : root(nullptr), size(0) {}
    // ~Database_BST();

    int getSize() const { return size; }
    void insert(std::string dir_name, std::string file_name, int unique); // TODO: consider MAX size
    void print(Database_BST_Node *start) const;

    friend std::ostream &operator<<(std::ostream &os, const Database_BST &tree)
    {
        tree.print(tree.root);

        return os;
    }
};

#include "Database_BST.hpp"