#pragma once

#include "ListNode.h"
#include <iostream>

#define LIST_MAX 100
class LinkedList
{
    friend class ListManager;

private:
    ListNode *dir_node;
    int size;

public:
    LinkedList() : dir_node(nullptr), size(0) {}
    // ~LinkedList();

    inline int getSize() const { return size; }
    void insert(std::string dir_name, std::string file_name = "\0", int unique = -1);
    // void deletion();

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list)
    {
        ListNode *cur_dir = nullptr;
        ListNode *cur_img = nullptr;

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

#include "LinkedList.hpp"