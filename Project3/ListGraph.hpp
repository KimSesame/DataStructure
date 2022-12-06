#include "ListGraph.h"

ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
	m_List = new map<int, int>[size];
}

ListGraph::~ListGraph()
{
	delete[] m_List;
}

void ListGraph::getAdjacentEdges(int vertex, map<int, int> *m)
{
}

void ListGraph::insertEdge(int from, int to, int weight)
{
	m_List[from].insert(make_pair(to, weight));
}

void ListGraph::printGraph(fstream& flog)
{
	for (int i = 0; i < m_Size; i++)
	{
		flog << "[" << i << "]";

		for (auto it_ = m_List[i].begin(); it_ != m_List[i].end() && flog << " -> "; it_++)
			flog << "(" << it_->first << "," << it_->second << ")";
		flog << endl;
	}
}