#include<bits/stdc++.h>
using namespace std;
/*
first cheak char is equall or not if equal
    them call the function for n-1 and m-1

else
    call for n-1
    and 
    call for m-1
    return max of both 

for dp store the result
*/
int LCSReccursive(string a,string b,int n,int m,vector<vector<int> > &dp)
{
    if(n == 0 || m == 0)
    {
        return 0;
    }
    if(dp[n][m] != -1)
        return dp[n][m];

    if(a[n-1] == b[m-1])
    {
        return dp[n][m]=1+LCSReccursive(a,b,n-1,m-1,dp);
    }
    else
    {
        int first=LCSReccursive(a,b,n-1,m,dp);
        int second=LCSReccursive(a,b,n,m-1,dp);

        return dp[n][m]=max(first,second);
    }
}

/*
first put 0 for i of 0 and j of 0

then cheak string 
if equall 
        then 1+dignal element
else
    max from last of a and b

*/
int LCSTupplet(string a,string b)
{
    int n=a.length();
    int m=b.length();
    vector<vector<int> > dp(1001,vector<int> (1001,-1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
                continue;
            }

            if(a[i] == b[j])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    vector<vector<int> > dp(1001,vector<int> (1001,-1));
    string a="ABCSD";
    string b="ASNBD";
    int n=a.length();
    int m=b.length();
    cout<<"Longet common subsequence from memorization =  ";
    cout<<LCSReccursive(a,b,n,m,dp)<<endl;
    cout<<"longest common subsequence from tupplert =   ";
    cout<<LCSTupplet(a,b);

}