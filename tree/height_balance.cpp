
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
bool isSafe(Node* root)
{
    if(root==NULL)
    return true;

    if(isSafe(root->left)==false)
    return false;

    if(isSafe(root->right) == false)
    return false;

    int lefthei=hightoftree(root->left);
    int righthei=hightoftree(root->right);

    if(abs(lefthei-righthei)<=1)
    return true;
    else
    return false;
}

//Optamise approch

bool isSafe_pointer(Node* root,int* height)
{
    if(root==NULL)
    return true;
    int lh=0,rh=0;
    if(isSafe_pointer(root->left,&lh)==false)
    return false;
    
    if(isSafe_pointer(root->right,&rh)==false)
    return false;

    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1)
    return true;
    else
    return false;
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
    int height=0;
    if(isSafe_pointer(root,&height))
    cout<<"balanced tree";
    else
    cout<<"Not Blanced";
    return 0;
}

/*
    Balanced Tree

          1
        /   \
       2      3
     /   \   /   \
     4    5  6    7
*/
