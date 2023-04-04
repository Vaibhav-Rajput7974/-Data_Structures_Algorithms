#include<iostream>
using namespace std;
int firstOc(int arr[],int key,int n,int i)
{
    if(i==n)
    return -1;

    if(arr[i]==key)
    return i;

    return firstOc(arr,key,n,i+1);
}
int lastOc(int arr[],int key,int n,int i)
{
    if(i==n)
    return -1;
    int lastIn=lastOc(arr,key,n,i+1);
    if(lastIn!=-1)
    return lastIn;

    if(arr[i]==key)
    return i;

    return -1;
}
int main()
{
    int key=3;
    int arr[]={1,2,3,3,4,3,8};
    cout<<firstOc(arr,key,7,0)<<endl;
    cout<<lastOc(arr,key,7,0)<<endl;
    return 0;
}