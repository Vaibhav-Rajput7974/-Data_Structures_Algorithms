
#include<iostream>
#include<vector>
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
Node* LCA(Node* root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    Node* leftlca=LCA(root->left,n1,n2);
    Node* rightlca=LCA(root->right,n1,n2);

    if(leftlca && rightlca)
    {
        return root;
    }
    if(leftlca==NULL && rightlca==NULL)
    {
        return NULL;
    }
    if(leftlca!=NULL)
    {
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}
int finddistance(Node* root,int k,int dist)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==k)
    {
        return dist;
    }
    int left=finddistance(root->left,k,dist+1);
    if(left !=-1 )
    {
        return left;
    }
    return finddistance(root->right,k,dist+1);
}
int distanceBW2Node(Node* root,int n1,int n2)
{
    Node* lca=LCA(root,n1,n2);
    // cout<<lca->data;
    int d1=finddistance(lca,n1,0);
    int d2=finddistance(lca,n2,0);
    return d1+d2;
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
    cout<<distanceBW2Node(root,7,2);
   // cout<<LCA2(root,6,7)->data;
    return 0;
}
/*

          1
        /   \
       2      3
     /   \   /   \
     4    5  6    7
*/
