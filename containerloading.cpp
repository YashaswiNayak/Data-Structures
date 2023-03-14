#include <iostream>
#include <vector>
using namespace std;
class knapsack
{
    vector<int> weight;

public:
    void add_items()
    {
        int n;
        weight.resize(n);
        cout << "Enter the number of items";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout<<"Enter the weight of "<<i<<" item"<<endl;
            cin >> weight[i];
        }
    }
    void sort();
    int knapsack01(int capacity);
};
void knapsack::sort()
{
    int temp;
    int n = weight.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (weight[j] < weight[j + 1])
            {
                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }
}
int knapsack::knapsack01(int capacity)
{
    int n = weight.size();
    sort();
    int numcontainers = 0, curweight = 0;
    for (int i = 0; i < n; i++)
    {
        if (curweight + weight[i] < capacity)
        {
            curweight += weight[i];
        }
        else
        {
            numcontainers++;
            curweight = weight[i];
        }
    }
    if (curweight > 0)
    {
        numcontainers++;
    }
    return numcontainers;
}

int main()
{
    int capacity;
    vector<int> weight;
    cout << "Enter the max capacity" << endl;
    cin >> capacity;
    knapsack z;
    z.add_items();
   cout<<"The number of conatiners is: "<< z.knapsack01(capacity);
}