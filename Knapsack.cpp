#include <iostream>
#include <vector>
using namespace std;
class Item
{
public:
  int value;
  int weight;

  Item(int value, int weight)
  {
    this->value = value;
    this->weight = weight;
  }
  void print()
  {
    cout << "Value : " << value << " | Weight: " << weight << endl;
  }
};
class knapsack
{
  vector<Item> lists;

public:
  void additems(Item q);
  void printitems();
  int knapsack_func(int maxwt);
  void sort();
};

void knapsack::sort()
{
  int n = lists.size();
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      double a = lists[j].value / lists[j].weight;
      double b = lists[j + 1].value / lists[j + 1].weight;
      if (a < b)
      {
        Item temp = lists[j];
        lists[j] = lists[j + 1];
        lists[j + 1] = temp;
      }
    }
  }
}
int knapsack::knapsack_func(int maxwt)
{
  int n = lists.size();
  int curweight = 0, findvalue = 0;
  sort();
  for (int i = 0; i < n; i++) // iterate through all the items
  {
    if (curweight + lists[i].weight <= maxwt) // check it the elements can be added without exceeding max capacity
    {
      curweight += lists[i].weight;
      findvalue += lists[i].value;
    } 
    else
    {
      int remain = maxwt - curweight; // it it does we check remaining weight and fraction of the current item into the knapsack
      findvalue += lists[i].value * ((double)remain / lists[i].weight);
      break;
    }
  }
  return findvalue;
}
void knapsack::additems(Item q)
{
  lists.push_back(q);
}
void knapsack::printitems()
{
  for (int q = 0; q < lists.size(); q++)
  {
    lists[q].print();
  }
}
int main()
{
  int max_weight, n, x, y;
  knapsack z;
  cout << "Enter the number of items" << endl;
  cin >> n;
  cout << "Enter the element with the respective weight" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Value: ";
    cin >> x;
    cout << "Weight: ";
    cin >> y;
    Item q(x, y);
    z.additems(q);
  }
  z.printitems();
  cout << "Enter the max capacity" << endl;
  cin >> max_weight;
  cout << "The maximum value we can obtain is " << z.knapsack_func(max_weight);
  return 0;
}
