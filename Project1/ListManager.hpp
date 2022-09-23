#include "ListManager.h"
#include "Error.h"
#include <fstream>

void ListManager::load()
{
    std::string unique_number;
    std::string image_title;

    std::fstream csv("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/img_files/filesnumbers.csv", std::ios::in); // Open the csv file
    csv.seekp(3, std::ios::beg);                                                                                          // Skip the BOM

    if (csv.is_open())
    {
        list.dir_node = new ListNode("img_files");
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
        std::cout << "====================" << std::endl;
        csv.close();
    }
    else
        print_error(ErrorCode::LOAD_ERR);

    return;
}

void ListManager::add(std::string dir_name, std::string file_name)
{
    if (list.dir_node == nullptr)
    {
        print_error(ErrorCode::ADD_ERR);
        return;
    }

    ListNode *cur_dir = list.dir_node;

    std::string unique_number;
    std::string image_title;

    // Open the csv file
    std::fstream csv(std::string("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/").append(dir_name).append("/").append(file_name), std::ios::in);
    csv.seekp(3, std::ios::beg); // Skip the BOM

    if (csv.is_open())
    {
        // Make directory node
        while (cur_dir->next_dir)
            cur_dir = cur_dir->next_dir;
        cur_dir->next_dir = new ListNode(dir_name);

        while (std::getline(csv, unique_number, ',')) // EOF if cannot extract unqiue_number
        {
            // Extract data from csv file
            std::getline(csv, image_title, '\n');
            image_title = image_title.substr(0, image_title.find(".RAW"));

            // Insert data to linked list
            list.insert("img_files", image_title, atoi(unique_number.c_str()));
        }

        std::cout << "========ADD=========" << std::endl;
        std::cout << "SUCCESS" << std::endl;
        std::cout << "====================" << std::endl;
        csv.close();
    }
    else
        print_error(ErrorCode::ADD_ERR);

    return;
}