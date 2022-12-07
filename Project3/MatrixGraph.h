#pragma once

#include "Graph.h"

class MatrixGraph : public Graph{
private:
	int** m_Mat;

public:
	MatrixGraph(bool type, int size);
	~MatrixGraph();	
		
	vector<int>* getAdjacentEdges(int vertex);
	void insertEdge(int from, int to, int weight);
	void printGraph(fstream& flog);
};

#include "MatrixGraph.hpp"