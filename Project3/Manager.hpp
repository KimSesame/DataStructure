#include "Manager.h"

void Manager::LOAD(string file_name)
{
    string type;
    string size;
    string line;
    int from, to;
    fstream fin("C:/Users/kimbs/repos/Assignments/DataStructure/Project3/" + file_name, ios::in);

    // Handle exception
    if (!fin.is_open() || fin.eof()) // file NOT existed or empty
    {
        flog << "========LOAD========" << endl;
        flog << ErrorCode::LOAD_ERR << endl;
        flog << "====================" << endl;
        return;
    }

    if (graph != nullptr) // if LOAD before
        delete graph;

    getline(fin, type); // read graph type
    getline(fin, size); // read graph size
    if (type == "L")    // List Graph
    {
        graph = new ListGraph(0, atoi(size.c_str()));
        string vertex;

        while (getline(fin, line))
        {
            // Extract data
            if (line.find(' ') == string::npos) // from vertex
            {
                vertex = line;
                from = atoi(vertex.c_str());
            }
            else // to vertex, weight
            {
                vertex = line.substr(0, line.find_first_of(' '));
                line.erase(0, vertex.size() + 1);
                size = line;

                to = atoi(vertex.c_str());
                graph->insertEdge(from, to, atoi(size.c_str()));
            }
        }
    }
    else // Matrix Graph
    {
        graph = new MatrixGraph(1, atoi(size.c_str()));
        string temp;

        for (int i = 0; i < atoi(size.c_str()); i++)
        {
            getline(fin, line);
            for (int j = 0; j < atoi(size.c_str()); j++)
            {
                // Extract data
                if (line.find(' ') != string::npos)
                {
                    temp = line.substr(0, line.find_first_of(' '));
                    line.erase(0, temp.size() + 1);
                }
                else
                    temp = line;

                // Store if have weight
                if (atoi(temp.c_str()))
                    graph->insertEdge(i, j, atoi(temp.c_str()));
            }
        }
    }

    // Print log
    flog << "========LOAD========" << endl;
    flog << "Success" << endl;
    flog << "====================" << endl;

    fin.close();
    return;
}

void Manager::PRINT(string param)
{
    flog << "========PRINT========" << endl;
    if (graph == nullptr || !param.empty())
        flog << ErrorCode::PRINT_ERR << endl;
    else
        graph->printGraph(flog);
    flog << "=====================" << endl;
}

void Manager::mBFS(string vertex)
{
    flog << "========BFS========" << endl;

    // Exceptions
    if (vertex.empty() || graph == nullptr || graph->getSize() <= atoi(vertex.c_str()) || vertex.find(' ') != vertex.npos)
    {
        flog << ErrorCode::BFS_ERR << endl;
        flog << "===================" << endl;
        return;
    }

    int start = atoi(vertex.c_str());
    BFS(flog, graph, start);
    flog << "===================" << endl;
}

void Manager::mDFS(string vertex)
{
    flog << "========DFS========" << endl;

    // Exceptions
    if (vertex.empty() || graph == nullptr || graph->getSize() <= atoi(vertex.c_str()) || vertex.find(' ') != vertex.npos)
    {
        flog << ErrorCode::DFS_ERR << endl;
        flog << "===================" << endl;
        return;
    }

    int start = atoi(vertex.c_str());
    DFS(flog, graph, start);
    flog << "===================" << endl;
}

void Manager::mDFS_R(string vertex)
{
    flog << "========DFS_R========" << endl;

    // Exceptions
    if (vertex.empty() || graph == nullptr || graph->getSize() <= atoi(vertex.c_str()) || vertex.find(' ') != vertex.npos)
    {
        flog << ErrorCode::DFS_R_ERR << endl;
        flog << "=====================" << endl;
        return;
    }

    int start = atoi(vertex.c_str());
    DFS_R(flog, graph, start);
    flog << "=====================" << endl;
}

void Manager::mKRUSKAL(string param)
{
    flog << "========Kruskal========" << endl;

    // Exceptions
    if (graph == nullptr || !param.empty())
    {
        flog << ErrorCode::KRUSKAL_ERR << endl;
        flog << "=====================" << endl;
        return;
    }

    if (!Kruskal(flog, graph))
        flog << ErrorCode::KRUSKAL_ERR << endl;

    flog << "=======================" << endl;
}

void Manager::mDIJKSTRA(string vertex)
{
    flog << "========Dijkstra========" << endl;

    // Exceptions
    if (vertex.empty() || graph == nullptr || graph->getSize() <= atoi(vertex.c_str()) || vertex.find(' ') != vertex.npos)
    {
        flog << ErrorCode::DIJKSTRA_ERR << endl;
        flog << "========================" << endl;
        return;
    }

    int start = atoi(vertex.c_str());
    Dijkstra(flog, graph, start);
    flog << "========================" << endl;
}

void Manager::mBELLMANFORD(string params)
{
    string v1, v2;

    v1 = params.substr(0, params.find_first_of(' '));
    params = params.erase(0, v1.size() + 1);
    v2 = params;

    flog << "========Bellman-Ford========" << endl;

    // Exceptions
    if (v1.empty() || v2.empty() || graph == nullptr || graph->getSize() <= max(atoi(v1.c_str()), atoi(v2.c_str())) ||
        min(atoi(v1.c_str()), atoi(v2.c_str())) < 0 || params.find(' ') != params.npos)
    {
        flog << ErrorCode::BELLMANFORD_ERR << endl;
        flog << "============================" << endl;
        return;
    }

    if (!Bellmanford(flog, graph, atoi(v1.c_str()), atoi(v2.c_str())))
        flog << ErrorCode::BELLMANFORD_ERR << endl;

    flog << "============================" << endl;
}

void Manager::mFLOYD(string line)
{
    flog << "========FLOYD========" << endl;

    // Exceptions
    if (graph == nullptr || !line.empty())
    {
        flog << ErrorCode::FLOYD_ERR << endl;
        flog << "=====================" << endl;
        return;
    }

    if (!FLOYD(flog, graph))
        flog << ErrorCode::FLOYD_ERR << endl;

    flog << "=====================" << endl;
}

// // // // // // // // // // // // // // // // // // // //