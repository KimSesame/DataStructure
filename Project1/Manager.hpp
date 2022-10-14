#include "Manager.h"
#include "Error.h"
#include "ImageEdit.h"
#include <iostream>

void Manager::ADD(std::string param)
{
    std::string dir_name;
    std::string file_name;

    dir_name = param.substr(0, param.find_first_of(' '));
    param.erase(0, dir_name.size() + 1);
    file_name = param;

    if (file_name.empty() || dir_name.empty())
        print_error(ErrorCode::ADD_ERR);
    else
        list_manager.add(dir_name, file_name);

    return;
}

void Manager::MODIFY(std::string param)
{
    std::string dir_name;
    std::string img_name;
    std::string num;

    dir_name = param.substr(0, param.find_first_of(' '));
    param.erase(0, dir_name.size() + 2);
    img_name = param.substr(0, param.find_first_of('\"'));
    param.erase(0, img_name.size() + 2);
    num = param;

    if (dir_name.empty() || img_name.empty() || num.empty())
        print_error(ErrorCode::MODIFY_ERR);
    else
        list_manager.modify(dir_name, img_name, stoi(num));

    return;
}

void Manager::MOVE()
{
    Loaded_LIST_Node *target = nullptr;
    std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);

    if (list_manager.list.getSize() == 0)
    {
        print_error(ErrorCode::MOVE_ERR);
        return;
    }

    out << "========MOVE========" << std::endl;
    while (list_manager.list.getSize() != 0)
    {
        target = list_manager.getTail();
        tree_manager.bst.insert(target->getDirName(), target->getName(), target->getUniqueNumber());
        list_manager.list.deletion(target->getUniqueNumber());
    }
    out << "SUCCESS" << std::endl;
    out << "====================" << std::endl;
    out.close();
    return;
}

void Manager::PRINT() const
{
    if (tree_manager.bst.root == nullptr)
    {
        print_error(ErrorCode::PRINT_ERR);
        return;
    }
    std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);

    out << "========PRINT=======" << std::endl;
    tree_manager.print();
    out << "====================" << std::endl;
    out.close();
}

void Manager::SEARCH(std::string param)
{
    std::string target;

    if (tree_manager.bst.size == 0)
    {
        print_error(ErrorCode::SEARCH_ERR);
        return;
    }

    param.erase(0, 1); // erase "\"" at front
    target = param.substr(0, param.find_first_of('\"'));

    if (target.empty())
        print_error(ErrorCode::SEARCH_ERR);
    else
        tree_manager.search(target);
}

void Manager::SELECT(std::string param)
{
    std::string num;

    num = param;

    if (num.empty())
        print_error(ErrorCode::SELECT_ERR);
    else
    {
        tree_manager.img_route = "";
        tree_manager.select(tree_manager.bst.root, stoi(num));

        if (tree_manager.img_route.empty()) // img_route unchanged
            print_error(ErrorCode::SELECT_ERR);
        else
        {
            std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);
            out << "=======SELECT=======" << std::endl;
            out << "SUCCESS" << std::endl;
            out << "====================" << std::endl;
            out.close();
        }
    }
}

void Manager::EDIT(std::string param)
{
    std::string option;
    std::string value;

    option = param.substr(0, 2);
    param.erase(0, 3);
    value = param;

    if (option.empty())
        print_error(ErrorCode::EDIT_ERR);
    else if (option == "-l" && value.empty())
        print_error(ErrorCode::EDIT_ERR);
    else
    {
        std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);
        switch (option.at(1))
        {
        case 'f':
            flip(tree_manager.img_route);
            out << "========EDIT========" << std::endl;
            out << "SUCCESS" << std::endl;
            out << "====================" << std::endl;
            break;
        case 'l':
            light(tree_manager.img_route, stoi(value));
            out << "========EDIT========" << std::endl;
            out << "SUCCESS" << std::endl;
            out << "====================" << std::endl;
            break;
        case 'r':
            resize(tree_manager.img_route);
            out << "========EDIT========" << std::endl;
            out << "SUCCESS" << std::endl;
            out << "====================" << std::endl;
            break;
        default:
            print_error(ErrorCode::EDIT_ERR);
            break;
        }
        out.close();
    }
}