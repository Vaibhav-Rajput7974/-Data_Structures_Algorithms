#include<iostream>
using namespace std;
void subs(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string rg=s.substr(1);

    subs(rg,ans);
    subs(rg,ans+ch);
}
int main()
{
    //string s;
    //cin>>s;
    subs("abc","");
    return 0;
}