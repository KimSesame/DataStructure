#pragma once

#include "ListManager.h"

class Manager
{
private:
    ListManager list_manager;

public:
    void LOAD() { list_manager.load(); }
    void ADD();

    // std::string& getCommand();
    // void runCommand(std::string command);
    // test
    void checkList() const
    {
        list_manager.check_list();
        std::cout << "list size: " << list_manager.list.getSize() << std::endl;
    }
};

#include "Manager.hpp"