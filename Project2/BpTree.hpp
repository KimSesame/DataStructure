#include "BpTree.h"

void BpTree::Insert(int key, set<string> set)
{
    FrequentPatternNode *new_fqp_node = new FrequentPatternNode;

    // EMPTY
    if (root == nullptr)
    {
        root = new BpTreeDataNode;
        new_fqp_node->InsertList(set);
        root->insertDataMap(key, new_fqp_node);
        return;
    }

    BpTreeNode *cur_node = root;
    // Move through indexNode
    while (cur_node->getIndexMap()) // cur_node->getIndexMap()->size() > 0
    {
        map<int, BpTreeNode *> *cur_indexMap = cur_node->getIndexMap();
        map<int, BpTreeNode *>::reverse_iterator iiter = cur_indexMap->rbegin();
        bool move_flag = false;
        for (; iiter != cur_indexMap->rend(); iiter++)
        {
            if (key >= (*iiter).first)
            {
                cur_node = (*iiter).second;
                move_flag = true;
                break;
            }
        }
        if (!move_flag)
            cur_node = cur_node->getMostLeftChild();
    }

    // Search dataNode
    auto target = cur_node->getDataMap()->find(key);
    // frequent pattern node is exist
    if (target != cur_node->getDataMap()->end())
    {
        (*target).second->InsertList(set);
        return;
    }

    // frequent pattern node is  NOT exist
    // Insert
    new_fqp_node->InsertList(set);
    cur_node->insertDataMap(key, new_fqp_node);

    // Inspect with order
    if (excessDataNode(cur_node))
    {
        splitDataNode(cur_node);
        cur_node = cur_node->getParent();
        while (excessIndexNode(cur_node))
        {
            splitIndexNode(cur_node);
            cur_node = cur_node->getParent();
        }
    }
    return;
}

BpTreeNode *BpTree::searchDataNode(int n)
{
    BpTreeNode *pCur = root;

    return pCur;
}

void BpTree::splitDataNode(BpTreeNode *pDataNode)
{
    BpTreeDataNode *newDataNode = new BpTreeDataNode;
    map<int, FrequentPatternNode *> *cur_dataMap = pDataNode->getDataMap();
    map<int, FrequentPatternNode *>::iterator diter = cur_dataMap->begin();
    int idx = 0; // index of cur_dataMap

    // Split dataNode
    for (; diter != cur_dataMap->end(); diter++)
    {
        if (idx >= ceil((order - 1) / 2.0)) // ceil((order-1)/2.0)  :  index of starting split
        {
            newDataNode->insertDataMap((*diter).first, (*diter).second);
            pDataNode->deleteMap((*diter).first); // IF ERROR USE TWO FOR LOOP
        }
        idx++;
    }

    // Link dataNodes
    pDataNode->setNext(newDataNode);
    newDataNode->setPrev(pDataNode);

    // Inspect existing indexNode
    // if NOT exist
    if (pDataNode->getParent() == root) // Create superIndexNode
    {
        BpTreeIndexNode *superIndexNode = new BpTreeIndexNode;
        superIndexNode->setMostLeftChild(pDataNode);
        superIndexNode->insertIndexMap(newDataNode->getDataMap()->begin()->first, newDataNode);
        pDataNode->setParent(superIndexNode);
        newDataNode->setParent(superIndexNode);
        root = superIndexNode;
    }
    else // if exist, insert at indexMap
    {
        pDataNode->getParent()->insertIndexMap(newDataNode->getDataMap()->begin()->first, newDataNode);
        newDataNode->setParent(pDataNode->getParent());
    }
    return;
}

void BpTree::splitIndexNode(BpTreeNode *pIndexNode)
{
    BpTreeIndexNode *newIndexNode = new BpTreeIndexNode;
    map<int, BpTreeNode *> *cur_indexMap = pIndexNode->getIndexMap();
    map<int, BpTreeNode *>::iterator iiter = cur_indexMap->begin();
    map<int, BpTreeNode *>::iterator titer;
    int idx = 0; // index of cur_indexMap

    // Split indexNode
    for (; iiter != cur_indexMap->end(); iiter++)
    {
        if (idx == ceil((order - 1) / 2.0)) // ceil((order-1)/2.0)  :  index of starting split
        {
            titer = iiter;
            pIndexNode->deleteMap((*iiter).first); // IF ERROR USE TWO FOR LOOP
        }
        else if (idx > ceil((order - 1) / 2.0))
        {
            newIndexNode->insertIndexMap((*iiter).first, (*iiter).second);
            pIndexNode->deleteMap((*iiter).first); // IF ERROR USE TWO FOR LOOP
        }
        idx++;
    }

    // Link
    newIndexNode->setMostLeftChild((*titer).second);

    // Inspect existing indexNode
    // if NOT exist
    if (pIndexNode->getParent() == root) // Create superIndexNode
    {
        BpTreeIndexNode *superIndexNode;
        superIndexNode->setMostLeftChild(pIndexNode);
        superIndexNode->insertIndexMap((*titer).first, newIndexNode);
        pIndexNode->setParent(superIndexNode);
        newIndexNode->setParent(superIndexNode);
        root = superIndexNode;
    }
    else // if exist, insert at indexMap
    {
        pIndexNode->getParent()->insertIndexMap((*titer).first, newIndexNode);
        newIndexNode->setParent(pIndexNode->getParent());
    }
    return;
}

bool BpTree::excessDataNode(BpTreeNode *pDataNode)
{
    if (pDataNode->getDataMap()->size() > order - 1)
        return true; // order is equal to the number of elements
    else
        return false;
}

bool BpTree::excessIndexNode(BpTreeNode *pIndexNode)
{
    if (pIndexNode->getIndexMap()->size() > order - 1)
        return true; // order is equal to the number of elements
    else
        return false;
}

bool BpTree::printConfidence(string item, double item_frequency, double min_confidence)
{

    return true;
}

bool BpTree::printFrequency(string item, int min_frequency) // print winratio in ascending order
{

    return true;
}

bool BpTree::printRange(string item, int min, int max)
{

    return true;
}

void BpTree::printFrequentPatterns(fstream &flog, set<string> pFrequentPattern, string item)
{
    flog << "{";
    set<string> curPattern = pFrequentPattern;
    curPattern.erase(item);
    for (set<string>::iterator it = curPattern.begin(); it != curPattern.end();)
    {
        string temp = *it++;
        if (temp != item)
            flog << temp;
        if (it == curPattern.end())
        {
            flog << "} ";
            break;
        }
        flog << ", ";
    }
}

bool BpTree::printBPtree(fstream &flog, string item, int min_freq)
{
    // EMPTY
    if (root == nullptr)
        return false;

    BpTreeNode *cur_node = root;
    bool flag_print = false;

    flog << "FrequentPattern\tFrequency" << endl;
    // Move to head
    while (cur_node->getMostLeftChild())
        cur_node = cur_node->getMostLeftChild();

    // Print if greater than min_frequency
    while (cur_node->getNext())
    {
        map<int, FrequentPatternNode *> *cur_dataMap = cur_node->getDataMap();
        map<int, FrequentPatternNode *>::iterator iter = cur_dataMap->begin();

        for (; iter != cur_dataMap->end(); iter++)
        {
            if ((*iter).first > min_freq)
            {
                for (multimap<int, set<string>>::iterator it = (*iter).second->getList().begin(); it != (*iter).second->getList().end(); it++)
                {
                    printFrequentPatterns(flog, (*it).second, item);
                    flog << (*iter).first << endl;
                }
                flag_print = true;
            }
        }
    }
    return flag_print;
}