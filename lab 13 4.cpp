
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V = 9;

vector<int> adj[9];

// Function to add edges
void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// BFS function
void BFS(int start)
{
    bool visited[9] = {false};

    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for (int i = 0; i < adj[curr].size(); i++)
        {
            int neighbor = adj[curr][i];

            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// DFS function
void DFS(int curr, bool visited[])
{
    visited[curr] = true;

    cout << curr << " ";

    for (int i = 0; i < adj[curr].size(); i++)
    {
        int neighbor = adj[curr][i];

        if (!visited[neighbor])
        {
            DFS(neighbor, visited);
        }
    }
}

int main()
{
    // Add graph connections
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);
    addEdge(3, 7);
    addEdge(4, 7);
    addEdge(5, 8);
    addEdge(6, 8);

    // Start BFS from vertex 0
    BFS(0);

    cout << endl;

    // Initially, all vertices are not visited
    bool visited[9] = {false};

    cout << "DFS: ";

    // Start DFS from vertex 0
    DFS(0, visited);

    return 0;
}
