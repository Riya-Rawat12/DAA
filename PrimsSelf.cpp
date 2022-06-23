#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    cout<<"Enter the no. of nodes and edges:";
    cin>>N>>M;

    vector<pair<int,int>>adj[N];

    int x,y,wt;
    for(int i=0;i<M;i++)
    {
        cout<<"Enter the value of x and y and weight:";
        cin>>x>>y>>wt;
        adj[x].push_back(make_pair(y,wt));
        adj[y].push_back(make_pair(x,wt));
    }

    int key[N];
    int parent[N];
    bool mst[N];
    
    for(int i=0;i<N;i++)
    {
        key[i]=INT_MAX,mst[i]=false;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    key[0]=0;
    parent[0]=-1;
    pq.push({0,0});

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        mst[u]=true;

        for(auto it:adj[u])
        {
            int v=it.first;
            int weight=it.second;
            if(mst[v]==false && weight<key[v])
            {
                parent[v]=u;
                key[v]=weight;
                pq.push({key[v],v});
            }
        }
    }

    for(int i=1;i<N;i++)
    {
        cout<<parent[i]<<" - "<<i<<"\n" ;
    }

    return 0;


}