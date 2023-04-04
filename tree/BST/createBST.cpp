/*
on every level we have to cheak that the given value is less or greter then and according to that we have to traverse in tree
if less then in left sub tree
else
in right sub tree
*/
#include<iostream>
using namespace std;
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
Node* insertBST(Node* root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(val<root->data)
    {
        root->left=insertBST(root->left,val);
    }
    else
    {
        root->right=insertBST(root->right,val);
    }
    return root;
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<"   ";
    inorder(root->right);
}
bool serach(Node* root,int K)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==K)
    {
        return true;
    }
    if(root->data<K)
    {
        return serach(root->right,K);
    }
    else
    {
        return serach(root->left,K);
    }
    //return false;
}
int main()
{
    Node* root=NULL;
    root=insertBST(root,5);
    insertBST(root,12);
    insertBST(root,1);
    insertBST(root,2);
    insertBST(root,4);
    inorder(root);
    cout<<serach(root,121);    
}
/*

            5
           /  \
          4     12
        /        
      2       
    /
   1
   */