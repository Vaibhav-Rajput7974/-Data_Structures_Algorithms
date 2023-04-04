/*
We know catalan of C(n)=sumition of C(i) * C(n-i); where i=0 to n-1

from above formula we can say C(3)=C(0)*C(2)+ c(1)*C(1) + C(2)*C(0);
using this we will write code
*/
#include<iostream>
using namespace std;
int catalanNum(int n)
{
    if(n<=1)
    {
        return 1;
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res+=catalanNum(i) * catalanNum(n-1-i);
    }
    return res;
}
int main()
{
    for(int i=0;i<10;i++)
    {
        cout<<catalanNum(i)<<"   ";
    }
    return 1;
}