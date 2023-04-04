#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
vector<int > arr[N];
int vis[N];
string s;
map<char,int> mp;
int maxi=0;
void DFS(int x)
{
    vis[x]=1;
    mp[s[x-1]]++;
    vector<int> :: iterator it;
    for(it=arr[x].begin();it!=arr[x].end();it++)
    {
        if(vis[*it])
        {

        }
        else
        {
            DFS(*it);
        }
    }
    
    map<char,int> ::iterator its;
    for(its=mp.begin();its!=mp.end();its++)
    {
        maxi=max(maxi,its->second);
    }
    mp[s[x-1]]--;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    cin>>s;
    for(int i=0;i<N;i++)
    {
        vis[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        arr[x].push_back(y);
    }
    DFS(1);
    cout<<maxi;
    return 0;
}