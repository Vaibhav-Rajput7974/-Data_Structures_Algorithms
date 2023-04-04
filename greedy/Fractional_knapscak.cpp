/*
we will find the value by weight ratio of every element and the short the array according to that faction 
after that we will cheak if the value of weight is > then that points value then we will directly add that value in ans and remove the weight of that value
from the total weight

*/
#include<bits/stdc++.h>
using namespace std;
bool compan(vector<int> &a,vector<int> &b)
{
    double vw1=(double)a[0]/a[1];
    double vw2=(double)b[0]/b[1];

    return vw1>vw2;
}
int main()
{
    int n,w;
    cin>>n;
    cin>>w;
    vector<vector<int> > v;
    for(int i=0;i<n;i++)
    {
        int value,weight;
        cin>>value>>weight;
        v.push_back({value,weight});
    }
    sort(v.begin(),v.end(),compan);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(w >= v[i][1])
        {
            ans+=v[i][0];
            w-=v[i][1];
            continue;
        }

        double vw=(double)v[i][0]/v[i][1];
        ans+=vw*w;
        w=0;
        break;
    }   
    cout<<ans;
    return 0;
}