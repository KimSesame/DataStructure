#pragma once

#include "ListManager.h"

class Manager
{
private:
    ListManager list_manager;

public:
    void LOAD() { list_manager.load(); }

    // std::string& getCommand();
    // void runCommand(std::string command);
    void checkList() const { list_manager.check_list(); }
};

#include "Manager.hpp"