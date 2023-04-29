#include<bits/stdc++.h>
using namespace std;
class DSU {
    public:
    vector<int> Parent, Rank;
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        return false;
    }
};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU(n);
        for(int i=0;i<n;i++)
        {
            queries[i].push_back(i);
        } 
        sort(queries.begin(),queries.end(), [&](auto const &a,auto const &b){
            return a[2]<b[2];
        });

        sort(edgeList.begin(),edgeList.end(), [&](auto const &a,auto const &b){
            return a[2]<b[2];
        });
        int i=0;
        vector<bool> res(queries.size(),false);
        for(auto q : queries)
        {
            while(i<edgeList.size() && edgeList[i][2] < q[2])
            {
                DSU.Union(edgeList[i][0],edgeList[i][1]);
                i++;
            }

            if(DSU.Find(q[0]) == DSU.Find(q[1]))
            {
                res[q[3]]=true;
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}