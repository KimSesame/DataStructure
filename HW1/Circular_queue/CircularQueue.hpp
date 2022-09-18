#include "CircularQueue.h"

template <typename T>
CircularQueue<T>::CircularQueue(int capacity) : capacity(capacity), front(0), rear(0), size(0)
{
    if (capacity <= 1)
        throw "Queue capacity must be > 1";
    queue = new T[capacity];
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
    for (int i = front + 1; i <= front + size; i++)
        cout << queue[i % capacity] << " ";
    cout << endl;
    // test
    for (int i = 0; i < capacity; i++)
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

        for (int i = capacity - std::max(front, rear); i > 0; i--)
            queue[2 * capacity - i] = queue[capacity - i];

        if (front == 0)
        {
            queue[rear + capacity] = item;
            rear = 2 * capacity - (capacity - rear);
        }
        else
        {
            front = 2 * capacity - (capacity - front);
            queue[rear] = item;
        }
        capacity *= 2;
        size++;

        return;
    }

    queue[rear] = item;
    size++;

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
    size--;

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
