#pragma once

#include "LinkedList.h"

class ListManager
{
    friend class Manager;

private:
    LinkedList list;

public:
    ListManager() {}
    ~ListManager() {}

    void load();
    // void add();
    void check_list() const { std::cout << list; } // test
};

#include "ListManager.hpp"