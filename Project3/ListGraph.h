#pragma once

#include "Graph.h"

class ListGraph : public Graph{
private:
	map < int, int >* m_List;

public:	
	ListGraph(bool type, int size);
	~ListGraph();
		
	map<int, int>* getAdjacentEdges(int vertex, int direct = 0);
	vector<pair<pair<int,int>,int>>* getEdges(void);
	void insertEdge(int from, int to, int weight);
	void printGraph(fstream& flog);
};

#include "ListGraph.hpp"