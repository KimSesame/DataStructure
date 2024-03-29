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
            manager.PRINT(line);
        else if (command == "BFS")
            manager.mBFS(line);
        else if (command == "DFS")
            manager.mDFS(line);
        else if (command == "DFS_R")
            manager.mDFS_R(line);
        else if (command == "KRUSKAL")
            manager.mKRUSKAL(line);
        else if (command == "DIJKSTRA")
            manager.mDIJKSTRA(line);
        else if (command == "BELLMANFORD")
            manager.mBELLMANFORD(line);
        else if (command == "FLOYD")
            manager.mFLOYD(line);
        // // // // // // // // // //
    } while (command != "EXIT");

    return 0;
}
