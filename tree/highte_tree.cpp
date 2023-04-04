#include<iostream>
using namespace std;
/*
we Will go throw the last node ans cheak the hight of tree at every node
using recurssion 
*/
struct Node
{
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

int hightoftree(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lefthight=hightoftree(root->left);
    int righthighit=hightoftree(root->right);
    return max(lefthight,righthighit)+1;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<hightoftree(root);
    return 0;
}