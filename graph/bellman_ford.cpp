#include<bits/stdc++.h>
using namespace std;
const int INF=1e7;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> dis(n,INF );
    vector< vector<int>> adj;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }
    int source;
    cin>>source;
    dis[source]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto it:adj)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            dis[v]=min(dis[v],dis[u]+w); 
        }
    }
    for(auto i:dis)
    {
        cout<<i<<" ";
    }
}