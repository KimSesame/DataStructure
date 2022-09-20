#include "ListManager.h"
#include <fstream>

void ListManager::load()
{
    ListNode *cur_node;

    std::string unique_number;
    std::string image_title;

    std::fstream csv("C:\\Users\\kimbs\\Documents\\repo\\Assignments\\DataStructure\\Project1\\img_files\\filesnumbers.csv", std::ios::in); // Open the csv file

    cur_node = list.dir_node;

    if (csv.is_open())
    {
        std::cout << std::string("I'm in file!") << std::endl; // test
        while (!csv.eof())
        {
            // Extract data from csv file
            std::getline(csv, unique_number, ',');
            std::getline(csv, image_title, ',');
            image_title.substr(0, image_title.find(".RAW"));

            std::cout << unique_number << ": " << image_title << std::endl; // test

            // Move data to linked list
            cur_node->next_img = new ListNode("img_files", image_title, atoi(unique_number.c_str()));

            cur_node = cur_node->next_img;
        }
        csv.close();
    }
    else
        std::cout << "File Open Fail" << std::endl; // test

    return;
}