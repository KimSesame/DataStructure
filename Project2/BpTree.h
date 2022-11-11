#pragma once

#include "BpTreeDataNode.h"
#include "BpTreeIndexNode.h"
#include <fstream>
#include <iostream>

class BpTree
{
private:
	BpTreeNode *root;
	int order; // m children
public:
	BpTree(int order = 3) : root(nullptr), order(order) {}
	~BpTree();

	/* essential */
	bool Insert(int key, set<string> set);
	bool excessDataNode(BpTreeNode *pDataNode);
	bool excessIndexNode(BpTreeNode *pIndexNode);
	void splitDataNode(BpTreeNode *pDataNode);
	void splitIndexNode(BpTreeNode *pIndexNode);
	BpTreeNode *getRoot() { return root; }
	BpTreeNode *searchDataNode(int n);

	void printFrequentPatterns(set<string> pFrequentPattern, string item);
	bool printFrequency(string item, int min_frequency);
	bool printConfidence(string item, double item_frequency, double min_confidence);
	bool printRange(string item, int min, int max);
};

#include "BpTree.hpp"