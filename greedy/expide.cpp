/*
in this problem we will first change the distace from the town to distance from the truck becouse 
then shot it on the bases of distance from he track
then mainten a haxheap of fule station which can be traverse in the current fule 
and if the value of curentfule become less the the fule requare for going to the next station 
the pop the element from the maxheap and add in current fule and inncreament the ans variable
after reaching the last station cheak if current fule is sufficent to reach the station or not if not then pop the element from the maxheap
if maxheap is empty then return -1;
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<int> > arr;
    //distance of fulestation from the town and fule avalible at that point
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    int l,p;
    cout<<"enter current fule and distance of track from the town";
    cin>>l>>p;

    //change distance from the town to distance from the track
    for(int i=0;i<n;i++)
    {
        arr[i][0]=l-arr[i][0];
    }
    sort(arr.begin(),arr.end(),[&](vector<int>&a,vector<int> &b)
    {
        return a[0]>b[0];
    });
    int ans=0;
    int current=p;
    int flage=false;
    priority_queue<int,vector<int>> q;
    for(int i=0;i<n;i++)
    {
        if(current>=l)
        break;
        
        while(current < arr[i][0])
        {
            if(q.empty())
            {
                flage=true;
                break;
            }
            ans++;
            current += q.top();
            q.pop();
        }
        if(flage)
        break;

        q.push(arr[i][1]);
    }

    while (!q.empty() && current <l)
    {
        current += q.top();
        q.pop();
        ans++;
    }
    if(flage)
    {
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}