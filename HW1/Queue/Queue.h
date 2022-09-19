#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "Chain.h"

template <typename T>
class Queue : public Chain<T>
{
private:
    int size;

public:
    Queue() : size(0) {}
    void Push(const T &data) { this->QueuePush(data); }
    void Pop() { this->QueuePop(); }
    void Print() const { this->Print(); }
};

#endif