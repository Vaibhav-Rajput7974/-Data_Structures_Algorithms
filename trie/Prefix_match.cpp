/*
in this we will create a trie which will store to thinks 
1.the count of how much time it have been visited  
2.next node pointer
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int cnt;
    map<char,Node*> next;
    Node(){
        cnt=0;
    }
};
int main(){
    int n=5;
    string arr[]={"abbs","adda","abbd","abbdh","abbdsa"};
    int k=3;
    string str="abbfd";
    Node* root =new Node();
    for(int i=0;i<n;i++){
        string x=arr[i];
        Node* temp=root;
        for(int j=0;j<x.length();j++){
            if(temp->next.find(x[j]) == temp->next.end())   temp->next[x[j]]=new Node;
            temp=temp->next[x[j]];
            temp->cnt++;
        }
    }
    Node* temp=root;
    for(int i=0;i<k;i++){
        if(temp->next.find(str[i]) == temp->next.end()){
            cout<<0;
            return 0;
        }
        temp=temp->next[str[i]];

    }
    cout<<temp->cnt;
    return 0;
}