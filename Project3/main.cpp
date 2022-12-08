#include "Manager.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    Manager manager;
    string line("");
    string command("");

    fstream command_file("C:/Users/kimbs/repos/Assignments/DataStructure/Project3/command.txt", ios::in);

    do
    {
        getline(command_file, line, '\n');
        command = line.substr(0, line.find_first_of(' '));
        line.erase(0, command.size() + 1);

        if (command == "EXIT")
            break;
        else if (command == "LOAD")
            manager.LOAD(line);
        else if (command == "PRINT")
            manager.PRINT();
        else if (command == "BFS")
            manager.mBFS(line);
        else if (command == "DFS")
            manager.mDFS(line);
        else if (command == "DFS_R")
            manager.mDFS_R(line);
        else if (command == "KRUSKAL")
            manager.mKRUSKAL();
        // // // // // // // // // //
    } while (command != "EXIT");

    return 0;
}
