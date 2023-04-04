/* 
replace all node with it's subtree sum
*/
#include<iostream> 
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

int sum_replace(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftSum=sum_replace(root->left);
    int rightSum=sum_replace(root->right);
    root->data=leftSum+rightSum+root->data;
    return root->data;
}

//using another method

void new_node(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    new_node(root->left);
    new_node(root->right);
    if(root->left!=NULL)
    {
        root->data+=root->left->data;
    }
    if(root->right!=NULL)
    {
        root->data+=root->right->data;
    }
}
void display(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    new_node(root);
    display(root);
    return 0;
}