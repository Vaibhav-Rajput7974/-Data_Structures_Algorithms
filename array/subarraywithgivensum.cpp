#include<bits/stdc++.h>
using namespace std;
int main(){
    int sum=12;
    int arr[]={1,3,1,5,3,52,3,2};
    int n=8;
    int cursum=0;
    int start=-1,end=-1;
    map<int,int> mp;
    for(int i=0;i<8;i++){
        cursum+=arr[i];
        if((cursum-sum) == 0){
            start=0;
            end=i;
            break;
        }
        if(mp.find(cursum-sum) != mp.end()){
            start=mp[cursum-sum]+1;
            end=i;
            break;
        }
        mp[cursum]=i;
    }
    cout<<start<<"  "<<end;
    return 0;
}