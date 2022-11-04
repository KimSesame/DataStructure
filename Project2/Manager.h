#pragma once

#include <fstream>
#include "Error.h"
#include "FPGrowth.h"
using namespace std;
class Manager
{
private:
    FPGrowth* fpgrowth;

public:
    Manager(){fpgrowth = new FPGrowth;}

    void LOAD();
    void PRINT_ITEMLIST() const;
};

#include "Manager.hpp"