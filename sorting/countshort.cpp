#include<iostream>
using namespace std;
void countshort(int arr[],int n)
{
    int k=arr[0];
    for(int i=0;i<n;i++)
    {
        if(k<arr[i])
        k=arr[i];
    }
    int coutq[k+1]={0};
    for(int i=0;i<k+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==arr[j])
            coutq[i]++;
        }
    }
    int sum=0;
    for(int i=0;i<k+1;i++)
    {
        sum+=coutq[i];
        coutq[i]=sum;
    }
    int ans[n];
    for(int i=n-1;i>=0;i--)
    {
        coutq[arr[i]]--;
        ans[coutq[arr[i]]]=arr[i];
    }
    for(int i=0;i<8;i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    int arr[]={2,3,2,1,4,6,5};
    countshort(arr,8);
    return 0;
}