#include "ListGraph.h"

ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
	m_List = new map<int, int>[size];
}

ListGraph::~ListGraph()
{
	delete[] m_List;
}

map<int, int> *ListGraph::getAdjacentEdges(int vertex, int direct)
{
	map<int, int> *adjacent_edges = new map<int, int>;
	map<int, int> vmap = m_List[vertex];

	// Append vertex is start position
	for (auto vw : vmap)
		adjacent_edges->insert(make_pair(vw.first, vw.second));

	if (direct)
		return adjacent_edges;

	// Append vertex is end position
	for (int i = 0; i < m_Size; i++)
		for (auto vw : m_List[i])
			if (vw.first == vertex)
				if (adjacent_edges->find(vw.first) == adjacent_edges->end())
					adjacent_edges->insert(make_pair(i, vw.second));
				else if (vw.second < adjacent_edges->at(vw.first))
					adjacent_edges->at(vw.first) = vw.second;
	return adjacent_edges;
}

vector<pair<pair<int, int>, int>> *ListGraph::getEdges(int direct)
{
	vector<pair<pair<int, int>, int>> *edges = new vector<pair<pair<int, int>, int>>;

	for (int i = 0; i < m_Size; i++)
	{
		map<int, int> *adjacnet_edges = getAdjacentEdges(i, direct);
		for (auto tw : *adjacnet_edges)
		{
			if (!direct) // indirected graph
			{
				if (i < tw.first)
					edges->push_back(make_pair(make_pair(i, tw.first), tw.second));
				else
					edges->push_back(make_pair(make_pair(tw.first, i), tw.second));
			}
			else // directed graph
				edges->push_back(make_pair(make_pair(i, tw.first), tw.second));
		}
	}
	// Eliminate duplication
	sort(edges->begin(), edges->end());
	edges->erase(unique(edges->begin(), edges->end()), edges->end());

	return edges;
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
