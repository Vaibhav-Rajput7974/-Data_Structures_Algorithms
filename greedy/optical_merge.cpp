/* first we will short arr 
and the add two number sum and store it in sum variable and then add that sum in ans
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int sum=0;
    int ans=0;
    sum=arr[0]+arr[1];
    ans+=sum;
    for(int i=2;i<n;i++)
    {
        sum+=arr[i];
        ans+=sum;
    }
    cout<<ans;
    return 0;
}