#include "ImageDataStack.h"

void ImageDataStack::push(ImageData *p_node)
{
    p_node->link = top;
    top = p_node;
}

ImageData *ImageDataStack::pop()
{
    if (top == nullptr)
        return nullptr;

    ImageData *del_node = top;
    top = del_node->link;

    return del_node;
}