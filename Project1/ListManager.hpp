#include "ListManager.h"
#include "Error.h"
#include <fstream>

void ListManager::load()
{
    ListNode *cur_node;

    std::string unique_number;
    std::string image_title;

    std::fstream csv("Project1\\img_files\\filesnumbers.csv", std::ios::in); // Open the csv file
    csv.seekp(3, std::ios::beg);                                             // Skip the BOM

    cur_node = list.dir_node;

    if (csv.is_open())
    {
        std::cout << "========LOAD========" << std::endl;
        while (std::getline(csv, unique_number, ','))   // EOF if cannot extract unqiue_number
        {
            // Extract data from csv file
            std::getline(csv, image_title, '\n');
            image_title = image_title.substr(0, image_title.find(".RAW"));

            // last line is blank (NOT data)
            if (!unique_number.compare("\n"))
                break;

            // Print data
            std::cout << image_title << "/" << unique_number << std::endl;

            // Move data to linked list
            cur_node->next_img = new ListNode("img_files", image_title, atoi(unique_number.c_str()));

            cur_node = cur_node->next_img;
        }
        csv.close();
    }
    else
    {
        std::cout << "========ERROR=======" << std::endl;
        std::cout << ErrorCode::LOAD_ERR << std::endl;
    }
    std::cout << "====================" << std::endl;

    return;
}