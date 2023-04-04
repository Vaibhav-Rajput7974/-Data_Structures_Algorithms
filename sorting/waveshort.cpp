#include<iostream>
using namespace std;
void swaping(int arr[],int i,int j)
{
    int tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
}
void waveshort(int arr[],int n)
{
    for(int i=1;i<n-1;i+=2)
    {
        if(arr[i]>arr[i-1])
        swaping(arr,i,i-1);
        
        if(arr[i]>arr[i+1] && i<=n-2)
        swaping(arr,i,i+1);

    }
}
int main()
{
    int arr[]={1,2,3,4,5};
    waveshort(arr,5);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}