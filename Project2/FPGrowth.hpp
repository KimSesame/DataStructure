#include "FPGrowth.h"

FPGrowth::FPGrowth()
{
    table = new HeaderTable;
}

bool FPGrowth::printList() const
{
    fstream fout("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/log.txt", ios::out | ios::app);

    // EMPTY
    if (table->getindexTable().size() == 0)
        return false;

    // Print
    table->descendingIndexTable();
    fout << "Item\tFrequency" << endl;
    for (auto iter = table->getindexTable().begin(); iter != table->getindexTable().end(); iter++)
        fout << (*iter).second << " " << (*iter).first << endl;
    
    fout.close();
    return true;
}