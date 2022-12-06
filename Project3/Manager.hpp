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

// // // // // // // // // // // // // // // // // // // //
void Manager::CHECK()
{
    graph->printGraph();
}
