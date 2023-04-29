#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct item
{
    int weight;
    int value;
};
int knapsack_backtrack(vector<item> &items, int capacity, int n, int currweight, int currvalue, vector<bool> &visited)
{
    if (n == items.size() || currweight == capacity)
        return currvalue;
    if (items[n].weight > capacity - currweight)
    {
        return knapsack_backtrack(items, capacity, n + 1, currweight, currvalue, visited);
    }
    visited[n] = true;
    int value_with = knapsack_backtrack(items, capacity, n + 1, currweight + items[n].weight, currvalue + items[n].value, visited);
    int value_without = knapsack_backtrack(items, capacity, n + 1, currweight, currvalue, visited);
    visited[n] = false;
    return max(value_with, value_without);
}
int knapsack(int capacity, vector<item> &items)
{
    int n = 0;
    vector<bool> visited(items.size(), false);
    return knapsack_backtrack(items, capacity, n, 0, 0, visited);
}
int main()
{
    vector<item> items = {
        {2, 20},
        {5, 30},
        {10, 50},
        {5, 10}};

    int x = knapsack(16, items);
    cout << "Max value is: " << x;
}