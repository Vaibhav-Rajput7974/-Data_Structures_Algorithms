#include <bits/stdc++.h>
using namespace std;
/*
we will make map for horizontal distance from root node to that point 
key in map == horizontal_distance
value in map == element of tree 
*/
struct Node
{
    /* data */
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
void getvertical_order(Node* root,int HDis,map<int,vector<int>> &mp)
{
    if(root==NULL)
    {
        return;
    }
    mp[HDis].push_back(root->data);
    getvertical_order(root->left,HDis-1,mp); // for leftsubtree horizontal_dis-1
    getvertical_order(root->right,HDis+1,mp); // for rightsubtree horizontal_dis+1
    return;
}
int main()
{
    map<int,vector<int>> mp;
    Node* root=new Node(10);
    root->left=new Node(7);
    root->right=new Node(4);
    root->left->left=new Node(3);
    root->left->right=new Node(11);
    root->right->left=new Node(14);
    root->right->right=new Node(6);
    int HDis=0;
    getvertical_order(root,HDis,mp);

    map<int,vector<int>> ::iterator itr;

    for(itr=mp.begin(); itr!=mp.end();++itr)
    {
        //cout<<itr->first;
        for(int i=0;i<(itr->second).size();i++)
        {
            cout<<(itr->second)[i]<<"  ";
        }
    }
    return 0;
}