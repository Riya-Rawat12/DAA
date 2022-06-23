#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[],bool visited[],int u)
{
    visited[u]=true;
    cout<<u<<" ";

    for(auto it:adj[u])
    {
        if(!visited[it])
        dfs(adj,visited,it);
    }
}

int main()
{
    int n,e;
    cout<<"Enter the no. of nodes and vertices";
    cin>>n>>e;
    bool visited[n];
    vector <int> adj[n];
    int x,y;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter x and y:";
        cin>>x>>y;
        addedge(adj,x,y);
    }

    cout<<"DFS traversal is:";
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        dfs(adj,visited,i);
    }
    return 0;
}