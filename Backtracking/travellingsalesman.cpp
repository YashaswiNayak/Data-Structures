#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
void tspbacktrack(vector<vector<int>> &graph, vector<int> &tour, vector<bool> &visited, int cost, int curr_city, int n, int &min_cost)
{
    if (curr_city == n)
    {
        min_cost = min(min_cost, cost + graph[tour[curr_city - 1]][tour[0]]);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            tour[curr_city] = i;
            tspbacktrack(graph, tour, visited, cost + graph[tour[curr_city - 1]][tour[curr_city]], curr_city + 1, n, min_cost);
            tour[curr_city] = -1;
            visited[i] = false;
        }
    }
}
int tsp(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> tour(n, -1);
    visited[start] = true;
    tour[0] = start;
    int min_cost = INT_MAX;
    tspbacktrack(graph, tour, visited, 0, 1, n, min_cost);
    return min_cost;
}

int main()
{
    vector<vector<int>> graph{
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0},
    };
    int min_cost = tsp(graph, 0);
    cout << "The minimum cost required is " << min_cost << endl;
    return 0;
}