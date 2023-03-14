#include <iostream>
#include <list>
#include <stack>
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
    void dfsrecursive(int, bool[]);
    int mothervertex();
};
int graph::mothervertex()
{
    bool visited[10];
    for (int i = 0; i < 10; i++)
    {
        visited[i] = false;
    }
    int last = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfsrecursive(i, visited);
            last = i;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        visited[i] = false;
    }
    dfsrecursive(last, visited);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            return -1;
        }
    }
    return last;
}
void graph::dfsrecursive(int s, bool visited[])
{
    visited[s] = true;
    for (int w : adj[s])
    {
        if (!visited[w])
        {
            dfsrecursive(w, visited);
        }
    }
}

void graph::create_graph(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
    cout << "Edge created" << endl;
}
void graph::print()
{
    list<int>::iterator q;
    for (int i = 0; i < v; i++)
    {
        adj[i].sort();
        cout << i << "-->";
        for (q = adj[i].begin(); q != adj[i].end(); q++)
        {
            cout << " " << *q;
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
    int mother = q.mothervertex();
    if (mother == -1)
    {
        cout << "There is no mother vertex" << endl;
    }
    else
    {
        cout << "The mother vertex is " << mother;
    }
    return 0;
}
