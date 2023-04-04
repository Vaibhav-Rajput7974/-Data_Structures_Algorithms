#include<iostream>
#include<stack>
using namespace std;
void left_max(int arr[],int left[],int n)
{
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while (!st.empty() && st.top()<arr[i])
        {
            st.pop();
        }
        if(st.empty())
        left[i]=arr[i];
        else
        left[i]=st.top();

        st.push(arr[i]);
    }
}
void right_max(int arr[],int right[],int n)
{
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while (!st.empty() && st.top()<arr[i])
        {
            st.pop();
        }
        if(st.empty())
        right[i]=arr[i];
        else
        right[i]=st.top();

        st.push(arr[i]);
    }
}
void water_trapped(int arr[],int n)
{
    int left[n];
    int right[n];
    left_max(arr,left,n);
    right_max(arr,right,n);

    for(int i=0;i<n;i++)
    {
        cout<<left[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<right[i]<<" ";
    }
}
void trap(int arr[],int n)
{
    stack<int> st;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]<arr[i])
        {
            int before=st.top();
            st.pop();
            if(st.empty())
            {
                break;
            }
            int dif=i-st.top()-1;
            ans+=(min(arr[st.top()],arr[i])-arr[before])*dif;
        }
        st.push(i);
    }
    //cout<< ;
    cout<<ans;
}
int main()
{
    int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};
    trap(arr,12);
    return 0;
}