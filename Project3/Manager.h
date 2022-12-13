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
    void PRINT(string param);
    void mBFS(string vertex);
    void mDFS(string vertex);
    void mDFS_R(string vertex);
    void mKRUSKAL(string param);
    void mDIJKSTRA(string vertex);
    void mBELLMANFORD(string params);
    void mFLOYD(string line);

    // // // // // // // // 
};

#include "Manager.hpp"