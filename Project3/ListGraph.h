#pragma once

#include "Graph.h"

class ListGraph : public Graph{
private:
	map < int, int >* m_List;

public:	
	ListGraph(bool type, int size);
	~ListGraph();
		
	vector<int>* getAdjacentEdges(int vertex);
	void insertEdge(int from, int to, int weight);
	void printGraph(fstream& flog);
};

#include "ListGraph.hpp"