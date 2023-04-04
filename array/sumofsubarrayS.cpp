#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter s"<<endl;
    int s;
    cin>>s;
    cout<<"Enter Number of element in Array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    int st=-1,ls=-1,i=0,j=0;
    while( j<n && sum+arr[j] <= s)
    {
        sum+=arr[j];
        j++;
    }
    if(sum==s)
    {
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }
    while(j<n)
    {
        sum+=arr[j];
        while(sum>s)
        {
            sum-=arr[i];
            i++;
        }
        if(sum==s)
        {
            st=i+1;
            ls=j+1;
            break;
        }
        j++;
    }
    cout<<"Array with the sum equal to "<<s<<endl;
    cout<<st<<" "<<ls<<endl;
    bool flag=true;
    cout<<flag;
    return 0;
}