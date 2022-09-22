#pragma once

#include <iostream>

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
    std::cout << "========ERROR=======" << std::endl;
    std::cout << code << std::endl;
    std::cout << "====================" << std::endl;

    return;
}