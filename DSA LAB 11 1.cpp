#include <iostream>
using namespace std;

#define SIZE 6

int queue[SIZE];
int front = -1, rear = -1;

void enqueue()
{
    int token;

    if (rear == SIZE - 1)
    {
        cout << "Waiting room is full!" << endl;
    }
    else
    {
        cout << "Enter token number: ";
        cin >> token;

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = token;

        cout << "Token issued successfully!" << endl;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "No customer is waiting!" << endl;
    }
    else
    {
        cout << "Serving token: " << queue[front] << endl;
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void display()
{
    if (front == -1)
    {
        cout << "No waiting customers!" << endl;
    }
    else
    {
        cout << "Waiting customers: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Issue Token";
        cout << "\n2. Serve Customer";
        cout << "\n3. Show Waiting Customers";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended.";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}