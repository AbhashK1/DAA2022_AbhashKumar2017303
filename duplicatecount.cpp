#include<iostream>
using namespace std;
int count(int arr[],int n,int key,bool flag)
{
    int mid=0;
    int l=0;
    int u=n-1;
    int c=-1;
    while(l<=u)
    {
        mid=(l+u)/2;
        if(key<arr[mid])
        u=mid-1;
        else if(key>arr[mid])
        l=mid+1;
        else 
        {
            c=mid;
            if(flag)
            {
                u=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
    }
    return c;
}
int search(int arr[],int n,int key)
{
    int left=count(arr,n,key,true);
    if(left<0)
        return 0;
    int right=count(arr,n,key,false);
    return right-left+1;
}

int main()
{
    cout<<"Enter Size of array";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter Key";
    int key;
    cin>>key;
    int y=search(arr,n,key);
    cout<<"Frequency: "<<y;
}