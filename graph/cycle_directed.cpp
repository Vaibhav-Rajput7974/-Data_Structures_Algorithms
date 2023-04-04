#include<bits/stdc++.h>
using namespace std;
bool iscycle(int src,vector<vector<int> > &adj,vector<bool> &visted, vector<int> &stack)
{
    stack[src]=true;
    if(!visted[src])
    {
        visted[src]=true;
        for(auto i: adj[src])
        {
            if(!visted[i] && iscycle(i,adj,visted,stack))
            {
                return true;
            }
            if(stack[i])
            {
                return true;
            }
        }
    }
    stack[src]=false;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n);
    vector<bool> visted(n,false);
    vector<int> stack(n,0);
    bool cycle=false;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0;i<n;i++)
    {
        if(!visted[i] && iscycle(i,adj,visted,stack))
        {
            cycle = true;
        }
    }
    if(cycle)
    cout<<"Cycle is present";
    else
    cout<<" Cycle is not present";
}