#pragma once

#include <iostream>
#include <fstream>

typedef enum _ErrorCode
{
    LOAD_ERR = 100,
    ADD_ERR = 200,
    MODIFY_ERR = 300,
    MOVE_ERR = 400,
    PRINT_ERR = 500,
    SEARCH_ERR = 600,
    SELECT_ERR = 700,
    EDIT_ERR = 800,
    UNDEFINED_ERR = 777
} ErrorCode;

void print_error(ErrorCode code);

void print_error(ErrorCode code)
{
    std::fstream out("C:/Users/kimbs/repos/Assignments/DataStructure/Project1/log.txt", std::ios::out | std::ios::app);

    out << "========ERROR=======\n";
    out << code << std::endl;
    out << "====================\n";

    out.close();
    return;
}