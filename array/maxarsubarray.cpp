#include<iostream>
using namespace std;
int main()
{
    cout<<"Array with the same common different"<<endl;
    cout<<"Enter Number of element in Array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int pr=arr[0]-arr[1];
    int cr=0;
    int siz=1;
    int mx=0;
    for(int i=0;i<n-1;i++)
    {
        cr=arr[i]-arr[i+1];
        if(pr==cr)
        siz++;
        else
        {
            siz=2;
            pr=arr[i]-arr[i+1];
        }
        if(siz>mx)
        mx=siz;
    }
cout<<mx;
}