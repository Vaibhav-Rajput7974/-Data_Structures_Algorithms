#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=6;
    int arr[]={1,2,2,2,3,1};
    map<int,int> mp;
    int k=2;
    for(int i=0;i<n;i++)
    {
        int presentsize=mp.size();
        if(mp[arr[i]]==0 && presentsize == k)
        {
            break;
        }
        mp[arr[i]]++;
    }
    vector<pair<int,int> > p;
    map<int,int> :: iterator itr;
    for(itr=mp.begin() ;itr!=mp.end() ;++itr)
    {
        if(itr->second !=0)
        {
            pair<int,int> p1;
            p1.first=itr->second;
            p1.second=itr->first;
            p.push_back(p1);
        }
    }
    sort(p.begin(),p.end(),greater <pair<int,int> >());
    vector<pair<int,int>> :: iterator pr;
    for(pr=p.begin() ; pr!=p.end() ; ++pr)
    {
        cout<<pr->second<<"   "<<pr->first<<endl;
    }
    return 0;
}