#include <iostream>
using namespace std;
void bubblesort(int *p, int n)
{
    int flag=1;
    for (int i = 0; i < n; i++)
    {
        if(p[i]>p[i+1]){

           flag=0;
           break;
        }
    }
    if(flag==1){
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;
            }
        }
    }
    
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
        cout << a[i]<<endl;
    }
}