#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int dp[1001][1001];
int solve(int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int choice=a[i] + min(solve(i+2,j) ,solve(i+1,j-1));
    int choice2=a[j]+min(solve(i,j-2) ,solve(i+1,j-1));

    return max(choice,choice2);
}
int main()
{
    a={1,2,3,4};
    for(int i=0;i<1001;i++)
    {
        for(int j=0;j<1001;j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<solve(0,3);
    return 0;
}