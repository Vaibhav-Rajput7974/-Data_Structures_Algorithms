/*
Making Tree using Inorder and postorder

We know in postorder last element is root node and in inorder element to the left of root is  left subtree 
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
int search(int Inorder[],int start,int end,int current)
{
    for(int i=start;i<=end;i++)
    {
        if(Inorder[i] == current)
        {
            return i;
        }
    }
    return -1;
}
Node* Make_tree_post(int postord[],int Inord[],int start,int end)
{
    static int idx=end;
    if(start>end)
    {
        return NULL;
    }
    int current=postord[idx];
    idx--;
    Node* node=new Node(current);
    if(start==end)
    {
        return node;
    }
    int pos=search(Inord,start,end,current);
    node->right=Make_tree_post(postord,Inord,pos+1,end);
    node->left=Make_tree_post(postord,Inord,start,pos-1);
    return node;
}
void postorder_print(struct Node* root)
{
    //1. left lefe
    //2. right lefe
    //3. root
    
    if(root==NULL)
    {
        return;
    }
    postorder_print(root->left);
    postorder_print(root->right);
    cout<<root->data<<"   ";
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
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    Node* root=Make_tree_post(postorder,inorder,0,4);
    postorder_print(root);
    cout<<endl;
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