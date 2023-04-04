#include<bits/stdc++.h>
using namespace std;
const int INF=1e7;
int main()
{
    int n,m;
    cin>>n>>m;
    vector< vector<pair<int,int> >> adj(n+1);
    vector<int> dis(n+1,INF);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int source;
    cin>>source;
    dis[source]=0;
    set<pair<int,int>  >s;
    s.insert({0,source});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        for(auto it:adj[x.second])
        {
            if(dis[it.first] > dis[x.second] + it.second)
            {
                s.erase({dis[it.first],it.first});
                dis[it.first] =dis[x.second]+it.second;
                s.insert({dis[it.first],it.first});
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        if(dis[i]<INF)
        {
            cout<<dis[i]<<"  ";
        }
    }
}