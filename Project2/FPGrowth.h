#pragma once

#include "HeaderTable.h"
#include <map>
class FPGrowth
{
private:
    int threshold;
    FPNode *fptree;
    HeaderTable *table;

public:
    FPGrowth();

    void createTable(string item) { table->insertTable(item); }

    HeaderTable *getHeaderTable() const { return table; }

    bool printList(fstream& flog);
};

#include "FPGrowth.hpp"