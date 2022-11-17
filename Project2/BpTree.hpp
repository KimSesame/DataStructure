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

    // // test =================================================================================================//
    // BpTreeNode *temp = root;
    // fstream trace("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/trace.txt", ios::out | ios::app);
    // int max;
    // while (temp->getMostLeftChild())
    //     temp = temp->getMostLeftChild();
    // while (temp)
    // {
    //     map<int, FrequentPatternNode *> *temp_dataMap = temp->getDataMap();
    //     map<int, FrequentPatternNode *>::iterator tit = temp_dataMap->begin();
    //     for (; tit != temp_dataMap->end(); tit++)
    //     {
    //         trace << (*tit).first << " ";
    //         max = (*tit).first;
    //     }
    //     temp = temp->getNext();
    // }

    // trace << "> Current MAX key: " << max << endl;
    // // ======================================================================================================//

    BpTreeNode *cur_node = root;
    // Move through indexNode
    //trace << "Insert " << key << ": "; // test
    while (cur_node->getIndexMap())
    {
        map<int, BpTreeNode *> *cur_indexMap = cur_node->getIndexMap();
        map<int, BpTreeNode *>::reverse_iterator iiter = cur_indexMap->rbegin();
        bool move_flag = false;
        for (; iiter != cur_indexMap->rend(); iiter++)
        {
            //trace << (*iiter).first; // test
            if (key >= (*iiter).first)
            {
                //trace << "right"; // test
                cur_node = (*iiter).second;
                move_flag = true;
                break;
            }
        }
        if (!move_flag)
        {
            //trace << "left"; // test
            cur_node = cur_node->getMostLeftChild();
        }
    }
    // trace << endl; // test
    // trace.close(); // test

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
    // Link

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
    map<int, FrequentPatternNode *>::iterator diter;
    int split = ceil((order - 1) / 2.0); // index of starting split
    int idx = 0;                         // index of cur_dataMap

    // Split dataNode
    while (cur_dataMap->size() > split)
    {
        for (diter = cur_dataMap->begin(); diter != cur_dataMap->end(); diter++)
        {
            if (idx == split)
            {
                newDataNode->insertDataMap((*diter).first, (*diter).second);
                pDataNode->deleteMap((*diter).first);
                break;
            }
            idx++;
        }
        idx = 0;
    }

    // Link dataNodes
    if (pDataNode->getNext())
    {
        pDataNode->getNext()->setPrev(newDataNode);
        newDataNode->setNext(pDataNode->getNext());
    }
    pDataNode->setNext(newDataNode);
    newDataNode->setPrev(pDataNode);

    // Inspect existing indexNode
    // if NOT exist
    if (pDataNode == root) // Create superIndexNode
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
    int split = ceil((order - 1) / 2.0); // index of starting split
    int idx = 0;                         // index of cur_indexMap
    bool link_flag = false;
    int superKey;

    // Split indexNode
    while (cur_indexMap->size() > split)
    {
        for (iiter = cur_indexMap->begin(); iiter != cur_indexMap->end(); iiter++)
        {
            if (idx == split)
            {
                if (!link_flag) // link first element of newIndexNode
                {
                    newIndexNode->setMostLeftChild((*iiter).second);
                    superKey = (*iiter).first;
                    pIndexNode->deleteMap((*iiter).first);
                    link_flag = true;
                }
                else
                {
                    newIndexNode->insertIndexMap((*iiter).first, (*iiter).second);
                    pIndexNode->deleteMap((*iiter).first);
                }
                (*iiter).second->setParent(newIndexNode);
                break;
            }
            idx++;
        }
        idx = 0;
    }

    // Inspect existing indexNode
    // if NOT exist
    if (pIndexNode == root) // Create superIndexNode
    {
        BpTreeIndexNode *superIndexNode = new BpTreeIndexNode;
        superIndexNode->setMostLeftChild(pIndexNode);
        superIndexNode->insertIndexMap(superKey, newIndexNode);
        pIndexNode->setParent(superIndexNode);
        newIndexNode->setParent(superIndexNode);
        root = superIndexNode;
    }
    else // if exist, insert at indexMap
    {
        pIndexNode->getParent()->insertIndexMap(superKey, newIndexNode);
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

bool BpTree::printConfidence(fstream &flog, string item, double item_frequency, double min_confidence)
{
    // EMPTY
    if (root == nullptr)
        return false;

    BpTreeNode *cur_node = root;
    double confidence;
    bool flag_print = false;
    flog << fixed;
    flog.precision(2);

    flog << "FrequentPattern\tFrequency\tConfidence" << endl;
    // Move to head
    while (cur_node->getMostLeftChild())
        cur_node = cur_node->getMostLeftChild();

    // Print
    while (cur_node)
    {
        map<int, FrequentPatternNode *> *cur_dataMap = cur_node->getDataMap();
        map<int, FrequentPatternNode *>::iterator iter = cur_dataMap->begin();

        for (; iter != cur_dataMap->end(); iter++)
        {
            confidence = (*iter).first / item_frequency;
            if (confidence >= min_confidence) // greater than min_confidence
            {
                multimap<int, set<string>> &patternList = (*iter).second->getList();
                multimap<int, set<string>>::iterator it = patternList.begin();
                for (; it != patternList.end(); it++)
                {
                    if (printFrequentPatterns(flog, (*it).second, item))
                    {
                        flog << (*iter).first << " "; // frequency
                        flog << confidence << endl;   // confidence
                        flag_print = true;
                    }
                }
            }
        }
        cur_node = cur_node->getNext();
    }
    return flag_print;
}

bool BpTree::printFrequency(string item, int min_frequency) // print winratio in ascending order
{

    return true;
}

bool BpTree::printRange(fstream &flog, string item, int min, int max)
{
    // EMPTY
    if (root == nullptr)
        return false;

    // WRONG RANGE
    if (max < min)
        return false;

    BpTreeNode *cur_node = root;
    bool flag_print = false;

    flog << "FrequentPattern\tFrequency" << endl;
    // Move to head
    while (cur_node->getMostLeftChild())
        cur_node = cur_node->getMostLeftChild();

    // Print
    while (cur_node)
    {
        map<int, FrequentPatternNode *> *cur_dataMap = cur_node->getDataMap();
        map<int, FrequentPatternNode *>::iterator iter = cur_dataMap->begin();

        for (; iter != cur_dataMap->end(); iter++)
        {
            if ((min <= (*iter).first) && ((*iter).first) <= max) // in range
            {
                multimap<int, set<string>> &patternList = (*iter).second->getList();
                multimap<int, set<string>>::iterator it = patternList.begin();
                for (; it != patternList.end(); it++)
                {
                    if (printFrequentPatterns(flog, (*it).second, item))
                    {
                        flog << (*iter).first << endl; // frequency
                        flag_print = true;
                    }
                }
            }
        }
        cur_node = cur_node->getNext();
    }
    return flag_print;
    return true;
}

bool BpTree::printFrequentPatterns(fstream &flog, set<string> pFrequentPattern, string item)
{
    if (pFrequentPattern.find(item) == pFrequentPattern.end())
        return false;

    flog << "{";
    for (set<string>::iterator iter = pFrequentPattern.begin(); iter != pFrequentPattern.end(); iter++)
    {
        if (*iter == item)
            continue;
        flog << *iter << ", ";
    }
    flog << item << "} ";
    return true;
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

    // Print
    while (cur_node)
    {
        map<int, FrequentPatternNode *> *cur_dataMap = cur_node->getDataMap();
        map<int, FrequentPatternNode *>::iterator iter = cur_dataMap->begin();

        for (; iter != cur_dataMap->end(); iter++)
        {
            if ((*iter).first >= min_freq) // greater than min_frequency
            {
                multimap<int, set<string>> &patternList = (*iter).second->getList();
                multimap<int, set<string>>::iterator it = patternList.begin();
                for (; it != patternList.end(); it++)
                {
                    if (printFrequentPatterns(flog, (*it).second, item))
                    {
                        flog << (*iter).first << endl; // frequency
                        flag_print = true;
                    }
                }
            }
        }
        cur_node = cur_node->getNext();
    }
    return flag_print;
}