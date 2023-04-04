/* do stack le ge current and next 
current me se data nikalte jaye ge or print karae ge or next me push karte jaye ge
ak bool variable le ge jo direction batye ga
*/
#include<iostream>
#include<stack>
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
void zigzakBST(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<Node*> currnet;
    stack<Node*> nextnode;

    bool lefttoright=true;
    currnet.push(root);

    while(!currnet.empty())
    {
        Node* temp=currnet.top();
        currnet.pop();

        if(temp)
        {
            cout<<temp->data<<"  ";
            //for left to right direction
            if(lefttoright)
            {
                if(temp->left!=NULL)
                {
                    nextnode.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    nextnode.push(temp->right);
                }
            }
            // for right to left direction
            else
            {
                if(temp->right!=NULL)
                {
                    nextnode.push(temp->right);
                }
                if(temp->left!=NULL)
                {
                    nextnode.push(temp->left);
                }
            }
        }
        if(currnet.empty())
        {
            lefttoright= !lefttoright;
            swap(currnet,nextnode);
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
    zigzakBST(root);
    return 0;
}