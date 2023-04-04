#include<iostream>
using namespace std;
const int N=1e5+2;
int dp[N];
const int MOD=1e9+7;
int min_square(int n)
{
    if(n==0 || n==1 ||  n==2 || n==3)
        return n;

    if(dp[n] != MOD)
        return dp[n];
    for(int i=1;i*i<=n ;i++)
    {
        dp[n]=min(dp[n],1+ min_square(n-(i*i)));
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<N;i++)
    {
        dp[i]=MOD;
    }
    cout<<min_square(n);
    return 0;
}