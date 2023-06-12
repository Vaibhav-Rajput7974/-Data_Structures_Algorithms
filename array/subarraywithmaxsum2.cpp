/*
max sum 
we willl not take the subarray whose sum is -ve in our answer

*/
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
    int currentsum=0;
    int currentmax=INT_MIN;
    for(int i=0;i<n;i++)
    {
        currentsum+=arr[i];
        if(currentsum<0)
        currentsum=0;
        currentmax=max(currentmax,currentsum);
    }
    cout<<"Max subarray not correct output"<<endl;
    cout<<currentmax<<endl;
}