/*
we know that moudles of any number will give that number in the range of 0 to n-1
so using this we can drive the formula = 
 arr[(i+k)%n]= arr[i];
*/

/*
        // using reverse 
        we will first reverse the given array into two part from 0 to k 
        then revese from k to n-1;
        then reverse full array
*/
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        temp[(i+k)%n] = arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
}
void reverse(vector<int> &arr,int start,int end){
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int main(){
    vector<int> arr={1,2,4,5,6,7};
    int n=arr.size();
    int k=2;
    //rotate(arr,k);
    k=n-k;
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}