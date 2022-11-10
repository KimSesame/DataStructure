#pragma once

#include <fstream>
#include <queue>
#include "Error.h"
#include "FPGrowth.h"
using namespace std;
class Manager
{
private:
    FPGrowth *fpgrowth;

public:
    fstream flog;

    Manager(int threshold)
    {
        fpgrowth = new FPGrowth(threshold);
        flog.open("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/log.txt", ios::out | ios::app);
    }

    ~Manager()
    {
        flog.close();
    }

    void LOAD();
    void PRINT_ITEMLIST();
    void PRINT_FPTREE();
};

#include "Manager.hpp"