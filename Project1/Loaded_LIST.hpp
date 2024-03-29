#include "Loaded_LIST.h"

void Loaded_LIST::insert(std::string dir_name, std::string file_name, int unique)
{
    Loaded_LIST_Node *new_node = new Loaded_LIST_Node(dir_name, file_name, unique);
    Loaded_LIST_Node *cur_dir = nullptr;
    Loaded_LIST_Node *cur_img = nullptr;

    // EMPTY case
    if (this->dir_node == nullptr)
    {
        this->dir_node = new_node;
        size++;
        return;
    }

    // Inspect the list size
    cur_dir = dir_node;
    if (size >= LIST_MAX)
    {
        while (cur_dir)
        {
            cur_img = cur_dir->next_img;
            if (cur_img)
            {
                deletion(cur_img->unique_number); // delete front data
                break;
            }
            cur_dir = cur_dir->next_dir;
        }
    }

    // Find insert location
    cur_dir = dir_node;
    while (cur_dir->next_dir)
        cur_dir = cur_dir->next_dir;
    cur_img = cur_dir;
    while (cur_img->next_img)
        cur_img = cur_img->next_img;

    // Insert
    cur_img->next_img = new_node;
    size++;

    return;
}

void Loaded_LIST::deletion(int unique)
{
    Loaded_LIST_Node *prev_dir = nullptr;
    Loaded_LIST_Node *cur_dir = dir_node;
    Loaded_LIST_Node *cur_img = nullptr;
    Loaded_LIST_Node *del_prev_node = nullptr;
    Loaded_LIST_Node *del_node = nullptr;
    int loop_break = 0;

    // Find del_prev_node & del_node
    while (cur_dir)
    {
        cur_img = cur_dir;
        while (cur_img->next_img)
        {
            if (cur_img->next_img->unique_number == unique)
            {
                del_prev_node = cur_img;
                del_node = cur_img->next_img;
                loop_break = 1;
                break;
            }
            cur_img = cur_img->next_img;
        }
        if (loop_break)
            break;
        prev_dir = cur_dir;
        cur_dir = cur_dir->next_dir;
    }

    // Delete
    del_prev_node->next_img = del_node->next_img;
    delete del_node;
    //  delete dir_node if empty after deletion
    if (del_prev_node->unique_number == -1 && del_prev_node->next_img == nullptr)
    {
        if (prev_dir)
            prev_dir->next_dir = (prev_dir->next_dir) ? prev_dir->next_dir->next_dir : nullptr;
        else
            dir_node = dir_node->next_dir;
        delete del_prev_node;
    }
    size--;

    return;
}

Loaded_LIST_Node *Loaded_LIST::search(int unique)
{
    Loaded_LIST_Node *cur_dir = dir_node;
    Loaded_LIST_Node *cur_img = nullptr;

    while (cur_dir)
    {
        cur_img = cur_dir->next_img;
        while (cur_img)
        {
            if (cur_img->unique_number == unique)
                return cur_img;
            cur_img = cur_img->next_img;
        }
        cur_dir = cur_dir->next_dir;
    }
    // NOT exist
    return nullptr;
}