#include <iostream>
using namespace std;
void ranksort(int a[], int n)
{
    int rank;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        rank = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] < a[i])
            {
                rank++;
            }
        }
        b[rank] = a[i];
    }
    for (int z = 0; z < n; z++)
    {
        cout << b[z] << " ";
    }
}
int main()
{
    int a[10];
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ranksort(a,n);
}