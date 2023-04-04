#include<iostream>
using namespace std;
void merge(int arr[],int mid,int s,int l)
{
    int n1=mid-s+1;
    int n2=l-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[s+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=s;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
            i++;
            k++;
    }
    
    while(j<n2)
    {
        arr[k]=b[j];
            j++;
            k++;
    }
}
void mergeshort(int arr[],int s,int l)
{
    if(s<l)
    {
        int mid=(l+s)/2;
        mergeshort(arr,s,mid);
        mergeshort(arr,mid+1,l);

        merge(arr,mid,s,l);
    }
}
int main()
{
    int arr[]={5,4,3,2,1};
    mergeshort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
   
    return 0;
}
