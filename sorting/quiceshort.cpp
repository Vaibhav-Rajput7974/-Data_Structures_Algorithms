#include<iostream>
using namespace std;
int partion(int arr[],int l,int r)
{
    int pi=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
    if(arr[j]<pi)
    {
        i++;
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
    }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return i+1;
    
}
void quice(int arr[],int l,int r)
{
    if(l<r)
    {
        int pi=partion(arr,l,r); 
        quice(arr,l,pi-1);
        quice(arr,pi+1,r);
    }
}
int main()
{
    int arr[]={4,3,6,2,5};
    quice(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}