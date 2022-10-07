#include "ImageDataQueue.h"

void ImageDataQueue::enqueue(ImageData* p_node)
{
    if (front == nullptr)
    {
        front = p_node;
        rear = p_node;
    }
    else
    {
        rear->link = p_node;
        rear = p_node;
    }
    return;
}

ImageData *ImageDataQueue::dequeue()
{
    ImageData *del_node = front;
    if (front == rear)
    {
        front = nullptr;
        rear = nullptr;
    }
    else
        front = del_node->link;
    
    return del_node;
}