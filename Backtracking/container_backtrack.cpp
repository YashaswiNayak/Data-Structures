#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int container_backtrack(vector<int> &weights, int capacity, int currweight, int n, int num_containers, vector<bool> &visited)
{
    if (n == weights.size())
        return num_containers;
    if (weights[n] > capacity)
        return container_backtrack(weights, capacity, currweight, n + 1, num_containers, visited);
    visited[n] = true;
    int value_with = container_backtrack(weights, capacity, currweight + weights[n], n + 1, num_containers + 1, visited);
    int value_without = container_backtrack(weights, capacity, currweight, n + 1, num_containers, visited);
    visited[n] = false;
    return max(value_with, value_without);
}
int container(vector<int> &weights, int capacity)
{
    int n = 0;
    vector<bool> visited(weights.size(), false);
    return container_backtrack(weights, capacity, 0, n, 0, visited);
}
int main()
{
    vector<int> weights = {5, 8, 9, 100};
    int x = container(weights, 120);
    cout << "The number of conatiners: " << x<<endl;
}