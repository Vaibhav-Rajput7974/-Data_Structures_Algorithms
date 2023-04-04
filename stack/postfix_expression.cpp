#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int postfix(string s)
{
    stack<int> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int ope2=st.top();
            st.pop();
            int ope1=st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(ope1+ope2);
                break;
            case '-':
                st.push(ope1-ope2);
                break;
            case '*':
                st.push(ope1*ope2);
                break;
            case '/':
                st.push(ope1/ope2);
                break;
            case '^':
                st.push(pow(ope1,ope2));
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string s="46+2/5*7+";
    cout<<postfix(s);
    return 0;
}