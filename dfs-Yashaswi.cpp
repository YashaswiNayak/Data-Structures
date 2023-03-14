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
};
void graph::dfsrecursive(int s, bool visited2[])
{
    visited2[s] = true;
    cout << " " << s;
    for (int w : adj[s])
    {
        if (!visited2[w])
        {
            dfsrecursive(w, visited2);
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
    bool visited1[10], visited2[10];
    for (int i = 0; i < 10; i++)
    {
        visited1[i] = false;
        visited2[i] = false;
    }
    int s;
    cout << "Enter the source" << endl;
    cin >> s;
   
    cout << "\ndfs traversal via recursion" << endl;
    q.dfsrecursive(s, visited2);

    return 0;
}