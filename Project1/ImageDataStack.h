#pragma once

class ImageData
{
    friend class ImageDataStack;
    friend class ImageDataQueue;

private:
    unsigned char data;
    ImageData *link;

public:
    ImageData(unsigned char data) : data(data), link(nullptr) {}
    unsigned char getData() const { return data; }
};

class ImageDataStack
{
    friend class Manager;

private:
    ImageData *top;

public:
    ImageDataStack() : top(nullptr) {}

    bool is_empty() const { return top == nullptr; }
    void push(ImageData *p_node);
    ImageData *pop();
};

#include "ImageDataStack.hpp"
