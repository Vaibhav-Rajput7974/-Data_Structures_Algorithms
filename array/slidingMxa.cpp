/* we will first calculate the sum of first k element then we will iterarte in all array by adding one element at the end and 
removeing another from the first index
and then comparing it with the ans and sum and storing the max of both the element 
*/
#include<iostream>
using namespace std;
int MaxWindowInArray(int arr[],int n,int k,int x)
{
    int ans=0;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    if(sum<=x)
    {
        ans=sum;
    }
    int start=0;
    for(int i=k;i<n;i++)
    {
        sum=sum-arr[start]+arr[i];
        start++;
        //sum+=arr[i];
        if(sum<=x)
        {
            ans=max(ans,sum);
        }
    }
    return ans;
}
int main()
{
    int arr[]={7,5,4,6,8,9};
    cout<<MaxWindowInArray(arr,6,3,20);
    return 0;
}