#include<iostream>
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
Node* insertBST(Node* root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(val<root->data)
    {
        root->left=insertBST(root->left,val);
    }
    else
    {
        root->right=insertBST(root->right,val);
    }
    return root;
}
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
bool serach(Node* root,int K)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==K)
    {
        return true;
    }
    if(root->data<K)
    {
        return serach(root->right,K);
    }
    else
    {
        return serach(root->left,K);
    }
    //return false;
}
Node* succeser(Node* root)
{
    Node* curr=root;
    while (curr && curr->left !=NULL)
    {
        curr=curr->left;
    }
    return curr;
    
}
Node* deleteNode(Node* root,int key)
{
    if(key<root->data)
    {
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=deleteNode(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp=root->left;
            free(root);
            return temp;
        }
        else{
            Node* inordersuc=succeser(root->right);
            root->data=inordersuc->data;
            root->right=deleteNode(root->right,inordersuc->data);
            }
    }
    return root;
}
int main()
{
    Node* root=NULL;
    root=insertBST(root,5);
    insertBST(root,12);
    insertBST(root,13);
    insertBST(root,2);
    insertBST(root,4);
    inorder(root);
    cout<<serach(root,121);   
    deleteNode(root,12);
    inorder(root); 
}
/*

            5
           /  \
          4     12
        /        
      2       
    /
   1
   */