#include <bits/stdc++.h>
using namespace std;



 int solution(int sol, int i,int n,int sum,int coins[]){

    if(n == 0 || sol > sum || i>=n)

        return 0;

    else if(sol == sum)

        return 1;

      return solution(sol+coins[i],i,n,sum,coins) + solution(sol,i+1,n,sum,coins) ;

}

int main()

{
    int n;

    cout<<"Enter total no. of coins:";
    cin>>n;
    int coins[n];

    int sum ;

    cout<<"Enter the value of coins:";
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }

    cout<<"Enter the sum :";
    cin>>sum;


    printf("Total solutions: %d",solution(0,0,n,sum,coins));

    return 0;

}