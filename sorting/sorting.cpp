#include<iostream>
using namespace std;
int selectshort(int arr[],int n)
{
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
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
int bubbleshort(int arr[],int n)
{
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
int insertshort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int current=arr[i];
        while(arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
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
    cout<<"1 for select shot"<<endl;
    cout<<"2 for bubble shot"<<endl;
    cout<<"3 for Quice shot"<<endl;
    int cs;
    cin>>cs;
    switch(cs)
    {
        case 1:
        selectshort(arr,n);
        break;
        case 2:
        bubbleshort(arr,n);
        break;
        case 3:
        insertshort(arr,n);
        break;
        default:
        cout<<"Wrong choice";
    }
    return  0;
}