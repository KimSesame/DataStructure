#pragma once

#include <list>
#include <algorithm>
#include "FPNode.h"

class HeaderTable
{
private:
	list<pair<int, string>> indexTable;
	map<string, FPNode *> dataTable;

public:
	HeaderTable() {}
	~HeaderTable();
	void insertTable(string item);
	list<pair<int, string>>& getindexTable() { return indexTable; }
	map<string, FPNode *>& getdataTable() { return dataTable; }
	FPNode *getNode(string item) { return dataTable.find(item)->second; }
	void descendingIndexTable() { indexTable.sort(greater<pair<int, string>>()); }
	void ascendingIndexTable() { indexTable.sort(); }
	int find_frequency(string item);
};

#include "HeaderTable.hpp"