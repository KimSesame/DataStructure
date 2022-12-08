#include "ListGraph.h"

ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
	m_List = new map<int, int>[size];
}

ListGraph::~ListGraph()
{
	delete[] m_List;
}

map<int, int> *ListGraph::getAdjacentEdges(int vertex)
{
	map<int, int> *adjacent_edges = new map<int, int>;
	map<int, int> vmap = m_List[vertex];

	// Append vertex is start position
	for (auto vw : vmap)
		adjacent_edges->insert(make_pair(vw.first, vw.second));

	// Append vertex is end position
	for (int i = 0; i < m_Size; i++)
		for (auto vw : m_List[i])
			if (vw.first == vertex)
				if (adjacent_edges->find(vw.first) == adjacent_edges->end())
					adjacent_edges->insert(make_pair(i, vw.second));
				else if (vw.second < adjacent_edges->at(vw.first))
					adjacent_edges->at(vw.first) = vw.second;
	// test
	cout << vertex << ": " << adjacent_edges->size() << endl;
	//
	return adjacent_edges;
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