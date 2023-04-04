#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of element in Array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Element  "<<i+1<<endl;
        cin>>arr[i];
    }
    cout<<"Enter element you want to search"<<endl;
    int a;
    cin>>a;
    int o=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==a)
        {
            cout<<"Element is at index No.="<<i+1<<endl;
            o++;
            break;
        }
    }
    if(o==0)
    cout<<"Element not found in array"<<endl;
}