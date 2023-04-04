#include<iostream>
using namespace std;
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
    int currentsum[n+1];
    currentsum[0]=0;
    for(int i=1;i<=n;i++)
    {
        currentsum[i]=currentsum[i-1]+arr[i-1];
    }
    int mx=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=0;j<i;j++)
        {
            sum=currentsum[i]-currentsum[j];
            mx=max(mx,sum);
        }
    }
    cout<<"sum of subarray with maximum sum="<<endl;
    cout<<mx<<endl;
}


