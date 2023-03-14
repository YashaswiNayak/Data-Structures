#include <iostream>
#include <list>
#include <queue>
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
    void bfs(int, bool[]);
};
void graph::bfs(int s, bool visited[])
{
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (int w : adj[u])
        {
            if (!visited[w])
            {
                visited[w] = true;
                q.push(w);
            }
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
    bool visited[10], visited2[10];
    for (int i = 0; i < 10; i++)
    {
        visited[i] = false;
    }
    int s;
    cout << "Enter the source" << endl;
    cin >> s;

    cout << "\ndfs traversal via recursion" << endl;
    q.bfs(s, visited);

    return 0;
}