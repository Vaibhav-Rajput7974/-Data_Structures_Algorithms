#include<iostream>
using namespace std;
int kiden(int arr[],int n)
{
    int currentsum=0;
    int currentmax=INT_MIN;
    for(int i=0;i<n;i++)
    {
        currentsum+=arr[i];
        if(currentsum<0)
        currentsum=0;
        currentmax=max(currentmax,currentsum);
    }
    return currentmax;
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
    int nonwrap=0;
    int wrap=0;
    int totalsum=0;
    nonwrap=kiden(arr,n);
    for(int i=0;i<n;i++)
    {
        totalsum+=arr[i];
        arr[i]=-arr[i];
    }
    wrap=totalsum+kiden(arr,n);
     cout<<"Max curculer subarray not correct output"<<endl;
    cout<<max(wrap,nonwrap)<<endl;
}