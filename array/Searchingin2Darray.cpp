#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter Number of Row"<<endl;
    cin>>n;
     cout<<"Enter Number of colum"<<endl;
    cin>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;
    int c=0;
    int r=n-1;
    while(key!=arr[c][r])
    {
        if(key<arr[c][r])
        r--;
        else
        c++;
        if(c==n || c<0 || r==n || r<0)
        break;
    }
    if(key==arr[c][r])
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
    return 0;
}