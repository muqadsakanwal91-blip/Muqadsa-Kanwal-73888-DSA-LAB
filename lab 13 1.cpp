
#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int V;
    vector<pair<int, int>> adj[4];

public:

    Graph(int v)
    {
        V = v;
    }

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
    }

    void display()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";

            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << "(" << adj[i][j].first
                     << ", " << adj[i][j].second << ") ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(2, 3, 40);

    cout << "Directed Weighted Graph:" << endl;

    g.display();

    return 0;
}
