#include "FPGrowth.h"

FPGrowth::FPGrowth() : threshold(2)
{
    fptree = new FPNode(0);
    table = new HeaderTable;
}

void FPGrowth::createdataTable()
{
    list<pair<int, string>> &indexTable = table->getindexTable();
    map<string, FPNode *> &dataTable = table->getdataTable();

    for (auto iter = indexTable.begin(); iter != indexTable.end(); iter++)
        dataTable.insert(make_pair((*iter).second, new FPNode(0)));

    return;
}

void FPGrowth::createFPtree(FPNode *root, string item)
{
    FPNode *cur_node = root;
    FPNode *new_node = nullptr;
    pair<string, FPNode *> new_pair;
    FPNode *target_node = nullptr;

    // Inspect children
    if (cur_node->getChildren().find(item) == cur_node->getChildren().end()) // NOT exist
    {
        // Insert
        new_node = new FPNode(1);
        new_pair = make_pair(item, new_node);
        cur_node->getChildren().insert(new_pair);
        new_node->setParent(cur_node);
        connectNode(table, item, new_node);
        return;
    }
    else // exist
    {
        // Update
        target_node = cur_node->getChildrenNode(item);
        target_node->updateFrequency(1);
        return;
    }
}

void FPGrowth::connectNode(HeaderTable *table, string item, FPNode *node)
{
    FPNode *cur_node = (*(table->getdataTable().find(item))).second; // set cur_node to head in dataTable

    // Move to tail
    while (cur_node->getNext())
        cur_node = cur_node->getNext();

    // Connect(Insert)
    cur_node->setNext(node);
}

bool FPGrowth::printList(fstream &flog)
{
    list<pair<int, string>> &indexTable = table->getindexTable();
    list<pair<int, string>>::iterator iter;

    // EMPTY
    if (indexTable.size() == 0)
        return false;

    // Print
    table->descendingIndexTable();
    flog << "Item\tFrequency" << endl;
    for (iter = indexTable.begin(); iter != indexTable.end(); iter++)
        flog << (*iter).second << " " << (*iter).first << endl;

    return true;
}

bool FPGrowth::printFPtree(fstream &flog)
{
    // EMPTY
    if (fptree->getChildren().size() == 0)
        return false;

    list<pair<int, string>> &indexTable = table->getindexTable();
    list<pair<int, string>>::iterator iter;
    FPNode *cur_node;

    // Print
    table->ascendingIndexTable();
    flog << "{StandardItem, Frequency} (Path_Item, Frequency)" << endl;
    for (iter = indexTable.begin(); iter != indexTable.end(); iter++)
    {
        // Inspect frequency
        if ((*iter).first < threshold)
            continue;

        flog << "{" << (*iter).second << ", " << (*iter).first << "}" << endl;
        cur_node = (table->getdataTable())[(*iter).second];
        // Traverse linked list
        while (cur_node->getNext())
        {
            cur_node = cur_node->getNext();
            FPNode *route_node = cur_node;
            // Print ancestors
            while (route_node != fptree)
            {
                map<string, FPNode *> &temp = route_node->getParent()->getChildren();
                map<string, FPNode *>::iterator temp_it = temp.begin();
                for (; temp_it != temp.end(); temp_it++)
                {
                    if ((*temp_it).second == route_node)
                    {
                        flog << "(" << (*temp_it).first << ", " << (*temp_it).second->getFrequency() << ") ";
                        break;
                    }
                }
                route_node = route_node->getParent();
            }
            flog << endl;
        }
    }
    return true;
}