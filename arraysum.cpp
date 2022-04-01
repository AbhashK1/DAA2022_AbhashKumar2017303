#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter Size of array: ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(arr[i]+arr[j]==arr[k])
                    cout<<"["<<arr[i]<<","<<arr[j]<<","<<arr[k]<<"]"<<endl;
            }
        }
    }
}