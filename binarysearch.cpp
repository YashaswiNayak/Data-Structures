#include<iostream>
using namespace std;
int binsearch(int a[],int n,int x)
{
    int low=0;
    int high=n-1;
   while(low<=high)
    {
        int mid=(low+high)/2;
        if(x==a[mid])
        {
            
            return mid+1;
            break;
        }
        else if(x>a[mid])
        {
            low=mid+1;
        }
        else if(x<a[mid])
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
   int a[100];
   int n;
   cout<<"Enter the size of the array"<<endl;
    cin>>n;
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x;
    cout<<"Enter the element to be searched"<<endl;
    cin>>x;
    int pos=binsearch(a,n,x);
    if(pos==-1)
    {
        cout<<"Element not found "<<endl;
    }
    else
    {
        cout<<"Element found "<<pos<<endl;
    }
    
}