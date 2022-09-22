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

    void load();                                           // TODO: Loaded_List MAX size 100
    void add(std::string dir_name, std::string file_name); // TODO: Loaded_List MAX size 100
    void check_list() const { std::cout << list; }         // test
};

#include "ListManager.hpp"