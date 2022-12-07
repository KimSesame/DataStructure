#include "GraphMethod.h"

bool BFS(fstream &flog, Graph *graph, int vertex)
{
    queue<int> q;
    map<int, bool> visit_table;
    vector<int> path;

    // Initialize visit table
    for (int i = 0; i < graph->getSize(); i++)
        visit_table.insert(make_pair(i, false));

    // Node search
    (*visit_table.find(vertex)).second = true; // mark visited
    q.push(vertex);
    while (!q.empty())
    {
        vector<int> *adj_nodes = graph->getAdjacentEdges(q.front());
        path.push_back(q.front()); // append at path
        q.pop();
        for (auto adj_node : *adj_nodes)
        {
            if (visit_table[adj_node] == false)
            {
                (*visit_table.find(adj_node)).second = true; // mark visited
                q.push(adj_node);
            }
        }
    }

    // Print path
    auto iter = path.begin();

    flog << "startvertex: " << vertex << endl;
    flog << *iter++;
    for (; iter != path.end(); iter++)
        flog << " -> " << *iter;
    flog << endl;

    return true;
}

// bool DFS(Graph* graph, int vertex)
// {

// }

// bool DFS_R(Graph* graph, vector<bool>* visit, int vertex)
// {

// }

// bool Kruskal(Graph* graph)
// {

// }

// bool Dijkstra(Graph* graph, int vertex)
// {

// }

// bool Bellmanford(Graph* graph, int s_vertex, int e_vertex)
// {

// }

// bool FLOYD(Graph* graph)
// {

// }