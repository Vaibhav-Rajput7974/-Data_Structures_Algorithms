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
bool getpath(Node* root,int n,vector<int> & path)
{
    if(root==NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if(root->data==n)
    {
        return true;
    }
    if(getpath(root->left,n,path) || getpath(root->right,n,path))
    {
        return true;
    }
    path.pop_back();
    return false;
}
int LCA(Node* root,int n1,int n2)
{
    vector<int> path1,path2;
    if(!getpath(root,n1,path1) || !getpath(root,n2,path2))
    {
        return true;
    }
    int pc;
    for(pc=0;pc<path1.size() && path2.size() ;pc++)
    {
        if(path1[pc]!=path2[pc])
        {
            break;
        }
    }
    return path1[pc-1];
}
Node* LCA2(Node* root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    Node* leftlcm=LCA2(root->left,n1,n2);
    Node* rightlcm=LCA2(root->right,n1,n2);
    
    if(leftlcm && rightlcm)
    {
        return root;
    }

    if(leftlcm!=NULL)
    {
        return leftlcm;
    }
    return rightlcm;
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
    cout<<LCA2(root,6,7)->data;
    return 0;
}
/*

          1
        /   \
       2      3
     /   \   /   \
     4    5  6    7
*/
