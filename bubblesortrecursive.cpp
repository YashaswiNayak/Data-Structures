#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubblesort(int *a, int n)
{
    int count = 0;
    if (n == 1)
        return;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
            count++;//for efficiency it will check if swapping has happened. If it didnt it means the array is already sorted
        }
    }
    if (count = 0)
        return;
    bubblesort(a,n-1);
}
int main()
{
    int a[100], n;
    cout << "Enter the size of teh array" << endl;
    cin >> n;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bubblesort(a, n);
    cout << "The sorted array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}