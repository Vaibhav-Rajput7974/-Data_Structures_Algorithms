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
    for(int i=0;i<n;i++)
    {                                     
        int maxi=arr[0];
        for(int j=i;j>=0;j--)
        {
            if(maxi<arr[j])
            {
                maxi=arr[j];
            }
        }
        cout<<maxi<<endl;
    }
    return 0;
}
