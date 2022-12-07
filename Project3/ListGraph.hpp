#include "ListGraph.h"

ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
	m_List = new map<int, int>[size];
}

ListGraph::~ListGraph()
{
	delete[] m_List;
}

vector<int> *ListGraph::getAdjacentEdges(int vertex)
{
	vector<int>* adjacent_nodes = new vector<int>;
	map<int, int> vmap = m_List[vertex];

	// Append vertex is start position
	for (auto vw : vmap)
		adjacent_nodes->push_back(vw.first);

	// Append vertex is end position
	for (int i = 0; i < m_Size; i++)
		for (auto vw : m_List[i])
			if (vw.first == vertex)
				adjacent_nodes->push_back(vw.first);
	
	sort(adjacent_nodes->begin(), adjacent_nodes->end());
	return adjacent_nodes;
}

void ListGraph::insertEdge(int from, int to, int weight)
{
	m_List[from].insert(make_pair(to, weight));
}

void ListGraph::printGraph(fstream &flog)
{
	for (int i = 0; i < m_Size; i++)
	{
		flog << "[" << i << "]";

		for (auto it_ = m_List[i].begin(); it_ != m_List[i].end() && flog << " -> "; it_++)
			flog << "(" << it_->first << "," << it_->second << ")";
		flog << endl;
	}
}