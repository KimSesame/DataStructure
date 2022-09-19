#pragma once

#include "LinkedList.h"

class ListManager
{
private:
    LinkedList list;

public:
    ListManager() {}
    ~ListManager() {}

    void load();
    //void add();
};

