#include <iostream>
#include <fstream>
#include "Manager.h"

int main(void)
{
    Manager manager;
    std::string line("");
    std::string command("");

    std::fstream command_file("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/command.txt", std::ios::in);

    do
    {
        std::getline(command_file, line, '\n');
        command = line.substr(0, line.find_first_of(' '));
        line.erase(0, command.size() + 1);

        if (command == "EXIT")
            break;
        else if (command == "LOAD")
            manager.LOAD();
        else if (command == "ADD")
            manager.ADD(line);
        else if (command == "MODIFY")
            manager.MODIFY(line);
        else if (command == "MOVE")
            manager.MOVE();
        else if (command == "PRINT")
            manager.PRINT();
        else if (command == "SEARCH")
            manager.SEARCH(line);
        else if (command == "SELECT")
            manager.SELECT(line);
        else if (command == "EDIT")
            manager.EDIT(line);
        else
            print_error(ErrorCode::UNDEFINED_ERR);
    } while (command != "EXIT");

    return 0;
}