#include "ListManager.h"
#include "Error.h"
#include <fstream>

void ListManager::load() // TODO: Loaded_List MAX size 100
{
    ListNode *cur_node;

    std::string unique_number;
    std::string image_title;

    std::fstream csv("Project1\\img_files\\filesnumbers.csv", std::ios::in); // Open the csv file
    csv.seekp(3, std::ios::beg);                                             // Skip the BOM

    if (csv.is_open())
    {
        list.insert("img_files");
        std::cout << "========LOAD========" << std::endl;
        while (std::getline(csv, unique_number, ',')) // EOF if cannot extract unqiue_number
        {
            // Extract data from csv file
            std::getline(csv, image_title, '\n');
            image_title = image_title.substr(0, image_title.find(".RAW"));

            // Print data
            std::cout << image_title << "/" << unique_number << std::endl;

            // Insert data to linked list
            list.insert("img_files", image_title, atoi(unique_number.c_str()));
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

void ListManager::add(std::string dir_name, std::string file_name) // TODO: Loaded_List MAX size 100
{
}