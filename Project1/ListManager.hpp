#include "ListManager.h"
#include <fstream>

void ListManager::load()
{
    ListNode *cur_node;

    std::string unique_number;
    std::string image_title;

    std::fstream csv("Project1\\img_files\\filesnumbers.csv", std::ios::in); // Open the csv file
    csv.seekp(3, std::ios::beg);                                             // Skip the BOM

    cur_node = list.dir_node;

    while (!csv.eof())
    {
        // Extract data from csv file
        std::getline(csv, unique_number, ',');
        std::getline(csv, image_title, '\n');
        image_title = image_title.substr(0, image_title.find(".RAW"));

        // std::cout << unique_number << ": " << image_title << std::endl; // test
        //static int i = 0;              // test
        //std::cout << ++i << std::endl; // test

        // Move data to linked list
        cur_node->next_img = new ListNode("img_files", image_title, atoi(unique_number.c_str()));

        cur_node = cur_node->next_img;
    }
    csv.close();

    return;
}