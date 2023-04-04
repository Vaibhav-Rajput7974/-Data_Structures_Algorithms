#include<bits/stdc++.h>
using namespace std;
bool iscycle(int src,vector<vector<int> > &adj,vector<bool> visted,int parent)
{
    visted[src]=true;
    for(auto i:adj[src])
    {
        if(i != parent)
        {
            if(visted[i])
            {
                return true;
            }
            if(!visted[i] and iscycle(i,adj,visted,src))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m;cin>>n>>m;
    int u,v;
    vector<vector<int> > adj(n);
    vector<bool> visted(n,false);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle=false;
    for(int i=0;i<n;i++)
    {
        if(!visted[i] && iscycle(i,adj,visted,-1))
        {
            cycle=true;
        }
    }
    if(cycle)
    {
        cout<<"Cycle is present";
    }
    else
    {
        cout<<"Cycle is not present";
    }
} 
