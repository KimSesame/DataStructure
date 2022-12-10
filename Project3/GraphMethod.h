#pragma once

#include "ListGraph.h"
#include "MatrixGraph.h"
#include <numeric>
// #include "vertexSet.h"

bool BFS(fstream &flog, Graph *graph, int vertex);
bool DFS(fstream &flog, Graph *graph, int vertex);
bool DFS_R(fstream &flog, Graph *graph, int vertex);
vector<int> *DFS_R(fstream &flog, Graph *graph, int vertex, map<int, bool> *visit_table, vector<int> *path);
bool Kruskal(fstream &flog, Graph *graph);
bool Dijkstra(fstream &flog, Graph *graph, int vertex);
bool Bellmanford(Graph *graph, int s_vertex, int e_vertex);
bool FLOYD(Graph *graph);

/////////////////////////

int getMinIdx(vector<int> distance, vector<int> visit_table)
{
    int min = MAX;
    int min_idx = -1;

    for (int i = 0; i < distance.size(); i++)
        if (!visit_table[i] && distance[i] < min)
        {
            min = distance[i];
            min_idx = i;
        }

    return min_idx;
}

#include "GraphMethod.hpp"
