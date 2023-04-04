/*
Travelsal technique of tree data structure 
1.  Preorder
2.Inorder
3.Postorder
*/
#include<iostream>
#include<stack>
using namespace std;
struct Node{
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
void preorder(struct Node* root)
{
    //1. root
    //2.left lefe
    //3. right lefe
    
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"   ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root)
{
    //1.left lefe
    //2. root
    //3. right lefe
    
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<"   ";
    inorder(root->right);
}
void postorder(struct Node* root)
{
    //1. left lefe
    //2. right lefe
    //3. root
    
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"   ";
    
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
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}

/*

          1
        /   \
       2      3
     /   \   /   \
     4    5  6    7
*/
