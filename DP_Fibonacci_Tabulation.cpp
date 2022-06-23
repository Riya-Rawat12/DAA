#include<iostream>
using namespace std;

int fib(int n)
{
    int x=0,y=1,curr;
    for(int i=2;i<=n;i++)
    {
        curr=x+y;
        x=y;
        y=curr;
    }
    return curr;
}

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"Answer:"<<fib(n);
}