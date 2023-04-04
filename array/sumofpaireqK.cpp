#include<iostream>
using namespace std;
int* selectshort(int arr[],int n)
{
    int *p=&arr[0];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return p;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int *p=selectshort(arr,n);
    cout<<"Shorted array is"<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i]=*p++;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter K Value"<<endl;
    int k;
    cin>>k;
    int i=0;
    int j=n-1;
    while(arr[i]+arr[j]!=k)
    {
        if(arr[i]+arr[j]<k)
        i++;
        if(arr[i]+arr[j]>k)
        j--;
    }
        if(i==j)
        cout<<"  false";
        else
        cout<<i+1<<" "<<j+1<<" true";
    return 0;
}