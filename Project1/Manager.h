#pragma once

#include "ListManager.h"

class Manager
{
private:
    ListManager list_manager;

public:
    void LOAD() { list_manager.load(); }

    void CHECK_list() const { list_manager.check_list(); }
};