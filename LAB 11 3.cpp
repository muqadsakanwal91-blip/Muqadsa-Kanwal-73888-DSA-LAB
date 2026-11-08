#include <iostream>
using namespace std;

#define SIZE 4

int queue[SIZE];
int front = -1;
int rear = -1;
int count = 0;

void enqueue(int value)
{
    if (count == SIZE)
    {
        cout << "Printer queue is full!" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        count++;

        cout << value << " added." << endl;
    }
}

void dequeue()
{
    if (count == 0)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << queue[front] << " removed." << endl;

        if (count == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }

        count--;
    }
}

void display()
{
    if (count == 0)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << queue[(front + i) % SIZE] << " ";
    }

    cout << endl;
}

int main()
{
    enqueue(101);
    enqueue(102);
    enqueue(103);
    enqueue(104);
    enqueue(105);

    dequeue();
    dequeue();

    enqueue(105);
    enqueue(106);

    cout << "\nPrinter Jobs: ";
    display();

    cout << "Front: " << front << endl;
    cout << "Rear: " << rear << endl;
    cout << "Count: " << count << endl;

    return 0;
}