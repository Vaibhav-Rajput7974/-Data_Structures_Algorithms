#include<iostream>
#include<deque>
using namespace std;
int MinSweet(int arr[],int k,int n)
{
    deque<int> ans;
    int minsw=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<=k;i++)
    {
        maxi=max(maxi,arr[i]);
        ans.push_back(arr[i]);
    }
    minsw=maxi;
    for(int i=k+1;i<n;i++)
    {
        ans.push_back(arr[i]);
        ans.pop_front();

        maxi=INT_MIN;
        for(int j=0;j<ans.size();j++)
        {
            maxi=max(maxi,ans[j]);
        }
        minsw=min(minsw,maxi);
    }
    maxi=INT_MIN;
    while(!ans.empty())
    {
        maxi=max(maxi,ans.front());
        ans.pop_front();
    }
    minsw=min(minsw,maxi);
    return minsw;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    cout<<MinSweet(arr,0,10);
    return 0;
}