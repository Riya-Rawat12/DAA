#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int arr[n];
    cout<<" Enter the array's element:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int min=INT_MIN;
    for(int i=0;i<n;i++)
    {
        min=max(min,arr[i]);
    }

    int f[min+1]={0};
    for(int i=0;i<n;i++)
    {
            f[arr[i]]++;
    }
    int j=0;
    for(int i=0;i<=min;i++)
    {
       // cout<<f[i]<<" ";
        if(f[i]>n/2)
        {
            cout<<"Element is present :"<<i;
            j++;

        }
    }
    if(j==0)
    {
        cout<<"No such element is present";
    }
}