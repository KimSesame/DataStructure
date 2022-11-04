#pragma once

#include <fstream>
#include "Error.h"
#include "FPGrowth.h"
using namespace std;
class Manager
{
private:
    FPGrowth *fpgrowth;

public:
    fstream flog;

    Manager()
    {
        fpgrowth = new FPGrowth;
        flog.open("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/log.txt", ios::out | ios::app);
    }

    ~Manager()
    {
        flog.close();
    }

    void LOAD();
    void PRINT_ITEMLIST();
};

#include "Manager.hpp"