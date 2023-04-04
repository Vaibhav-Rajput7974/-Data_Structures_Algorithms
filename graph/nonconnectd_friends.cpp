#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > friends;
vector<bool> vis;
vector<int> ans;    
void get_com(int src)
{
    if(vis[src])
        return ;
    vis[src]=true;
    ans.push_back(src);
    for(auto i :friends[src])
    {
        if(!vis[i])
        {
            get_com(i);
            vis[i]=true;
        }
    }
}
int main()
{
    int n,m;
    cout<<"Enter Number of friends"<<endl;
    cin>>n>>m;
    friends=vector<vector<int> >(n);
    vis=vector<bool> (n,0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        friends[x].push_back(y);
        friends[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        { 
            ans.push_back(100);
        }
    }
    for(auto i:ans)
    {
        cout<<i<<"   ";
    }
}