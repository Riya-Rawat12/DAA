#include<iostream>
#include<algorithm>
using namespace std;

const int MAX=1e4 + 5;
int id [MAX] ;
int nodes,edges;

pair<long long,pair<int,int>>p[MAX];

void initialize()
{
    for(int i=0;i<MAX;i++)
    {
        id[i]=i;
    }
}

int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}

void union1(int x,int y)
{
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}

long long Krushkal(pair<long long,pair<int,int>>p[])
{
    int x,y;
    long long cost,minCost=0;
    for(int i=0;i<edges;i++)
    {
        x=p[i].second.first;
        x=p[i].second.second;
        cost=p[i].second.first;

        if(root(x)!=root(y))
        {
            minCost+=cost;
            union1(x,y);
        }
    }
    return minCost;
}

int main()
{
    int x,y;
    long long weight,cost,minCost;
    initialize();
    cout<<"Enter the no. of nodes and edges:";
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        cout<<"Enter the value of x and y and the edge weight:";
        cin>>x>>y>>weight;

        p[i]=make_pair(weight,make_pair(x,y));
    }
    sort(p,p+edges);
    minCost=Krushkal(p);
    cout<<"Minimum cost is :"<<minCost;

}