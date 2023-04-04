/*
for every coin we have to choice 
1. take the coin (arr,m,V-arr[m-1]) 
2. not take it (arr,m-1,V))

*/
#include<bits/stdc++.h>
using namespace std;
int counts;
const int N=1e3+2;
int dp[N][N];
int coin_change(int arr[],int m,int V)
{
    if(V==0)
    {
        //counts++;
        return 1;
    }
    if(V<0)
    {
        return 0;
    }
    if(m<=0)
    {
        return 0;
    }
    if(dp[m][V] != -1)
        return dp[m][V];

    dp[m][V]= coin_change(arr,m,V-arr[m-1]) + coin_change(arr,m-1,V);
    return dp[m][V];
}
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dp[i][j]=-1;
        }   
    }
    int arr[]={1,2,3};
    int n=3;
    int V=6;
    counts=0;
    cout<<coin_change(arr,3,V);
    //cout<<counts;
    return 0;
}