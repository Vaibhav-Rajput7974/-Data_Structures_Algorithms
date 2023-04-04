#include<iostream>
using namespace std;
int MinWindow(int arr[],int n,int x)
{
    int start=0;
    int end=0;
    int sum=0;
    int length=INT_MAX;
    while(end<n && end>=start)
    {
        if(sum<x)
        {
            sum+=arr[end];
            end++;
        }
        else if(sum>=x)
        {
            length=min(length,end-start);
            sum-=arr[start];
            start++;
        }//cout<<sum<<endl;
    }
    return length;
}
int main()
{
    int arr[]={1,4,45,6,10,13};
    cout<<MinWindow(arr,6,51);
    return 0;
}
