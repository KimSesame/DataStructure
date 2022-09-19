#include "ListManager.h"
#include <fstream>

void ListManager::load()
{
    ListNode* cur_node;

    std::string unique_number;
    std::string image_title;

    std::fstream csv("./img_files/filesnumbers.csv", std::ios::in); // Open the csv file

    cur_node = list.dir_node;
    while (!csv.eof())
    {
        // Extract data from csv file
        std::getline(csv, unique_number, ',');
        std::getline(csv, image_title, '\n');
        image_title.substr(0, image_title.find(".RAW"));

        // Move data to linked list
        cur_node->getNextImg() = new ListNode("img_files", image_title, atoi(unique_number.c_str()));
    }

    csv.close();
    return;
}