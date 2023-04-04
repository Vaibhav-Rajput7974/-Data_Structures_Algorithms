#include<iostream>
using namespace std;
int to_num(string x)
    {
        int ans=0;
        int val=1;
        for(int i=x.length()-1;i>=0;i--)
        {
            char ch=x[i]-48;
            //cout<<x[i];
            ans=ans+val*ch;
            val=val*10;
            //cout<<ans;
        }
        cout<<ans<<endl;
        return ans;
    }
        int isValid(string s) {
            // code here
            int count=0;
            string temp="";
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='.')
                {
                    count++;
                    int num=to_num(temp);
                    //cout<<num;

                    if(num>=0 && num<=255)
                    {
                        temp="";
                        //num=0;
                        continue;
                    }
                    else
                    {
                        return 0;
                    }
                }
                temp.push_back(s[i]);
                //cout<<temp<<endl;

            }
                    int num=to_num(temp);
                    if(num>=0 && num<=255)
                    {
                        temp="";
                    }
                    else
                    {
                        return 0;
                    }
                    if(count==3)
                    return 1;
                    else return 0;
        }
int main()
{
    cout<<endl;
    cout<<isValid("123.222.111.111");
    return 0;
}