#include<bits/stdc++.h>
using namespace std;
  void DFSearch(int node,vector<vector<int> > &adj,vector<int> &vis,vector<int> &num)
{
    vis[node]=1;
    num.push_back(node);
    //cout<<node<<" ";

    vector<int> ::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();++it)
    {
        if(vis[*it])
        {
        }
        else
        {
            DFSearch(*it,adj,vis,num);
        }                   
    }
}
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<int> vis(V+1,0);
        vector<vector<int> > ans;
        for(int i=1;i<=V;i++)
        {
            if(vis[i]==0)
            {
            vector<int> num;
            DFSearch(i,adj,vis,num);
            cout<<endl;
            for(int j=0;j<num.size();j++)
            {
                //cout<<num[j]<<"  ";
            }
            ans.push_back(num);
            }
        }
        //cout<<ans.size();
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j]<<"  ";
            }
            cout<<endl;
        }
        return 0;
    }
    int B=0;
    void IT(int i,map<int,vector <pair<int,int> >> &mp)
    {
        vector < pair<int,int>  > :: iterator it;

        for(it=mp[i].begin();it!=mp[i].end();it++)
        {
            B+=it->second;
            cout<<it->second;
            IT(it->first,mp);
        }
    }
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        int rootdata=A[0];
        map<int,vector <pair<int,int> >> mp;

        for(int i=1;i<N;i++)
        {
            mp[P[i]].push_back({i+1,A[i]});
            cout<<P[i]<<"="<<i+1<<"  "<<A[i]<<endl;
        }
        map<int,vector <pair<int,int> >> ::iterator it;
        it=mp.begin();
        B=A[0];
        IT(it->first,mp);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> arr[n];
        for(int i=0;i<connections.size();i++)
        {
            arr[connections[i][0]].push_back(connections[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            for(auto j:arr[i])
            {
                cout<<j<<"  ";
            }
            cout<<endl;
        }

        return 0;
    }
    int main()
    {
        vector<vector<int> > con={{0,1},{0,2},{1,2}};
        makeConnected(4,con);
        /*
        int V=7;
        vector<vector<int>> adj
        ={
            {},
            {2},
            {7,1},
            {4,5},
            {5,3},
            {3,4},
            {6},
            {}
        };
        vector<int> P={-1,1,2,1};
        vector<int> A={3,1,2,10};
        bestNode(4,A,P);
        cout<<endl;
        cout<<B;
        //int code=findNumberOfGoodComponent(V,adj);
        */
       return 0;
    }