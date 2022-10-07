#include "Manager.h"
#include "Error.h"
#include <iostream>

void Manager::ADD()
{
    std::string param;
    std::string dir_name;
    std::string file_name;

    std::cin.clear();
    getline(std::cin, param, '\n');
    param.erase(0, 1); // erase ' ' at front
    dir_name = param.substr(0, param.find_first_of(' '));
    param.erase(0, dir_name.size() + 1);
    file_name = param;

    if (file_name.empty() || dir_name.empty())
        print_error(ErrorCode::ADD_ERR);
    else
        list_manager.add(dir_name, file_name);

    return;
}

void Manager::MODIFY()
{
    std::string param;
    std::string dir_name;
    std::string img_name;
    std::string num;

    std::cin.clear();
    getline(std::cin, param, '\n');
    param.erase(0, 1); // erase ' ' at front
    dir_name = param.substr(0, param.find_first_of(' '));
    param.erase(0, dir_name.size() + 2);
    img_name = param.substr(0, param.find_first_of('\"'));
    param.erase(0, img_name.size() + 2);
    num = param;

    if (dir_name.empty() || img_name.empty() || num.empty())
        print_error(ErrorCode::MODIFY_ERR);
    else
        list_manager.modify(dir_name, img_name, atoi(num.c_str()));

    return;
}

void Manager::MOVE()
{
    Loaded_LIST_Node *target = nullptr;

    if (list_manager.list.getSize() == 0)
    {
        print_error(ErrorCode::MOVE_ERR);
        return;
    }

    std::cout << "========MOVE========" << std::endl;
    while (list_manager.list.getSize() != 0)
    {
        target = list_manager.getTail();
        tree_manager.bst.insert(target->getDirName(), target->getName(), target->getUniqueNumber());
        list_manager.list.deletion(target->getUniqueNumber());
    }
    std::cout << "SUCCESS" << std::endl;
    std::cout << "====================" << std::endl;
    return;
}

void Manager::PRINT() const
{
    if (tree_manager.bst.root == nullptr)
    {
        print_error(ErrorCode::PRINT_ERR);
        return;
    }

    std::cout << "========PRINT=======" << std::endl;
    tree_manager.print();
    std::cout << "====================" << std::endl;
    std::cout << "tree size: " << tree_manager.bst.getSize() << std::endl; // test
}

void Manager::SEARCH()
{
    std::string param;
    std::string target;

    if (tree_manager.bst.size == 0)
    {
        print_error(ErrorCode::SEARCH_ERR);
        return;
    }

    std::cin.clear();
    getline(std::cin, param, '\n');
    param.erase(0, 2); // erase " \"" at front
    target = param.substr(0, param.find_first_of('\"'));

    if (target.empty())
        print_error(ErrorCode::SEARCH_ERR);
    else
        tree_manager.search(target);
}

void Manager::SELECT()
{
    std::string param;
    std::string num;

    std::cin.clear();
    getline(std::cin, param, '\n');
    param.erase(0, 1);
    num = param;

    if (num.empty())
        print_error(ErrorCode::SELECT_ERR);
    else
    {
        tree_manager.img_route = "";
        tree_manager.select(tree_manager.bst.root, atoi(num.c_str()));

        if (tree_manager.img_route.empty()) // img_route unchanged
            print_error(ErrorCode::SELECT_ERR);
        else
        {
            std::cout << "=======SELECT=======" << std::endl;
            std::cout << "SUCCESS" << std::endl;
            std::cout << "====================" << std::endl;
            std::cout << tree_manager.img_route << std::endl; // test
        }
    }
}