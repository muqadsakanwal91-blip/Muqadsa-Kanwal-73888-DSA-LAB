#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueue(queue<int>& q)
{
    stack<int> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Original Queue: ";

    queue<int> temp = q;

    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }

    reverseQueue(q);

    cout << "\nReversed Queue: ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}