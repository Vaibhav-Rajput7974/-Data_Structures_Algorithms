/*

we Will do level order Traversal and will print the last element at every Level
*/
#include<iostream>
#include<queue>
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
void right_view(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    int n=q.size();
    while (!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* curr=q.front();
            q.pop();
            if(i==n-1)
            {
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
    
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
    right_view(root);
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
