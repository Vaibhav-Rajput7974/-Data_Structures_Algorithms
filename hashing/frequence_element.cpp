#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,2,1,3,2,4,7};
    map <int,int> mp;
    int n=10;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    map<int,int> ::iterator itr;
    for(itr=mp.begin();itr!=mp.end();++itr)
    {
        cout<<itr->first<<"   "<<itr->second<<endl;
    }
    return 0;
}