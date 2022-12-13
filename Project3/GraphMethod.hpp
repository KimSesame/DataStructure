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
    vector<pair<pair<int, int>, int>> *edges = graph->getEdges();
    vector<pair<pair<int, int>, int>> mst_edges;
    vector<int> set_table;

    // Init set table
    for (int i = 0; i < graph->getSize(); i++)
        set_table.push_back(i);

    // Sort by weight in ascending order
    QuickSort(*edges, 0, edges->size() - 1);

    // Get MST
    for (auto edge : *edges)
    {
        if (accumulate(set_table.begin(), set_table.end(), 0) == 0 || mst_edges.size() == graph->getSize() - 1)
            break;

        if (Find(set_table, edge.first.first) == Find(set_table, edge.first.second)) // cycle occur if union
            continue;

        Union(set_table, edge.first.first, edge.first.second);
        mst_edges.push_back(edge);
    }

    // Not MST
    if (mst_edges.size() != graph->getSize() - 1)
        return false;

    // Get MST cost
    int cost = 0;
    for (auto edge : mst_edges)
        cost += edge.second;

    // Print MST information
    for (int i = 0; i < graph->getSize(); i++)
    {
        flog << "[" << i << "] ";
        for (auto edge : mst_edges)
        {
            if (edge.first.first == i)
                flog << edge.first.second << "(" << edge.second << ") ";
            else if (edge.first.second == i)
                flog << edge.first.first << "(" << edge.second << ") ";
        }
        flog << endl;
    }
    flog << "cost: " << cost << endl;

    return true;
}

bool Dijkstra(fstream &flog, Graph *graph, int vertex)
{
    vector<int> distance;
    vector<int> visit_table;
    vector<int> path_table;

    // Init tables
    for (int i = 0; i < graph->getSize(); i++)
        distance.push_back(MAX);
    distance[vertex] = 0;

    for (int i = 0; i < graph->getSize(); i++)
        visit_table.push_back(false);

    for (int i = 0; i < graph->getSize(); i++)
        path_table.push_back(-1);

    // Search
    int cur_node = vertex;
    visit_table[vertex] = true;
    while (accumulate(visit_table.begin(), visit_table.end(), 0) != visit_table.size())
    {
        map<int, int> *adjacent_edges = graph->getAdjacentEdges(cur_node, 1);

        // Update min distance
        for (auto adj_edge : *adjacent_edges)
            if (((distance[cur_node] != MAX) ? distance[cur_node] : 0) + adj_edge.second < distance[adj_edge.first])
            {
                path_table[adj_edge.first] = cur_node;
                distance[adj_edge.first] = ((distance[cur_node] != MAX) ? distance[cur_node] : 0) + adj_edge.second;
            }

        cur_node = getMinIdx(distance, visit_table);
        if (cur_node == -1)
            break;

        visit_table[cur_node] = true;
    }

    // Set path
    flog << "startvertex: " << vertex << endl;
    for (int i = 0; i < path_table.size(); i++)
    {
        if (i == vertex)
            continue;

        vector<int> rpath;
        int cur = i;
        while (path_table[cur] != -1)
        {
            rpath.push_back(cur);
            cur = path_table[cur];
        }
        rpath.push_back(cur);

        // Print path
        flog << "[" << i << "] ";
        if (cur != vertex)
        {
            flog << "x" << endl;
            continue;
        }

        auto riter = rpath.rbegin();

        flog << *riter++;
        for (; riter != rpath.rend(); riter++)
            flog << " -> " << *riter;
        flog << " (" << distance[i] << ")" << endl;
    }
    return true;
}

bool Bellmanford(fstream &flog, Graph *graph, int start, int end)
{
    vector<pair<pair<int, int>, int>> *edges = graph->getEdges(1);
    vector<int> distance;
    vector<int> path_table;

    // Init tables
    for (int i = 0; i < graph->getSize(); i++)
        distance.push_back(MAX);
    distance[start] = 0;

    for (int i = 0; i < graph->getSize(); i++)
        path_table.push_back(-1);

    // Search
    for (int i = 0; i < graph->getSize(); i++)
        for (auto edge : *edges)
            if (distance[edge.first.second] > distance[edge.first.first] + edge.second)
            {
                distance[edge.first.second] = distance[edge.first.first] + edge.second;
                path_table[edge.first.second] = edge.first.first;
            }

    for (auto edge : *edges)
        // negative cycle exists if distance update
        if (distance[edge.first.second] > distance[edge.first.first] + edge.second)
            return false;

    // Set path
    vector<int> rpath;
    int cur = end;
    while (path_table[cur] != -1)
    {
        rpath.push_back(cur);
        cur = path_table[cur];
    }
    rpath.push_back(cur);

    // Print path
    auto riter = rpath.rbegin();

    flog << *riter++;
    for (; riter != rpath.rend(); riter++)
        flog << " -> " << *riter;
    flog << endl;
    flog << "cost: " << distance[end] << endl;

    return true;
}

// bool FLOYD(fstream& flog, Graph* graph)
// {

// }