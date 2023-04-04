#include<iostream>
using namespace std;
void gcd(int a,int b)
{
    while(b!=0)
    {
        int rem=a%b;
        a=b;
        b=rem;
    }
    cout<<a;
}
int main()
{
    int a,b;
    cin>>a>>b;
    gcd(a,b);
    return 0;
}