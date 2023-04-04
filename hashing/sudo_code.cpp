#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void helper(int r,int c,vector<vector<char> > &arr,map<pair<int,int> ,map<int,int> > &mp,
vector<map<int,int> > row, vector<map<int,int> > col)
{
    if(r==9)
    {
       for(int i=0;i<9;i++)
       {
        for(int j=0;j<9;j++)
        {
            cout<<arr[i][j]<<"    ";
        }
        cout<<endl;
       }
       return;
    }

    if(c==9)
    {
        helper(r+1,0,arr,mp,row,col);
        return;
    }

    if(arr[r][c]!='.')
    {
        helper(r,c+1,arr,mp,row,col);
        return ;
    }

    for(int i=1;i<=9;i++)
    {
        int rw=r/3;
        int cw=c/3;
        if(!mp[{rw,cw}][i] && !row[r][i] && !col[c][i])
        {
            mp[{rw,cw}][i]=1;
            row[r][i]=1;
            col[c][i]=1;
            arr[r][c]=i+'0';
            helper(r,c+1,arr,mp,row,col);
            mp[{rw,cw}][i]=0;
            row[r][i]=0;
            col[c][i]=0;
            arr[r][c]='.';    
        }
    }
}

void sudo_code(vector<vector<char> > &arr)
{
    map<pair<int,int> ,map<int,int> > mp;
    vector<map<int,int> > row(9);
    vector<map<int,int> > col(9);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j] != '.')
            {
                mp[{i/3,j/3}][arr[i][j]-'0']=1;
                row[i][arr[i][j]-'0']=1;
                col[j][arr[i][j]-'0']=1;
            }
        }
    }
    helper(0,0,arr,mp,row,col);
}
int main()
{
    vector<vector<char> > arr={
        {'5', '3' , '.' , '.' , '7' , '.' , '.' , '.' , '.' },
        {'6', '.' , '.' , '1' , '9' , '5' , '.' , '.' , '.' },
        {'.', '9' , '8' , '.' , '.' , '.' , '.' , '6' , '.' },
        {'8', '.' , '.' , '.' , '6' , '.' , '.' , '.' , '3' },
        {'4', '.' , '.' , '8' , '.' , '3' , '.' , '.' , '1' },
        {'7', '.' , '.' , '.' , '2' , '.' , '.' , '.' , '6' },
        {'.', '6' , '.' , '.' , '.' , '.' , '2' , '8' , '.' },
        {'.', '.' , '.' , '4' , '1' , '9' , '.' , '.' , '5' },
        {'.', '.' , '.' , '.' , '8' , '.' , '.' , '7' , '9' },
    };
    sudo_code(arr);
}














