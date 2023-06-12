#include<bits/stdc++.h>
using namespace std;
/*
for every element cheak if it is greater then the last element in ans arry 
if greater
    push that element 
else 
    find the element just smaller than it and replace it with that element 

*/
int main()
{
    vector<int> arr={2,5,3,7,11,8,10,13, 6};
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int  i=1;i<arr.size();i++){
        if(ans.back() < arr[i]){
            ans.push_back(arr[i]);
        }
        else{
            int idx=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[idx]=arr[i];
        }
    }
    
    cout<<ans.size();
}