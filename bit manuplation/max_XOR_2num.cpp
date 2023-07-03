/*
we are going to use the login that XOR of 0 and 1 is 1 
so we will maximise the XOR by finding oposit bit for the given bit
we will use trie for storing 0 and 1 
*/
#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    Trie* zero;
    Trie* one;
};
void insert(Trie* root,int val){
    Trie* cur=root;
    for(int i=31;i>=0;i--){
        int bit=(val >>i ) & 1;
        if(bit == 1){
            if(cur->one == NULL){
                Trie* newnode=new Trie();
                cur->one=newnode;
            }
            cur=cur->one;
        }
        else{
            if(cur->zero == NULL){
                Trie* newnode=new Trie();
                cur->zero=newnode;
            }
            cur=cur->zero;
        }
    }
}
int max_XOR(Trie* root,int val){
    Trie* cur=root;
    int ans=0;
    for(int i=31;i>=0;i--){
        int bit=(val>>i) & 1;
        if(bit == 0){
            if(cur->one != NULL){
                ans+=(1<<i);
                cur=cur->one;
            }
            else{
                cur=cur->zero;
            }
        }
        else{
            if(cur->zero != NULL){
                ans+=(1<<i);
                cur=cur->zero;
            }
            else{
                cur=cur->one;
            }
        }
    }
    return ans;
}
int main(){
    int arr[]={8,5,4,9,1};
    Trie* root=new Trie();
    for(int i=0;i<5;i++){
        insert(root,arr[i]);
    }
    int maxi=INT_MIN;
    for(int i=0;i<5;i++){
        int cur=max_XOR(root,arr[i]);
        maxi=max(maxi,cur);
    }
    cout<<maxi;
}