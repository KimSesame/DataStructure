#pragma once

#include "ListNode.h"
#include <iostream>

class LinkedList
{
    friend class ListManager;

private:
    ListNode *dir_node;

public:
    LinkedList(std::string dir = "img_files") { dir_node = new ListNode(dir); }
    //~LinkedList();

    //void insert();
    //void deletion();

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &list)
    {
        ListNode *cur_dir = nullptr;
        ListNode *cur_img = nullptr;

        cur_dir = list.dir_node;
        while (cur_dir)
        {
            os << cur_dir;

            cur_img = cur_dir->getNextImg();
            while (cur_img)
            {
                os << cur_img;
                cur_img = cur_img->getNextImg();
            }

            cur_dir = cur_dir->getNextDir();
        }
        return os;
    }
};