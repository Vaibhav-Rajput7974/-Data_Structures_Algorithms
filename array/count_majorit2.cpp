/*
FIND element appare more then n/3 time 
we can see that there are maximum 2 such element in array 
we will ue the approch of boyer_moore algoithm to calculate the two majority element 
and then will cheak that element have occure more then n/3 time or not
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,1,2,1,4,2,1,3,2};
    int sz=(sizeof(arr)/sizeof(arr[0]))/3;
    int x=-1;
    int y=-1;
    int cx=0;
    int cy=0;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if(x == arr[i]){
            cx++;
        }
        else if(y == arr[i]){
            cy++;
        }
        else if(cx == 0){
            x=arr[i];
            cx=1;
        }
        else if(cy == 0){
            y=arr[i];
            cy=1;
        }
        else{
            cx--;
            cy--;
        }
    }
    cx=cy=0;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if(x == arr[i]){
            cx++;
        }
        else if(y == arr[i]){
            cy++;
        }
    }
    if(cx > sz){
        cout<<x<<endl;
    }
    if(cy > sz){
        cout<<y<<endl;
    }
    return 0;
}