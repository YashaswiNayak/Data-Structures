#include <iostream>
using namespace std;
int  binsearch(int a[], int low, int high,int x)
{
    if(low<=high){
        int mid=(low+high)/2;
        if(x==a[mid]){
            return 1;
        }
        else if(x<a[mid]){
            binsearch(a,low,mid-1,x);
        }
        else if(x>a[mid])
        {
            binsearch(a,mid+1,high,x);
        }
    }
    
return -1;
}
int main()
{
    int a[100];
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cout << "Enter the element to be searched" << endl;
    cin >> x;
    int low=0;
    int high=n-1;
    int val=binsearch(a,low,high,x);
    if(val==1)
    {
        cout<<"Element found"<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }


    
}
