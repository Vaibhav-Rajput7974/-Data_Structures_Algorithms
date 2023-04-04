/*
diameter me a to root node incude rahe ga ya nhi 
agra rahe ga tab hight ho jaye gi = height of right + hight of left + 1;

agra root include nhi hai tab heght ya to diameter of right tree rahe gi ya fir left rahe gi=max(diameterof_right,diameterof_left); 
*/
#include<iostream>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    int data;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
int heightof_tree(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftheight=heightof_tree(root->left);
    int rightheight=heightof_tree(root->right);

    return max(leftheight,rightheight)+1;
}
int diameter_tree(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int diameter_left=diameter_tree(root->left);
    int diameter_right=diameter_tree(root->right);

    int lfheight=heightof_tree(root->left);
    int rgheight=heightof_tree(root->right);

    int diameter=lfheight+rgheight+1;

    return max(max(diameter_left,diameter_right),diameter);
}

//optimice approch of calculating diameter
//Using pointer

int calculate_dimaeter(Node* root,int* height)
{
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int LDiameter=calculate_dimaeter(root->left,&lh);
    int RDiameter=calculate_dimaeter(root->right,&rh);

    int currentDiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(max(LDiameter,RDiameter),currentDiameter);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->left->left=new Node(4);
    root->left->left->left->left=new Node(5);
   //root->right=new Node(6);
   // root->left->right->right=new Node(7);
   // cout<<diameter_tree(root);
   int height=0;
    cout<<calculate_dimaeter(root,&height);
    return 0;
}