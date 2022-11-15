#include "Manager.h"

void Manager::LOAD()
{
    string line;
    string item;
    FPNode *root = nullptr;
    priority_queue<pair<int, string>> pq; // max heap for descending sort

    fstream fin("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/market.txt", ios::in);

    // Create indexTable
    if (!fin.is_open() || fpgrowth->getHeaderTable()->getindexTable().size() > 0)
    {
        flog << "========LOAD========" << endl;
        flog << "ERROR " << ErrorCode::LOAD_ERR << endl;
        flog << "====================" << endl;
        return;
    }
    else
    {
        while (getline(fin, line))
        {
            while (!line.empty())
            {
                item = line.substr(0, line.find_first_of('\t')); // extract item
                line.erase(0, item.size() + 1);

                fpgrowth->createindexTable(item);
            }
        }
    }

    fin.close();

    // Create dataTable
    fpgrowth->createdataTable();

    // Create fptree
    fin.open("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/market.txt", ios::in);

    while (getline(fin, line))
    {
        // Sort items by table order
        while (!line.empty())
        {
            item = line.substr(0, line.find_first_of('\t'));
            line.erase(0, item.size() + 1);

            for (auto iter = fpgrowth->getHeaderTable()->getindexTable().begin(); iter != fpgrowth->getHeaderTable()->getindexTable().end(); iter++)
            {
                if ((*iter).second == item)
                {
                    pq.push(*iter);
                    break;
                }
            }
        }

        // Insert fptree node
        root = fpgrowth->getTree();
        while (!pq.empty())
        {
            fpgrowth->createFPtree(root, pq.top().second);
            root = root->getChildrenNode(pq.top().second);
            pq.pop();
        }
    }

    // Print log
    flog << "========LOAD========" << endl;
    flog << "SUCCESS" << endl;
    flog << "====================" << endl;

    fin.close();
    return;
}

void Manager::BTLOAD()
{
    string line;
    string frequency;
    string item;
    BpTreeNode *root = nullptr;
    set<string> items;

    fstream fin("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/result.txt", ios::in);

    // Create indexTable
    if (!fin.is_open() || bptree->getRoot() != nullptr)
    {
        flog << "========BTLOAD========" << endl;
        flog << "ERROR " << ErrorCode::LOAD_ERR << endl;
        flog << "======================" << endl;
        return;
    }
    else
    {
        while (getline(fin, line))
        {
            frequency = line.substr(0, line.find_first_of('\t')); // extract frequency
            line.erase(0, frequency.size() + 1);
            items.clear();
            while (!line.empty())
            {
                item = line.substr(0, line.find_first_of('\t')); // extract item
                line.erase(0, item.size() + 1);

                items.insert(item);
            }

            bptree->Insert(atoi(frequency.c_str()), items);
        }
    }

    // Print log
    flog << "========BTLOAD========" << endl;
    flog << "SUCCESS" << endl;
    flog << "======================" << endl;

    fin.close();
    return;
}

void Manager::PRINT_ITEMLIST()
{
    flog << "========PRINT_ITEMLIST========" << endl;
    if (!fpgrowth->printList(flog))
        flog << "ERROR " << ErrorCode::PRINT_ITEMLIST_ERR << endl;
    flog << "==============================" << endl;

    return;
}

void Manager::PRINT_FPTREE()
{
    flog << "========PRINT_FPTREE========" << endl;
    if (!fpgrowth->printFPtree(flog))
        flog << "ERROR " << ErrorCode::PRINT_FPTREE_ERR << endl;
    flog << "============================" << endl;

    return;
}

void Manager::PRINT_BPTREE(string param)
{
    string item;
    string min_freq;

    item = param.substr(0, param.find_first_of('\t'));
    param.erase(0, item.size() + 1);
    min_freq = param;

    flog << "========PRINT_BPTREE========" << endl;
    if (item.empty() || min_freq.empty())
        flog << "ERROR " << ErrorCode::PRINT_BPTREE_ERR << endl;
    else if (!bptree->printBPtree(flog, item, atoi(min_freq.c_str())))
        flog << "ERROR " << ErrorCode::PRINT_BPTREE_ERR << endl;
    flog << "============================" << endl;

    return;
}

void Manager::PRINT_RANGE(string param)
{
    string item;
    string min;
    string max;

    item = param.substr(0, param.find_first_of('\t'));
    param.erase(0, item.size() + 1);
    min = param.substr(0, param.find_first_of('\t'));
    param.erase(0, min.size() + 1);
    max = param;

    flog << "========PRINT_RANGE========" << endl;
    if (item.empty() || min.empty() || max.empty())
        flog << "ERROR " << ErrorCode::PRINT_RANGE_ERR << endl;
    else if (!bptree->printRange(flog, item, atoi(min.c_str()), atoi(max.c_str())))
        flog << "ERROR " << ErrorCode::PRINT_RANGE_ERR << endl;
    flog << "===========================" << endl;

    return;
}