#pragma once

#include "Error.h"
#include "FPGrowth.h"
#include "BpTree.h"
#include <cstdlib>
#include <fstream>
#include <queue>
using namespace std;
class Manager
{
private:
    FPGrowth *fpgrowth;
    BpTree* bptree;

public:
    fstream flog;

    Manager(int threshold, int BpOrder)
    {
        fpgrowth = new FPGrowth(threshold);
        bptree = new BpTree(BpOrder);
        flog.open("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/log.txt", ios::out | ios::app);
    }

    ~Manager()
    {
        flog.close();
    }

    void LOAD();
    void BTLOAD();
    void PRINT_ITEMLIST();
    void PRINT_FPTREE();
    void PRINT_BPTREE(string param);
    void PRINT_CONFIDENCE(string param);
    void PRINT_RANGE(string param);
};

#include "Manager.hpp"