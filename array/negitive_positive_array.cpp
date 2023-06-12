#include<bits/stdc++.h>
using namespace std;
void roated(int arr[],int idx,int idx2){
    int temp=arr[idx2];
    for(int i=idx2;i>idx;i--){
        arr[i]=arr[i-1];
    }
    arr[idx]=temp;
}
void rearrange(int arr[],int n){
    int wrongeidx=-1;
    for(int i=0;i<n;i++){
        if(wrongeidx != -1){
            if((arr[wrongeidx] >=0 && arr[i]<0) || (arr[wrongeidx] <0 && arr[i] >=0)){
                roated(arr,wrongeidx,i);

            if(i-wrongeidx >= 2){
                wrongeidx+=2;
            }
            else{
                wrongeidx=-1;
            }
            }
        }
        else
        {
            if((i%2 == 1 && arr[i] < 0) || (i%2 == 0 && arr[i] > 0) ){
                wrongeidx=i;
            }
        }
    }
}
int main(){
    int arr[]={-1,1,2,3,-3};
    int n=5;
    rearrange(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}