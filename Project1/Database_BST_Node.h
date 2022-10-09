#pragma once

#include "ImageNode.h"
#include <iostream>

class Database_BST_Node : public ImageNode
{
    friend class Database_BST;
    friend class Stack;
    friend class Queue;
    friend class TreeManager;

private:
    Database_BST_Node *parent;
    Database_BST_Node *left;
    Database_BST_Node *right;
    Database_BST_Node *link;
    bool visited;

public:
    Database_BST_Node(std::string dir, std::string name, int number)
        : ImageNode(dir, name, number), parent(nullptr), left(nullptr), right(nullptr), visited(false) {}
    ~Database_BST_Node() {}

    Database_BST_Node *getParent() { return parent; }
    Database_BST_Node *getLeft() { return left; }
    Database_BST_Node *getRight() { return right; }

    friend void operator<<(std::fstream &os, const Database_BST_Node &node)
    {
        std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);
        os << node.dirname << " / \"" << node.name << "\" / " << node.unique_number << std::endl;
        out.close();
    }
};
