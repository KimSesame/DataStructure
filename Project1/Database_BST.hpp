#include "Database_BST.h"

void Database_BST::insert(std::string dir_name, std::string file_name, int unique)
{
    Database_BST_Node *new_node = new Database_BST_Node(dir_name, file_name, unique);
    Database_BST_Node *cur_node = nullptr;

    // EMPTY case
    if (this->root == nullptr)
    {
        this->root = new_node;
        size++;
        return;
    }

    // Insert
    cur_node = root;
    while (cur_node)
    {
        if (new_node->unique_number < cur_node->unique_number)
        {
            if (cur_node->left == nullptr)
            {
                cur_node->left = new_node;
                break;
            }
            else
                cur_node = cur_node->left;
        }
        else if (new_node->unique_number > cur_node->unique_number)
        {
            if (cur_node->right == nullptr)
            {
                cur_node->right = new_node;
                break;
            }
            else
                cur_node = cur_node->right;
        }
    }
    size++;
}

void Database_BST::print(Database_BST_Node *start) const
{
    if (start)
    {
        print(start->left);
        std::cout << *start;
        print(start->right);
    }
    return;
}