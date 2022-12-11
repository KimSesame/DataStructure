#pragma once

#include "Graph.h"

class MatrixGraph : public Graph{
private:
	int** m_Mat;

public:
	MatrixGraph(bool type, int size);
	~MatrixGraph();	
		
	map<int, int>* getAdjacentEdges(int vertex, int direct = 0);
	vector<pair<pair<int,int>,int>>* getEdges(void);
	void insertEdge(int from, int to, int weight);
	void printGraph(fstream& flog);
};

#include "MatrixGraph.hpp"