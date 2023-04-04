#include<iostream>
#include<stack>
using namespace std;
bool cheak_brackit(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(!st.empty() && s[i]==')')
        {
            if(st.top()=='(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if(!st.empty() && s[i]==']')
        {
            if(st.top()=='[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if(!st.empty() && s[i]=='}')
        {
            if(st.top()=='{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cout<<cheak_brackit("{[()]}");
    return 0;
}