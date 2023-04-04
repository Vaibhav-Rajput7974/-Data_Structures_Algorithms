#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2;
int dp[N];
int lis(vector<int> &arr,int n)
{
    if(dp[n] != -1)
        return dp[n];
    
    dp[n]=1;

    for(int i=0;i<n;i++)
    {
        if(arr[n]>arr[i])
        {
            dp[n]=max(dp[n],1+lis(arr,i));
        }
    }
    return dp[n];
}
int main()
{
    for(int i=0;i<N;i++)
    {
        dp[i]=-1;
    }
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<lis(arr,n-1);
    return 0;
}