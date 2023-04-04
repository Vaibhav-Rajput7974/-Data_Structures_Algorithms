/*
we will use greedy techniq in this problem
fir we will use the highest value coin and then go on to the low value and add it in the ans

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=10;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int x;
    cin>>x;
    sort(v.begin(),v.end(),greater<int>());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int curr=x/v[i];
        ans+=curr;
        x-=curr*v[i];
        if(x==0)
        break;
    }
    cout<<ans<<endl;
    return 0;
}