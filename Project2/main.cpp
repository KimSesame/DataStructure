#include "Manager.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    Manager manager(2, 3);
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
        else if (command == "PRINT_FPTREE")
            manager.PRINT_FPTREE();
        else if (command == "PRINT_BPTREE")
            manager.PRINT_BPTREE(line);
    } while (command != "EXIT");

    return 0;
}
