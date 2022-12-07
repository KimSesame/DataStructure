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

vector<int> *MatrixGraph::getAdjacentEdges(int vertex)
{
	vector<int> *adjacent_nodes = new vector<int>;

	// Append vertex is start position
	for (int j = 0; j < m_Size; j++)
		if(m_Mat[vertex][j])
			adjacent_nodes->push_back(j);

	// Append vertex is end position
	for (int i = 0; i < m_Size; i++)
		if(m_Mat[i][vertex])
			adjacent_nodes->push_back(i);

	sort(adjacent_nodes->begin(), adjacent_nodes->end());
	return adjacent_nodes;
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
