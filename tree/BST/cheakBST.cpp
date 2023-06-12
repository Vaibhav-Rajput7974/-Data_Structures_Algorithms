/*

we will mantanin the value to current note so that we have idea of not going obove or below that value*/
#include<iostream>
using namespace std;
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
void prtpreorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"   ";
    prtpreorder(root->left);
    prtpreorder(root->right);
}
bool cheakBST(Node* root,int min,int max)
{
    if(root==NULL)
    {
        return true;
    }
    int key=root->data;
    if(key>min && key<max)
    {
        if(!cheakBST(root->left,min,key))
        {
            return false;
        }
        if(!cheakBST(root->right,key,max))
        {
            return false;
        }
        return true;
    }
    return false;
}
Node* constructBST(int preorder[],int *preIdx,int key,int min,int max,int n)
{
    if(*preIdx>=n)
    {
        return NULL;
    }
    Node* root=NULL;
    if(key>min && key<max)
    {
        root=new Node(key);
        *preIdx=*preIdx+1;

        if(*preIdx<n)
        {
            root->left=constructBST(preorder,preIdx,preorder[*preIdx],min,key,n);
        }
        if(*preIdx<n)
        {
            root->right=constructBST(preorder,preIdx,preorder[*preIdx],key,max,n);
        }
    }
    return root;
}
int main()
{
    int preorder[]={10,2,1,13,11};
    int preIdx=0;
    int n=5;
    //Node* root=constructBST(preorder,&preIdx,preorder[0],INT_MIN,INT_MAX,n);
    Node* root=new Node(10);
    root->left=new Node(8);
    root->left->left=new Node(9);
    root->right=new Node(13);
    prtpreorder(root);
    cout<<cheakBST(root,INT_MIN,INT_MAX);
    return 0;
}
