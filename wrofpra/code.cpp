#include <bits/stdc++.h>
using namespace std;
 
// A function to print all prime
// factors of a given number n
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}


string convert(string s, int numRows) {
        int n=s.length();
        vector<char > ans[numRows];
        int count;
        if(numRows > 2)
            count = numRows-1;
        else
        {
            count=0;
        }
        int j=0;
        //int col=0;
        int rowskip=count;
        int colskip=count;
        while(j<n)
        {
            cout<<rowskip;
            if( rowskip == count)
            {
                //cout<<"  s";
                for(int i=0;i<numRows;i++)
                {
                    ans[i].push_back(s[j]);
                    j++;
                    if(j>=n)
                        break;
                }
                rowskip--;
            }
            else
            {
                //cout<<"  dsd";
                for(int i=0;i<numRows;i++)
                {
                    cout<<colskip;
                    if(colskip == 1)
                    {
                        ans[i].push_back(s[j]);
                       // cout<<"dsd";
                        j++;
                        colskip = count ;
                    }
                    if(j>= n)
                            break;
                    colskip--;
                    
                }
                
                rowskip--;
            }
            cout<<endl;
            if(rowskip == 0 )
            {
                rowskip = count;
            }
        }
        string sum="";
        string a="";
        for(int i=0;i<numRows;i++)
        {
            a.push_back(ans[i][2]);
            for(auto j: ans[i])
            {
                char temp=char(j);
                cout<<temp<<"  ";
            }
            cout<<endl;
        }
        return a;
    }
 
/* Driver code */


int compress(vector<char>& s) {
        int i=0;
        int n=s.size();
        string ans="";
        pair<char,int> p;
        //p.
       // p=make_pair('0',0);
        while(i<n)
        {
            if(p.first == '0')
            {
                p.first=s[i];
                p.second=1;
            }
            if(p.first == s[i])
            {
                p.second =p.second+1;
            }
            else
            {
                ans.push_back(p.first);
                //cout<<p.second;
               ans+= to_string(p.second-1);
                //ans.push_back(num);
                p.first='0';
                p.second=0;
                continue;
            }
            i++;
        }
        ans.push_back(p.first);
        ans+= to_string(p.second-1);
        for(int i=0;i<ans.size();i++)
        {
            s[i]=ans[i];
        }
        cout<<ans;
        return ans.size();
    }
    string Binary(int n)
    {
        string ans="";
        while(n)
        {
            int num = n%2;
            ans= to_string(num)+ ans; 
            n=n/2;
        }
        return ans;
    }

class WordDictionary {
    public:
    string val;
    WordDictionary* next;

WordDictionary* head;
    WordDictionary() {
        head=this;
        head->val="";
        head->next=NULL;
    }
    WordDictionary(string wr)
    {
        head=this;
        head->val=wr;
        head->next=NULL;
    }
    void addWord(string word) {
        head->next=new WordDictionary(word);
        //head->next->val=word;
        head=head->next;
    }
    
    bool search(string word) {
        //cout<<"ra,";
        WordDictionary* newhead=this;
        //cout<<newhead->val;
        while(newhead!=NULL)
        {
            cout<<newhead->val;
            newhead=newhead->next;
        }
        return false;
    }
};

int main()
{
    int n =6;
    //convert("PAYPALISHIRING",3);
   // vector<char> ans={'a','a','b','b','c','c','c'};
   // compress(ans);
   //cout<<Binary(54)<<endl;
   //cout<<s;
    WordDictionary* obj = new WordDictionary();
    obj->addWord("word");
    obj->addWord("wfdsford");
    obj->addWord("wordffd");
    
    bool param_2 = obj->search("word");
   // cout<<"sd";
    return 0;
}