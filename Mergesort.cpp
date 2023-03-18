#include <iostream>
using namespace std;

void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *le = new int[n1];
    int *ri = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        le[i] = a[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        ri[j] = a[q + 1 + j];
    }
    int x = 0;
    int y = 0;
    int k = p;
    for (; x < n1 && y < n2; k++)
    {
        if (le[x] <= ri[y])
        {
            a[k] = le[x];
            x++;
        }
        else
        {
            a[k] = ri[y];
            y++;
        }
    }
    while (x < n1)
    {
        a[k] = le[x];
        k++;
        x++;
    }
    while (y < n2)
    {
        a[k] = ri[y];
        k++;
        y++;
    }
    delete[] le;
    delete[] ri;
}

void merge_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array " << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    merge_sort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}