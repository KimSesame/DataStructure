#include "TreeManager.h"

void TreeManager::search(std::string target)
{
    set_queue();
    std::cout << "=======SEARCH=======" << std::endl;
    print_queue(); // test
    std::cout << "====================" << std::endl;
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

void TreeManager::print_queue()
{
    while (queue.front)
        std::cout << *(queue.dequeue());
}