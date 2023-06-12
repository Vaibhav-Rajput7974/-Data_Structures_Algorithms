/*
         common subsequence
for every element we have choice to take it or not take it 
*/
#include<iostream>
#include<vector>
using namespace std;
vector<string> v1;
vector<string> v2;

void subseq(string s,string ans)
{
    if(s.length()==0)
    {
        v1.push_back(ans);
        cout<<ans<<endl;
        return;
    }

    string rec=s.substr(1);
    char ch=s[0];
    
    subseq(rec,ans);
    subseq(rec,ans+ch);
}
void subseq2(string s,string ans)
{
    if(s.length()==0)
    {
        v2.push_back(ans);
        cout<<ans<<endl;
        return;
    }

    string rec=s.substr(1);
    char ch=s[0];
    
    subseq2(rec,ans);
    subseq2(rec,ans+ch);
}

int main()
{
    string s,t;
    cin>>s>>t;
    subseq(s,"");
    subseq2(t,"");
    int count=0;
    for(int i=0;i<v1.size();i++)
    {
        int o=0;
        for(int j=0;j<v2.size();j++)
        {
            if(v1[i]==v2[j])
            {
                o=10;
                break;
            }
        }
        if(o==10)
        count++;
    }
    cout<<count;
    return 0;
}