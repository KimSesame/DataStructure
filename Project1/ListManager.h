#pragma once

#include "Loaded_LIST.h"

class ListManager
{
    friend class Manager;

private:
    Loaded_LIST list;

public:
    ListManager() {}
    ~ListManager() {}

    void load();                                           
    void add(std::string dir_name, std::string file_name); 
    void modify(std::string dir_name, std::string img_name, int unique); 
    
    Loaded_LIST_Node* getTail() const;
    void check_list() const { std::cout << list; }         // test
};

#include "ListManager.hpp"