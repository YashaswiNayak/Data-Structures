#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
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
    
    cout << "The sorted array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}