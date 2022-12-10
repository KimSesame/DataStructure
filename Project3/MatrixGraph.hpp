#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(bool type, int size) : Graph(type, size)
{
	m_Mat = new int *[size];
	for (int i = 0; i < size; i++)
	{
		m_Mat[i] = new int[size];
		memset(m_Mat[i], 0, sizeof(int) * size);
	}
}

MatrixGraph::~MatrixGraph()
{
	for (int i = 0; i < getSize(); i++)
	{
		delete[] m_Mat[i];
	}
	delete[] m_Mat;
}

map<int, int> *MatrixGraph::getAdjacentEdges(int vertex, int direct)
{
	map<int, int> *adjacent_edges = new map<int, int>;

	// Append vertex is start position
	for (int j = 0; j < m_Size; j++)
		if (m_Mat[vertex][j])
			adjacent_edges->insert(make_pair(j, m_Mat[vertex][j]));

	if (direct)
		return adjacent_edges;

	// Append vertex is end position
	for (int i = 0; i < m_Size; i++)
		if (m_Mat[i][vertex])
			if (adjacent_edges->find(i) == adjacent_edges->end())
				adjacent_edges->insert(make_pair(i, m_Mat[i][vertex]));
			else if (m_Mat[i][vertex] < adjacent_edges->at(i))
				adjacent_edges->at(i) = m_Mat[i][vertex];

	return adjacent_edges;
}

void MatrixGraph::insertEdge(int from, int to, int weight)
{
	m_Mat[from][to] = weight;
}

void MatrixGraph::printGraph(fstream &flog)
{
	if (m_Size < 0)
		return;

	flog << '\t';
	for (int i = 0; i < m_Size; i++)
	{
		flog << "[" << i << "]" << '\t';
	}
	flog << endl;

	for (int i = 0; i < m_Size; i++)
	{
		flog << "[" << i << "]";
		for (int j = 0; j < m_Size && flog << '\t'; j++)
		{
			flog << m_Mat[i][j];
		}
		flog << endl;
	}
}
