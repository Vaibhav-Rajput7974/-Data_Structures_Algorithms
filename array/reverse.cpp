#include<iostream>
using namespace std;
void reverefac(string s)
{
    if(s.length()==0)
    return ;

    string rec=s.substr(1);
    reverefac(rec);

    cout<<s[0];
    return;
}
int main()
{
    string s;
    cin>>s;
    reverefac(s);
    return 0;
}