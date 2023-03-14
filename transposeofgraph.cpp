#include <iostream>
#include <list>
#include <stack>
using namespace std;
class graph
{
    list<int> adj[10];
    int v, e;

public:
    graph(int v)
    {
        this->v = v;
    }
    void create_graph(int, int);
    void print();
    graph gettranspose();
};
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
graph graph::gettranspose()
{
    list<int>::iterator q;
    graph g(v);
    for (int i = 0; i < v; i++)
    {
        for (q = adj[i].begin(); q != adj[i].end(); q++)
        {
            g.adj[*q].push_back(i);
        }
    }
    return g;
}
int main()
{
    int v, e;
    cout << "Enter the number of vertices" << endl;
    cin >> v;
    cout << "Enter the number edges" << endl;
    cin >> e;
    graph q(v);
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
    graph qt = q.gettranspose();
    cout << "The transpose of the graph is " << endl;
    qt.print();
    return 0;
}