#pragma once

#include "ListManager.h"
#include "TreeManager.h"

class Manager
{
private:
    ListManager list_manager;
    TreeManager tree_manager;

public:
    void LOAD() { list_manager.load(); }
    void ADD();
    void MODIFY();
    void MOVE();
    void PRINT() const;
    void SEARCH();

    // test
    void checkList() const
    {
        list_manager.check_list();
        std::cout << "list size: " << list_manager.list.getSize() << std::endl;
    }
};

#include "Manager.hpp"