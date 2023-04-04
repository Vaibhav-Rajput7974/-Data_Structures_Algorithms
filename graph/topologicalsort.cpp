#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m; 
    int cnt=0;
    vector<vector<int> > adj(n);
    vector<int> In_deg(n,0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        In_deg[y]++;
    }

    queue<int> pq;
    for(int i=0;i<n;i++)
    {
        if(In_deg[i]==0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        cnt++;
        int x=pq.front();
        pq.pop();
        cout<<x<<" ";
        for(auto it:adj[x])
        {
            In_deg[it]--;
            if(In_deg[it]==0)
            {
                pq.push(it);
            }
        }
    }
}