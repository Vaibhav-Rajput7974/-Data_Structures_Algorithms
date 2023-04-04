#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int dp[N];
int main()
{
    for(int i=0;i<N;i++)
    {
        dp[i]=1;
    }
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    //return ans;
}