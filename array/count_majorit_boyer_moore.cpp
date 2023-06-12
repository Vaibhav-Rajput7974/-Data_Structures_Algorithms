#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,2,1,1,2,2,1};
    // we will find the majority and non majority element in array and 
    // majority element are those element which occure more then n/2 time

    int count=0;
    int element=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(count == 0){
            element = arr[i];
        }
        if(element == arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    cout<<element;    
}