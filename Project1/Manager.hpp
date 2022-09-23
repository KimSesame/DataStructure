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

    if(file_name.empty() || dir_name.empty())
        print_error(ErrorCode::ADD_ERR);
    else
        list_manager.add(dir_name, file_name);

    return;
}

// std::string& Manager::getCommand()
// {
//     static std::string command;

//     std::cin >> command;
//     return command;
// }

// void Manager::runCommand(std::string command)
// {
//     if(!command.compare("LOAD"))    LOAD();
//     else if(!command.compare("CHECK LIST")) checkList();

// }