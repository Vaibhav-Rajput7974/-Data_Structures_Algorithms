#include<bits/stdc++.h>
using namespace std;
int multipulReccursive(int arr[],int i,int j,vector<vector<int> > &dp)
{
    if(i == j )
    {
        return 0;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
    {
        dp[i][j]=min(dp[i][j],multipulReccursive(arr,i,k,dp) + multipulReccursive(arr,k+1,j,dp) + arr[i] *arr[k] *arr[j]);
    } 
    return dp[i][j];
}
int main()
{
    int arr[]={1,2,3,4};
    int n=4;
    vector<vector<int> > dp (1001,vector<int> (1001,-1));
    cout<<multipulReccursive(arr,0,n-1,dp);
    return 0;
}