#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
vector<bool> vis;
vector<int> componet;
int get_com(int src)
{
    if(vis[src])
    return 0;
    int ans=1;
    vis[src]=true;    
    for(auto i:adj[src])
    {
        if(!vis[i])
        {
            ans+=get_com(i);
            vis[i]=true;
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    adj=vector<vector<int> > (n);
    vis=vector<bool> (n,0);
    for(int i=0;i<m;i++)
    {
        int x,y;

        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            componet.push_back(get_com(i));
        }
    }
    long long ans=0;
    for(auto i:componet)
    {
        ans+=i*(n-i);
        cout<<i<<"  ";
    }
    cout<<endl;
    cout<<"total Number of combination from different component are ->"<<ans/2;
    return 0;
}