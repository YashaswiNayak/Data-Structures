#include <iostream>
#include <list>
using namespace std;
class graph
{
    list<int> adj[10];
    int v, e;

public:
    graph(int v, int e)
    {
        this->v = v;
        this->e = e;
    }
    void create_graph(int, int);
    void print();
    bool cycle(int, int, bool[]);
    bool hascycle();
};

bool graph::hascycle()
{
    bool visited[10];
    for (int i = 0; i < 10; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; ++i)
    {
        if (!visited[i])
        {
            if (cycle(i, -1, visited))
            {
                return true;
            }
        }
    }
    return false;
}
bool graph::cycle(int V, int par, bool visited[])
{
    visited[V] = true;
    for (int u : adj[V])
    {
        if (!visited[u])
        {
            if (cycle(u, V, visited))
            {
                return true;
            }
        }
        else if (u != par)
        {
            return true;
        }
    }
    return false;
}
void graph::create_graph(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
    cout << "Edge created" << endl;
}
void graph ::print()
{

    for (int i = 0; i < v; i++)
    {
        adj[i].sort();
        cout << i << "-->";
        for (int w : adj[i])
        {
            cout << w << " ";
        }
        cout << endl;
    }
}
int main()
{
    int v;
    cout << "Enter the number of vertices" << endl;
    cin >> v;
    cout << "Enter the number of edges" << endl;
    int e;
    cin >> e;
    graph q(v, e);
    int source, destination;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter source" << endl;
        cin >> source;
        cout << "Enter destination" << endl;
        cin >> destination;
        q.create_graph(source, destination);
    }
    q.print();

    if (q.hascycle())
    {
        cout << "Cycle found" << endl;
    }
    else
    {
        cout << "Cycle not found" << endl;
    }
}