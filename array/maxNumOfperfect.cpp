/*
programm to find max number of perfect number in given size of subarray

*/

#include<iostream>
#include<math.h>
using namespace std;
bool Isperfect(int n)
{
    //this function will cheak that the given number is perfect or not
    int sum=1;
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i == 0)
        {
            if(i==n/i)
            {
                sum+=i;
            }
            else
            {
                sum+=i+n/i;
            }
        }
    }
    if(sum==n && n!=1)
    {
        return true;
    }
    else{
        return false;
    }
}
int MaxSum(int arr[],int n,int k)
{
    //this function will find the maxinum sum of in k window
    if(n<k)
    {
        cout<<"Invalid input"<<endl;
        return -1;
    }
    int res=0;
    for(int i=0;i<k;i++)
    {
        res+=arr[i];
    }
    int sum=res;
    for(int i=k;i<n;i++)
    {
        sum+=arr[i]-arr[i-k];
        res=max(res,sum);
    }
    return res;
}
int maxNumPerfect(int arr[],int n,int k)
{
    // this funtion will cheak that the number is perfect or not 
    //if -> perfect then arr[i]=1;
    //else arr[i]=0;

    for(int i=0;i<n;i++)
    {
        if(Isperfect(arr[i]))
        {
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }

    return MaxSum(arr,n,k);
}
int main()
{
    int arr[]={28,2,3,6,496,99,8128,24};
    int k=4;
    int n=8;
    cout<<maxNumPerfect(arr,n,k);
    return 0;
}