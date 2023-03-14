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
    void dfs(int s, stack<int>&, bool[]);
    void toposort();
};
void graph::toposort()
{
    bool visited[10] = {false};
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, s, visited);
        }
    }
    int x;
    while (!s.empty())
    {
        x = s.top();
        cout << x << " ";
        s.pop();
    }
}
void graph::dfs(int x, stack<int>& s, bool visited[])
{
    for (int i : adj[v])
    {
        if (!visited[i])
        {
            dfs(i, s, visited);
        }
    }
    s.push(x);
}
void graph::create_graph(int x, int y)
{
    adj[x].push_back(y);
}
void graph::print()
{
    for (int i = 0; i < v; i++)
    {
        adj[i].sort();
        cout << i << "-->";
        for (int w : adj[i])
        {
            cout << w;
        }
        cout << endl;
    }
}
int main()
{
    int v, e;
    cout << "Enter the number of vertices" << endl;
    cin >> v;
    cout << "Enter the number of edges" << endl;
    cin >> e;
    graph q(v, e);
    int source, destination;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter the source" << endl;
        cin >> source;
        cout << "Enter the destination" << endl;
        cin >> destination;
        q.create_graph(source, destination);
    }
    q.print();
    q.toposort();
}