/*
we will find mid element of array and assign it as root and the left element are element of left subtree and right element are the element of rightsubtree
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
Node* sortedBST(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);

    root->left=sortedBST(arr,start,mid-1);

    root->right=sortedBST(arr,mid+1,end);

    return root;
}
int main()
{
    int arr[]={1,2,3,4,5,6};
    Node* root=sortedBST(arr,0,5);
    inorder(root);
    return 0;
}