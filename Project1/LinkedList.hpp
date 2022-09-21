#include "LinkedList.h"

void LinkedList::insert(std::string dir_name, std::string file_name, int unique)
{
    ListNode *new_node = new ListNode(dir_name, file_name, unique);
    ListNode *cur_node = nullptr;

    // EMPTY case
    if (this->dir_node == nullptr)
    {
        this->dir_node = new_node;
        size++;
        return;
    }

    // Find tail & insert
    cur_node = dir_node;
    while (cur_node->next_img)
        cur_node = cur_node->next_img;
    cur_node->next_img = new_node;
    size++;

    return;
}