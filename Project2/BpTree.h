#pragma once

#include "BpTreeDataNode.h"
#include "BpTreeIndexNode.h"
#include <fstream>
#include <iostream>
#include <cmath>

class BpTree
{
private:
	BpTreeNode *root;
	int order; // m children
public:
	BpTree(int order = 3) : root(nullptr), order(order) {}
	~BpTree();

	/* essential */
	void Insert(int key, set<string> set);
	bool excessDataNode(BpTreeNode *pDataNode);
	bool excessIndexNode(BpTreeNode *pIndexNode);
	void splitDataNode(BpTreeNode *pDataNode);
	void splitIndexNode(BpTreeNode *pIndexNode);
	BpTreeNode *getRoot() { return root; }
	BpTreeNode *searchDataNode(int n);

	bool printFrequency(string item, int min_frequency);
	bool printConfidence(fstream& flog, string item, double item_frequency, double min_confidence);
	bool printRange(fstream& flog, string item, int min, int max);
	bool printFrequentPatterns(fstream& flog, set<string> pFrequentPattern, string item);
	bool printBPtree(fstream& flog, string item, int min_freq);
};

#include "BpTree.hpp"