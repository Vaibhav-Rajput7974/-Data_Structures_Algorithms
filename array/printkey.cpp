#include<iostream>
using namespace std;
string keypade[]={"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void printbu(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code=keypade[ch-'0'];
    string ros=s.substr(1);

    for(int i=0;i<code.length();i++)
    {
        printbu(ros,ans+code[i]);
    }
}
int main()
{
    string s="23";
    printbu(s,"");
    return 0;
}