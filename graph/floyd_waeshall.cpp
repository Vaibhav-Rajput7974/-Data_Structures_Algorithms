/*
1. first we will create adjacence matrix for the give in graph
2. the we will add try to add nodes in between of the two list and will cheak 
if(distence of the node is > distence of that node to starting node + distence of that node to ending node)
then we will change the value of the node 
else 
    continue;
*/

#include<bits/stdc++.h>
using namespace std;
const int INF=1e7;
int main()
{
    int n,m;
    cin>>n>>m;
    
    vector< vector<pair<int,int> >> adj(n);

    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }

    vector<int> arr(n,INF);
    vector<vector<int> >graph(n,arr);

    for(int i=0;i<n;i++)
    {
        for(auto j:adj[i])
        {
            graph[i][j.first]=j.second;
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j]=graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }

}





