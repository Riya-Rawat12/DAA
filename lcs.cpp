#include<bits/stdc++.h>
using namespace std;
int lcs(string X, string Y)
{
      int n= X.size();
      int m= Y.size();

      int t[n+1][m+1];
      for(int i=0;i<n+1;i++)
      {
          for(int j=0;j<m+1;j++)
          {
              t[i][j]=0;
          }
      }

      for(int i=1;i<n+1;i++)
      {
          for(int j=1;j<m+1;j++)
          {
              if(X[i-1]==Y[j-1])
              {
                  t[i][j]= 1+t[i-1][j-1];
              }
              else
              {
                    t[i][j]= max(t[i-1][j] ,t[i][j-1] );
              }
          }
      }
      return t[n][m];
}
int main()
{
    string X, Y;
    cout<<"The string is :";
    cin>>X;
    cout<<"The string 2 is:";
    cin>>Y;

    int ans=lcs(X,Y);
    cout<<"The common is:"<<ans;
}