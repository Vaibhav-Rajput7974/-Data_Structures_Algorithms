#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=8;
    string station[n]={"TH","GA","IC","HA","TE","LU","NA","CA"};
    int dis[8]={800,600,750,900,1400,1200,1100,1500};
    //cin>>n;

    string source;
    string distination;
    cin>>source>>distination;
    int idx1=-1;
    int idx2=-1;
    for(int i=0;i<n;i++){
        if(source == station[i]){
            idx1=i;
        }
        if(distination == station[i]){
            idx2=i;
        }
    }
    if(idx1 == -1 || idx2 == -1 || idx1 == idx2){
        cout<<"invalid test";
    }
    int distance=0;
    //int end=idx2+1;
    while(idx1 != idx2){
        if(idx1+1 == n){
            idx1=0;
        }
        else{
            idx1+=1;
        }
        //cout<<dis[idx1];
        distance+=dis[idx1];
    }
    //distance+=dis[idx2];
    int total=distance/1000;
    if(distance % 1000 >=500){
        total+=1;
    }
    cout<<total*5;
    return 0;
}