#include<iostream>
using namespace std;
int binarysearch(int arr[],int key,int s,int l)
{
    int mid=s+l/2;
    if(key>arr[sizeof(arr)/sizeof(int)-1] || s==l)
    return -1;
    if(arr[mid]==key)
    return mid+1;
    else if(key<arr[mid])
    {
        s=0;
        l=mid;
        binarysearch(arr,key,s,l);
    }
    else if(key>arr[mid])
    {
        s=mid+1;
        l=sizeof(arr)/sizeof(int)-1;
        binarysearch(arr,key,s,l);
    }
    
}
int main()
{
    cout<<"Enter Number of element in Array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key=7;
    int s=0;
    int l=sizeof(arr)/sizeof(int)-1;
   // cout<<l;
    cout<<binarysearch(arr,key,s,l);
}