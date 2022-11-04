#include <iostream>
#include <fstream>
#include "Manager.h"

using namespace std;

int main(void)
{
    Manager manager;
    string line("");
    string command("");

    fstream command_file("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/command.txt", ios::in);

    do
    {
        getline(command_file, line, '\n');
        command = line.substr(0, line.find_first_of(' '));
        line.erase(0, command.size() + 1);

        if (command == "EXIT")
            break;
        else if (command == "LOAD")
            manager.LOAD();
        else if (command == "PRINT_ITEMLIST")
            manager.PRINT_ITEMLIST();
    } while (command != "EXIT");

    return 0;
}
