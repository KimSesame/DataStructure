#pragma once

#include "ListGraph.h"
#include "MatrixGraph.h"
#include <numeric>
#include <utility>

bool BFS(fstream &flog, Graph *graph, int vertex);
bool DFS(fstream &flog, Graph *graph, int vertex);
bool DFS_R(fstream &flog, Graph *graph, int vertex);
vector<int> *DFS_R(fstream &flog, Graph *graph, int vertex, map<int, bool> *visit_table, vector<int> *path);
bool Kruskal(fstream &flog, Graph *graph);
bool Dijkstra(fstream &flog, Graph *graph, int vertex);
bool Bellmanford(fstream& flog, Graph *graph, int start, int end);
bool FLOYD(fstream& flog, Graph *graph);

///////////////////////////////////////////////////////////////////////////

void QuickSort(vector<pair<pair<int, int>, int>> &edges, const int left, const int right);
void Union(vector<int>& set_table, int vertex1, int vertex2);
int Find(vector<int> set_table, int vertex);
int getMinIdx(vector<int> distance, vector<int> visit_table);

// QuickSort by weight in ascending order for kruskal
void QuickSort(vector<pair<pair<int, int>, int>> &edges, const int left, const int right)
{
    if (left < right){
        int i = left;
        int j = right + 1;
        int pivot = edges[left].second;

        do
        {
            do i++; while (edges[i].second < pivot);
            do j--; while (edges[j].second > pivot);
            if (i < j) swap(edges[i], edges[j]);
        } while (i < j);
        swap(edges[left], edges[j]);

        QuickSort(edges, left, j-1);
        QuickSort(edges, j+1, right);
    }
}

// Union each vertex set into lower vertex for kruskal
void Union(vector<int>& set_table, int vertex1, int vertex2)
{
    int set1 = Find(set_table, vertex1);
    int set2 = Find(set_table, vertex2);

    if (set1 < set2)
        set_table[vertex2] = set1;
    else
        set_table[vertex1] = set2;
}

// Return parent of set which vertex is included for kruskal
int Find(vector<int> set_table, int vertex)
{
    if (set_table[vertex] == vertex)
        return vertex;
    return Find(set_table, set_table[vertex]);
}

// Return min index of non-visited vertices for dijkstra
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
