#include<iostream>
using namespace std;
string removed(string s)
{
if(s.length()==0)
return "";

char ch=s[0];
string ans=removed(s.substr(1));

if(ch==ans[0])
{
return ans;
}
return (ch+ans);
}
int main()
{
    cout<<removed("raaffag")<<endl;
    return 0;
}