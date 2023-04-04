#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
const int N=1e5+6;

vector<int> parent(N);
vector<int> sz(N);
void make_set(int v)
{
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v)
{
    if(parent[v] == v)
    return v;

    return parent[v]=find_set(parent[v]);
}
void make_union(int v,int u)
{
    int i=find_set(v);
    int j=find_set(u);
    if(i != j)
    {
        if(sz[i] < sz[j])
        swap(i,j);
        parent[j]=i;
        sz[i] += sz[j];

    }
}
//vector<bool> vis(n,0);
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj.push_back({x,y});
    }
    for(int i=0;i<N;i++)
    {
        make_set(i);
    }
    bool cycle=false;
    for(auto i: adj)
    {
        int v=i[0];
        int u=i[1];
        int x=find_set(v);
        int y=find_set(u);
        if( x == y)
        cycle=true;
        else
        make_union(v,u);
    }
    if(cycle)
    {
        cout<<" Cycle is present ";
    }
    else
    {
        cout<<"Cycle is not present";
    }
    return 0;
}