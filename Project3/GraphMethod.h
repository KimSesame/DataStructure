#pragma once

#include "ListGraph.h"
#include "MatrixGraph.h"
//#include "vertexSet.h"

bool BFS(fstream& flog, Graph* graph, int vertex);
bool DFS(fstream& flog, Graph* graph, int vertex);
bool DFS_R(Graph* graph, vector<bool>* visit, int vertex);
bool Kruskal(Graph* graph);
bool Dijkstra(Graph* graph, int vertex);
bool Bellmanford(Graph* graph, int s_vertex, int e_vertex);
bool FLOYD(Graph* graph);

#include "GraphMethod.hpp"
