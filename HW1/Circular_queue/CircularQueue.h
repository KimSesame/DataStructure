#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
class CircularQueue
{
private:
    T *queue;     // array for queue elements
    int front;    // position of front element
    int rear;     // position of rear element
    int capacity; // capacity of queue array

public:
    CircularQueue(int capacity);
    ~CircularQueue() { delete[] queue; }
    bool IsEmpty() const;
    void Print() const; // need modification case of queue expansion
    T &Front() const;
    T &Rear() const;
    void Push(const T &item);   // need modification case of queue expansion
    T &Pop();
};

template <typename T>
void ChangeSize1D(T *&a, const int oldSize, const int newSize);

#include "CircularQueue.hpp"
#endif