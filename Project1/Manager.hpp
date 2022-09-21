#include "Manager.h"
#include <iostream>

void Manager::ADD()
{
    std::string dir_name;
    std::string file_name;

    std::cin >> dir_name >> file_name;
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