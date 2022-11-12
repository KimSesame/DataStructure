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

bool BpTree::printBPtree(fstream &flog)
{
}