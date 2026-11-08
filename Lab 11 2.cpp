#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void display()
{
    Node* temp = front;

    if (front == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int countNodes()
{
    int count = 0;
    Node* temp = front;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void displayRear()
{
    if (rear == NULL)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Rear value: " << rear->data << endl;
    }
}

void clearQueue()
{
    Node* temp;

    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }

    rear = NULL;

    cout << "Queue cleared successfully!" << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    cout << "Queue: ";
    display();

    cout << "Total nodes: " << countNodes() << endl;

    displayRear();

    clearQueue();

    cout << "Queue after clearing: ";
    display();

    return 0;
}