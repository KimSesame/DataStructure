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

        if (command == "EXIT")
            break;
        else if (command == "LOAD")
            manager.LOAD();
        else if (command == "ADD")
            manager.ADD();
        else if (command == "MODIFY")
            manager.MODIFY();
        else if (command == "MOVE")
            manager.MOVE();
        else if (command == "PRINT")
            manager.PRINT();
        else if (command == "SEARCH")
            manager.SEARCH();
        else if (command == "SELECT")
            manager.SELECT();
        else if (command == "   CHECKLIST") // test
            manager.checkList();
        else
            print_error(ErrorCode::UNDEFINED_ERR);
    } while (command != "EXIT");

    return 0;
}