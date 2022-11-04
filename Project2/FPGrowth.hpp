#include "FPGrowth.h"

FPGrowth::FPGrowth()
{
    table = new HeaderTable;
}

bool FPGrowth::printList(fstream& flog)
{
    list<pair<int, string>> indexTable = table->getindexTable();
    list<pair<int, string>>::iterator iter = indexTable.begin();

    // EMPTY
    if (indexTable.size() == 0)
        return false;

    // Print
    indexTable.sort(greater<pair<int, string>>());
    flog << "Item\tFrequency" << endl;
    for (; iter != indexTable.end(); iter++)
        flog << (*iter).second << " " << (*iter).first << endl;

    return true;
}