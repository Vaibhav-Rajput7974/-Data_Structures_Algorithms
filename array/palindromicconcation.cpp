#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool isPlaindrom(int num)
{
    int temp=num;
    int ans=0;
    while(temp!=0)
    {
        int dig=temp%10;
        ans=ans*10+dig;
        //coun++;
        temp=temp/10;
    }
    if(ans==num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
vector<int> palindrom(int arr[],int n,int k)
{
    vector<int> ans;
    int num=0;
    for(int i=0;i<k;i++)
    {
        int temp=arr[i];
        while(temp!=0)
        {
            num=num*10;
            temp=temp/10;
        }
        num+=arr[i];
    }
   // cout<<num<<"  ";
    if(isPlaindrom(num))
    {
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
    for(int i=k;i<n;i++)
    {
        int dig=0;
        int cheak=num;
        while(arr[i-k]<cheak)
        {
            dig++;
            cout<<cheak<<"  ";
            cheak/=10;
        }
        //cout<<num<<"  ";
        num=(num % (int) pow(10,k-1));
        //cout<<num<<"  ";
        int temp1=arr[i];
        while(temp1!=0)
        {
            num=num*10;
            temp1=temp1/10;
        }
        num+=arr[i];
        //cout<<num<<"   ";
        if(isPlaindrom(num))
        {
            for(int j=1+i-k;j<=i;j++)
            {
                ans.push_back(arr[j]);
            }
            return ans;
        }
    }
    return ans;
}
int main()
{
    int arr[]={2,3,51,1,1,15};
    vector<int> ans=palindrom(arr,6,4);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"   ";
    }
    return 0;
}