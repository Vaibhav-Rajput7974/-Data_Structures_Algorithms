#include<iostream>
using namespace std;
int binarytodec(int n)
{
    int ans=0;
    int i=1;
    while(n!=0)
    {
        int m=n%10;
        ans=ans+m*i;
        i*=2;
        n=n/10;
    }
    return ans;
}
int octaltodec(int n)
{
    int ans=0;
    int i=1;
    while(n!=0)
    {
        int m=n%10;
        ans=ans+m*i;
        i*=8;
        n=n/10;
    }
    return ans;
}
int hexaadecimaltodec(int n)
{
    int ans=0;
    int i=1;
    while(n!=0)
    {
        int m=n%10;
        ans=ans+m*i;
        i*=16;
        n=n/10;
    }
    return ans;
}

int decimaltobinary(int n)
{
    int ans=0;
    int i=1;
    while(n!=0)
    {
        int m=n%2;
        ans=ans+m*i;
        cout<<ans<<endl;
        i*=10;
        n=n/2;
    }
    return ans;
}
int decimaltoctal(int n)
{
    int ans;
    int i=1;
    while(n!=0)
    {
        int m=n%8;
        ans=ans+m*i;
        i*=10;
        n=n/8;
    }
    return ans;
}
int decimaltohexadecimal(int n)
{
    int ans;
    int i=1;
    while(n!=0)
    {
        int m=n%16;
        ans=ans+m*i;
        i*=10;
        n=n/16;
    }
    return ans;
}
int main()
{
    cout<<"Enter which operation you want to perform"<<endl;
    cout<<"Press 1 to convert binary to decimal"<<endl;
    cout<<"Press 2 to convert octal to decimal"<<endl;
    cout<<"Press 3 to convert hexadecimal to decimal"<<endl;
    cout<<"Press 4 to convert decimal to binary"<<endl;
    cout<<"Press 5 to convert decimal to octal"<<endl;
    cout<<"Press 6 to convert decimal to hexadecimal"<<endl;

    int select;
    cin>>select;
    int num;
    switch(select)
    {
        case 1:
        cout<<"Enter binary number"<<endl;
        cin>>num;
        cout<<binarytodec(num);
        break;
        case 2:
        cout<<"Enter octal number"<<endl;
        cin>>num;
        cout<<octaltodec(num);
        break;
        case 3:
        cout<<"Enter hexadecimal number"<<endl;
        cin>>num;
        cout<< hexaadecimaltodec(num);
        break;
        case 4:
        cout<<"Enter decimal number"<<endl;
        cin>>num;
        cout<< decimaltobinary(num);
        break;
        case 5:
        cout<<"Enter decimal number"<<endl;
        cin>>num;
        cout<< decimaltoctal(num);
        break;
        case 6:
        cout<<"Enter hexadecimal number"<<endl;
        cin>>num;
        cout<< decimaltohexadecimal(num);
        break;
        default:
        cout<<"Wrong choice";
    }
}