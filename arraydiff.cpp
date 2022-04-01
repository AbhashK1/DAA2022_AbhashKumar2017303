#include<iostream>
using namespace std;
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
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(arr[i]-arr[j])==key)
            {
                cout<<"["<<arr[i]<<","<<arr[j]<<"]"<<endl;
            }
        }
    }
}