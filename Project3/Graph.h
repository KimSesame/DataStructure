#pragma once

#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

#define MAX 999999

class Graph
{
protected:
	bool m_Type; // 0:List 1:Matrix
	int m_Size;

public:
	Graph(bool type, int size) : m_Type(type), m_Size(size) {}
	~Graph();

	bool getType();
	int getSize();

	virtual map<int, int>* getAdjacentEdges(int vertex) = 0;
	virtual void insertEdge(int from, int to, int weight) = 0;
	virtual void printGraph(fstream& flog) = 0;
};

#include "Graph.hpp"
