#include<bits/stdc++.h>
using namespace std;
float fractional(int profit[], int weight[], int n , int Bag_Size)
{
          vector<pair<float , int>>v;
          int W=0;
          float p=0;
          float ratio;
          for(int i=0;i<n;i++)
          {
               ratio= float(profit[i])/weight[i];
               v.push_back({ratio,i});
          }
          sort(v.begin(),v.end());
         
          int i=n-1;
          while(W<=Bag_Size)
          {
              W=W+weight[v[i].second];
        
              if(W>Bag_Size)
              {
                  W=W-weight[v[i].second];
                  break;
              }
               p=p+profit[v[i].second];
              i--;
              
          }
          if(W==Bag_Size)
          {
              return p;
          }
          else
          {
              int z=Bag_Size-W;
             // p=p+ float(profit[v[i].second]*z)/weight[v[i].second];
             p=p+ (z*v[i].first);
          }
          return p;
}

int main()
{    
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    int profit[n];
    int weight[n];
    cout<<"Enter the profit:"; 
    for(int i=0;i<n;i++)
    {
        cin>>profit[i];
    }
    cout<<"Enter the weight:";
     for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    float ans;
    int Bag_Size;
    cout<<"Enter the bag size:";
    cin>>Bag_Size;
    cout<<endl;
    ans=fractional(profit,weight,n,Bag_Size);
    cout<<"The profit is:"<<ans;
    return 0;

}