#include<iostream>
using namespace std;
string removex(string s)
{
    if(s.length()==0)
    return "";

    string ans=removex(s.substr(1));
    if(s[0]=='x')
    return ans+'x';

    return s[0]+ans;
}
int main()
{
    cout<<removex("abxxbs");
    return 0;
}