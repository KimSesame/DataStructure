#include "Manager.h"

void Manager::LOAD()
{
    string line;
    string item;

    fstream fin("C:/Users/kimbs/repos/Assignments/DataStructure/Project2/market.txt", ios::in);

    if (!fin.is_open() || fpgrowth->getHeaderTable()->getindexTable().size() > 0)
    {
        flog << "========LOAD========" << endl;
        flog << "ERROR " << ErrorCode::LOAD_ERR << endl;
        flog << "====================" << endl;
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

        flog << "========LOAD========" << endl;
        flog << "SUCCESS" << endl;
        flog << "====================" << endl;
    }

    fin.close();
    return;
}

void Manager::PRINT_ITEMLIST()
{
    flog << "========PRINT_ITEMLIST========" << endl;
    if (!fpgrowth->printList(flog))
        flog << "ERROR " << ErrorCode::PRINT_ITEMLIST_ERR << endl;
    flog << "==============================" << endl;

    return;
}