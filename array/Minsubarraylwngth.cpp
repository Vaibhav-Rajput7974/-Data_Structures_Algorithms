#include<iostream>
using namespace std;
int MinLength(int arr[],int n,int x)
{
    int Mxlength=n+1;
    int start=0,end=0,sum=0;
    while (sum<=x)
    {
        /* code */
        sum+=arr[end++];
    }
    while(sum>x && start<n)
    {
        if(end-start<Mxlength)
        {
            Mxlength=end-start;
        }
        sum-=arr[start++];  
    }
    return Mxlength;
}
int main()
{
    int arr[]={1,4,45,6,10,13};
    cout<<MinLength(arr,5,51);
    return 0;
}