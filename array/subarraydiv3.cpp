/*
sliding window approch
adding sum of digites in sum 
and subtracting the sum of digites in starting
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> subArraydiv(int arr[],int n,int k)
{
    vector<int> ans;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        int num=arr[i];
        while(num!=0)
        {
            int dig=num%10;
            sum+=dig;
            num=num/10;
        }
    }
    if(sum%3==0)
    {
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
    for(int i=k;i<n;i++)
    {
        int add=0;
        int sub=0;
        int num1=arr[i];
        int num2=arr[i-k];
        while(num1!=0)
        {
            int dig=num1%10;
            add+=dig;
            num1=num1/10;
        }
        while(num2!=0)
        {
            int dig=num2%10;
            sub+=dig;
            num2=num2/10;
        }
        sum=sum+add-sub;
        if(sum%3==0)
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
    int arr[]={12,3,1,2,5};
    vector<int>ans=subArraydiv(arr,5,3);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"   ";
    }
    return 0;
}