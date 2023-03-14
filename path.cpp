#include <iostream>
#include <list>
#include <vector>
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
    bool path(int, int, bool[], vector<int> &);
};
bool graph::path(int s, int d, bool visited[], vector<int> &p)
{
    visited[s] = true;
    p.push_back(s);
    if (s == d)
    {
        for (int i = 0; i < p.size(); i++)
        {
            cout << p[i] << " ";
        }

        cout << endl;
        return true;
    }
    else
    {
        for (int w : adj[s])
        {
            if (!visited[w])
            {
                if (path(w, d, visited,p))
                {
                    return true;
                }
            }
        }
    }
    p.pop_back();
    visited[s]=false;
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

    bool visited[10];
    for (int i = 0; i < 10; i++)
    {
        visited[i] = false;
    }
    int s;
    cout << "Enter the source" << endl;
    cin >> s;
    cout << "Enter destination" << endl;
    int d;
    cin >> d;
    vector<int> p;
    if (q.path(s, d, visited, p) == true)
    {
        cout << "There is a path between " << s << " and " << d;
    }
    else
    {
        cout << "There is no path between " << s << " and " << d;
    }

    return 0;
}