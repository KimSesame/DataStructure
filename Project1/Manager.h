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
    void ADD(std::string param);
    void MODIFY(std::string param);
    void MOVE();
    void PRINT() const;
    void SEARCH(std::string param);
    void SELECT(std::string param);
    void EDIT(std::string param);
};

#include "Manager.hpp"