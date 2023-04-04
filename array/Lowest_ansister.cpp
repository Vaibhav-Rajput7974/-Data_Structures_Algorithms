/*
lowest common ansister is the point where the path of two node changes 
show we will find the path of two node and cheak where the path is changed and will return that point
*/
#include<iostream>
#include<vector>
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
bool getpath(Node* root,int key,vector<int> &v1)
{
    if(root==NULL)
    return false;

    v1.push_back(root->data);
    if(key==root->data)
    {
        return true;
    }

    if(getpath(root->left,key,v1) || getpath(root->right,key,v1))
    {
        return true;
    }
    v1.pop_back();
    return false;
}
int LCA(Node* root ,int n1,int n2)
{
    vector<int> v1,v2;
    if(!getpath(root,n1,v1) || !getpath(root,n2,v2))
    return -1;
    int i;
    for(i=0;i<v1.size() && v2.size();i++)
    {
        if(v1[i]!=v2[i])
        {
            break;;
        }
    }
    return v1[i-1];
}
Node* LCA2(Node* root ,int n,int m)
{
    if(root==NULL)
    return NULL;
    if(root->data==n || root->data==m)
    return root;

    Node* leftNode=LCA2(root->left,n,m);
    Node* rightNode=LCA2(root->right,n,m);

    if(leftNode && rightNode)
    return root;

    if(leftNode!=NULL)
    return leftNode;

    return rightNode;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->left->right=new Node(9);
    
    root->right->right=new Node(7);
    cout<<LCA2(root,9,7)->data;
    //right_view(root);
    return 0;
}

/*

          1
        /   \
       2      3
     /   \   /   \
     4    5  6    7
              \
                9  
*/