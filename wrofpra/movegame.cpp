#include<iostream>
using namespace std;
int count=0;
void game(int a,int b,string ans)
{
    if(b<a)
    return;
    if(a==b)
    {
        cout<<ans<<endl;
        count++;
        return ;
    }
    for(int i=1;i<=6;i++)
    {
        game(a+i,b,ans+" "+to_string(i));
    }
}
int main()
{
    game(0,4,"");
    cout<<count;
    return 0;
}