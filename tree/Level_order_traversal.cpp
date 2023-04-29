/*
har element ke liye dekhe ge ki us ka left ya fir right child hai ki nhi agra hai to use que me push kar de ge
fir har level ke bad NULL ko push kar de ge

*/
#include<iostream>
#include<queue>
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
void Level_traversal(Node* root)
{
    if(root==NULL)
    return;
    int sum=0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();
        Node* cheak=q.front();
        
        if(node!=NULL)
        {
            sum+=node->data;
            //cout<<node->data<<" ";
            if(node->left!=NULL)
            q.push(node->left);
            if(node->right!=NULL)
            q.push(node->right);
        }
        else if(!q.empty())
        {
            cout<<sum<<endl;
            sum=0;
            cout<<endl;
            q.push(NULL);
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
    root->right->right=new Node(7);
    Level_traversal(root);
    return 0;
}
