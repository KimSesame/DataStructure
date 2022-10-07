#pragma once

#include "ImageDataStack.h"

class ImageDataQueue
{
    friend class Manager;

private:
    ImageData *front;
    ImageData *rear;

public:
    ImageDataQueue() : front(nullptr), rear(nullptr) {}

    bool is_empty() const { return front == nullptr; }
    void enqueue(ImageData *p_node);
    ImageData *dequeue();
};

#include "ImageDataQueue.hpp"