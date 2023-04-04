#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+2;
 vector<int> adj[N];
    bool mark[N];
//vector<int> adj[100];
int main()
{
    //cout<<" fdvd";
   int n,m;
    cin>>n;
    cin>>m;
    
    for(int i=0;i<N;i++)
    {
        mark[i]=0;
    }
    int x,y;
    for(int i=0;i<m;i++)
    {
        
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    mark[1]=true;
    while(!q.empty());
    {
        int node=q.front();
        q.pop();
        cout<<node<<endl;
        vector<int> :: iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++)
        {
            if(!mark[*it])
            {
            mark[*it]=true;
            q.push(*it);
            }
        }
    }
    return 0;
}
