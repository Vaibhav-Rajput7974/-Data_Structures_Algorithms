/*
in shorted array
max=(A[n-1]-A[0])+(A[n-2]-A[1])+(A[n-3]+A[2])........
which can also be writen as sum of element after the half - sum of element before the mid

min=(A[1]-A[0])+(A[3]-A[2])+(A[5]-A[4]).........
which can also be writen ans sum of odd element - sum of even element
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    long long mx=0;
    long long mi=0;
    for(int i=0;i<n/2;i++)
    {
        mx += (arr[n/2+i] - arr[i]);
        mi += (arr[n*2+1] -arr[n*2]);
    }
    cout<<mi<<"   "<<mx<<endl;
}
