#include<iostream>
#include<stack>
using namespace std;
void preves_smaller(int arr[],int n,int smaller[])
{
    stack<int> s;
    for(int i=0;i<n;i++)
    {
    while(!s.empty() && arr[s.top()]>=arr[i])
    s.pop();
    if(s.empty())
    smaller[i]=-1;
    else
    smaller[i]=s.top();

    s.push(i);
    }
}
void next_smaller(int arr[],int n,int smaller[])
{
    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
    while(!s.empty() && arr[s.top()]>=arr[i])
    {
    s.pop();
    }
    if(s.empty())
    smaller[i]=n;
    else
    smaller[i]=s.top();

    s.push(i);
    }
}
int maxrectangle(int arr[],int n)
{
    
    int psmaller[n];
    int nsmaller[n];
    preves_smaller(arr,n,psmaller);
    next_smaller(arr,n,nsmaller);
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,(nsmaller[i]-psmaller[i]-1)*arr[i]);
        //cout<<(nsmaller[i]-psmaller[i]-1)*arr[i]<<" ";
    }
    cout<<mx;
    return 1;
}
int main()
{
    int arr[]={4,2,1,5,6,3,2,4,2};
    maxrectangle(arr,9);
}