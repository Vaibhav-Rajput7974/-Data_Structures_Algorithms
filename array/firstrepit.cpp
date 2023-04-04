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
    const int N=12312;
    int idx[N];
    for(int i=0;i<N;i++)
    {
        idx[i]=-1;
    }
    int minidx=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(idx[arr[i]]!= -1)
        {
            minidx=min(minidx,idx[arr[i]]);
        }
        else
        {
            idx[arr[i]]=i;
        }
    }
    cout<<"First repeting element is "<<endl;
    cout<<minidx+1<<endl;
    return 0;
}