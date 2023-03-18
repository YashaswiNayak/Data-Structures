#include <iostream>
using namespace std;
int partition(int a[], int p, int q, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r ; j++)
    {
        if (a[j] <= x)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    return i+1;
}
void quicksort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, q, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
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
    quicksort(a,0,n-1);
    cout<<"Sorted array is"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}