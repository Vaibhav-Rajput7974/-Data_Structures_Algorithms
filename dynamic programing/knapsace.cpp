#include<iostream>
using namespace std;
const int N=1e3+2;
int value[N];
int wt[N];
int dp[N][N];
int knap(int n,int w)
{
    if(w<=0)
    {
        return 0;
    }
    if(n<=0)
    {
        return 0;
    }
    if(dp[n][w] != -1)
        return dp[n][w];
    if(wt[n-1] >w)
    {
        dp[n][w]= knap(n-1,w);
    }
    else
        dp[n][w]= max(knap(n-1,w),knap(n-1,w-wt[n-1] )+value[n-1]);
    return dp[n][w];
}
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dp[i][j]= -1 ;
        }
            
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    int w;cin>>w;
    cout<<knap(n,w);
    return 0;
}