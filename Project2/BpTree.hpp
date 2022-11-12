#include "BpTree.h"

void BpTree::Insert(int key, set<string> set)
{
}

BpTreeNode *BpTree::searchDataNode(int n)
{
    BpTreeNode *pCur = root;

    return pCur;
}

void BpTree::splitDataNode(BpTreeNode *pDataNode)
{
}

void BpTree::splitIndexNode(BpTreeNode *pIndexNode)
{
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
    if (root->getIndexMap()->size() == 0 && root->getDataMap()->size() == 0)
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
                    printFrequentPatterns(flog, (*it).second, item);
                flag_print = true;
            }
        }
    }
    return flag_print;
}