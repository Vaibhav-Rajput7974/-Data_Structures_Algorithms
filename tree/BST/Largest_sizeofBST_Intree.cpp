/*
recurssion ki help se last node pr jaye ge or fir cheak kare ge ki who BST hai ya nhi agra hai toh
ans= wo node+leftsubtree + rightsubtree kar de ge or isBST= true
agra nhi hai toh
ans = maximum value of right subtree or leftsubtree || isBST=false

*/
#include<iostream>
#include<climits>
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
//storing information of every Node
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
Info LargestBST(Node* root)
{
    if(root==NULL)
    {
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL)
    {
        return {1,root->data,root->data,1,true};
    }
    Info leftInfo=LargestBST(root->left);
    Info rightInfo=LargestBST(root->right);

    Info curr;
    curr.size=(1+ leftInfo.size + rightInfo.size);
    
    //cheaking condition for BST
    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min=min(leftInfo.min, min(root->data , rightInfo.min));
        curr.max=max( rightInfo.max , max( leftInfo.max,root->data));
        curr.ans=curr.size;
        curr.isBST=true;
        return curr;
    }
    curr.ans=max(leftInfo.ans,rightInfo.ans);
    curr.isBST=false;
    return curr;
}
int main()
{
    Node* root=new Node(15);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(5);

    cout<<LargestBST(root).ans;
    return 0;
}
