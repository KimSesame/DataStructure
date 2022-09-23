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