#pragma once

#include "Error.h"
#include "GraphMethod.h"
#include <cstdlib>
#include <fstream>
using namespace std;
class Manager
{
private:
    Graph* graph;

public:
    fstream flog;

    Manager() : graph(nullptr)
    {
        flog.open("C:/Users/kimbs/repos/Assignments/DataStructure/Project3/log.txt", ios::out | ios::app);
    }

    ~Manager()
    {
        flog.close();
    }

    void LOAD(string line);
    void PRINT();

    // // // // // // // // 
};

#include "Manager.hpp"