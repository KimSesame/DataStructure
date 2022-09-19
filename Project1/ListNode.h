#pragma once

#include "ImageNode.h"
#include <iostream>

class ListNode : public ImageNode
{
    friend class LinkedList;
    friend class ListManager;

private:
    ListNode *next_dir;
    ListNode *next_img;

public:
    ListNode(std::string dir, std::string name = NULL, int number = NULL)
        : ImageNode(dir, name, number), next_dir(nullptr), next_img(nullptr) {}
    ~ListNode() {}

    ListNode *getNextDir() const { return next_dir; }
    ListNode *getNextImg() const { return next_img; }

    friend std::ostream &operator<<(std::ostream &os, const ListNode &node)
    {
        if (node.name.compare(NULL))                      // dir_node
            os << "[" << node.dirname << "] ";            // Debug with print
        else                                              // img_node
            os << "(node.m_name: " << node.name << "), "; // Debug with print

        return os;
    }
};