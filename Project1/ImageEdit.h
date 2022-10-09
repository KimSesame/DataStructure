#pragma once

#include "iostream"
#include "cstdio"
#include "cmath"
#include "ImageDataStack.h"
#include "ImageDataQueue.h"

#define HEIGHT 256
#define WIDTH 256

void copy(std::string i_route);
void flip(std::string i_route);
void light(std::string i_route, int value);
void resize(std::string i_route);

void copy(std::string i_route)
{
    unsigned char i_data[HEIGHT][WIDTH];
    unsigned char o_data[HEIGHT][WIDTH];

    std::string i_name = i_route.substr(i_route.find_last_of("/") + 1, i_route.size());
    std::string i_file = i_route + ".RAW";
    std::string o_file = "C:/Users/kimbs/repos/Assignments/DataStructure/Project1/Result/" + i_name + "_copied" + ".RAW";

    FILE *i_raw;
    FILE *o_raw;

    // Read raw file
    i_raw = fopen(i_file.c_str(), "rb");
    if (i_raw == NULL)
        return;
    fread(i_data, sizeof(unsigned char), HEIGHT * WIDTH, i_raw);

    // Copy
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            o_data[i][j] = i_data[i][j];

    // Write copied data
    o_raw = fopen(o_file.c_str(), "wb");
    fwrite(o_data, sizeof(unsigned char), HEIGHT * WIDTH, o_raw);

    fclose(i_raw);
    fclose(o_raw);
}

void flip(std::string i_route)
{
    unsigned char i_data[HEIGHT][WIDTH];
    unsigned char o_data[HEIGHT][WIDTH];
    ImageDataStack stack;

    std::string i_name = i_route.substr(i_route.find_last_of("/") + 1, i_route.size());
    std::string i_file = i_route + ".RAW";
    std::string o_file = "C:/Users/kimbs/repos/Assignments/DataStructure/Project1/Result/" + i_name + "_flipped" + ".RAW";

    FILE *i_raw;
    FILE *o_raw;

    // Read raw file
    i_raw = fopen(i_file.c_str(), "rb");
    if (i_raw == NULL)
        return;
    fread(i_data, sizeof(unsigned char), HEIGHT * WIDTH, i_raw);

    // Flip
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            stack.push(new ImageData(i_data[i][j]));

    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            o_data[i][j] = stack.pop()->getData();

    // Write flipped data
    o_raw = fopen(o_file.c_str(), "wb");
    fwrite(o_data, sizeof(unsigned char), HEIGHT * WIDTH, o_raw);

    fclose(i_raw);
    fclose(o_raw);
}

void light(std::string i_route, int value)
{
    unsigned char i_data[HEIGHT][WIDTH];
    unsigned char o_data[HEIGHT][WIDTH];
    unsigned char data;
    ImageDataQueue queue;

    std::string i_name = i_route.substr(i_route.find_last_of("/") + 1, i_route.size());
    std::string i_file = i_route + ".RAW";
    std::string o_file = "C:/Users/kimbs/repos/Assignments/DataStructure/Project1/Result/" + i_name + "_adjusted" + ".RAW";

    FILE *i_raw;
    FILE *o_raw;

    // Read raw file
    i_raw = fopen(i_file.c_str(), "rb");
    if (i_raw == NULL)
        return;
    fread(i_data, sizeof(unsigned char), HEIGHT * WIDTH, i_raw);

    // Adjust
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            queue.enqueue(new ImageData(i_data[i][j]));

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            data = queue.dequeue()->getData();
            o_data[i][j] = (data + value > 255) ? 255 : data + value;
        }
    }

    // Write adjusted data
    o_raw = fopen(o_file.c_str(), "wb");
    fwrite(o_data, sizeof(unsigned char), HEIGHT * WIDTH, o_raw);

    fclose(i_raw);
    fclose(o_raw);
}

void resize(std::string i_route)
{
    unsigned char i_data[HEIGHT][WIDTH];
    unsigned char o_data[HEIGHT / 2][WIDTH / 2];
    double total = 0; // total of near 4 pixels

    std::string i_name = i_route.substr(i_route.find_last_of("/") + 1, i_route.size());
    std::string i_file = i_route + ".RAW";
    std::string o_file = "C:/Users/kimbs/repos/Assignments/DataStructure/Project1/Result/" + i_name + "_resized" + ".RAW";

    FILE *i_raw;
    FILE *o_raw;

    // Read raw file
    i_raw = fopen(i_file.c_str(), "rb");
    if (i_raw == NULL)
        return;
    fread(i_data, sizeof(unsigned char), HEIGHT * WIDTH, i_raw);

    // Resize
    int o_i = 0, o_j = 0;
    for (int i = 0; i < HEIGHT; i += 2)
    {
        o_j = 0;
        for (int j = 0; j < WIDTH; j += 2)
        {
            total = (i_data[i][j] + i_data[i][j + 1] + i_data[i + 1][j] + i_data[i + 1][j + 1]);
            o_data[o_i][o_j++] = round(total / 4);
        }
        o_i++;
    }

    // Write resized data
    o_raw = fopen(o_file.c_str(), "wb");
    fwrite(o_data, sizeof(unsigned char), (HEIGHT / 2) * (WIDTH / 2), o_raw);

    fclose(i_raw);
    fclose(o_raw);
}