/*
for every element of array we will maintain two varible 
first =min value which can be put under thar node 
second =max value which can be put under thar node

har niode pr call kare ge tab tak ki value assign ni ho jati

*/
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
    Node* root=constructBST(preorder,&preIdx,preorder[0],INT_MIN,INT_MAX,n);
    prtpreorder(root);
    return 0;
}
