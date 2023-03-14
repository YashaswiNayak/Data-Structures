#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
using namespace std;
int inf = INT_MAX;
class sets
{
public:
    int u, w;
};
class graph
{
    list<sets> adj[100];
    int v;

public:
    graph(int v)
    {
        this->v = v;
    }
    void add(sets x, sets y)
    {
        adj[x.u].push_back(y);
        adj[y.u].push_back(x);
    }
    void print()
    {
        list<sets>::iterator q;
        for (int i = 0; i < v; i++)
        {
            cout << i << "--> ";
            adj[i].sort();
            for (q = adj[i].begin(); q != adj[i].end(); ++q)
            {
                cout << q->u << " ";
            }
            cout << endl;
        }
    }
    vector<int> dijkstras(int s)
    {
        vector<int> dist;
        dist.resize(v, inf);
        dist[s] = 0;
        vector<bool> visited(v, false);
        for (int i = 0; i < v; i++)
        {
            int x = findmin(dist, visited);
            visited[x] = true;
            list<sets>::iterator q;
            for (q = adj[x].begin(); q != adj[x].end(); ++q)
            {
                if (!visited[q->u] && dist[x] + q->w < dist[q->u] && dist[x] != inf)
                {
                    dist[q->u] = dist[x] + q->w;
                }
            }
        }
        return dist;
    }
    int findmin(vector<int> &dist, vector<bool> &visited)
    {
        int min = inf;
        int min_vertex = -1;
        for (int i = 0; i < dist.size(); i++)
        {
            if (min > dist[i] && !visited[i])
            {
                min = dist[i];
                min_vertex = i;
            }
        }
        return min_vertex;
    }
};

int main()
{
    int v;
    cout << "Enter the number of vertices" << endl;
    cin >> v;
    graph q(v);
    cout << "Enter the number of edges" << endl;
    int e, weight;
    cin >> e;
    sets s, d;
    for (int i = 0; i < e; i++)
    {
        cout << "Source: " << endl;
        cin >> s.u;
        cout << "Destination: " << endl;
        cin >> d.u;
        cout << "Weight:" << endl;
        cin >> weight;
        d.w = weight;
        s.w = weight;
        q.add(s, d);
    }
    q.print();
    cout << endl;
    int source;
    cout << "Enter the source" << endl;
    cin >> source;
    vector<int> dist = q.dijkstras(source);
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " --> " << dist[i] << endl;
    }
    return 0;
}