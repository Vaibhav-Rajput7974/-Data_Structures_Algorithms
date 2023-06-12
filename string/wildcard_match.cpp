/*

we wil cheak from last charater if the character match we will go to previse character of moth the string and patten and if "?" also the same
if "*" then we will cheak to match * with empty string or with some sequence and will cheak for ever sequence
*/
#include<bits/stdc++.h>
using namespace std;
int f(int i,int j, string &s,string &p,vector<vector<int>> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return dp[i][j]=1;
        if(j==0 && i>0) return dp[i][j]=0;
        if(i==0 && j>0)
        {
            while(j>0)
            {
                if(p[j-1]=='*') j--;
                else return dp[i][j]=0;
            }
            return dp[i][j]=1;
        }
        
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        
        if(p[j-1]=='*')
        {
            return dp[i][j] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp) ? 1:0;
            //Two cases
            //Consider * as len=0
            //Give one charcter to * and remain at *
            //at next step it will again be decided from both these cases
        }
        return dp[i][j]=0;
        
    }
    
int main(){
    string s="abcdf";
    string p="a?c*";
    int n=s.length(),m=p.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout<< f(n,m,s,p,dp);
}