#include "Database_BST.h"

Database_BST_Node *Database_BST::getMin(Database_BST_Node *start) const
{
    Database_BST_Node *cur_node = start;
    while (cur_node->left)
        cur_node = cur_node->left;

    return cur_node;
}

Database_BST_Node *Database_BST::getMax(Database_BST_Node *start) const
{
    Database_BST_Node *cur_node = start;
    while (cur_node->right)
        cur_node = cur_node->right;

    return cur_node;
}

Database_BST_Node *Database_BST::search(int unique) const
{
    // EMPTY case
    if (root == nullptr)
        return nullptr;

    Database_BST_Node *cur_node = root;
    while (cur_node)
    {
        if (unique == cur_node->unique_number)
            return cur_node;
        else if (unique > cur_node->unique_number)
            cur_node = cur_node->right;
        else if (unique < cur_node->unique_number)
            cur_node = cur_node->left;
    }

    // Search FAIL
    return nullptr;
}

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

    // Inspect the BST size
    if (size >= BST_MAX)
        deletion(getMin(root)->unique_number);

    // Insert
    cur_node = root;
    while (cur_node)
    {
        if (new_node->unique_number < cur_node->unique_number)
        {
            if (cur_node->left == nullptr)
            {
                cur_node->left = new_node;
                new_node->parent = cur_node;
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
                new_node->parent = cur_node;
                break;
            }
            else
                cur_node = cur_node->right;
        }
    }
    size++;
}

void Database_BST::deletion(int unique)
{
    Database_BST_Node *del_node = search(unique);
    Database_BST_Node *parent_node = nullptr;
    Database_BST_Node *replace_node = nullptr;
    Database_BST_Node *temp = nullptr;

    // del_node is NOT EXIST
    if (del_node == nullptr)
        return;

    parent_node = del_node->parent;

    // Case 1: leaf node
    if (del_node->left == nullptr && del_node->right == nullptr)
    {
        // del_node is root
        if (del_node == root)
            root = nullptr;
        // not root
        else
        {
            // del_node is left child
            if (del_node == parent_node->left)
                parent_node->left = nullptr;
            // del_node is right child
            else
                parent_node->right = nullptr;
        }
    }
    // Case 2: has ONE child
    // del_node has left child
    else if (del_node->right == nullptr)
    {
        // del_node is root
        if (del_node == root)
        {
            root = del_node->left;
            root->parent = nullptr;
        }
        // not root
        else
        {
            // del_node is left child
            if (del_node == parent_node->left)
            {
                parent_node->left = del_node->left;
                del_node->left->parent = parent_node;
            }
            // del_node is right child
            else
            {
                parent_node->right = del_node->left;
                del_node->left->parent = parent_node;
            }
        }
    }
    // del_node has right child
    else if (del_node->left == nullptr)
    {
        // del_node is root
        if (del_node == root)
        {
            root = del_node->right;
            root->parent = nullptr;
        }
        // not root
        else
        {
            // del_node is left child
            if (del_node == parent_node->left)
            {
                parent_node->left = del_node->right;
                del_node->right->parent = parent_node;
            }
            // del_node is right child
            else
            {
                parent_node->right = del_node->right;
                del_node->right->parent = parent_node;
            }
        }
    }
    // Case 3: has TWO children
    else
    {
        replace_node = getMax(del_node->left);
        // Swap data
        temp = new Database_BST_Node(*del_node);
        del_node->dirname = replace_node->dirname;
        del_node->name = replace_node->name;
        del_node->unique_number = replace_node->unique_number;

        replace_node->dirname = temp->dirname;
        replace_node->name = temp->name;
        replace_node->unique_number = temp->unique_number;
        delete temp;

        deletion(replace_node->unique_number);
    }

    delete del_node;
    size--;
}

void Database_BST::print(Database_BST_Node *start) const
{
    if (start)
    {
        std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);
        print(start->left);
        out << *start;
        print(start->right);
        out.close();
    }
    return;
}