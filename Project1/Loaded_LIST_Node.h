#pragma once

#include "ImageNode.h"
#include <iostream>

class Loaded_LIST_Node : public ImageNode
{
    friend class Loaded_LIST;
    friend class ListManager;

private:
    Loaded_LIST_Node *next_dir;
    Loaded_LIST_Node *next_img;

public:
    Loaded_LIST_Node(std::string dir, std::string name = "\0", int number = -1)
        : ImageNode(dir, name, number), next_dir(nullptr), next_img(nullptr) {}
    ~Loaded_LIST_Node() {}

    Loaded_LIST_Node *getNextDir() { return next_dir; }
    Loaded_LIST_Node *getNextImg() { return next_img; }

    friend std::ostream &operator<<(std::ostream &os, const Loaded_LIST_Node &node)
    {
        if (node.unique_number == -1)                                      // dir_node
            os << "[" << node.dirname << "] " << std::endl;                // Debug with print
        else                                                               // img_node
            os << "(" << node.unique_number << ": " << node.name << "), "; // Debug with print

        return os;
    }
};