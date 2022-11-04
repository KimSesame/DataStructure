#include "Manager.h"

void Manager::LOAD()
{
    string line;
    string item;

    fstream fin("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/market.txt", ios::in);
    fstream fout("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/log.txt", ios::out | ios::app);

    if (!fin.is_open() || fpgrowth->getHeaderTable()->getindexTable().size() > 0)
    {
        fout << "========LOAD========" << endl;
        fout << "ERROR " << ErrorCode::LOAD_ERR << endl;
        fout << "====================" << endl;
        return;
    }
    else
    {
        while (getline(fin, line))
        {
            while (!line.empty())
            {
                item = line.substr(0, line.find_first_of('\t'));
                line.erase(0, item.size() + 1);

                fpgrowth->createTable(item);
            }
        }

        fout << "========LOAD========" << endl;
        fout << "SUCCESS" << endl;
        fout << "====================" << endl;
    }

    fin.close();
    fout.close();
    return;
}

void Manager::PRINT_ITEMLIST() const
{
    fstream fout("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/log.txt", ios::out | ios::app);

    fout << "========PRINT_ITEMLIST========" << endl;
    if (!fpgrowth->printList())
        fout << "ERROR " << ErrorCode::PRINT_ITEMLIST_ERR << endl;
    fout << "==============================" << endl;

    fout.close();
    return;
}