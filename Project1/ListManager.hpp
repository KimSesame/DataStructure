#include "ListManager.h"
#include "Error.h"
#include <fstream>

void ListManager::load()
{
    std::string unique_number;
    std::string image_title;

    // Open the csv file
    std::fstream csv("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/img_files/filesnumbers.csv", std::ios::in);
    csv.seekp(3, std::ios::beg); // Skip the BOM

    if (csv.is_open())
    {
        std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);

        list.dir_node = new Loaded_LIST_Node("img_files");
        out << "========LOAD========\n";
        while (std::getline(csv, unique_number, ',')) // EOF if cannot extract unqiue_number
        {
            // Extract data from csv file
            std::getline(csv, image_title, '\n');
            image_title = image_title.substr(0, image_title.find(".RAW"));

            // Print data
            out << image_title << "/" << unique_number << std::endl;

            // Insert data to linked list
            list.insert("img_files", image_title, stoi(unique_number));
        }
        out << "====================\n";
        csv.close();
        out.close();
    }
    else
        print_error(ErrorCode::LOAD_ERR);

    return;
}

void ListManager::add(std::string dir_name, std::string file_name)
{
    // Loaded_List NOT exist
    if (list.dir_node == nullptr)
    {
        print_error(ErrorCode::ADD_ERR);
        return;
    }

    Loaded_LIST_Node *cur_dir = list.dir_node;

    std::string unique_number;
    std::string image_title;

    // Open the csv file
    std::fstream csv("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/" + dir_name + "/" + file_name, std::ios::in);
    csv.seekp(3, std::ios::beg); // Skip the BOM

    if (csv.is_open())
    {
        // Make directory node
        while (cur_dir->next_dir)
            cur_dir = cur_dir->next_dir;
        cur_dir->next_dir = new Loaded_LIST_Node(dir_name);

        while (std::getline(csv, unique_number, ',')) // EOF if cannot extract unqiue_number
        {
            // Extract data from csv file
            std::getline(csv, image_title, '\n');
            image_title = image_title.substr(0, image_title.find(".RAW"));

            // Insert data to linked list
            list.insert(dir_name, image_title, stoi(unique_number));
        }
    
        std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);
        out << "========ADD=========" << std::endl;
        out << "SUCCESS" << std::endl;
        out << "====================" << std::endl;
        csv.close();
        out.close();
    }
    else
        print_error(ErrorCode::ADD_ERR);

    return;
}

void ListManager::modify(std::string dir_name, std::string img_name, int unique)
{
    // Loaded_List NOT exist
    if (list.dir_node == nullptr)
    {
        print_error(ErrorCode::MODIFY_ERR);
        return;
    }

    // Duplicated unique number
    if (list.search(unique))
    {
        print_error(ErrorCode::MODIFY_ERR);
        return;
    }

    Loaded_LIST_Node *cur_dir = nullptr;
    Loaded_LIST_Node *cur_img = nullptr;
    Loaded_LIST_Node *modified_node = nullptr;

    // Find directory
    cur_dir = list.dir_node;
    while (cur_dir)
    {
        if (cur_dir->dirname == dir_name)
            break;
        cur_dir = cur_dir->next_dir;
    }

    // Find img with file name
    if (cur_dir->dirname == dir_name)
    {
        cur_img = cur_dir;
        while (cur_img->next_img)
        {
            if (cur_img->next_img->name == img_name)
            {
                modified_node = new Loaded_LIST_Node(dir_name, img_name, unique);
                list.deletion(cur_img->next_img->unique_number);
                modified_node->next_img = cur_img->next_img;
                cur_img->next_img = modified_node;
                (list.size)++;

                std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);
                out << "=======MODIFY=======" << std::endl;
                out << "SUCCESS" << std::endl;
                out << "====================" << std::endl;
                out.close();
                return;
            }
            cur_img = cur_img->next_img;
        }
    }

    // Error if NOT found
    print_error(ErrorCode::MODIFY_ERR);
    return;
}

Loaded_LIST_Node *ListManager::getTail() const
{
    Loaded_LIST_Node *cur_dir = nullptr;
    Loaded_LIST_Node *cur_img = nullptr;

    // EMPTY LIST
    if (list.dir_node == nullptr)
        return nullptr;

    cur_dir = list.dir_node;
    while (cur_dir->next_dir)
        cur_dir = cur_dir->next_dir;
    cur_img = cur_dir;
    while (cur_img->next_img)
        cur_img = cur_img->next_img;

    return cur_img;
}