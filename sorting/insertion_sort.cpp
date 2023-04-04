#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={12,45,23,51,19,8};
    int n=6;
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int current=arr[i];
        while(j>=0 && arr[j]>current)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}