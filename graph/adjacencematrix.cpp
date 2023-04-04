#include<bits/stdc++.h> 
using namespace std;
void usingarray(int n,int m)
{
    int N=1e5+2;

    //vector<vector<int>> adj( n +1, vector<int> (n+1, 0));
    vector<int> adj[N];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1][y-1]=1;
        adj[y-1][x-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj[i][j]<<"  "; 
        }
        cout<<endl;
    }

}
void vectorpush(int n,int m)
{
    vector<vector<int> > adj(1e5+2);
    for(int i=0;i<m;i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x-1].push_back(y);
        adj[y-1].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"->";
        vector<int> ::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();++it)
        {
            cout<<*it<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,m;
    cin>>n;
    cin>> m;
    int choice;
    cin>>choice;
    if(choice==1)
    usingarray(n,m);
    if(choice==2)
    vectorpush(n,m);
}