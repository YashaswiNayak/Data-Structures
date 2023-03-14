#include <iostream>
using namespace std;
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;

}
void selectionsort(int *p, int n)
{
   
    int i,j;
   for(i=0;i<n-1;i++)
   {
      int min=i;
      for(j=i+1;j<n;j++)
      {
        if(p[j]<p[min])
        {
           min=j;
        }
        swap(p[min],p[i]);
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
    selectionsort(a, n);
    cout << "The sorted array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

}