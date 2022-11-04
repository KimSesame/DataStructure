#include "HeaderTable.h"

HeaderTable::~HeaderTable()
{
}

void HeaderTable::insertTable(string item)
{
    auto iter = indexTable.begin();
    // Inspect existence
    for (; iter != indexTable.end(); iter++)
    {
        // Already exist
        if ((*iter).second == item)
        {
            (*iter).first++;
            return;
        }
    }

    // Insert new item
    indexTable.push_back(pair<int, string>(1, item));

    return;
}