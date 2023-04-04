/*
Make tree using preorder Traversal
In this type we will use 2 variable-
one will point to the left lefe and second will point to the right lefe
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
int i=0;
void Make_tree_preorder(int arr[],Node* root)
{
    i++;
    if(root==NULL)
    {
        return;
    }
    root->data=arr[i];
    Node* temp1=root->left;
    Make_tree_preorder(arr,root->left);
    Node* temp2=root->right;
    Make_tree_preorder(arr,root->right);

}
int main()
{
    Node* root=NULL;
    int arr[]={1,2,3};
    return 0;
}