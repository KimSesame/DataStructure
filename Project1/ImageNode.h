#pragma once

#include <string>
#include <iostream>
class ImageNode
{
    friend class Loaded_LIST_Node;
    friend class Loaded_LIST;
    friend class ListManager;
    friend class Database_BST_Node;
    friend class Database_BST;
    friend class TreeManager;

protected:
    std::string name;
    std::string dirname;

    int unique_number;

public:
    ImageNode() {}
    ImageNode(std::string dir, std::string name, int number)
        : dirname(dir), name(name), unique_number(number) {}

    friend std::ostream &operator<<(std::ostream &os, const ImageNode &node)
    {
        os << "(node.m_name: " << node.name << "), "; // Debug with print
        return os;
    }
};
