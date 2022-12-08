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
        map<int, int> *adj_edges = graph->getAdjacentEdges(q.front());
        path.push_back(q.front()); // append at path
        q.pop();
        for (auto adj_edge : *adj_edges)
        {
            if (visit_table[adj_edge.first] == false)
            {
                (*visit_table.find(adj_edge.first)).second = true; // mark visited
                q.push(adj_edge.first);
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

bool DFS(fstream &flog, Graph *graph, int vertex)
{
    stack<int> s;
    map<int, bool> visit_table;
    vector<int> path;

    // Initialize visit table
    for (int i = 0; i < graph->getSize(); i++)
        visit_table.insert(make_pair(i, false));

    // Node search
    (*visit_table.find(vertex)).second = true; // mark visited
    path.push_back(vertex);                    // append at path
    s.push(vertex);
    while (!s.empty())
    {
        int cur_node = s.top();
        map<int, int> *adj_edges = graph->getAdjacentEdges(cur_node);
        s.pop();

        for (auto adj_edge : *adj_edges)
        {
            if (visit_table[adj_edge.first] == false)
            {
                (*visit_table.find(adj_edge.first)).second = true; // mark visited
                path.push_back(adj_edge.first);
                s.push(cur_node);
                s.push(adj_edge.first);
                break;
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

bool DFS_R(fstream &flog, Graph *graph, int vertex)
{
    map<int, bool> *visit_table = new map<int, bool>;
    vector<int> *path = new vector<int>;

    // Initialize visit table
    for (int i = 0; i < graph->getSize(); i++)
        (*visit_table).insert(make_pair(i, false));

    // Print path
    path = DFS_R(flog, graph, vertex, visit_table, path);
    auto iter = (*path).begin();

    flog << "startvertex: " << vertex << endl;
    flog << *iter++;
    for (; iter != (*path).end(); iter++)
        flog << " -> " << *iter;
    flog << endl;

    return true;
}

vector<int> *DFS_R(fstream &flog, Graph *graph, int vertex, map<int, bool> *visit_table, vector<int> *path)
{
    map<int, int> *adj_edges = graph->getAdjacentEdges(vertex);

    (*visit_table).at(vertex) = true;
    (*path).push_back(vertex);
    for (auto adj_edge : *adj_edges)
        if (!(*visit_table)[adj_edge.first])
            DFS_R(flog, graph, adj_edge.first, visit_table, path);
    return path;
}

bool Kruskal(fstream &flog, Graph *graph)
{
}

// bool Dijkstra(Graph* graph, int vertex)
// {

// }

// bool Bellmanford(Graph* graph, int s_vertex, int e_vertex)
// {

// }

// bool FLOYD(Graph* graph)
// {

// }