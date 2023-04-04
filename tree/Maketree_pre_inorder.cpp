/*
Making Tree using Inorder and preorder

We know in preorder first element is root node and in inorder element to the left of root is element of left subtree 
and right are element of right subtree
*/

#include<iostream>
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
int search(int inorder[],int start,int end,int current)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==current)
        return i;
    }
    return -1;
}
/*

Ese tree bane ga
4  - 2  -  1  -  5 -  1  fir return 

*/
Node* Make_tree(int preorder[],int Inorder[],int start,int end)
{
    static int idx=0;
    if(start>end)
    {
        return NULL;
    }
    int current=preorder[idx];
    idx++;
    Node* node=new Node(current);
    if(start==end)
    {
        return node;
    }
    int pos=search(Inorder,start,end,current);
    node->left=Make_tree(preorder,Inorder,start,pos-1);
    node->right=Make_tree(preorder,Inorder,pos+1,end);
    return node;
}
void preorder_print(struct Node* root)
{
    //1. root
    //2.left lefe
    //3. right lefe
    
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"   ";
    preorder_print(root->left);
    preorder_print(root->right);
}
int main()
{
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node* root=Make_tree(preorder,inorder,0,4);
    preorder_print(root);
    return 0;
}

/*
               1
             /   \
           2       3
          /       /
        4        5

        */