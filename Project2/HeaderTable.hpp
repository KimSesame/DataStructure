#include "HeaderTable.h"

HeaderTable::~HeaderTable()
{
}

void HeaderTable::insertTable(string item)
{
    list<pair<int, string>>::iterator iter = indexTable.begin();
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

int HeaderTable::find_frequency(string item)
{
    list<pair<int, string>>::iterator iter = indexTable.begin();
    for (; iter != indexTable.end(); iter++)
    {
        if((*iter).second == item)
            return (*iter).first;
    }
    return 0;
}
