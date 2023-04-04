#include<iostream>
using namespace std;
int fabino(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;

    return fabino(n-1)+fabino(n-2);
}
int main()
{
    int n;
    cin>>n;
    fabino(n);
    return 0;
}