#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int prefix(string s)
{
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int ope1=st.top();
            st.pop();
            int ope2=st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(ope1+ope2);
                break;
            case '-':
                st.push(ope1-ope2);
                break;
            case '/':
                st.push(ope1/ope2);
                break;
            case '*':
                st.push(ope1*ope2);
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
    string s="-+7*45+20";
    cout<<prefix(s);
    return 0;
}
