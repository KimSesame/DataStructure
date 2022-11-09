#include "FPNode.h"

FPNode *FPNode::getChildrenNode(string item)
{
    map<string, FPNode *>::iterator iter = children.find(item);
    if (iter == children.end())
        return nullptr;
    FPNode *findNode = iter->second;
    return findNode;
}
