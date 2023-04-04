#include<iostream>
using namespace std;
void tohe(int n,char src,char des,char hel)
{
    if(n==0)
    return;

    tohe(n-1,src,hel,des);
    cout<<src<<"   "<<des<<endl;
    tohe(n-1,hel,des,src);
}
int main()
{
    tohe(3,'A','C','B');
    return 0;
}