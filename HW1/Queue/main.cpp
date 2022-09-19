#include <iostream>
#include "Queue.h"
using namespace std;

int main(void)
{
    Queue<int> queue;
    int choice = 0;
    int data;

    do
    {
        cout << "\nEnter the number of process: " << endl;
        cout << "1: PRINT, 2: PUSH, 3: POP" << endl;
        cout << "0: EXIT" << endl;
        cout << " >> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            queue.Print();
            break;
        case 2:
            cout << "Enter the data want to push: ";
            cin >> data;
            queue.Push(data);
            break;
        case 3:
            queue.Pop();
            break;

        default:
            break;
        }
    } while (choice);

    return 0;
}