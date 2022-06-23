#include<bits/stdc++.h>
using namespace std;

bool CycleDetect(int node,vector<int>adj[],int v, vector<int>&dfsvis,vector<int>&vis){
    vis[node]=1;
    dfsvis[node]=1;
   for (auto it:adj[node])
   {
    if(vis[it]==0)
    {
        if(CycleDetect(it,adj,v,dfsvis,vis))return true;
       
    }
     else if(dfsvis[it]==1)return true;
   }
    dfsvis[node]=0;
    return false;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<int>adj[v];
    for (int i = 0; i < e; i++)
    {
        int u,v1;
        cin>>u>>v1;
        adj[u].push_back(v1);
    }
     vector<int>dfsvis(v,0);
     vector<int>vis(v,0);
    bool flag=false;
    for (int i = 0; i < v; i++)
    {
     if(vis[i]==0)
     flag=CycleDetect(i,adj,v,dfsvis,vis);
     if(flag)break;   
    }
    
    if(flag){
        cout<<"Cycle Exist"<<endl;
    }
    else cout<<"No cycle"<<endl;
}