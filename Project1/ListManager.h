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
    void add(std::string dir_name, std::string file_name); 
    void check_list() const { std::cout << list; }         // test
};

#include "ListManager.hpp"