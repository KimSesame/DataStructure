#include "TreeManager.h"

void TreeManager::search(std::string target)
{
    Database_BST_Node *cur_node = nullptr;

    set_queue();
    std::cout << "=======SEARCH=======" << std::endl;
    while (!queue.is_empty())
    {
        cur_node = queue.dequeue();
        cur_node->visited = false;
        if (string_search(cur_node->name, target))
            std::cout << *cur_node;
    }
    std::cout << "====================" << std::endl;
}

void TreeManager::select(Database_BST_Node *start, int unique)
{
    if (start)
    {
        if (start->unique_number == unique)
            img_route = "C:/Users/kimbs/repos/Assignments/DataStructure/Project1/" + start->dirname + "/" + start->name;
        select(start->left, unique);
        select(start->right, unique);
    }
}

void TreeManager::set_queue()
{
    Database_BST_Node *cur_node = bst.root;
    Database_BST_Node *last_node = nullptr;

    stack.push(cur_node);
    while (!stack.is_empty())
    {
        if ((cur_node->left == nullptr && cur_node->right == nullptr) ||
            (cur_node->left != nullptr && cur_node->left->visited && cur_node->right == nullptr) ||
            (cur_node->right == last_node && last_node != nullptr))
        {
            cur_node->visited = true;
            queue.enqueue(stack.pop());
            last_node = cur_node;
            cur_node = stack.top;
            continue;
        }

        if (cur_node->left && cur_node->left->visited == false)
            stack.push(cur_node->left);
        else if (cur_node->right)
            stack.push(cur_node->right);
        cur_node = stack.top;
    }
}

bool TreeManager::string_search(std::string str, std::string target)
{
    int str_size = str.size();
    int target_size = target.size();
    int cur_idx = 0;
    int match_cnt = 0;

    while (cur_idx < str.size() - target.size() + 1)
    {
        match_cnt = 0;
        for (int i = 0; i < target_size; i++)
            if (str.at(cur_idx + i) == target.at(i))
                match_cnt++;

        if (match_cnt == target_size)
            return true;

        cur_idx += (match_cnt > 1) ? match_cnt : 1;
    }
    return false;
}

void TreeManager::print_queue()
{
    while (queue.front)
        std::cout << *(queue.dequeue());
}