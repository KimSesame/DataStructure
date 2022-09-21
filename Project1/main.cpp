#include <iostream>
#include "Manager.h"
using namespace std;

int main(void)
{
    Manager manager;
    string command("");

    do
    {
        cin >> command;

        if (command == "LOAD")
            manager.LOAD();
        else if (command == "ADD")
            manager.ADD();
        else if (command == "CHECKLIST")
            manager.checkList();
    } while (command != "EXIT");

    return 0;
}