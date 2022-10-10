#pragma once

#include "Loaded_LIST_Node.h"
#include <iostream>

#define LIST_MAX 100
class Loaded_LIST
{
    friend class ListManager;

private:
    Loaded_LIST_Node *dir_node;
    int size;

public:
    Loaded_LIST() : dir_node(nullptr), size(0) {}
    ~Loaded_LIST() { while(dir_node) deletion(dir_node->next_img->unique_number); }

    inline int getSize() const { return size; }
    void insert(std::string dir_name, std::string file_name = "\0", int unique = -1);
    void deletion(int unique);
    Loaded_LIST_Node* search(int unique);

    friend std::ostream &operator<<(std::ostream &os, const Loaded_LIST &list)
    {
        Loaded_LIST_Node *cur_dir = nullptr;
        Loaded_LIST_Node *cur_img = nullptr;

        cur_dir = list.dir_node;
        while (cur_dir)
        {
            os << *cur_dir;
            cur_img = cur_dir->getNextImg();
            while (cur_img)
            {
                os << *cur_img;
                cur_img = cur_img->getNextImg();
            }
            os << std::endl;
            cur_dir = cur_dir->getNextDir();
        }
        return os;
    }
};

#include "Loaded_LIST.hpp"