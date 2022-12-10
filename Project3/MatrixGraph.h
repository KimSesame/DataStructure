#pragma once

#include "Graph.h"

class MatrixGraph : public Graph{
private:
	int** m_Mat;

public:
	MatrixGraph(bool type, int size);
	~MatrixGraph();	
		
	map<int, int>* getAdjacentEdges(int vertex, int direct);
	void insertEdge(int from, int to, int weight);
	void printGraph(fstream& flog);
};

#include "MatrixGraph.hpp"