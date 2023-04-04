#include<iostream>
using namespace std;
int main()
{
    string s1="raajAAAA";
    int freq[52];
    for(int i=0;i<52;i++)
    freq[i]=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>='a' && s1[i]<='z')
        freq[s1[i]-'a']++;
        else if(s1[i]>='A' && s1[i]<='Z')
        freq[26+s1[i]-'A']++;
    }
    int maxi=0;
    char ans='a';
    for(int i=0;i<52;i++)
    {
        if(maxi<freq[i])
        {
            maxi=freq[i];
            if(i<26)
            ans=i+'a';
            else
            ans=26-i+'A';
        }
    }
    cout<<maxi<<" "<<ans<<endl;
    return 0;
}