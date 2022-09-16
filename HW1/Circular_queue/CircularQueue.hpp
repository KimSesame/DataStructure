#include <iostream>
#include <algorithm>
#include "CircularQueue.h"
using namespace std;

template <typename T>
CircularQueue<T>::CircularQueue(int capacity) : capacity(capacity)
{
    if (capacity <= 1)
        throw "Queue capacity must be > 1";
    queue = new T[capacity];
    front = 0;
    rear = 0;
}

template <typename T>
inline bool CircularQueue<T>::IsEmpty() const
{
    return front == rear;
}

template <typename T>
inline T &CircularQueue<T>::Front() const
{
    if (IsEmpty())
        throw "Queue is EMPTY";
    return queue[front];
}

template <typename T>
inline T &CircularQueue<T>::Rear() const
{
    if (IsEmpty())
        throw "Queue is EMPTY";
    return queue[rear];
}

template <typename T>
void CircularQueue<T>::Print() const
{
    for (int i = front + 1; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

template <typename T>
void CircularQueue<T>::Push(const T &item)
{
    rear = (rear + 1) % capacity; // move rear clockwise

    if (rear == front) // queue is FULL
    {
        ChangeSize1D(queue, capacity, 2 * capacity);
        capacity *= 2;
    }

    queue[rear] = item;

    return;
}

template <typename T>
T &CircularQueue<T>::Pop()
{
    if (IsEmpty())
        throw "Queue is EMPTY. Cannot delete";

    static T target;

    front = (front + 1) % capacity; // move clockwise
    target = queue[front];          // save data in target
    queue[front].~T();              // delete

    return target;
}

template <typename T>
void ChangeSize1D(T *&a, const int oldSize, const int newSize)
{
    if (newSize < 0)
        throw "New length must be >= 0";

    T *temp = new T[newSize];
    int number = std::min(oldSize, newSize);
    std::copy(a, a + number, temp);
    delete[] a;
    a = temp;

    return;
}
