#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main(){

    vector<int> arr = {-10,9,2,1,3,4,0,3};
    int k=3;
    int n=8;
    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        if(!q.empty() and arr[q.back()]<arr[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(arr[q.front()]);
    for(int i=k;i<n;i++)
    {
        if(q.front()== (i-k))
        {
            q.pop_front();
        }
        while (!q.empty() and arr[q.back()]<arr[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(arr[q.front()]);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
} 