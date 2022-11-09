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

    void createindexTable(string item) { table->insertTable(item); }
    void createdataTable();
    void createFPtree(FPNode* root, string item);
    void connectNode(HeaderTable* table, string item, FPNode* node);

    HeaderTable *getHeaderTable() const { return table; }
	FPNode* getTree() { return fptree; }

    bool printList(fstream& flog);
    bool printFPtree(fstream& log);
};

#include "FPGrowth.hpp"