#include<iostream>
#include<vector>
using namespace std;
bool mycom(pair<int,int> p1,pair<int,int> p2)
{
return p1.first<p2.first;
}
int main()
{
    int arr[]={10,16,7,14,5,3,2};
    vector< pair<int ,int >> v;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        pair <int,int > p;
        p.first=arr[i];
        p.second=i;
        v.push_back(p);
    }
    //sort(v.begin(),v.end(),mycom);
    return 0;
}